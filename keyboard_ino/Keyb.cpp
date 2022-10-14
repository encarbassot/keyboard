#include "Keyb.h"
#include "CONFIG.h"
#include "Arduino.h"
#include "utils.h"
#include "Key.h"


#ifndef SERIAL_OUTPUT
  #include <Keyboard.h>
#endif

void Keyb::setup(){
  for(unsigned char i=0; i<PINS_DECO_LEN;i++){
    pinMode(pins_deco[i],OUTPUT);
  }
  for(unsigned char i=0; i<PINS_MUX_LEN;i++){
    pinMode(pins_mux[i],OUTPUT);
  }
  pinMode(PIN_MUX_INP,INPUT);

  #ifdef SERIAL_OUTPUT
    Serial.begin(9600);
    delay(2000);
    Serial.println("BEGIN");
  #else
    Keyboard.begin(); 
    delay(200);
    Keyboard.releaseAll();
  #endif
  
  #ifdef ADJACENCY_MATRIX
    translateMatrix();
  #endif


  #ifdef TEST3
    #ifndef SERIAL_OUTPUT
       #ERROR: TEST3 only works with Serial output
    #endif
    for(int j=0;j<VIRTUAL_ROWS;j++){
      for(int i=0;i<VIRTUAL_COLUMNS;i++){
        Serial.print(getVal(codes[0][j][i]));
        Serial.print("\t");
      }
      Serial.println();
    }
  #endif//TEST3
}

void Keyb::loop(){
  readMatrix();
  modifiersTimeout();//1 of 10 cycles maybe
}

void Keyb::readMatrix(){
  bool aux;
  #ifdef TEST1
  delay(10);
  Serial.println();Serial.println();Serial.println(keyCount);
    #ifndef SERIAL_OUTPUT
     #ERROR: TEST1 only works with Serial output
    #endif
  #endif

  keyCount = 0;
  
  for(int j=0;j<VIRTUAL_ROWS;j++){
    
    #ifdef BOARD_DECODER
    setDecoder(j);
    #else
    //digitalWrite(mat_outs[j],LOW);
    #endif
    
    for(int i=0;i<VIRTUAL_COLUMNS;i++){
      
      #ifdef BOARD_MULTIPLEXER
      aux = setMultiplexer(i);
      #else
      //aux = !digitalRead(mat_inps[i]);
      #endif
      keyCount += aux;
      
      #ifdef TEST1
        Serial.print(aux);
      #else
      
      if(aux!=prev[j][i]){
        prev[j][i]=aux;
        timestampLastKey = millis();
        
        #ifdef TEST2
        if(!aux){
          #ifdef SERIAL_OUTPUT
          Serial.println(test2counter);
          #else
          Keyboard.print(test2counter);
          Keyboard.press(test2counter);Keyboard.release(test2counter);
          Keyboard.press(CODE_ENTER);Keyboard.release(CODE_ENTER);
          #endif
          test2counter++;
          if(test2counter>255){
            test2counter=10;
          }
        }
        #else//test2
        if(aux){//press
          keyPress(j,i);
        }else{//release
          keyRelease(j,i);
        }
        #endif//test2
      }
      #endif//test1
      //delay(1);
    }
    #ifdef TEST1
    Serial.println();
    #endif

    #ifndef BOARD_DECODER
    //digitalWrite(mat_outs[j],HIGH);
    #endif
  }
  delay(1);
}

bool Keyb::keyStat(unsigned char k[]){return keyStat(k[0],k[1]);}
bool Keyb::keyStat(unsigned char j, unsigned char i){return prev[j][i];}

unsigned int Keyb::getKeyCode(unsigned char as){
  if(as>=KEY_CODE_LEN){
    return 0;
  }
  return key_code[as];
}
////////DO KEY///////////
void Keyb::doKey(unsigned char j,unsigned char i){
  #ifdef SERIAL_OUTPUT
    Serial.print("###");
  #endif
  
  doKey(true,j,i);
  delay(MINIMUM_PRESS_TIME);
  doKey(false,j,i);
}

void Keyb::doKey(bool pressing,unsigned char j,unsigned char i,bool usePrev = false){
  unsigned char layout = getLayout(usePrev);
  #ifdef SERIAL_OUTPUT
    Serial.print("m:");Serial.print(getMode(j,i,layout));Serial.print(" L:");Serial.print(layout);Serial.print(" (");Serial.print(j);Serial.print(",");Serial.print(i);Serial.print(") ");
    Serial.print("[");Serial.print(prevModStat[0]);Serial.print(",");Serial.print(modStat[0]);Serial.print("]");
  #endif
  if(modeManager(j,i,layout,pressing)){
    doKey(pressing,getKeyCode(getVal(j,i,layout)));
  }
}

void Keyb::doKey(unsigned int keyCode){
   doKey(true,getKeyCode(keyCode));
   delay(MINIMUM_PRESS_TIME);
   doKey(false,getKeyCode(keyCode)); 
}
void Keyb::doKey(bool pressing,unsigned int keyCode){
  if(keyCode == 0) return;
  
  #ifdef SERIAL_OUTPUT
  if(pressing){
      Serial.print("Press ");Serial.println(keyCode);
    }else{
      Serial.print("Relea ");Serial.println(keyCode);
    }
  #else
    if(pressing){
      Keyboard.press(keyCode);
    }else{
      Keyboard.release(keyCode);
    }
  #endif
}

///////DO KEY/////////

void Keyb::doModifier(unsigned char which = 0){
  if(which != 0)
    modifierWrite(true,which);//set a los modificadores deseados
  modifierWrite(false,~which);//release a los que no
}

void Keyb::modifierWrite(bool val,unsigned char whichModifier){

  //                     LSB                            MSB
  unsigned int keys[] = {K_SHIFT,K_CTRL,K_ALT,K_ALTGR,K_GUI};
  unsigned char changes = val? whichModifier ^ modifiersStatus : whichModifier & modifiersStatus;
  //if val,     changes is the values that arent equals: status its 0 and which is 1 the one you want to change
  //if not val, changes is the values that are   equals: status its 1 and which is 1 the one you want to change

  for(unsigned char i = 0;i<5/*length of keys[]*/;i++){
    if(bitRead(changes,i)){
      doKey(val,getKeyCode(keys[i]));
      bitWrite(modifiersStatus,i,val);
    }
  }
}

void Keyb::modifiersTimeout(){
  if(keyCount==0){
    if(millis()-timestampLastKey>RELEASE_MODIFIERS_AFTER){
      doModifier();
    }
  }
}

unsigned char Keyb::getMode(unsigned char j,unsigned char i,unsigned char layout=0){
  unsigned char m = uncompMode(codes[layout][j][i]);
  return m==COPY
            ?getMode(j,i,getVal(j,i,layout,false))
            :m;
}

unsigned int Keyb::getVal(unsigned char k[],unsigned char layout){return getVal(k[0],k[1],layout);} //getVal(_shift,layout)
unsigned char Keyb::getVal(unsigned char j,unsigned char i,unsigned char layout,bool lookForCopy = true){
  unsigned char m = uncompMode(codes[layout][j][i]);
  return m==COPY&&lookForCopy
            ?getVal(j,i,uncompVal(codes[layout][j][i]))
            :uncompVal(codes[layout][j][i]);
}

bool Keyb::isKey(unsigned char k[], unsigned char j,unsigned char i){return k[0]==j&&k[1]==i;}
bool Keyb::isModifier(unsigned char j, unsigned char i,unsigned char layout=0){
  return getMode(j,i,layout) & 0b001000000;
}



void Keyb::makePrevModStat(){
  for(unsigned char i = 0; i<MODIFIERS_COUNT;i++){
    prevModStat[i] = modStat[i];
  }
}

void Keyb::scanForKeys(bool isPress){
  for(unsigned char j = 0;j<VIRTUAL_ROWS;j++){
    for(unsigned char i=0;i<VIRTUAL_COLUMNS;i++){
      if(prev[j][i] && !isModifier(j,i)){
        modifierIsKey=false; 
        doKey(false,j,i,isPress);
        doKey(true,j,i,!isPress);
      }
    }
  }
}

#ifdef ADJACENCY_MATRIX
void Keyb::translateMatrix(){
  //virt codes,fisic codesAdj
  unsigned char k,j,i,_i,_j;
  for(k = 0 ; k<NUM_LAYOUTS;k++){
    for(j = 0;j<VIRTUAL_ROWS;j++){
      for(i=0;i<VIRTUAL_COLUMNS;i++){
        _j=adjacencyMatrix[j][i][0];
        _i=adjacencyMatrix[j][i][1];
        codes[k][j][i]= codesAdj[k][_j][_i];
      }
    }
  }
  //delete[] codesAdj;
  //delete[] adjacencyMatrix;
}
#endif

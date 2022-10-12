#include "Keyb.h"
#include "CONFIG.h"
#include "Arduino.h"
#include "utils.h"

void Keyb::setup(){
  for(unsigned char i=0; i<PINS_DECO_LEN;i++){
    pinMode(pins_deco[i],OUTPUT);
  }
  for(unsigned char i=0; i<PINS_MUX_LEN;i++){
    pinMode(pins_mux[i],OUTPUT);
  }
  pinMode(PIN_MUX_INP,INPUT);

  
  Serial.begin(9600);
  delay(2000);
  Serial.println("BEGIN");
}

void Keyb::loop(){
  readMatrix();
}

void Keyb::readMatrix(){
  bool aux;
  
  #ifdef TEST1
  Serial.println();Serial.println();
  #endif
  
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
      
      #ifdef TEST1
      Serial.print(aux);
      #else
      if(aux!=prev[j][i]){
        prev[j][i]=aux;
        if(aux){//press
          layoutBuffer = getLayout();
          keyPress(j,i,layoutBuffer);
        }else{//release
          keyRelease(j,i,layoutBuffer);
        }
      }
      #endif
      delay(1);
    }
    #ifdef TEST1
    Serial.println();
    #endif

    #ifndef BOARD_DECODER
    //digitalWrite(mat_outs[j],HIGH);
    #endif
  }
  delay(22);
}

bool Keyb::keyStat(unsigned char k[]){return keyStat(k[0],k[1]);}
bool Keyb::keyStat(unsigned char j, unsigned char i){return prev[j][i];}

void Keyb::doKey(bool pressing,unsigned char j,unsigned char i,unsigned char layout){
  #ifdef SERIAL_OUTPUT
    Serial.print(getMode(j,i,layout));Serial.print("[");Serial.print(layout);Serial.print("](");Serial.print(j);Serial.print(",");Serial.print(i);Serial.print(") ");
  #endif
  doKey(pressing,getVal(j,i,layout));
}

void Keyb::doKey(bool pressing,unsigned int keyCode){
  #ifdef SERIAL_OUTPUT
    Serial.print(pressing?"Press ":"Release ");Serial.println(keyCode);
  #else
    if(pressing){
      Keyboard.press(keyCode);
    }else{
      Keyboard.release(keyCode);
    }
  #endif
}
void Keyb::doKey(unsigned char j,unsigned char i,unsigned char layout){
  #ifdef SERIAL_OUTPUT
    Serial.print(getMode(j,i,layout));Serial.print("[");Serial.print(layout);Serial.print("](");Serial.print(j);Serial.print(",");Serial.print(i);Serial.print(") ");
  #endif
  
  doKey(getVal(j,i,layout));
}
void Keyb::doKey(unsigned int keyCode){
  #ifdef SERIAL_OUTPUT
    Serial.print("Press&Release ");Serial.println(keyCode);
  #else
    Keyboard.press(keyCode);
    delay(MINIMUM_PRESS_TIME);
    Keyboard.release(keyCode);
  #endif
}

void Keyb::doModifier(unsigned char which = MOD_NONE){
  if(which != 0)
  modifierWrite(true,which);
  unsigned char invWhich = ~which;
  //if(invWhich != 0)
  modifierWrite(false,invWhich);
}

void Keyb::modifierClr(){modifierWrite(false,MOD_ALL);}//reset all
//or use Keyboard.releseall();

void Keyb::modifierWrite(bool val,unsigned char whichModifier){
  //Serial.println(whichModifier);
  //                        LSB                                       MSB
  unsigned char keys[] = {CODE_SHIFT,CODE_CTRL,CODE_ALT,CODE_ALTGR,CODE_GUI};//8 max
  unsigned char changes = val? whichModifier ^ modifiersStatus : whichModifier & modifiersStatus;
  //if val,     changes is the values that arent equals: status its 0 and which is 1 the one you want to change
  //if not val, changes is the values that are   equals: status its 1 and which is 1 the one you want to change

  for(unsigned char i = 0;i<5/*length of keys[]*/;i++){
    if(bitRead(changes,i)){
      doKey(val,keys[i]);
      bitWrite(modifiersStatus,i,val);
    }
  }
}

unsigned char Keyb::getMode(unsigned char j,unsigned char i,unsigned char layout){
  unsigned char m = uncompMode(codes[layout][j][i]);
  return m==COPY
            ?getMode(j,i,getVal(j,i,layout))
            :m;
}

unsigned int Keyb::getVal(unsigned char k[],unsigned char layout){return getVal(k[0],k[1],layout);} //getVal(_shift,layout)
unsigned char Keyb::getVal(unsigned char j,unsigned char i,unsigned char layout){
  //unsigned char m = uncompMode(codes[layout][j][i]);
  //return m==COPY
            //?23
            //:uncompVal(codes[layout][j][i]);
  return  uncompVal(codes[layout][j][i]);
}

bool Keyb::isKey(unsigned char k[], unsigned char j,unsigned char i){return k[0]==j&&k[1]==i;}
bool Keyb::isModifier(unsigned char j, unsigned char i,unsigned char layout){
  return getBit(getMode(j,i,layout),1,3);}

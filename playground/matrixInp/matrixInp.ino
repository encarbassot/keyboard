#include <Keyboard.h>
#define NUM_ROW 4
#define NUM_COL 4

const unsigned char mat_outs[] = {10,16,14,15};   //OUTPUT
const unsigned char mat_inps[] = {A3,A2,A1,A0};   //INPUT
bool prev[NUM_ROW][NUM_COL];

void setup() {
  // put your setup code here, to run once:
  Keyboard.begin(); 
  for(unsigned char i = 0; i<NUM_COL; i++){
    pinMode(mat_inps[i],INPUT_PULLUP);
  }
  for(unsigned char i = 0;i<NUM_ROW;i++){
    pinMode(mat_outs[i],OUTPUT);
    digitalWrite(mat_outs[i],HIGH);
  }
  delay(200);
  Keyboard.releaseAll();

}

void loop() {
  for(unsigned char j=0;j<NUM_ROW;j++){
      digitalWrite(mat_outs[j],LOW);
      for(unsigned char i=0;i<NUM_COL;i++){
          bool aux = !digitalRead(mat_inps[i]);
          if(aux!=prev[j][i]){
            if (aux){//press
              keyPress(j,i);
            }else{//release
              keyRelease(j,i);
            }
          }
          prev[j][i] = aux;
        
      }
      digitalWrite(mat_outs[j],HIGH);
    }
}

void keyPress(unsigned char j, unsigned char i){
  char text='a';
  Keyboard.press(text+j*NUM_COL+i);
}

void keyRelease(unsigned char j, unsigned char i){
  char text='a';
  Keyboard.release(text+j*NUM_COL+i);
}

/*
 * abcdefghijklmnop
 */

#include "Keyb.h"
#include "CONFIG.h"
#include "Arduino.h"



void Keyb::doScript(unsigned char n){
  switch(n){
    case S_COMMENT:
      doKey(KP_SLASH); //61524
      doKey(KP_SLASH); //61524
      doKey(K_LEFT);   //61520
      doKey(K_LEFT);   //61520
      doKey(K_DOWN);   //91521
      
    break;
    case S_SEMICOLON_ENTER:
      doKey(K_END);       //61517
      doModifier(M_SHIFT);//57346
      doKey(K_COMMA);     //61494
      doKey(K_ENTER);     //61480
      doModifier(); //release 57346
    break;
    case S_MOUSE:
      #ifndef SERIAL_OUTPUT
        Mouse.move(0,-30,0);
      #else
        Serial.println("mousE");
      #endif
      
    break;
    case S_NEWLINE:
      doKey(K_END);
      doKey(K_ENTER);
    break; 
    case S_SWAPLAYOUT:
      if(mainLayout == L_NORMAL){
            mainLayout = L_QWERTY;
            Keyboard.print("qwerty");
      }else{
            mainLayout = L_NORMAL;
            Keyboard.print("dvorak");
      }
    break;
  }
}

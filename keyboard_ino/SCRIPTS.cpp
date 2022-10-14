#include "Keyb.h"
#include "CONFIG.h"
#include "Arduino.h"



void Keyb::doScript(unsigned char n){
  switch(n){
    case S_COMMENT:
      doKey(KP_SLASH);
      doKey(KP_SLASH);
      doKey(K_LEFT);
      doKey(K_LEFT);
      doKey(K_DOWN);
      
    break;
    case S_SEMICOLON_ENTER:
      doKey(K_END);
      doModifier(M_SHIFT);
      doKey(K_COMMA);
      doKey(K_ENTER); 
    break;
    case S_MOUSE:
      #ifndef SERIAL_OUTPUT
        Mouse.move(0,-30,0);
      #endif
      
    break;
  }
}

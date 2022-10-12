#include "Keyb.h"
#include "CONFIG.h"
#include "Arduino.h"

void Keyb::doScript(unsigned char n){
  switch(n){
    case 1:
      Serial.println("TEST");
      
    break;
  }
}

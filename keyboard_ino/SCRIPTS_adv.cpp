#include "Keyb.h"
#include "CONFIG.h"
#include "Arduino.h"
#include "utils.h"

unsigned char Keyb::getLayout(){
  bool fn1 = keyStat(_FN1);
  //bool fn2 = keyStat(_FN2);

  //if(fn1&&fn2){return 3};
  if(fn1){return 1;}
  //if(fn2){return 2;}

  return 0;
}

void Keyb::keyPress(unsigned char j,unsigned char i,unsigned char layout){
  #ifdef ADJACENCY_MATRIX
    fisicToVirtual(&j,&i);
  #endif
  
  if(isModifier(j,i,layout)){
    modifierIsKey = !modifierIsKey;
  }else{
    modifierIsKey = false;
    /**********/
    bool pressKey = modeManager(j,i,layout);
    if(pressKey){
      doKey(true,j,i,layout);
    }
    /**********/
  }

}

void Keyb::keyRelease(unsigned char j,unsigned char i,unsigned char layout){
  #ifdef ADJACENCY_MATRIX
    fisicToVirtual(&j,&i);
  #endif
  
  if(modifierIsKey && isModifier(j,i,layout)){
    modifierIsKey = false;
    if(modeManager(j,i,layout)){
      doKey(j,i,layout);
    }
  }
  if(!modifierIsKey && !isModifier(j,i,layout)){
    doKey(false,j,i,layout);
  }
}

//return false when its not need to execute the keyPress()
bool Keyb::modeManager(unsigned char j,unsigned char i, unsigned char layout){
  unsigned char m = getBit(getMode(j,i,layout),3);
  switch(m){

    case 0:
      doModifier();
      //modifierClr();
    break;
    case 2:
      doModifier(MOD_ALT);
//      modifierWrite(false,MOD_SHIFT);
      //modifierWrite(true,MOD_ALT);
    break;
    case 3:
      doModifier(MOD_SHIFT);
      //modifierWrite(false,MOD_ALT);
      //modifierWrite(true,MOD_SHIFT);
    break;
    case SCRIPT://4
      doScript(getVal(j,i,layout));
    break;
  }
  
  return true;
}

#include "Keyb.h"
#include "CONFIG.h"
#include "Arduino.h"
#include "utils.h"

unsigned char Keyb::getLayout(bool usePrev = false){
  bool *mStat = usePrev?prevModStat:modStat;
  bool fn1 = mStat[0];
  bool esc = mStat[1];
  bool tab = mStat[2];
 
  if(fn1&&esc){return 4;}
  if(fn1){return 2;}
  if(esc){return 3;}
  if(tab){return 1;}
  
  return 0;
}

void Keyb::keyPress(unsigned char j,unsigned char i){
  //Serial.print(isModifier(j,i));
  if(isModifier(j,i)){
    makePrevModStat();
    modStat[getBit(getMode(j,i),6,0)]=true;
    //Serial.print(modStat[0]);Serial.print(modStat[1]);Serial.print(" - ");Serial.print(prevModStat[0]);Serial.println(prevModStat[1]);
    modifierIsKey = true;
    scanForKeys(true);

  }else{
    modifierIsKey = false;
    doKey(true,j,i);
  }
}

void Keyb::keyRelease(unsigned char j,unsigned char i){
  if(isModifier(j,i)){
    scanForKeys(false);
    makePrevModStat();
    modStat[getBit(getMode(j,i),6,0)]=false;
    //Serial.print(modStat[0]);Serial.print(modStat[1]);Serial.print(" - ");Serial.print(prevModStat[0]);Serial.println(prevModStat[1]);
    if(modifierIsKey){
      modifierIsKey = false;
      doKey(j,i);
    }
  }else{
    doKey(false,j,i);
  }
}

//return false when its not need to execute the keyPress()
//this is called in doKey();
bool Keyb::modeManager(unsigned char j,unsigned char i, unsigned char layout,bool pressing){
  unsigned char m = getMode(j,i,layout);
  //bool isMod = isModifier(j,i);
  
  if(true){//!isMod
    if(m & 0b100000){
      doModifier(m & 0b11111);
    }else{
      switch(m){
        case 0://NONE normal key
          doModifier();//release all
          
        break;
        case SCRIPT:
          if(!pressing){
            doScript(getVal(j,i,layout));
          }
          return false;
        break;
      }//switch
    }
  }//if(!isMod
  
  return true;
}

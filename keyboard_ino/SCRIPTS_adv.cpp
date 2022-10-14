#include "Keyb.h"
#include "CONFIG.h"
#include "Arduino.h"
#include "utils.h"

unsigned char Keyb::getLayout(bool usePrev = false){
  bool *mStat = usePrev?prevModStat:modStat;
  bool space      = mStat[W_SPC];
  bool del        = mStat[W_DEL];
  bool enter      = mStat[W_ENT];  
  bool backspace  = mStat[W_BKS];
  if(space&&del){return L_F1F2;}
  if(del)       {return L_NUMPAD;}
  if(backspace) {return L_ARROWS;}
  if(space)     {return L_SYMBOLS;}
  if(enter)     {return L_PSEUDO_SHIFT;}
  
  return mainLayout;//L_NORMAL --- L_QWERTY
}

void Keyb::keyPress(unsigned char j,unsigned char i){
  //Serial.print(isModifier(j,i));
  if(isModifier(j,i)){
    makePrevModStat();
    modStat[getHardModId(getMode(j,i))]=true;
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
    modStat[getHardModId(getMode(j,i))]=false;
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
//this is called before doKey();
bool Keyb::modeManager(unsigned char j,unsigned char i, unsigned char layout,bool pressing){
  unsigned char mode = getMode(j,i,layout);
  unsigned char m = getTopMode(mode);
  unsigned char _m = getLowMode(mode);
  
  if(m == _COPY || m == _MOD){
    doModifier(_m);
  }

  if(m == 0 || m == _MODIFIER){
    Serial.print("aaaa");
    if(isScript(mode)){
      if(!pressing){//only script on the pres, no at the release
        Serial.print("ssss");
        doScript(getVal(j,i,layout));
        
      }
      return false;
    }else{
      doModifier();//release all
    }
  }
  
  return true;
}

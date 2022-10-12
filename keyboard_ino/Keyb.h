#ifndef KEYB_H
#define KEYB_H

#include "CONFIG.h"

class Keyb{
  public:
    //keyb.cpp
    void setup();
    void loop();

  private:
    bool prev[VIRTUAL_ROWS][VIRTUAL_COLUMNS];
    unsigned char prevLayout;
    unsigned char layoutBuffer;
    unsigned char modifiersStatus = 0;
    unsigned char modifierIsKey = 0;

    //SCRIPTS_adv.cpp
    void keyPress(unsigned char,unsigned char,unsigned char);
    void keyRelease(unsigned char,unsigned char,unsigned char);
    unsigned char getLayout();
    bool modeManager(unsigned char,unsigned char,unsigned char);

    //SCRIPTS.cpp
    void doScript(unsigned char);


    //Keyb.cpp
    void readMatrix();
    bool keyStat(unsigned char*);
    bool keyStat(unsigned char,unsigned char);
    void doKey(bool,unsigned char,unsigned char,unsigned char);
    void doKey(bool,unsigned int);
    void doKey(unsigned char,unsigned char,unsigned char);
    void doKey(unsigned int);
    void doModifier(unsigned char which = MOD_NONE);
    void modifierClr();
    void modifierWrite(bool,unsigned char);
    unsigned char getMode(unsigned char,unsigned char,unsigned char);
    unsigned int getVal(unsigned char*,unsigned char);
    unsigned char getVal(unsigned char,unsigned char,unsigned char);
    bool isKey(unsigned char*,unsigned char,unsigned char);
    bool isModifier(unsigned char ,unsigned char,unsigned char);
    
};

#endif //KEYB_H

#ifndef KEYB_H
#define KEYB_H

#include "CONFIG.h"

#ifndef SERIAL_OUTPUT
  #include <Keyboard.h>
#endif

class Keyb{
  public:
    //keyb.cpp
    void setup();
    void loop();

  private:
    unsigned char keyCount=0;
    #ifdef ADJACENCY_MATRIX
      unsigned int codes[NUM_LAYOUTS][VIRTUAL_ROWS][VIRTUAL_COLUMNS];
      unsigned char modifiers[MODIFIERS_COUNT][2];
    #endif
    unsigned int getKeyCode(unsigned char);
    bool modStat[MODIFIERS_COUNT];//modifier status
    bool prevModStat[MODIFIERS_COUNT];
    bool prev[VIRTUAL_ROWS][VIRTUAL_COLUMNS];
    unsigned char prevLayout;
    unsigned char modifiersStatus = 0;
    unsigned long timestampLastKey=0;
    bool modifierIsKey = false;
    #ifdef TEST2
    unsigned int test2counter = 10;
    #endif
    unsigned char mainLayout =  L_NORMAL; //L_NORMAL --- L_QWERTY


    //SCRIPTS_adv.cpp
    void keyPress(unsigned char,unsigned char);
    void keyRelease(unsigned char,unsigned char);
    unsigned char getLayout(bool usePrev = false);
    bool modeManager(unsigned char,unsigned char,unsigned char,bool);

    //SCRIPTS.cpp
    void doScript(unsigned char);


    //Keyb.cpp
    void readMatrix();
    bool keyStat(unsigned char*);
    bool keyStat(unsigned char,unsigned char);
    void doKey(unsigned char,unsigned char);
    void doKey(bool,unsigned char,unsigned char,bool usePrev = false);
    void doKey(bool,unsigned int);
    void doKey(unsigned int);
    void doModifier(unsigned char which = 0);
    void modifiersTimeout();
    //void modifierClr();
    void modifierWrite(bool,unsigned char);
    unsigned char getMode(unsigned char,unsigned char,unsigned char layout =0);
    unsigned char getTopMode(unsigned char mode);
    unsigned char getLowMode(unsigned char mode);
    unsigned char getHardModId(unsigned char mode);
    bool isScript(unsigned char mode);
    unsigned int getVal(unsigned char*,unsigned char);
    unsigned char getVal(unsigned char,unsigned char,unsigned char,bool lookForCopy = true);
    bool isKey(unsigned char*,unsigned char,unsigned char);
    bool isModifier(unsigned char ,unsigned char,unsigned char layout=0);
    void makePrevModStat();
    void scanForKeys(bool);
    
    
    #ifdef ADJACENCY_MATRIX
      void translateMatrix();
    #endif
};

#endif //KEYB_H

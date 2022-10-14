#ifndef CONFIG_H
#define CONFIG_H
#include "Arduino.h"
#include "utils.h"
#include "BOARD.h"

//////////////TESTS//////////////
//#define TEST1 //print 01 matrix
//#define TEST2 //that prints all codes from 10 to 255 (stetpByStep)
//#define TEST3 //prints the virtual codeLayout on boot
////////////TESTS///////////////////

//define more keys to your own
//const unsigned char _FN1[2] = {6,3};//position in virtual
//const unsigned char _FN2[2] = {6,2};

  //MODIFIER -> set the key as a modifier (should be in all layouts) "c(MODIFIER | 3b, 12b)" "c(MODIFIER | count, code)" 
  //COPY     -> set on value the layout you want to copy the key from
  //SCRIPT   -> will execute the script N specified on <value> from the scriptList
  //M_ALTGR  -> will press the key code together with AltGr to make symbols
  //M_SHIFT  -> will press the key code together with Shift to make symbols

#define MODIFIERS_COUNT 4
#define W_SPC 0 
#define W_ENT 1
#define W_BKS 2
#define W_DEL 3

#define S_COMMENT 0
#define S_SEMICOLON_ENTER 1
#define S_MOUSE 2
#define S_NEWLINE 3
#define S_SWAPLAYOUT 4

#define NUM_LAYOUTS 7
#define L_NORMAL 0
#define L_SYMBOLS 1 //symbols
#define L_PSEUDO_SHIFT 2 //pseudoSHIFT
#define L_ARROWS 3 //ARROWS
#define L_F1F2 4     //F1F2 
#define L_NUMPAD 5 //NUMPAD
#define L_QWERTY 6


#ifdef ADJACENCY_MATRIX
const unsigned int codesAdj[NUM_LAYOUTS][FISICAL_ROWS][FISICAL_COLUMNS]={
  /*fix 
   * CTRL + SHIFT + esc 
   * CTRl alt sup
   * esc release all
   * F1F2...
   * insert
   * K_CAPS_LOCK,K_NUM_LOCK
   * alt F4
  */
  {//NORMAL 
    {0,0,K_ESC,c(M_SHIFT,K_COMMA),K_COMMA,K_PERIOD,K_P,K_Y,K_F,K_G,K_C,K_R,K_L,c(SCRIPT,S_MOUSE),0,0},
    {0,0,K_TAB,K_A,K_O,K_E,K_U,K_I,K_D,K_H,K_T,K_N,K_S,KM_PLAY_PAUSE,0,0},
    {0,0,K_SHIFT,K_MINUS,K_Q,K_J,K_K,K_X,K_B,K_M,K_W,K_V,K_Z,K_NONE,0,0},
    {0,0,K_CTRL,K_GUI,K_ALT,K_ALTGR,c(MODIFIER|W_SPC,K_SPACE),c(MODIFIER|W_DEL,K_DELETE),c(MODIFIER|W_ENT,K_ENTER),c(MODIFIER|W_BKS,K_BACKSPACE),K_NONE,K_NONE,K_NONE,c(SCRIPT,S_SWAPLAYOUT),0,0}
  },{//SPACE (SYMBOLS)
    {0,0,c(COPY,0),K_0,                       K_1,            K_2,                K_3,                       K_4,           K_5,              K_6,                         K_7,                      K_8,           K_9,           c(COPY,0),0,0},
    {0,0,c(COPY,0),c(M_SHIFT,K_RIGHT_BRACE),c(M_SHIFT,K_8), c(M_ALTGR,K_QUOTE),   c(M_ALTGR,K_LEFT_BRACE),   c(M_SHIFT,K_7) ,c(M_SHIFT,K_SLASH),c(M_ALTGR,K_RIGHT_BRACE),   c(M_ALTGR,K_BACKSLASH),c(M_SHIFT,K_9) ,K_NONE,       c(COPY,0),0,0},
    {0,0,c(COPY,0),K_MINUS                 ,c(M_SHIFT,K_1) ,c(M_SHIFT,K_6)       ,c(M_ALTGR,K_1)            ,c(M_ALTGR,K_2) ,c(M_ALTGR,K_3),   c(M_SHIFT,K_0)              ,c(M_SHIFT,K_MINUS),       K_SLASH         ,K_NONE          ,K_NONE,0,0},
    {0,0,c(COPY,0),c(COPY,0)                  ,c(COPY,0)    ,c(COPY,0)          ,c(COPY,0)                   ,c(COPY,0)     ,c(COPY,0)         ,c(COPY,0)                  ,c(COPY,0)                 ,K_NONE       ,K_NONE        ,K_NONE,0,0}
  },{//ENTER (PSEUDOS SHIFT) 
    {0,0,c(COPY,0),c(M_SHIFT,K_PERIOD),K_LESSTHAN     ,c(M_SHIFT,K_LESSTHAN),c(M_SHIFT,K_P),c(M_SHIFT,K_Y),c(M_SHIFT,K_F),c(M_SHIFT,K_G),c(M_SHIFT,K_C),c(M_SHIFT,K_R),c(M_SHIFT,K_L),  0,0},
    {0,0,c(COPY,0),c(M_SHIFT,K_A)     ,c(M_SHIFT,K_O) ,c(M_SHIFT,K_E)       ,c(M_SHIFT,K_U),c(M_SHIFT,K_I),c(M_SHIFT,K_D),c(M_SHIFT,K_H),c(M_SHIFT,K_T),c(M_SHIFT,K_N),c(M_SHIFT,K_S),c(SCRIPT,S_NEWLINE),0,0},
    {0,0,c(COPY,0),c(M_SHIFT,K_2)     ,c(M_SHIFT,K_Q) ,c(M_SHIFT,K_J)       ,c(M_SHIFT,K_K),c(M_SHIFT,K_X),c(M_SHIFT,K_B),c(M_SHIFT,K_M),c(M_SHIFT,K_W),c(M_SHIFT,K_V),c(M_SHIFT,K_Z),c(SCRIPT,S_COMMENT),0,0},
    {0,0,c(COPY,0),c(COPY,0)          ,c(COPY,0)      ,c(COPY,0)            ,c(COPY,0)     ,c(COPY,0)     ,c(COPY,0)     ,c(COPY,0)     ,c(COPY,0)       ,K_NONE        ,K_DELETE      ,c(M_ALTGR,K_3),0,0}
  },{//BACKSPACE (ARROWS)
    {0,0,c(COPY,0),0,0,0,0,0,0,K_HOME,K_UP,  K_END,  0,0,0,0},
    {0,0,c(COPY,0),0,0,0,0,0,0,K_LEFT,K_DOWN,K_RIGHT,0,0,0,0},
    {0,0,c(COPY,0),0,0,0,0,0,0,       0,0,0,         0,0,0,0},
    {0,0,c(COPY,0),c(COPY,0),c(COPY,0),c(COPY,0),c(COPY,0),c(COPY,0),c(COPY,0),c(COPY,0),K_BACKSPACE,0,0,0,0,0}
  },{//SPACE n DEL (F1F2)
    {0,0,K_F1,K_F2,K_F3,K_F4,K_F5,K_F6,K_F7,K_F8,K_F9,K_F10,K_F11,K_F12,0,0},
    {0,0,K_F13,K_F14,K_F15,K_F16,K_F17,K_F18,K_F19,K_F20,K_F21,K_F22,K_F23,K_F24,0,0},
    {0,0,c(COPY,0),K_NONE,K_NONE,K_NONE,K_NONE,K_NONE,K_NONE,K_NONE,                            0,0,0},
    {0,0,c(COPY,0),c(COPY,0),c(COPY,0),c(COPY,0),c(COPY,0),c(COPY,0),c(COPY,0),c(COPY,0),c(COPY,0), 0,0}
  },{//DEL (NUMPAD)
    {0,0,c(COPY,0),K_NONE,K_NONE,K_NONE,K_NONE,K_NONE,K_NONE,               KP_7,KP_8,KP_9,    K_BACKSPACE,   K_NONE,0,0},
    {0,0,c(COPY,0),K_NONE,K_NONE,K_NONE,K_NONE,K_NONE,K_NONE,               KP_4,KP_5,KP_6,    KP_ENTER,      K_NONE,0,0},
    {0,0,c(COPY,0),K_NONE,K_NONE,K_NONE,K_NONE,K_NONE,K_NONE,               KP_1,KP_2,KP_3,    KP_SLASH,      K_NONE,0,0},
    {0,0,c(COPY,0),c(COPY,0),c(COPY,0),c(COPY,0),c(COPY,0),c(COPY,0),K_NONE,KP_PERIOD,KP_0,KP_PLUS,KP_ASTERIX,K_NONE,0,0}
  },{//QWERTY
    {0,0,K_ESC,  K_Q,K_W,K_E,K_R,K_Y,K_U,K_I,K_O,K_P,K_LEFT_BRACE,K_BACKSPACE,0,0},
    {0,0,K_TAB,  K_A,K_S,K_D,K_F,K_G,K_H,K_J,K_K,K_L,K_SEMICOLON,K_ENTER,0,0},
    {0,0,K_SHIFT,K_Z,K_X,K_C,K_V,K_B,K_N,K_M,K_COMMA,K_PERIOD,K_SLASH,K_NONE,0,0},
    {0,0,K_CTRL, K_GUI,K_ALT,K_SPACE,c(COPY,0),c(COPY,0),c(COPY,0),c(COPY,0),K_NONE,K_NONE,K_NONE,c(SCRIPT,S_SWAPLAYOUT),0,0}
  }
};//*/







#endif //ADJACENCY_MATRIX

//if defined SERIAL_OUTPUT will output as Serial.print()
//otherwise its gona act as a keyboard
//only use for debug
//#define SERIAL_OUTPUT

#define MINIMUM_PRESS_TIME 2
#define RELEASE_MODIFIERS_AFTER 100
#endif //CONFIG_H

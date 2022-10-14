#ifndef CONFIG_H
#define CONFIG_H
#include "Arduino.h"
#include "utils.h"
#include "BOARD.h"
#include "Key.h"

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

#define NUM_LAYOUTS 5
#define MODIFIERS_COUNT 3

const unsigned char modifiersAdj[MODIFIERS_COUNT][2]={{4,3}};//virtual position

#define S_COMMENT 0 // not implemented)
#define S_SEMICOLON_ENTER 1
#define S_MOUSE 2

#ifdef ADJACENCY_MATRIX
const unsigned int codesAdj[NUM_LAYOUTS][FISICAL_ROWS][FISICAL_COLUMNS]={
  /*fix 
   * CTRL + SHIFT + esc 
   * esc release alll
  */
  {//NORMAL 
    {0,0,c(MODIFIER | 1,K_ESC),c(M_SHIFT,K_COMMA),K_COMMA,K_PERIOD,K_P,K_Y,K_F,K_G,K_C,K_R,K_L,K_BACKSPACE,0,0},
    {0,0,c(MODIFIER | 2,K_TAB),K_A,K_O,K_E,K_U,K_I,K_D,K_H,K_T,K_N,K_S,K_ENTER,0,0},
    {0,0,K_SHIFT,K_MINUS,K_Q,K_J,K_K,K_X,K_B,K_M,K_W,K_V,K_Z,KP_SLASH,0,0},
    {0,0,K_CTRL,K_GUI,c(M_ALT,K_NONE),c(MODIFIER | 0,K_SPACE),K_SPACE,K_ALTGR ,K_NONE,K_NONE,K_NONE,K_NONE,K_DELETE,c(M_ALTGR,K_3),0,0}
  },{//TAB
    {0,0,c(COPY,0),c(M_SHIFT,K_PERIOD),K_LESSTHAN,c(M_SHIFT,K_LESSTHAN),K_P,K_Y,K_F,K_G,K_BACKSLASH,K_R,      c(M_SHIFT,K_8),c(M_SHIFT,K_9),0,0},
    {0,0,c(COPY,0),K_CAPS_LOCK,K_NUM_LOCK,c(M_ALTGR,K_E),K_U,K_I,K_D,K_H,K_T,K_SEMICOLON,                     c(M_ALTGR,K_LEFT_BRACE),c(M_ALTGR,K_RIGHT_BRACE),0,0},
    {0,0,c(M_SHIFT,K_TAB),c(M_SHIFT,K_2),K_Q,K_J,K_K,K_X,K_B,K_M,K_W,K_V,               c(M_ALTGR,K_QUOTE),   c(M_ALTGR,K_BACKSLASH),0,0},
    {0,0,c(M_CTRL,K_TAB),c(M_GUI,K_TAB),c(M_ALT,K_TAB),c(COPY,0),c(COPY,0),c(COPY,0),K_NONE,K_NONE,K_NONE,    K_NONE,K_DELETE,c(M_ALTGR,K_3),0,0}
  },{//FN
    {0,0,c(COPY,0),K_0,K_1,K_2,K_3,K_4,K_5,K_6,K_7,K_8,K_9,c(COPY,0),0,0},
    {0,0,c(COPY,0),K_MINUS,K_EQUAL,K_LEFT_BRACE,K_RIGHT_BRACE,K_BACKSLASH,K_SEMICOLON,K_QUOTE,K_TILDE,K_COMMA,K_PERIOD,c(K_SHIFT,K_SLASH),0,0},
    {0,0,c(COPY,0),K_SLASH,K_NONE,K_NONE,K_NONE,K_NONE,K_NONE,K_NONE,K_NONE,K_HOME,K_UP,K_END,0,0},
    {0,0,c(COPY,0),c(COPY,0),c(COPY,0),c(COPY,0),c(SCRIPT,S_MOUSE),c(COPY,0),K_NONE,K_NONE,K_NONE,K_LEFT,K_DOWN,K_RIGHT,0,0}
  },{//Esc
    {0,0,c(COPY,0),c(SCRIPT,S_SEMICOLON_ENTER),K_1,K_2,K_3,K_4,K_5,K_6,                          0,K_F1,K_F2,K_F3,0,0},
    {0,0,c(COPY,0),K_MINUS,K_EQUAL,K_LEFT_BRACE,K_RIGHT_BRACE,K_BACKSLASH,K_SEMICOLON,K_QUOTE,   0,K_F4,K_F5,K_F6,0,0},
    {0,0,c(COPY,0),K_SLASH,K_NONE,K_NONE,K_NONE,K_NONE,K_NONE,K_NONE,                            0,K_F7,K_F8,K_F9,0,0},
    {0,0,c(COPY,0),c(COPY,0),c(COPY,0),c(COPY,0),c(COPY,0),c(COPY,0),K_NONE,K_NONE,              0,K_F10,K_F11,K_F12,0,0}
  },{//Esc & FN
    {0,0,c(COPY,0),K_0,K_1,K_2,K_3,K_4,K_5,K_6,                                                  KP_PLUS,KP_SLASH,KP_ASTERIX,KP_MINUS,0,0},
    {0,0,c(COPY,0),K_MINUS,K_EQUAL,K_LEFT_BRACE,K_RIGHT_BRACE,K_BACKSLASH,K_SEMICOLON,K_QUOTE,   KP_ENTER,KP_7,KP_8,KP_9,0,0},
    {0,0,c(COPY,0),K_SLASH,K_NONE,K_NONE,K_NONE,K_NONE,K_NONE,K_NONE,                            KP_PERIOD,KP_4,KP_5,KP_6,0,0},
    {0,0,c(COPY,0),c(COPY,0),c(COPY,0),c(COPY,0),c(COPY,0),c(COPY,0),K_NONE,K_NONE,              KP_0,KP_1,KP_2,KP_3,0,0}
  }
};







#endif //ADJACENCY_MATRIX

//if defined SERIAL_OUTPUT will output as Serial.print()
//otherwise its gona act as a keyboard
//only use for debug
//#define SERIAL_OUTPUT

#define MINIMUM_PRESS_TIME 2
#define RELEASE_MODIFIERS_AFTER 100
#endif //CONFIG_H

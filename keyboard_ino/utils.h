#ifndef UTILS_H
#define UTILS_H

#include "Arduino.h"
#include "BOARD.h"
#ifndef SERIAL_OUTPUT
  #include <Keyboard.h>
#endif

//for codes matrix, kinds of modes

//topMode
#define MODIFIER 0b00100000 //hard modifier
#define COPY     0b01100000 
#define MOD      0b01000000 // softmod
#define _MODIFIER 0b001
#define _COPY     0b011
#define _MOD      0b010

//lowMode
#define M_SHIFT  0b00000001 | MOD //0b01000001
#define M_CTRL   0b00000010 | MOD //0b01000010
#define M_ALT    0b00000100 | MOD //0b01000100
#define M_ALTGR  0b00001000 | MOD //0b01001000
#define M_GUI    0b00010000 | MOD //0b01010000
#define SCRIPT   0b00010000 






unsigned int c(unsigned char,unsigned char);
unsigned char uncompMode(unsigned int x);
unsigned char uncompVal(unsigned int x);
unsigned int getBit(unsigned int n,unsigned char k,unsigned char p=0);

#ifdef BOARD_DECODER
  void setDecoder(unsigned char j);
#endif

#ifdef BOARD_MULTIPLEXER
  bool setMultiplexer(unsigned char j);
#endif

#if defined(BOARD_MULTIPLEXER) || defined(BOARD_DECODER)
  bool intToBinaryPos(int intNum,int pos);
#endif


// KEY CODES
//https://www.pjrc.com/teensy/td_keyboard.html
//https://www.arduino.cc/en/Reference/KeyboardModifiers
#define KEY_CODE_LEN 134 //MAx 255
#ifdef TEENSY
  const unsigned int key_code[KEY_CODE_LEN]={
      0,                      KEY_A,                  KEY_B,                KEY_C,                    KEY_D,            KEY_E,                  KEY_F,                  KEY_G,
      KEY_H,                  KEY_I,                  KEY_J,                KEY_K,                    KEY_L,            KEY_M,                  KEY_N,                  KEY_O,
      KEY_P,                  KEY_Q,                  KEY_R,                KEY_S,                    KEY_T,            KEY_U,                  KEY_V,                  KEY_W,
      KEY_X,                  KEY_Y,                  KEY_Z,                KEY_1,                    KEY_2,            KEY_3,                  KEY_4,                  KEY_5,
      KEY_6,                  KEY_7,                  KEY_8,                KEY_9,                    KEY_0,            KEY_ENTER,              KEY_ESC,                KEY_BACKSPACE,
      KEY_TAB,                KEY_SPACE,              KEY_MINUS,            KEY_EQUAL,                KEY_LEFT_BRACE,   KEY_RIGHT_BRACE,        KEY_BACKSLASH,          KEY_SEMICOLON,
      KEY_QUOTE,              KEY_TILDE,              KEY_COMMA,            KEY_PERIOD,               KEY_SLASH,        KEY_CAPS_LOCK,          KEY_F1,                 KEY_F2,
      KEY_F3,                 KEY_F4,                 KEY_F5,               KEY_F6,                   KEY_F7,           KEY_F8,                 KEY_F9,                 KEY_F10,
      KEY_F11,                KEY_F12,                KEY_PRINTSCREEN,      KEY_SCROLL_LOCK,          KEY_PAUSE,        KEY_INSERT,             KEY_HOME,               KEY_PAGE_UP,
      KEY_DELETE,             KEY_END,                KEY_PAGE_DOWN,        KEY_RIGHT,                KEY_LEFT,         KEY_DOWN,               KEY_UP,                 KEY_NUM_LOCK,
      KEYPAD_SLASH,           KEYPAD_ASTERIX,         KEYPAD_MINUS,         KEYPAD_PLUS,              KEYPAD_ENTER,     KEYPAD_1,               KEYPAD_2,               KEYPAD_3,
      KEYPAD_4,               KEYPAD_5,               KEYPAD_6,             KEYPAD_7,                 KEYPAD_8,         KEYPAD_9,               KEYPAD_0,               KEYPAD_PERIOD,
      MODIFIERKEY_CTRL,       MODIFIERKEY_RIGHT_CTRL, MODIFIERKEY_SHIFT,    MODIFIERKEY_RIGHT_SHIFT,  MODIFIERKEY_ALT,  MODIFIERKEY_RIGHT_ALT,  MODIFIERKEY_GUI,        MODIFIERKEY_RIGHT_GUI,
      KEY_MEDIA_PLAY,         KEY_MEDIA_PAUSE,        KEY_MEDIA_RECORD,     KEY_MEDIA_STOP,           KEY_MEDIA_REWIND, KEY_MEDIA_FAST_FORWARD, KEY_MEDIA_PREV_TRACK,   KEY_MEDIA_NEXT_TRACK,
      KEY_MEDIA_VOLUME_DEC,   KEY_MEDIA_VOLUME_INC,   KEY_MEDIA_PLAY_PAUSE, KEY_MEDIA_PLAY_SKIP,      KEY_MEDIA_MUTE,   KEY_MEDIA_EJECT,        KEY_SYSTEM_POWER_DOWN,  KEY_SYSTEM_SLEEP,
      KEY_SYSTEM_WAKE_UP,     61540,/*LESSTHAN*/      61544,/*F13*/         61545,                    61546,            61547,                  61548,                  61549,
      61550,                  61551,                  61552,                61553,                    61554,            61555/*F24*/

  };
#else
  const unsigned int key_code[KEY_CODE_LEN]={
      0,140,141,142,143,144,145,146,//NONE ABCDEFG
      147,148,149,150,151,152,153,154,//HIJKLMNO
      155,156,157,158,159,160,161,162,//PQRSTUVW
      163,164,165,166,167,168,169,170,//XYZ12345
      171,172,173,174,175,KEY_RETURN,KEY_ESC,KEY_BACKSPACE,//6789
      KEY_TAB,180,181,182,183,184,185,187,//0 SPACE MINUS EQUAL LEFTBRACE RIGHTBRACE backslash semicolon  
      188,189,190,191,192,KEY_CAPS_LOCK,KEY_F1,KEY_F2,//quote TILDE COMMA PERIOD SLASH
      KEY_F3,KEY_F4,KEY_F5,KEY_F6,KEY_F7,KEY_F8,KEY_F9,KEY_F10,
      KEY_F11,KEY_F12,206,207,208,KEY_INSERT,KEY_HOME,KEY_PAGE_UP,
      KEY_DELETE,KEY_END,KEY_PAGE_DOWN,KEY_RIGHT_ARROW,KEY_LEFT_ARROW,KEY_DOWN_ARROW,KEY_UP_ARROW,219,
      220,221,222,223,224,225,226,227,
      228,229,230,231,232,233,234,235,
      KEY_LEFT_CTRL,KEY_RIGHT_CTRL,KEY_LEFT_SHIFT,KEY_RIGHT_SHIFT,KEY_LEFT_ALT,KEY_RIGHT_ALT,KEY_LEFT_GUI,KEY_RIGHT_GUI,
      0,0,0,0,0,0,0,0,
      0,0,0,0,0,0,0,0,
      0,236,240,241,242,243,244,245,//LESSTHAN , F13... 
      246,247,248,249,250,251//...F24
};
#endif																																

#define K_NONE 0 //KEY_CODE_LEN
#define K_A 1
#define K_B 2
#define K_C 3
#define K_D 4
#define K_E 5
#define K_F 6
#define K_G 7
#define K_H 8
#define K_I 9
#define K_J 10
#define K_K 11
#define K_L 12
#define K_M 13
#define K_N 14
#define K_O 15
#define K_P 16
#define K_Q 17
#define K_R 18
#define K_S 19
#define K_T 20
#define K_U 21
#define K_V 22
#define K_W 23
#define K_X 24
#define K_Y 25
#define K_Z 26
//                 SHIFT  ALTGR
#define K_1 27 //   !       |
#define K_2 28 //   "       @
#define K_3 29 //   ·       #
#define K_4 30 //   $       ~
#define K_5 31 //   %       €
#define K_6 32 //   &       
#define K_7 33 //   /       
#define K_8 34 //   (       
#define K_9 35 //   )       
#define K_0 36 //   =       

#define K_ENTER 37
#define K_ESC 38
#define K_BACKSPACE 39
#define K_TAB 40
#define K_SPACE 41      //   SHIFT  ALTGR   LAYOUT ESPAÑOL
#define K_MINUS 42      //'   ?      
#define K_EQUAL 43      //¡   ¿       
#define K_LEFT_BRACE 44 //``  ^^      [ 
#define K_RIGHT_BRACE 45//+   *       ]
#define K_BACKSLASH 46  //ç   Ç       }
#define K_SEMICOLON 47  //ñ   Ñ        
#define K_QUOTE 48      //´´  ¨¨      {
#define K_TILDE 49      //º   ª       \               /
#define K_COMMA 50      //,   ;       
#define K_PERIOD 51     //.   :       
#define K_SLASH 52      //-   _       
#define K_CAPS_LOCK 53

#define K_F1 54
#define K_F2 55
#define K_F3 56
#define K_F4 57
#define K_F5 58
#define K_F6 59
#define K_F7 60
#define K_F8 61
#define K_F9 62
#define K_F10 63
#define K_F11 64
#define K_F12 65

#define K_PRINTSCREEN 66
#define K_SCROLL_LOCK 67
#define K_PAUSE 68
#define K_INSERT 69
#define K_HOME 70
#define K_PAGE_UP 71
#define K_DELETE 72
#define K_END 73
#define K_PAGE_DOWN 74
#define K_RIGHT 75
#define K_LEFT 76
#define K_DOWN 77
#define K_UP 78

#define K_NUM_LOCK 79
#define KP_SLASH 80
#define KP_ASTERIX 81
#define KP_MINUS 82
#define KP_PLUS 83
#define KP_ENTER 84
#define KP_1 85
#define KP_2 86
#define KP_3 87
#define KP_4 88
#define KP_5 89
#define KP_6 90
#define KP_7 91
#define KP_8 92
#define KP_9 93
#define KP_0 94
#define KP_PERIOD 95

#define K_CTRL 96
#define K_CTRL_R 97

#define K_SHIFT 98
#define K_SHIFT_R 99

#define K_ALT 100
#define K_ALTGR 101

#define K_GUI 102
#define K_GUI_R 103


#define KM_PLAY 104
#define KM_PAUSE 105
#define KM_RECORD 106
#define KM_STOP 107
#define KM_REWIND 108
#define KM_FAST_FORWARD 109
#define KM_PREV 110
#define KM_NEXT 111
#define KM_VOLUME_DEC 112
#define KM_VOLUME_INC 113
#define KM_PLAY_PAUSE 114
#define KM_PLAY_SKIP 115
#define KM_MUTE 116
#define KM_EJECT 117

#define KS_POWER_DOWN 118
#define KS_SLEEP 119
#define KS_WAKE_UP 120
#define K_LESSTHAN 121

#define K_F13 122
#define K_F14 123
#define K_F15 124
#define K_F16 125
#define K_F17 126
#define K_F18 127
#define K_F19 128
#define K_F20 129
#define K_F21 130
#define K_F22 131
#define K_F23 132
#define K_F24 133


#endif //UTILS_H

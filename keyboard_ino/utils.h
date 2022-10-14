

#ifndef UTILS_H
#define UTILS_H

#include "Arduino.h"
#include "BOARD.h"

//for codes matrix, kinds of modes
#define COPY     0b00000001
#define SCRIPT   0b00000010
#define MODIFIER 0b01000000
#define M_SHIFT  0b00100001
#define M_CTRL   0b00100010
#define M_ALT    0b00100100
#define M_ALTGR  0b00101000
#define M_GUI    0b00110000


// M_ALT | M_SHIFT 0011
//free 0101 0110 011


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
#define KEY_CODE_LEN 121
const unsigned int key_code[KEY_CODE_LEN]={
    KEY_A,                  KEY_B,                KEY_C,                    KEY_D,            KEY_E,                  KEY_F,                  KEY_G,                  KEY_H,
    KEY_I,                  KEY_J,                KEY_K,                    KEY_L,            KEY_M,                  KEY_N,                  KEY_O,                  KEY_P,
    KEY_Q,                  KEY_R,                KEY_S,                    KEY_T,            KEY_U,                  KEY_V,                  KEY_W,                  KEY_X,
    KEY_Y,                  KEY_Z,                KEY_1,                    KEY_2,            KEY_3,                  KEY_4,                  KEY_5,                  KEY_6,
    KEY_7,                  KEY_8,                KEY_9,                    KEY_0,            KEY_ENTER,              KEY_ESC,                KEY_BACKSPACE,          KEY_TAB,    
    KEY_SPACE,              KEY_MINUS,            KEY_EQUAL,                KEY_LEFT_BRACE,   KEY_RIGHT_BRACE,        KEY_BACKSLASH,          KEY_SEMICOLON,          KEY_QUOTE,
    KEY_TILDE,              KEY_COMMA,            KEY_PERIOD,               KEY_SLASH,        KEY_CAPS_LOCK,          KEY_F1,                 KEY_F2,                 KEY_F3,
    KEY_F4,                 KEY_F5,               KEY_F6,                   KEY_F7,           KEY_F8,                 KEY_F9,                 KEY_F10,                KEY_F11,
    KEY_F12,                KEY_PRINTSCREEN,      KEY_SCROLL_LOCK,          KEY_PAUSE,        KEY_INSERT,             KEY_HOME,               KEY_PAGE_UP,            KEY_DELETE,
    KEY_END,                KEY_PAGE_DOWN,        KEY_RIGHT,                KEY_LEFT,         KEY_DOWN,               KEY_UP,                 KEY_NUM_LOCK,           KEYPAD_SLASH,
    KEYPAD_ASTERIX,         KEYPAD_MINUS,         KEYPAD_PLUS,              KEYPAD_ENTER,     KEYPAD_1,               KEYPAD_2,               KEYPAD_3,               KEYPAD_4,
    KEYPAD_5,               KEYPAD_6,             KEYPAD_7,                 KEYPAD_8,         KEYPAD_9,               KEYPAD_0,               KEYPAD_PERIOD,          MODIFIERKEY_CTRL,
    MODIFIERKEY_RIGHT_CTRL, MODIFIERKEY_SHIFT,    MODIFIERKEY_RIGHT_SHIFT,  MODIFIERKEY_ALT,  MODIFIERKEY_RIGHT_ALT,  MODIFIERKEY_GUI,        MODIFIERKEY_RIGHT_GUI,  KEY_MEDIA_PLAY,
    KEY_MEDIA_PAUSE,        KEY_MEDIA_RECORD,     KEY_MEDIA_STOP,           KEY_MEDIA_REWIND, KEY_MEDIA_FAST_FORWARD, KEY_MEDIA_PREV_TRACK,   KEY_MEDIA_NEXT_TRACK,   KEY_MEDIA_VOLUME_DEC,
    KEY_MEDIA_VOLUME_INC,   KEY_MEDIA_PLAY_PAUSE, KEY_MEDIA_PLAY_SKIP,      KEY_MEDIA_MUTE,   KEY_MEDIA_EJECT,        KEY_SYSTEM_POWER_DOWN,  KEY_SYSTEM_SLEEP,       KEY_SYSTEM_WAKE_UP,
    61540
};

#define K_NONE KEY_CODE_LEN
#define K_A 0
#define K_B 1
#define K_C 2
#define K_D 3
#define K_E 4
#define K_F 5
#define K_G 6
#define K_H 7
#define K_I 8
#define K_J 9
#define K_K 10
#define K_L 11
#define K_M 12
#define K_N 13
#define K_O 14
#define K_P 15
#define K_Q 16
#define K_R 17
#define K_S 18
#define K_T 19
#define K_U 20
#define K_V 21
#define K_W 22
#define K_X 23
#define K_Y 24
#define K_Z 25
#define K_1 26
#define K_2 27
#define K_3 28
#define K_4 29
#define K_5 30
#define K_6 31
#define K_7 32
#define K_8 33
#define K_9 34
#define K_0 35
#define K_ENTER 36
#define K_ESC 37
#define K_BACKSPACE 38
#define K_TAB 39
#define K_SPACE 40      //   SHIFT  ALTGR   LAYOUT ESPAÑOL
#define K_MINUS 41      //'   ?      
#define K_EQUAL 42      //¡   ¿       
#define K_LEFT_BRACE 43 //``  ^^      [ 
#define K_RIGHT_BRACE 44//+   *       ]
#define K_BACKSLASH 45  //ç   Ç       }
#define K_SEMICOLON 46  //ñ   Ñ        
#define K_QUOTE 47      //´´  ¨¨      {
#define K_TILDE 48      //º   ª       \     /
#define K_COMMA 49      //,   ;       
#define K_PERIOD 50     //.   :       
#define K_SLASH 51      //-   _       
#define K_CAPS_LOCK 52
#define K_F1 53
#define K_F2 54
#define K_F3 55
#define K_F4 56
#define K_F5 57
#define K_F6 58
#define K_F7 59
#define K_F8 60
#define K_F9 61
#define K_F10 62
#define K_F11 63
#define K_F12 64
#define K_PRINTSCREEN 65
#define K_SCROLL_LOCK 66
#define K_PAUSE 67
#define K_INSERT 68
#define K_HOME 69
#define K_PAGE_UP 70
#define K_DELETE 71
#define K_END 72
#define K_PAGE_DOWN 73
#define K_RIGHT 74
#define K_LEFT 75
#define K_DOWN 76
#define K_UP 77
#define K_NUM_LOCK 78
#define KP_SLASH 79
#define KP_ASTERIX 80
#define KP_MINUS 81
#define KP_PLUS 82
#define KP_ENTER 83
#define KP_1 84
#define KP_2 85
#define KP_3 86
#define KP_4 87
#define KP_5 88
#define KP_6 89
#define KP_7 90
#define KP_8 91
#define KP_9 92
#define KP_0 93
#define KP_PERIOD 94
#define K_CTRL 95
#define K_CTRL_R 96
#define K_SHIFT 97
#define K_SHIFT_R 98
#define K_ALT 99
#define K_ALTGR 100
#define K_GUI 101
#define K_GUI_R 102
#define KM_PLAY 103
#define KM_PAUSE 104
#define KM_RECORD 105
#define KM_STOP 106
#define KM_REWIND 107
#define KM_FAST_FORWARD 108
#define KM_PREV 109
#define KM_NEXT 110
#define KM_VOLUME_DEC 111
#define KM_VOLUME_INC 112
#define KM_PLAY_PAUSE 113
#define KM_PLAY_SKIP 114
#define KM_MUTE 115
#define KM_EJECT 116
#define KS_POWER_DOWN 117
#define KS_SLEEP 118
#define KS_WAKE_UP 119
#define K_LESSTHAN 120


#endif //UTILS_H

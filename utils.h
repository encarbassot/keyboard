

#ifndef UTILS_H
#define UTILS_H

#include "Arduino.h"
#include "BOARD.h"

//for codes matrix, kinds of modes
#define MODIFIER 0b1000
#define COPY     0b1111
#define SCRIPT   0b0100

unsigned int c(unsigned char,unsigned char);
unsigned char uncompMode(unsigned int x);
unsigned char uncompVal(unsigned int x);
unsigned int getBit(unsigned int n,unsigned char k,unsigned char p=0);

#ifdef ADJACENCY_MATRIX
  void fisicToVirtual(unsigned char *j,unsigned char *i);
#endif

#ifdef BOARD_DECODER
  void setDecoder(unsigned char j);
#endif

#ifdef BOARD_MULTIPLEXER
  bool setMultiplexer(unsigned char j);
#endif

#if defined(BOARD_MULTIPLEXER) || defined(BOARD_DECODER)
  bool intToBinaryPos(int intNum,int pos);
#endif


#define MOD_SHIFT 0b00000001
#define MOD_CTRL  0b00000010
#define MOD_ALT   0b00000100
#define MOD_ALTGR 0b00001000
#define MOD_GUI   0b00010000
#define MOD_ALL   0b11111111
#define MOD_NONE  0b00000000

// KEY CODES

  #define CODE_CAPS 193 //capsLock / bloqMayus/
  #define CODE_BACKSPACE 8
  #define CODE_BACKSPACE2 178
  #define CODE_TAB 9
  #define CODE_TAB2 179
  #define CODE_ENTER 10   //return / newLine
  #define CODE_ENTER2 176 //return / newLine
  #define CODE_SPACE 32
  #define CODE_INSERT 209
  #define CODE_BEGUIN 210 //home / jump to beguin of the line
  #define CODE_REPAG 211
  #define CODE_ESC 177
  #define CODE_SUP 212 //suprimir / delete
  #define CODE_END 213 //jump to end of line
  #define CODE_AVPAG 214
  #define CODE_ARROW_RIGHT 215
  #define CODE_ARROW_LEFT 216
  #define CODE_ARROW_DOWN 217
  #define CODE_ARROW_UP 218
  #define CODE_NUMLOCK 219        //NUMPAD
  #define CODE_SLASH_NUM 220      //NUMPAD
  #define CODE_ASTERISK 221       //NUMPAD
  #define CODE_MINUS 222          //NUMPAD
  #define CODE_PLUS 223           //NUMPAD
  #define CODE_ENTER_NUM          //NUMPAD
  #define CODE_NUM1 225           //NUMPAD
  #define CODE_NUM2 226           //NUMPAD
  #define CODE_NUM3 227           //NUMPAD
  #define CODE_NUM4 228           //NUMPAD
  #define CODE_NUM5 229           //NUMPAD
  #define CODE_NUM6 230           //NUMPAD
  #define CODE_NUM7 231           //NUMPAD
  #define CODE_NUM8 232           //NUMPAD
  #define CODE_NUM9 233           //NUMPAD
  #define CODE_NUM0 234           //NUMPAD
  #define CODE_F1 194
  #define CODE_F2 195
  #define CODE_F3 196
  #define CODE_F4 197
  #define CODE_F5 198
  #define CODE_F6 199
  #define CODE_F7 200
  #define CODE_F8 201
  #define CODE_F9 202
  #define CODE_F10 203
  #define CODE_F11 204
  #define CODE_F12 205
  #define CODE_F13 240
  #define CODE_F14 241
  #define CODE_F15 242
  #define CODE_F16 243
  #define CODE_F17 244
  #define CODE_F18 245
  #define CODE_F19 246
  #define CODE_F20 247
  #define CODE_F21 248
  #define CODE_F22 249
  #define CODE_F23 245
  #define CODE_F24 246
  #define CODE_CTRL 128
  #define CODE_SHIFT 129
  #define CODE_ALT 130
  #define CODE_GUI 131 //WINDOWS
  #define CODE_CONTROL_RIGHT 132
  #define CODE_SHIFT_RIGHT 133
  #define CODE_ALTGR 134 //Alt Right
  #define CODE_GUI_RIGHT 135
  #define CODE_SLASH 38
  #define CODE_SEMICOLON 60 // ;

#endif //UTILS_H

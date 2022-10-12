#include <Keyboard.h>

void setup() {
  //Initialize serial and wait for port to open:
  Keyboard.begin();
  delay(500);

  // prints title with ending line break
  Keyboard.println("ASCII Table ~ Character Map");
}

// first visible ASCIIcharacter '!' is number 33:
int thisByte = 32;
// you can also write ASCII characters in single quotes.
// for example, '!' is the same as 33, so you could also use this:
// int thisByte = '!';

void loop() {
  // prints value unaltered, i.e. the raw binary version of the byte.
  // The Serial Monitor interprets all bytes as ASCII, so 33, the first number,
  // will show up as '!'
  Keyboard.write(thisByte);

  Keyboard.print(" ");
  // prints value as string as an ASCII-encoded decimal (base 10).
  // Decimal is the default format for Serial.print() and Serial.println(),
  // so no modifier is needed:
  Keyboard.print(thisByte);
  // But you can declare the modifier for decimal if you want to.
  // this also works if you uncomment it:

  // Serial.print(thisByte, DEC);


  Keyboard.print(" 0x");
  // prints value as string in hexadecimal (base 16):
  Keyboard.print(thisByte, HEX);


  Keyboard.print(" 0b");
  // prints value as string in binary (base 2) also prints ending line break:
  Keyboard.println(thisByte, BIN);

  // if printed last visible character '~' or 126, stop:
  if (thisByte == 126) {    // you could also use if (thisByte == '~') {
    // This loop loops forever and does nothing
    while (true) {
      continue;
    }
  }
  // go on to the next character
  thisByte++;
}
/*
ASCII Table ª Character Map ESP
    32 0x20 0b100000
  ! 33 0x21 0b100001
  ¨ 34 0x22 0b100010
  · 35 0x23 0b100011
  $ 36 0x24 0b100100
  % 37 0x25 0b100101
  / 38 0x26 0b100110
  ´ 39 0x27 0b100111
  ) 40 0x28 0b101000
  = 41 0x29 0b101001
  ( 42 0x2A 0b101010
  ¿ 43 0x2B 0b101011
  , 44 0x2C 0b101100
  ' 45 0x2D 0b101101
  . 46 0x2E 0b101110
  - 47 0x2F 0b101111
  0 48 0x30 0b110000
  1 49 0x31 0b110001
  2 50 0x32 0b110010
  3 51 0x33 0b110011
  4 52 0x34 0b110100
  5 53 0x35 0b110101
  6 54 0x36 0b110110
  7 55 0x37 0b110111
  8 56 0x38 0b111000
  9 57 0x39 0b111001
  Ñ 58 0x3A 0b111010
  ñ 59 0x3B 0b111011
  ; 60 0x3C 0b111100
  ¡ 61 0x3D 0b111101
  : 62 0x3E 0b111110
  _ 63 0x3F 0b111111
  " 64 0x40 0b1000000
  A 65 0x41 0b1000001
  B 66 0x42 0b1000010
  C 67 0x43 0b1000011
  D 68 0x44 0b1000100
  E 69 0x45 0b1000101
  F 70 0x46 0b1000110
  G 71 0x47 0b1000111
  H 72 0x48 0b1001000
  I 73 0x49 0b1001001
  J 74 0x4A 0b1001010
  K 75 0x4B 0b1001011
  L 76 0x4C 0b1001100
  M 77 0x4D 0b1001101
  N 78 0x4E 0b1001110
  O 79 0x4F 0b1001111
  P 80 0x50 0b1010000
  Q 81 0x51 0b1010001
  R 82 0x52 0b1010010
  S 83 0x53 0b1010011
  T 84 0x54 0b1010100
  U 85 0x55 0b1010101
  V 86 0x56 0b1010110
  W 87 0x57 0b1010111
  X 88 0x58 0b1011000
  Y 89 0x59 0b1011001
  Z 90 0x5A 0b1011010
  `91 0x5B 0b1011011
  ç 92 0x5C 0b1011100
  + 93 0x5D 0b1011101
  & 94 0x5E 0b1011110
  ? 95 0x5F 0b1011111
  º 96 0x60 0b1100000
  a 97 0x61 0b1100001
  b 98 0x62 0b1100010
  c 99 0x63 0b1100011
  d 100 0x64 0b1100100
  e 101 0x65 0b1100101
  f 102 0x66 0b1100110
  g 103 0x67 0b1100111
  h 104 0x68 0b1101000
  i 105 0x69 0b1101001
  j 106 0x6A 0b1101010
  k 107 0x6B 0b1101011
  l 108 0x6C 0b1101100
  m 109 0x6D 0b1101101
  n 110 0x6E 0b1101110
  o 111 0x6F 0b1101111
  p 112 0x70 0b1110000
  q 113 0x71 0b1110001
  r 114 0x72 0b1110010
  s 115 0x73 0b1110011
  t 116 0x74 0b1110100
  u 117 0x75 0b1110101
  v 118 0x76 0b1110110
  w 119 0x77 0b1110111
  x 120 0x78 0b1111000
  y 121 0x79 0b1111001
  z 122 0x7A 0b1111010
  ^ 123 0x7B 0b1111011
  Ç 124 0x7C 0b1111100
  * 125 0x7D 0b1111101
  ª 126 0x7E 0b1111110
 */

 /*
ASCII Table ~ Character Map ENG
    32 0x20 0b100000
  ! 33 0x21 0b100001
  " 34 0x22 0b100010
  # 35 0x23 0b100011
  $ 36 0x24 0b100100
  % 37 0x25 0b100101
  & 38 0x26 0b100110
  ' 39 0x27 0b100111
  ( 40 0x28 0b101000
  ) 41 0x29 0b101001
  * 42 0x2A 0b101010
  + 43 0x2B 0b101011
  , 44 0x2C 0b101100
  - 45 0x2D 0b101101
  . 46 0x2E 0b101110
  / 47 0x2F 0b101111
  0 48 0x30 0b110000
  1 49 0x31 0b110001
  2 50 0x32 0b110010
  3 51 0x33 0b110011
  4 52 0x34 0b110100
  5 53 0x35 0b110101
  6 54 0x36 0b110110
  7 55 0x37 0b110111
  8 56 0x38 0b111000
  9 57 0x39 0b111001
  : 58 0x3A 0b111010
  ; 59 0x3B 0b111011
  < 60 0x3C 0b111100
  = 61 0x3D 0b111101
  > 62 0x3E 0b111110
  ? 63 0x3F 0b111111
  @ 64 0x40 0b1000000
  A 65 0x41 0b1000001
  B 66 0x42 0b1000010
  C 67 0x43 0b1000011
  D 68 0x44 0b1000100
  E 69 0x45 0b1000101
  F 70 0x46 0b1000110
  G 71 0x47 0b1000111
  H 72 0x48 0b1001000
  I 73 0x49 0b1001001
  J 74 0x4A 0b1001010
  K 75 0x4B 0b1001011
  L 76 0x4C 0b1001100
  M 77 0x4D 0b1001101
  N 78 0x4E 0b1001110
  O 79 0x4F 0b1001111
  P 80 0x50 0b1010000
  Q 81 0x51 0b1010001
  R 82 0x52 0b1010010
  S 83 0x53 0b1010011
  T 84 0x54 0b1010100
  U 85 0x55 0b1010101
  V 86 0x56 0b1010110
  W 87 0x57 0b1010111
  X 88 0x58 0b1011000
  Y 89 0x59 0b1011001
  Z 90 0x5A 0b1011010
  [ 91 0x5B 0b1011011
  \ 92 0x5C 0b1011100
  ] 93 0x5D 0b1011101
  ^ 94 0x5E 0b1011110
  _ 95 0x5F 0b1011111
  ` 96 0x60 0b1100000
  a 97 0x61 0b1100001
  b 98 0x62 0b1100010
  c 99 0x63 0b1100011
  d 100 0x64 0b1100100
  e 101 0x65 0b1100101
  f 102 0x66 0b1100110
  g 103 0x67 0b1100111
  h 104 0x68 0b1101000
  i 105 0x69 0b1101001
  j 106 0x6A 0b1101010
  k 107 0x6B 0b1101011
  l 108 0x6C 0b1101100
  m 109 0x6D 0b1101101
  n 110 0x6E 0b1101110
  o 111 0x6F 0b1101111
  p 112 0x70 0b1110000
  q 113 0x71 0b1110001
  r 114 0x72 0b1110010
  s 115 0x73 0b1110011
  t 116 0x74 0b1110100
  u 117 0x75 0b1110101
  v 118 0x76 0b1110110
  w 119 0x77 0b1110111
  x 120 0x78 0b1111000
  y 121 0x79 0b1111001
  z 122 0x7A 0b1111010
  { 123 0x7B 0b1111011
  | 124 0x7C 0b1111100
  } 125 0x7D 0b1111101
  ~ 126 0x7E 0b1111110
  * 
  */

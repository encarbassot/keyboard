#include "Keyb.h"
#include "CONFIG.h"

Keyb k;

void setup(){
  k.setup();
}

void loop(){
  k.loop();
}




/******TO*DO*******
what if not defined BOARD_DECODER & BOARD_MULTIPLEXER

if press a modifier & a key is pressed should release it

key recorders class
  
 */

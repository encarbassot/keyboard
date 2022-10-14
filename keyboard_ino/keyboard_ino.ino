#include "Keyb.h"
//#include "CONFIG.h"

Keyb k;

void setup(){
  k.setup();
}

void loop(){
  k.loop();
}




/******TO*DO*******
what if not defined BOARD_DECODER & BOARD_MULTIPLEXER

read bloqMayus and blocqNum status to nevel let it be enabled

key recorders class

after release Hmodifier wait few millis to release other keys, then act

scanForKeys() if 2 modifiers pressed goes crazy
 */

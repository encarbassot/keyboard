#include "utils.h"
#include "BOARD.h"



#define INT_SIZE 16
#define MODE_SHIFT 12
#define MODE_SIZE INT_SIZE - MODE_SHIFT
unsigned int c(unsigned char mode,unsigned char code){
  //code on the LSB and mode starting on the BYTE_LEN
  //return code + (mode << (INT_LEN-MODE_BIT_LEN));
  return (mode<<MODE_SHIFT)+code;
}


/*get k bits from the left of p position
p starts with  0 on LSB
example getBit(0b11011,3,1) ->   5
10111 -> 1(101)1
3 -> refers to length
1 -> refeers to shift
*/

// Function to extract k bits from p position
unsigned int getBit(unsigned int number,unsigned char k,unsigned char p=0){
  //(1<<k) - 1 creates a mask with  k 1's ex: k = 3 -> 111
  //number>>p shifts to the right p times ex: number=1011001 p=3 -> 00010111
  return (((1 << k) - 1) & (number >> p ));
}

unsigned char uncompMode(unsigned int n){
  return getBit(n,MODE_SIZE,MODE_SHIFT);
}

unsigned char uncompVal(unsigned int n){
  return getBit(n,MODE_SHIFT,0);
}

#ifdef ADJACENCY_MATRIX
  void fisicToVirtual(unsigned char *j,unsigned char *i){
    unsigned char _j=adjacencyMatrix[*j][*i][0];
    *i=adjacencyMatrix[*j][*i][1];
    *j = _j;
  }
#endif


#if defined(BOARD_MULTIPLEXER) || defined(BOARD_DECODER)
  bool intToBinaryPos(int intNum,int pos){
    return (intNum & (1<<pos))>>pos;
  }
#endif

#ifdef BOARD_DECODER
void setDecoder(unsigned char j){
  for(unsigned char i=0;i<PINS_DECO_LEN;i++){
    digitalWrite(pins_deco[i],intToBinaryPos(j,i));
  }
}
#endif

#ifdef BOARD_MULTIPLEXER
  bool setMultiplexer(unsigned char j){
    for(unsigned char i=0;i<PINS_MUX_LEN;i++){
      digitalWrite(pins_mux[i],intToBinaryPos(j,i));
    }
    return digitalRead(PIN_MUX_INP);
  }
#endif

#ifdef ADJACENCY_MATRIX
  
#endif

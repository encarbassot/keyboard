#include "Arduino.h"
#ifndef BOARD_H
#define BOARD_H

#define VIRTUAL_COLUMNS 8
#define VIRTUAL_ROWS 8

#define BOARD_DECODER //DECODER 74HC238
#ifdef BOARD_DECODER
  const unsigned char pins_deco[] = {23,22,21};//{6,7,8};
  #define PINS_DECO_LEN 3
#endif


#define BOARD_MULTIPLEXER//MULTIPLEXOR 74LS151
#ifdef BOARD_MULTIPLEXER
  const unsigned char pins_mux[] =  {17,18,19};//{3,4,5};
  #define PINS_MUX_LEN 3
  #define PIN_MUX_INP 20//2aaaaaaa
  
#endif

#define ADJACENCY_MATRIX
//may take a few milliseconds on the boot.
#ifdef ADJACENCY_MATRIX

#define FISICAL_COLUMNS 16
#define FISICAL_ROWS 4

  
  /*const unsigned char adjacencyMatrix[FISICAL_ROWS][FISICAL_COLUMNS][2]={//enter a fisic position & return virtual position
    {{0,0},{7,0},{6,0},{5,0},{4,0},{3,0},{2,0},{1,0},{6,7},{5,7},{4,7},{3,7},{2,7},{1,7},{0,7},{7,7}},
    {{0,1},{7,1},{6,1},{5,1},{4,1},{3,1},{2,1},{1,1},{6,6},{5,6},{4,6},{3,6},{2,6},{1,6},{0,6},{7,6}},
    {{0,2},{7,2},{6,2},{5,2},{4,2},{3,2},{2,2},{1,2},{6,5},{5,5},{4,5},{3,5},{2,5},{1,5},{0,5},{7,5}},
    {{0,3},{7,3},{6,3},{5,3},{4,3},{3,3},{2,3},{1,3},{6,4},{5,4},{4,4},{3,4},{2,4},{1,4},{0,4},{7,4}},
  };//*/
  const unsigned char adjacencyMatrix[VIRTUAL_ROWS][VIRTUAL_COLUMNS][2]={//enter a virtual position & return fisical position
    {{0,15},{1,15},{2,15},{3,15},{3,14},{2,14},{1,14},{0,14}},
    {{0, 7},{1, 7},{2, 7},{3, 7},{3,13},{2,13},{1,13},{0,13}},
    {{0, 6},{1, 6},{2, 6},{3, 6},{3,12},{2,12},{1,12},{0,12}},
    {{0, 5},{1, 5},{2, 5},{3, 5},{3,11},{2,11},{1,11},{0,11}},
    {{0, 4},{1, 4},{2, 4},{3, 4},{3,10},{2,10},{1,10},{0,10}},
    {{0, 3},{1, 3},{2, 3},{3, 3},{3, 9},{2, 9},{1, 9},{0, 9}},
    {{0, 2},{1, 2},{2, 2},{3, 2},{3, 8},{2, 8},{1, 8},{0, 8}},
    {{0, 1},{1, 1},{2, 1},{3, 1},{3, 0},{2, 0},{1, 0},{0, 0}}
  };//*/  

#endif //ADJACENCY MATRIX

#endif //BOARD_H

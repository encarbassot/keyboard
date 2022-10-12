#ifndef CONFIG_H
#define CONFIG_H
#include "Arduino.h"
#include "utils.h"
#include "BOARD.h"

//////////////TESTS//////////////
//#define TEST1 //print 01 matrix
//#define TEST2
///////////////////////////////

//define more keys to your own
const unsigned char _FN1[2] = {6,3};//position in virtual
//const unsigned char _FN2[2] = {6,2};


  //MODIFIER -> set the key as a modifier
  //COPY     -> set on value the layout you want to copy the key from
  //SCRIPT   -> will execute the script N specified on <value> from the scriptList

#define NUM_LAYOUTS 2
#ifdef ADJACENCY_MATRIX
const unsigned int codes[NUM_LAYOUTS][FISICAL_ROWS][FISICAL_COLUMNS]={
  {
    {0,0,c(0,1),c(1,2), 3, 4, 5, 6, 7, 8, 9,10,11,12,0,0},
    {0,0,13,14,15,16,17,18,19,20,21,22,23,24,0,0},
    {0,0,25,26,27,28,29,30,31,32,33,34,35,36,0,0},
    {0,0,c(MODIFIER | 1,37),38,39,40,41,42,43,44,45,46,47,48,0,0}
  },{
    {0,0,49,50,51,52,53,54,55,56,57,58,59,60,0,0},
    {0,0,61,62,63,64,65,66,67,68,70,71,72,73,0,0},
    {0,0,74,75,76,77,78,79,80,81,82,83,84,85,0,0},
    {0,0,c(COPY,0),87,88,89,90,91,92,93,94,95,96,97,0,0}
  }

};


#endif //ADJACENCY_MATRIX

//if defined SERIAL_OUTPUT will output as Serial.print()
//otherwise its gona act as a keyboard
//only use for debug
#define SERIAL_OUTPUT


#endif //CONFIG_H

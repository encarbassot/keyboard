/*
This code its for testing the functionality of an DECODER and MULTIPLEXOR

DECODER -> 
with the convination of 3 inputs it is going to output the 
binary representation of the 3 inputs to one of the 8 outputs
all the other 7 outputs will remain on 0v

MTLTIPLEXER or MUX-> 
with the convination of 3 inputs it can choose a chanel of its 8 and 
at the output will be the status of the selected input


in this program we are setting an output on the DEC and readint it from de MUX
in this example all the 8 outputs on the DECODER must be connected to the 8 inputs on the MUX

*/

//deco
#define A 8
#define B 7
#define C 6

//mux
#define X 3
#define Y 4
#define Z 5
//mux input
#define INPUT_MULTIPLEXER_PIN 8


const unsigned char mat_outs[] = {A,B,C};   //OUTPUT or DECODER(74HC238)
const unsigned char mat_inps[] = {X,Y,Z};   //INPUT  or MULTIPLEXER(74LS151)


void setup() {
  // setup the inputs and outputs

  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(X,OUTPUT);
  pinMode(Y,OUTPUT);
  pinMode(Z,OUTPUT);
  pinMode(INPUT_MULTIPLEXER_PIN,INPUT);

  Serial.begin(9600);
  Serial.println("BEGIN");

}

void loop() {

  for(byte i=0 ;i<8;i++){
    setOut(i);
    delay(5);
    readOut();
    delay(100);
  }

}

void setOut(byte j){
/*it sets the 3 outputs to the binart conviaton of <j>
J | A B C
---------
0 | 0 0 0
1 | 1 0 0
2 | 0 1 0
3 | 1 1 0
4 | 0 0 1
5 | 1 0 1
6 | 0 1 1
7 | 1 1 1
*/
  
for(unsigned char i=0;i<3;i++){
    digitalWrite(mat_outs[i],j & (1<<i));
  }
}

bool setIn(byte j){
  //helper function of readOut()
  //given a number <j> selects the <j> channel and returns its value
  
  for(unsigned char i=0;i<3;i++){
    digitalWrite(mat_inps[i],j & (1<<i));
  }
  return digitalRead(INPUT_MULTIPLEXER_PIN);
}

void readOut(){

  //goes channel by channel and reads its value
  for(byte i=0 ;i<8;i++){
    Serial.print(setIn(i));
  }
  Serial.println();
}

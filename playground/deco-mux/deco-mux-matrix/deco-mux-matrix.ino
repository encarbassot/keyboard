/*
READ INPUT MATRIX WITH DECODER AND MULTIPLEXER

build a 8x8 button matrix:
 - connect MUX and DECO to Arduino
 - connect each column to decoder output
 - connect each row to multiplexer input
 - connect a diode in serie in each button (DECO -> MUX) direcion


*/

//DECODER 74HC238
#define A 8
#define B 7
#define C 6
const unsigned char pins_deco[] = {C,B,A};
#define PINS_DECO_LEN 3

//MULTIPLEXOR 74LS151
#define X 3
#define Y 4
#define Z 5
const unsigned char pins_mux[] = {X,Y,Z};
#define PINS_MUX_LEN 3
#define PIN_MUX_IN 2



void setup() {
  // setup inputs and outputs
  for(unsigned char i=0; i<PINS_DECO_LEN;i++){
    pinMode(pins_deco[i],OUTPUT);
  }
  for(unsigned char i=0; i<PINS_MUX_LEN;i++){
    pinMode(pins_mux[i],OUTPUT);
  }
  pinMode(PIN_MUX_IN,INPUT);


  Serial.begin(9600);
  delay(2000);
  Serial.println("BEGIN");
}

void loop() {

  bool aux;
  for(int j=0;j<8;j++){
    
    // first on 5v
    setDeco(j);
    
    for(int i=0;i<8;i++){

      //then listen on each column
      //if the button on the intersection is pressed we will read a value true
      aux = setMux(i);

      Serial.print(aux);
    }
    Serial.println();
  }
  delay(20);
  Serial.println();
  Serial.println();

}





void setDeco(unsigned char j){
  for(unsigned char i=0;i<PINS_DECO_LEN;i++){
    digitalWrite(pins_deco[i],intToBinaryPos(j,i));
  }
}

bool setMux(unsigned char j){
  for(unsigned char i=0;i<PINS_MUX_LEN;i++){
    digitalWrite(pins_mux[i],intToBinaryPos(j,i));
  }
  return digitalRead(PIN_MUX_IN);
}

bool intToBinaryPos(int intNum,int pos){
  return (intNum & (1<<pos))>>pos;
}

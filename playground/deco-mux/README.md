# DECODER & MULTIPLEXOR

<img src="../../img/media/circuit_5_keyb48.jpeg" height="500">

### CODE EXAMPLES
  - [deco-mux.ino](deco-mux/deco-mux.ino) explains how a **Multiplexer** and a **Decoder** works
  - [deco-mux-matrix.ino](deco-mux-matrix/deco-mux-matrix.ino) explains how to read a button matrix with a **Multiplexer** and a **Decoder**
## Decoder
 - see on [wikipedia](https://wikipedia.org/wiki/Decodificador)  
 - [74HC238 datasheet](../../documentation/datasheet-DECO-M74HC238_STMicroelectronics.pdf)  

![74HC238 pinout](../../img/74HC238.png)
 - **(A0,A1,A2)**-> microcontroller selector
 - **(Y0,Y1...Y6,Y7)**-> Decoder outputs
 - **(!E1,!E2,E3)** -> bring the option to connect 4 of them to create an **ULTRA-DECODER**
    - **!E1** and **!E2** set to ground (for normal operation)
    - **E3** set to 5V (for normal operation)
 - **VCC & GND** -> 🙃

A decoder has **n** inputs and **2<sup>n</sup>** outputs  
And what it does it's to trigger only the output that matches the input binary combination

for the **74HC238** that I'm using on the project, the output table is the next:

| A | B | C || Y0 | Y1 | Y2 | Y3 | Y4 | Y5 | Y6 | Y7 |
|---|---|---|-|----|----|----|----|----|----|----|----|
🔴|🔴|🔴| |🟢|🔴|🔴|🔴|🔴|🔴|🔴|🔴|
🔴|🔴|🟢| |🔴|🟢|🔴|🔴|🔴|🔴|🔴|🔴|
🔴|🟢|🔴| |🔴|🔴|🟢|🔴|🔴|🔴|🔴|🔴|
🔴|🟢|🟢| |🔴|🔴|🔴|🟢|🔴|🔴|🔴|🔴|
🟢|🔴|🔴| |🔴|🔴|🔴|🔴|🟢|🔴|🔴|🔴|
🟢|🔴|🟢| |🔴|🔴|🔴|🔴|🔴|🟢|🔴|🔴|
🟢|🟢|🔴| |🔴|🔴|🔴|🔴|🔴|🔴|🟢|🔴|
🟢|🟢|🟢| |🔴|🔴|🔴|🔴|🔴|🔴|🔴|🟢|

see it on action  
<img alt="decpder gif" src="../../img/media/VID-20210621-WA0035.gif" width="400" heigth="716" style="height:400px; object-fit: cover;">

## Multiplexor
 A multiplexor its basically an input selector
 it has **n** channel selectors, **2<sup>n</sup>** inputs and 1 output  
 with the microcontroller, you can select any input by setting the channel selectors **HIGH** or **LOW**  
 then it will set its output to the value of the selected input

 - see on [wikipedia](wikipedia.org/wiki/Multiplexor)
 - [74LS151 datasheet](../../documentation/datasheet-MUX-74LS151.pdf)

![74LS151 pinout](../../img/74LS151.png)
 - **(A,B,C)**-> microcontroller channel selector
 - **(D0,D1..D6,D7)** -> Multipexor inputs
 - **(Y,W)** 
    - **Y** -> output
    - **W** -> negated output
 - **G** -> set to ground for formal operation



 | C|B|A|| Y | W |
|---|---|-|--|----|-|
🔴|🔴|🔴| |D0|!D0|
🔴|🔴|🟢| |D1|!D1|
🔴|🟢|🔴| |D2|!D2|
🔴|🟢|🟢| |D3|!D3|
🟢|🔴|🔴| |D4|!D4|
🟢|🔴|🟢| |D5|!D5|
🟢|🟢|🔴| |D6|!D6|
🟢|🟢|🟢| |D7|!D7|

## COMBINATION DECO & MUX
read first how [input matrix](../inputMatrix/README.md) works

## Functionality
Thanks to the chips 
 - 3 to 8 LINE DECODER [74HC238](../../documentation/datasheet-DECO-M74HC238_STMicroelectronics.pdf)
 - 8 to 3 LINE MULTIPLEXOR [74LS151](../../documentation/datasheet-MUX-74LS151.pdf)

 we can read up to 64 inputs with only 6+1 pins of the microcontroller

## Arduino pro micro
![](../../img/proMicro4x12keyb.drawio.png)

## TEENSY LC
![](../../img/teensyLC4x12keyb.drawio.png)

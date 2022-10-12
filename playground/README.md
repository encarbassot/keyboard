# Playground
here are some codes that may help to understand de functionality of the keyboard
this wants to be a non over complicated way to understand the deep code of keyboard

## Example codes
 - [deco-mux.ino](deco-mux/deco-mux.ino) explains how a **Multiplexer** and a **Decoder** works
 ![conectionDiagram](../img/mdeia/20210910_165638.jpg)
 ![decoderExample](../img/mdeia/VID-20210621-WA0035.gif)
 - [deco-mux-matrix.ino](deco-mux-matrix/deco-mux-matrix.ino) explains how to read a button matrix with a **Multiplexer** and a **Decoder**
 - [matrixInp.ino](matrixInp/matrixInp.ino) Reads a button matrix without a multiplexer or decoder, raw input from row/column to Arduino input/output
 - [ascii.ino](ascii/ascii.ino) emulates a keyboard keypress for each key that can exist and prints a table with the codes of ach key

 ## Interesting to include the next functionalities to the keyboard
 - [sd.ino](sd/sd.ino) reads a microSD and outputs the contents of a file
 - [oled.ino](oled/oled.ino) shows information via oled **SSD1306** (128×32) or (128x64) with [Adafruit library](https://github.com/adafruit/Adafruit_SSD1306)
 - [bluetooth.ino](bluetooth/bluetooth.ino) comunication with phone to wirtie from an app
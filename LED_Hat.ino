/* The Goal of this code is to have a keyboard give input to an Arduino
 and have the Arduino scroll the input across an 7-Hex LED Display*/

#include <PS2Keyboard.h>

//Pin connected to ST_CP of 74HC595
int latchReg = 0;
//Pin connected to SH_CP of 74HC595
int clockReg = 1;
//Pin connected to DS of 74HC595
int dataReg = 3;
//Pin connected to the data of the keyboard
int dataKey = 4;
//Pin connected to the clock of the keyboard
int clockKey = 5;
/* Note that I am not defining which pin connects to your the keyboard input
    this is interrupt 0 which is attached to pin 2. */

//Defined Characters
#define A 
#define B 
#define C 
#define D 
#define E 
#define F 
#define G 
#define H 
#define I 
#define J 
#define K 
#define L 
#define M 
#define N 
#define O 
#define P 
#define Q 
#define R 
#define S 
#define T 
#define U 
#define V 
#define W 
#define X 
#define Y 
#define Z 

//holders for infomation being passed to the shifting function
byte data;
byte dataArray[26];

void setup() {
  //set pins to output becuase they are addressed in the main loop
  pinMode(latchReg, OUTPUT)
  Serial.begin(9600);
  
  //Arduino doesn't seem to have a way to write binary straight into the code 
  //so these values are in HEX.  Decimal would have been fine, too.
  dataArray[0] = 0x41; //01000001
  dataArray[1] = 0x42; //01000010
  dataArray[2] = 0x43; //01000011
  dataArray[3] = 0x44; //01000100
  dataArray[4] = 0x45; //01000101
  dataArray[5] = 0x46; //01000110
  dataArray[6] = 0x47; //01000111
  dataArray[7] = 0x48; //01001000
  dataArray[8] = 0x49; //01001001
  dataArray[9] = 0x4A; //01001010
  dataArray[10] = 0x4B; //01001011
  dataArray[11] = 0x4C; //01001100
  dataArray[12] = 0x4D; //01001101
  dataArray[13] = 0x4E; //01001110
  dataArray[14] = 0x4F; //01001111
  dataArray[15] = 0x50; //01010000
  dataArray[16] = 0x51; //01010001
  dataArray[17] = 0x52; //01010010
  dataArray[18] = 0x53; //01010011
  dataArray[19] = 0x54; //01010100
  dataArray[20] = 0x55; //01010101
  dataArray[21] = 0x56; //01010110
  dataArray[22] = 0x57; //01010111
  dataArray[23] = 0x58; //01011000
  dataArray[24] = 0x59; //01011001
  dataArray[25] = 0x5A; //01011010
  
  keyboard.begin(4);
  Serial.begin(9600);
}

void loop() {
  
  if(keyboard.available()){
    byte key =keyboard.read();
    byte val = key-'0';
    
    
    else if(dat == PS2_KC_ENTER) {

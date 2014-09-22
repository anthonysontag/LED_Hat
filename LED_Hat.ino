/* This code will allow a keyboard give input to an Arduino platform
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
    
#define dataKey
PS2Keyboard keyboard;

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
byte letter;
byte letterArray[10];

void setup() {
  //set interrupt pin to pin 2, function it calls, and trigger type
  attachInterrupt(2, begin_type, RISING);
  
  //set pins to input or output becuase they are addressed in the main loop
  pinMode(latchReg, OUTPUT);
  pinMode(clockReg, OUTPUT);
  pinMode(dataReg, OUTPUT);
  pinMode(dataKey, INPUT);
  pinMode(clockKey, OUTPUT);
  
  keyboard.begin(4);
}

void loop() {
//if switch is flipped
//start begin_type
//else continue scrolling current array

}

void begin_type()  {
  if(keyboard.available()) {          //if key is in buffer
    byte key = keyboard.read();       //read key in buffer

    while (key != PS2_KC_ENTER) {     //while key typed is not enter
      
      int i;
      for (int i = 0; i < 10; i++) {  //for 10 iterations
        byte letter = key;            //store letter typed in byte
        byte val = letter-'0';        //moves letter one position in the array to the left
        letterArray[i] = letter;      //stores byte letter in array
      }
    }
  }
    else {
      //ground latch pin during transmit
      digitalWrite(latchReg, LOW);
      //clocks the array to the shift registers
      shiftOut(dataReg, clockReg, LSBFIRST, letterArray);
      //ungrounds latch pin after transmit
      digitalWrite(latchReg, HIGH);
    }
  } 

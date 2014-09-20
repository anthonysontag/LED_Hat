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
byte letterArray[20];

void setup() {
  //set interrupt pin to pin 2, function it calls, and trigger type
  attachInterrupt(2, begin_type, RISING);
  
  //set pins to input or output becuase they are addressed in the main loop
  pinMode(latchReg, OUTPUT);
  pinMode(clockReg, OUTPUT);
  pinMode(dataReg, OUTPUT);
  pinMode(dataKey, INPUT);
  pinMode(clockKey, OUTPUT);
  Serial.begin(9600);
  
  keyboard.begin(4);
  Serial.begin(9600);
}

void loop() {
  
}

void begin_type()  {
  if(keyboard.available()) {          //if keyboard is connected
    key = keyboard.read();             //read typed key

    while (key != PS2_KC_ENTER) {     //while key typed is not enter
      
      int i;
      for (int i = 0; i < 20; i++) {  //for 20 iterations
        byte letter = key;              //Store letter typed in byte
        byte val = letter-'0';          //
        letterArray[i] = letter;        //
      }
    
    if else {
      digitalWrite(latchReg, LOW);    //ground latch pin during transmit
      shiftOut(dataReg, clockReg, LSBFIRST, i);
      digitalWrite(latchReg, HIGH);
    }
    }
  }
}  

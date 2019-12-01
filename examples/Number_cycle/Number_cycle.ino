#include <sevenSegment.h>   // Include the sevenSegment library

// The library can either be declared using pins straight (sega-segg), pins straight with decimal point (sega-segdp) or with a shift register (data, clock, latch) (dp or no dp)
// Un-comment the one you are using below!

//sevenSegment sevseg(5, 6, 7, 8, 9, 10, 11, true);      // Uncomment for straight wiring pins (segment a - segment g)
//sevenSegment sevseg(5, 6, 7, 8, 9, 10, 11, 12), true;  // Uncomment for straight wiring pins with a decimal point (segment a - decimal point)
//sevenSegment sevseg(5, 6, 7, true);                    // Uncomment for shift register wiring pins (Data, Clock, Latch) (it doesn't matter if it has a decimal point or not)

int delayTime = 1000;   // Milliseconds to delay after each number (default 1 second)
int displays = 4;  // Number of seven segment displays you have daisy-chained (default 1)

void setup() {
  // Nothing needs to go here apart from clearing the displays, the library sets up the pins for you
  sevseg.clear(displays);
}

void loop() {
  //Cycle from 0-9, then blank
  sevseg.display('0'); // Display the number 0
  delay(delayTime);    // Delay for the delay time specified in the integer delayTime
  sevseg.display('1');
  delay(delayTime);
  sevseg.display('2');
  delay(delayTime);
  sevseg.display('3');
  delay(delayTime);
  sevseg.display('4');
  delay(delayTime);
  sevseg.display('5');
  delay(delayTime);
  sevseg.display('6');
  delay(delayTime);
  sevseg.display('7');
  delay(delayTime);
  sevseg.display('8');
  delay(delayTime);
  sevseg.display('9');
  delay(delayTime);
  sevseg.clear(); // Include clearing one screen in the display cycle (this leaves a gap when it starts again if you have multiple screens)
  delay(delayTime);
}

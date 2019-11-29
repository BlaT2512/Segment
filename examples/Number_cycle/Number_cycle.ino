#include <sevenSegment.h>   // Include the sevenSegment library

// The library can either be declared using pins straight (sega-segg) or with a shift register (data, clock, latch)
// Un-comment the one you are using below!

//sevenSegment sevseg(5, 6, 7, 8, 9, 10, 11);  // Uncomment for straight wiring pins (segment a - segment g)
//sevenSegment sevseg(5, 6, 7);                // Uncomment for shift register wiring pins (Data, Clock, Latch)

int delayTime = 1000;   // Milliseconds to delay after each number (default 1 second)

void setup() {
  // Nothing needs to go here, the library sets up the pins for you
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
  sevseg.display('~'); // Include clearing the screen in the display cycle
  delay(delayTime);
}

/*
 * Number_cycle.ino - Example arduino sketch demonstrating scrolling through the numbers 1-10 on a seven-segment display
 * Part of the Arduino Segment library
 * https://github.com/BlaT2512/Segment
 */

#include <Segment.h>   // Include the Segment library

// The library can either be declared using pins straight (sega-segg), pins straight with decimal point (sega-segdp) or with a shift register (data, clock, latch) (dp or no dp)
// See README.md for more information on how to declare the library
// Un-comment the one you are using below!

//Segment sevseg(5, 6, 7, 8, 9, 10, 11, true);      // Uncomment for straight wiring pins (segment a - segment g)
//Segment sevseg(5, 6, 7, 8, 9, 10, 11, 12), true;  // Uncomment for straight wiring pins with a decimal point (segment a - decimal point)
//Segment sevseg(5, 6, 7, -1, 7, true);             // Uncomment for shift register wiring pins (Data, Clock, Latch) (it doesn't matter if it has a decimal point or not)

int delayTime = 1000;   // Milliseconds to delay after each number (default 1 second)
int displays = 4;  // Number of seven segment displays you have daisy-chained (default 1)

void setup() {
  sevseg.clear(displays); // Clear the number of displays you have
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

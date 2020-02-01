/*
 * Number_cycle.ino - Example arduino sketch demonstrating scrolling through the numbers 1-10 on a sixteen-segment display
 * Part of the Arduino Segment library
 * https://github.com/BlaT2512/Segment
 */

#include <Segment.h>   // Include the Segment library

// The library can either be declared using pins straight (sega-segm), pins straight with decimal point (sega-segdp) or with a shift register (data, clock, latch, dp)
// See README.md for more information on how to declare the library
// Un-comment the one you are using below! NOTE: you will not need a decimal point for this example, so leave that parameter as -1 on shift register declaration

//Segment sixtseg(2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, A0, A1, A2, A3, true);      // Uncomment for straight wiring pins (segment a - segment m)
//Segment sixtseg(2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, A0, A1, A2, A3, A4, true);  // Uncomment for straight wiring pins with a decimal point (segment a - decimal point)
//Segment sixtseg(5, 6, 7, -1, 16, true);                                             // Uncomment for shift register wiring pins (Data, Clock, Latch, , Segments) (no decimal point needed for this example)

int delayTime = 1000;   // Milliseconds to delay after each number (default 1 second)
int displays = 4;  // Number of sixteen segment displays you have daisy-chained (default 1)

void setup() {
  sixtseg.clear(displays); // Clear the number of displays you have
}

void loop() {
  //Cycle from 0-9, then blank
  sixtseg.display('0'); // Display the number 0
  delay(delayTime);    // Delay for the delay time specified in the integer delayTime
  sixtseg.display('1');
  delay(delayTime);
  sixtseg.display('2');
  delay(delayTime);
  sixtseg.display('3');
  delay(delayTime);
  sixtseg.display('4');
  delay(delayTime);
  sixtseg.display('5');
  delay(delayTime);
  sixtseg.display('6');
  delay(delayTime);
  sixtseg.display('7');
  delay(delayTime);
  sixtseg.display('8');
  delay(delayTime);
  sixtseg.display('9');
  delay(delayTime);
  sixtseg.clear(); // Include clearing one screen in the display cycle (this leaves a gap when it starts again if you have multiple screens)
  delay(delayTime);
}

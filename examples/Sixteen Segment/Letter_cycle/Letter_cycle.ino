/*
 * Letter_cycle.ino - Example arduino sketch demonstrating scrolling through the letters A-Z on a sixteen-segment display
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
  sevseg.clear(displays); // Clear the number of displays you have
}

void loop() {
  //Since there are so many letters, we will be using a loop rather than displaying each one with sevseg.display('A') and so on (see Number_cycle)
  for (char ch = 'A'; ch <= 'Z'; ch++) { // This means that character ch starts on A and increments by one each time. The loop will go until ch is Z.
    sevseg.display(ch); // Display the letter, ch
    delay(delayTime); // Delay for the delay time specified in the integer delayTime
  }
  sevseg.clear(); // Include clearing one screen in the display cycle (this will be a gap if you have multiple daisy-chained displays)
  delay(delayTime);
}

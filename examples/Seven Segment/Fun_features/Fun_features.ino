/*
 * Fun_features.ino - Example arduino sketch demonstrating the 'example' function of the Segment library
 * Part of the Arduino Segment library
 * https://github.com/BlaT2512/Segment
 */

#include <Segment.h> // Include the Segment library

// The library can either be declared using pins straight (sega-segg), pins straight with decimal point (sega-segdp) or with a shift register (data, clock, latch) (dp or no dp)
// See README.md for more information on how to declare the library
// Un-comment the one you are using below!

//Segment sevseg(5, 6, 7, 8, 9, 10, 11, true);      // Uncomment for straight wiring pins (segment a - segment g)
//Segment sevseg(5, 6, 7, 8, 9, 10, 11, 12, true);  // Uncomment for straight wiring pins with a decimal point (segment a - decimal point)
//Segment sevseg(5, 6, 7, -1, 7, true);             // Uncomment for shift register wiring pins (Data, Clock, Latch) (it doesn't matter if it has a decimal point or not)

void setup() {
  sevseg.clear(); // Clear your display (this example is intended for one display)
}

void loop() {
  // Cycle through all the modes of the Example function
  sevseg.example(1, 500, 1); // Cycle through numbers
  delay(1000);
  sevseg.example(1, 500, 2); // Cycle through letters
  delay(1000);
  sevseg.example(1, 500, 3); // Cycle through numbers & letters
  delay(1000);
  sevseg.example(1, 500, 4); // Cycle through numbers & punctuation
  delay(1000);
  sevseg.example(1, 500, 5); // Cycle through letters & punctuation
  delay(1000);
  sevseg.example(1, 500, 6); // Cycle through numbers, letters & punctuation (everything)
  delay(1000);
  
  // Skip all the negative versions of mode 1 (they are just the reverse)
  
  sevseg.example(2, 100); // Animate 1 segment around the display clockwise
  delay(1000);
  sevseg.example(-2, 100); // Animate 1 segment around the display anticlockwise
  delay(1000);
  sevseg.example(3, 100); // Animate 1 blank segment around the lit-up display clockwise
  delay(1000);
  sevseg.example(-3, 100); // Animate 1 blank segment around the lit-up display anticlockwise
  delay(1000);
  sevseg.example(4, 100); // Animate move upwards
  delay(1000);
  sevseg.example(-4, 100); // Animate move downwards
  delay(1000);
  sevseg.example(5, 100); // Animate in an 8 fasion (figure-8)
  delay(1000);
  sevseg.example(-5, 100); // Animate in an 8 fashion (figure-8) reverse
  delay(1000);
  sevseg.example(6, 100); // Animate all segments on (a,b,c,d,e,f,g order)
  delay(1000);
  sevseg.example(-6, 100); // Animate all segments off (g,f,e,d,c,b,a order)
  delay(1000);
}

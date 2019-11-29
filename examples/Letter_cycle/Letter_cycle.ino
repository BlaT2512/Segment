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
  //Since there are so many letters, we will be using a loop rather than displaying each one with sevseg.display('A') and so on (see Number_cycle)
  for (char ch = 'A'; ch <= 'Z'; ch++) { // This means that character ch starts on A and increments by one each time. The loop will go until ch is Z.
    sevseg.display(ch); // Display the letter, ch
    delay(delayTime); // Delay for the delay time specified in the integer delayTime
  }
  sevseg.display('~'); // Include clearing the screen in the display cycle
  delay(delayTime);
}

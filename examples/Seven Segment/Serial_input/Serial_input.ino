#include <Segment.h> // Include the Segment library

// The library can either be declared using pins straight (sega-segg), pins straight with decimal point (sega-segdp) or with a shift register (data, clock, latch) (dp or no dp)
// Un-comment the one you are using below!

//Segment sevseg(5, 6, 7, 8, 9, 10, 11, true);      // Uncomment for straight wiring pins (segment a - segment g)
//Segment sevseg(5, 6, 7, 8, 9, 10, 11, 12, true);  // Uncomment for straight wiring pins with a decimal point (segment a - decimal point)
//Segment sevseg(5, 6, 7, true);                    // Uncomment for shift register wiring pins (Data, Clock, Latch) (it doesn't matter if it has a decimal point or not)

String incoming = ""; // This is where we will store what is recieved from the serial
int displays = 4; // Change this to the numbers of 7seg-displays you are using (daisy chained)

void setup() {
  Serial.begin(9600); // Begin the serial at 9600 baud
  sevseg.clear(displays); // Clear the number of displays you have
}

void loop() {
  while(!Serial.available()){;} // While nothing has been typed in the serial, do nothing
  // Something has now been entered in the serial
  incoming = Serial.readString(); // Retrieve the entered string from the serial
  incoming.trim(); // Remove newline characters and whitespace from the end

  // DISPLAY THE STRING
  sevseg.displayString(incoming, displays, true); // Display the string "incoming" on the number of displays in the variable 'displays', and clear the displays beforehand
}

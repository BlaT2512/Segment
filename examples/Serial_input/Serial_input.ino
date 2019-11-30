#include <sevenSegment.h> // Include the sevenSegment library

// The library can either be declared using pins straight (sega-segg) or with a shift register (data, clock, latch)
// Un-comment the one you are using below!

//sevenSegment sevseg(5, 6, 7, 8, 9, 10, 11);  // Uncomment for straight wiring pins (segment a - segment g)
sevenSegment sevseg(4, 6, 5);                // Uncomment for shift register wiring pins (Data, Clock, Latch)

String incoming = ""; // This is where we will store what is recieved from the serial
int displays = 4; // Change this to the numbers of 7seg-displays you are using (daisy chained)

void setup() {
  Serial.begin(9600); // Begin the serial at 9600 baud
}

void loop() {
  while(!Serial.available()){;} // While nothing has been typed in the serial, do nothing
  // Something has now been entered in the serial
  incoming = Serial.readString(); // Retrieve the entered string from the serial
  incoming.trim(); // Remove newline characters and whitespace from the end

  // CLEAR THE DISPLAYS
  for (int i = 0; i <= displays; i++) { // Repeat for all the seven-segment displays you have
    sevseg.display('~'); // Clear the displays
    delay(10);
  }
  delay(100);

  // DETERMINE WHETHER THE STRING NEEDS TO BE SCROLLED
  if (incoming.length() <= displays){ // If the string length is less than or the same as the number of screens
      // STRING DOESN'T NEED TO BE SCROLLED
      for (int i = 0; i <= incoming.length() - 1; i++) { // Repeat for each character of the string that came in the serial
        sevseg.display(incoming.charAt(i)); // Display the corresponding character on the 7 segment display
        delay(10);
      }
  }
  else {
      // STRING NEEDS TO BE SCROLLED
      for (int i = 0; i <= incoming.length() - 1; i++) { // Repeat for each character of the string that came in the serial
        sevseg.display(incoming.charAt(i)); // Display the corresponding character on the 7 segment display
        delay(1000);
        if (Serial.available()) break;
        
        if (i >= incoming.length() - 1){ // If this is the last character
          delay(1000); // Delay 1 second
          if (Serial.available()) break;
          delay(1000); // Delay 1 second
          if (Serial.available()) break;
          delay(1000); // Delay 1 second
          if (Serial.available()) break;
          sevseg.display('~');
          delay(1000);
          i = -1; // Start the cycle again on -1, as 1 will get added when it starts again making the variable 0
        }
        
        if (Serial.available()) break;
      }
  }
}

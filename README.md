# sevenSegment Library
Welcome to the sevenSegment library! This is an Arduino library for seven-segment displays, wired up to the arduino using 8 wires (sega - segg) OR with a shift register (clock, latch and data).

<img src="extras/SevSeg.png" alt="seven segment display" width="200"/>

# Installation
To install sevenSegment, install it using the Arduino library manager, or manually from the [releases page](https://github.com/Blake-Tourneur/sevenSegment/releases).

# Using the library / syntax
### Declare the library
You can either declare the library for use with straight wiring or with a shift register.

STRAIGHT WIRING:
```
#include <sevenSegment.h>   // Include the sevenSegment library
sevenSegment sevseg(5, 6, 7, 8, 9, 10, 11);   // Set the pins you want (segment a - segment g)
```
SHIFT REGISTER WIRING:
```
#include <sevenSegment.h>   // Include the sevenSegment library
sevenSegment sevseg(5, 6, 7);   // Set the pins you want (Data, Clock, Latch)
```

### Commands
You can currently print to your seven segment display most possible English alphanumeric characters and symbols. It is possible to print: Numbers 0-9, Letters A-Z and Characters "#$%&'()*+,-~/\`:;<=>?[]{}\\^_

The format of the function is `sevseg.display(char charac)`.

Here are some examples of printing single characters:
```
  sevseg.display('A'); // Display letter A
  sevseg.display('5'); // Display number 5
  sevseg.display(';'); // Display character ;
  sevseg.display('G'); // Display letter G
  sevseg.display('3'); // Display number 3
  sevseg.display('/'); // Display character /
```
You can also print a string to the display(s), and it will print all the characters. By specifying the number of displays daisy-chained, it will automatically scroll the text if there is more characters in it than the number of displays. Also, you can specify whether to clear displays beforehand. If not and a word is shorter than the number of displays, there will be a letter from the previous word on unused displays.

The format of the function is `sevseg.displayString(String word, int displays = 1, bool cleardisp = true)`

Here are some examples of printing strings:
```
  sevseg.displayString("Hello"); // Display Hello on 1 display, and clear the display beforehand
  sevseg.displayString("Goodbye", 4); // Display Goodbye on 4 displays, and clear the displays beforehand
  sevseg.displayString("OK", 3, false); // Display OK on 3 displays, and don't clear the displays beforehand (since there are three displays, the 3rd one will have a letter from the previous display on it as it isn't cleared)
  sevseg.displayString("Seeya", 5, true); // Display Seeya on 5 displays, and clear the displays beforehand
```

And to clear the display, use `sevseg.clear(displays)`, where displays is the number of 7seg displays daisy-chained (integer). The command will clear them all. To just clear one display (or, if you have multiple, it will be like a space/gap), use `sevseg.display(' ')` or `sevseg.clear()`.

### Examples
The examples available for this library are:

`Number_Cycle.ino` - Cycles through the numbers 0-9 and then blank. Go to `File > Examples > sevenSegment > Number_Cycle`.

`Letter_Cycle.ino` - Cycles through the letters A-Z and then blank. Demonstrates use of 'for' loop. Go to `File > Examples > sevenSegment > Letter_Cycle`.

`Serial_Input.ino` - Prints the character/string on the seven-segment display recieved by the serial. Go to `File > Examples > sevenSegment > Serial_Input`.

# Updates
Updates can be done through the Arduino Library Manager, or by downloading the latest package from [releases page](https://github.com/Blake-Tourneur/sevenSegment/releases).
#### Future update list (current version 2.0.0):
2.0.1 - Update examples for new version/functions

2.1.0 - Move large variable (numMatrix) to PROGMEM (this saves memory on the Arduino as it currently uses around 90% of Arduino SRAM storage because of the all the data for every letter, character and number.

2.2.0 - Fix an error where only shift register displays work.

2.3.0 - Add support for displays with a decimal point.

3.0.0 - Add support for 14-segment displays, 16-segment displays, dot matrix displays, BCD (binary coded decimal) decoder wired displays and (possibly) rename library to Segment.

# License
This library is licensed under the `Apache 2.0` license. For more information, [click here](https://www.apache.org/licenses/LICENSE-2.0).

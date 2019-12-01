# sevenSegment Library
Welcome to the sevenSegment library! This is an Arduino library for seven-segment displays, wired up to the arduino using 7 wires (sega - segg), with a decimal point (sega - dp) or with a shift register (clock, latch and data).

<img src="extras/SevSeg.png" alt="seven segment display" width="200"/>

# Installation
To install sevenSegment, install it using the Arduino library manager, or manually from the [releases page](https://github.com/Blake-Tourneur/sevenSegment/releases).

# Using the library / syntax
### Declare the library
You can either declare the library for use with straight wiring, straight wiring with a decimal point or with a shift register. You also specify whether you have a common cathode (one ground pin on the display and a positive pin for all the segments) or a common anode display (one positive pin on the display and a ground pin for all the segments). True is common cathode and False is common anode.

STRAIGHT WIRING:
```
#include <sevenSegment.h>   // Include the sevenSegment library
sevenSegment sevseg(5, 6, 7, 8, 9, 10, 11, true);   // Set the pins you want and whether the display is common anode/cathode
//        Segments: a, b, c, d, e, f,  g,  c a/c
```
STRAIGHT WIRING WITH DECIMAL POINT:
```
#include <sevenSegment.h>   // Include the sevenSegment library
sevenSegment sevseg(5, 6, 7, 8, 9, 10, 11, 12, true);   // Set the pins you want and whether the display is common anode/cathode
//        Segments: a, b, c, d, e, f,  g,  dp, c a/c
```
SHIFT REGISTER WIRING:
```
#include <sevenSegment.h>   // Include the sevenSegment library
sevenSegment sevseg(5, 6, 7, true);   // Set the pins you want and whether the display is common anode/cathode
//            Pins: D, C, L, c a/c
```

### Commands
You can currently print to your seven segment display most possible English alphanumeric characters and symbols. It is possible to print: Numbers 0-9, Letters A-Z and Characters "#$%&'()*+,-~/\`:;<=>?[]{}.\\^_!

The format of the function is `sevseg.display(char charac)`.

Here are some examples of printing single characters:
```
  sevseg.display('A'); // Display letter A
  sevseg.display('5'); // Display number 5
  sevseg.display(';'); // Display character ;
  sevseg.display('G'); // Display letter G
  sevseg.display('3'); // Display number 3
  sevseg.display('!'); // Display character ! (only supported for display with decimal point)
```
You can also print a string to the display(s), and it will print all the characters. By specifying the number of displays daisy-chained, it will automatically scroll the text if there is more characters in it than the number of displays. Also, you can specify whether to clear displays beforehand. If not and a word is shorter than the number of displays, there will be a letter from the previous word on unused displays.

The format of the function is `sevseg.displayString(String word, int displays = 1, bool cleardisp = true)`

Here are some examples of printing strings:
```
  sevseg.displayString("Hello"); // Display Hello on 1 display, and clear the display beforehand
  sevseg.displayString("Good bye", 4); // Display Good bye on 4 displays, and clear the displays beforehand
  sevseg.displayString("OK", 3, false); // Display OK on 3 displays, and don't clear the displays beforehand (since there are three displays, the 3rd one will have a letter from the previous display on it as it isn't cleared)
  sevseg.displayString("Awesome!", 5, true); // Display Awesome! on 5 displays, and clear the displays beforehand
```

And to clear the display, use `sevseg.clear(displays)`, where displays is the number of 7seg displays daisy-chained (integer). The command will clear them all. To just clear one display (or, if you have multiple, it will be like a space/gap), use `sevseg.display(' ')` or `sevseg.clear()`.

### Examples
The examples available for this library are:

`Number_Cycle.ino` - Cycles through the numbers 0-9 and then blank. Go to `File > Examples > sevenSegment > Number_Cycle`.

`Letter_Cycle.ino` - Cycles through the letters A-Z and then blank. Demonstrates use of 'for' loop. Go to `File > Examples > sevenSegment > Letter_Cycle`.

`Serial_Input.ino` - Prints the character/string on the seven-segment display recieved by the serial. Go to `File > Examples > sevenSegment > Serial_Input`.

# Updates
Updates can be done through the Arduino Library Manager, or by downloading the latest package from [releases page](https://github.com/Blake-Tourneur/sevenSegment/releases).
#### Future update list (current version 2.5.0):
2.6.0 - Add fun/example function to do things such as scroll through every number, letter or character, scroll through segments clockwise/counterclockwise and more

3.0.0 - Add support for 16-segment displays

3.0.1 - Rename library to Segment.

3.1.0 - Configure library to only compile functions/matrixes that are used to Arduino (this saves space with the large matrixes for the 16seg display, 14seg display and 7seg display)

3.2.0 - Add support for 14-segment displays

3.3.0 - Add support for dot matrix displays
#### Possible updates
Add support for BCD (binary coded decimal) decoder wired displays

# License
This library is licensed under the `Apache 2.0` license. For more information, [click here](https://www.apache.org/licenses/LICENSE-2.0).

# sevenSegment Library
Welcome to the sevenSegment library! This is an Arduino library for seven-segment displays, wired up to the arduino using 8 wires (sega - segg) OR with a shift register (clock, latch and data).

<img src="extras/SevSeg.png" alt="drawing" width="200"/>

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
You can currently print to your seven segment display the numbers 0-9 and the letters A-Z.
Here are some examples:
```
  sevseg.display('A'); // Display letter A
  sevseg.display('6'); // Display number 6
  sevseg.display('G'); // Display letter G
  sevseg.display('3'); // Display number 3
```
And to clear the display, use `sevseg.display('~')`
In the next update, some special characters will also be supported.

### Examples
The examples available for this library are:

`Number_Cycle.ino` - Cycles through the numbers 0-9 and then blank. Go to `File > Examples > sevenSegment > Number_Cycle`.

`Letter_Cycle.ino` - Cycles through the letters A-Z and then blank. Go to `File > Examples > sevenSegment > Letter_Cycle`.

`Serial_Input.ino` - Prints the character on the seven-segment display recieved by the serial. Go to `File > Examples > sevenSegment > Serial_Input`.

# Updates
A new update is coming out soon! It will support seven segment displays with a decimal point and special characters. Updates can be done through the Arduino Library Manager, or by downloading the latest package from [releases page](https://github.com/Blake-Tourneur/sevenSegment/releases).


# License
This library is licensed under the `Apache 2.0` license. For more information, [click here](https://www.apache.org/licenses/LICENSE-2.0).

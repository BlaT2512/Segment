# singleSevSeg Library
Welcome to the singleSevSeg library! This is an Arduino library for a single seven-segment display, wired up to the arduino using 8 wires (sega - segg and GND). Support for displays with a decimal point (dp) will be coming in the next release.

<img src="extras/SevSeg.png" alt="drawing" width="200"/>

# Installation
To install singleSevSeg, install it using the Arduino library manager, or manually from the [releases page](https://github.com/Blake-Tourneur/singleSevSeg/releases).

# Using the library / syntax
### Declare the library
At the top of your sketch, declare the library like this:
```
#include <singleSevSeg.h>   // Include the singleSevSeg library
singleSevSeg sevseg(5, 6, 7, 8, 9, 10, 11);   // Set the pins you want (segment a - segment g)
```

### Commands
You can currently print to your seven segment display the numbers 0-9:
```
  sevseg.ZERO();
  sevseg.ONE();
  sevseg.TWO();
  sevseg.THREE();
  sevseg.FOUR();
  sevseg.FIVE();
  sevseg.SIX();
  sevseg.SEVEN();
  sevseg.EIGHT();
  sevseg.NINE();
  ```
And to clear the display, use `sevseg.CLEAR();`
In the next update, letters will be also supported.

### Examples
To view an example of cycling through the different numbers (`Number_Cycle.ino`), go to `File > Examples > singleSevSeg > Number_Cycle`.

# Updates
A new major update is coming out soon! It will support the letters of the alphabet that can be made on a seven-seg display, and also support shift registers. The name of the library may also be changing.

# License
This library is licensed under the `Apache 2.0` license. For more information, [click here](https://www.apache.org/licenses/LICENSE-2.0).

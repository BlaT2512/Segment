/*
   Segment.h - Library for using 7/14/16 segment displays
   Display must be wired up to parallel to the Arduino, or using a shift register
   Created by Blake Tourneur, October 2, 2018.
   Released into the public domain
*/

#ifndef Segment_h
#define Segment_h

#include "Arduino.h"

class Segment
{
  public:
    Segment(int sega, 
            int segb, 
            int segc, 
            int segd, 
            int sege, 
            int segf, 
            int segg, 
            bool cathode = true);  // Configuration for 7-segment display, no decimal point

    Segment(int sega, 
            int segb, 
            int segc, 
            int segd, 
            int sege, 
            int segf, 
            int segg, 
            int segdp, 
            bool cathode = true);  // Configuration for 7-segment display with dp

    Segment(int sega1, 
            int sega2, 
            int segb, 
            int segc, 
            int segd1, 
            int segd2, 
            int sege, 
            int segf, 
            int segg1, 
            int segg2, 
            int segh, 
            int segi, 
            int segj, 
            int segk, 
            int segl, 
            int segm, 
            bool cathode = true);  // Configuration for 16-segment display, no decimal point

    Segment(int sega1, 
            int sega2, 
            int segb, 
            int segc, 
            int segd1, 
            int segd2, 
            int sege, 
            int segf, 
            int segg1, 
            int segg2, 
            int segh, 
            int segi, 
            int segj, 
            int segk, 
            int segl, 
            int segm, 
            int segdp,
            bool cathode = true);  // Configuration for 16-segment display with dp

    Segment(int Data, 
            int Clock, 
            int Latch, 
            int segdp = -1,  // Only used if using a 16-segment display
            int Segments = 7, 
            bool cathode = true);  // Configuration for any shift-register wired display

    void display(char charac);  // Function for displaying character
    void clear(int displays = 1);  // Function for clearing display(s)
    void displayString(String word, int displays = 1, bool cleardisp = true);  // Function for displaying string
    void example(int mode, int delayTime, int semiMode = 0);  // Function for displaying fun examples, see below
    // NOTE: Putting a negative sign before the mode reverses it. eg. mode -1 and semimode 1 scrolls from 9 to 0
    // The modes for the example function are:
    // 1 - Scroll through characters. Semimodes are:
    //     1 - Just numbers
    //     2 - Just letters
    //     3 - Numbers & letters
    //     4 - Numbers & punctuation
    //     5 - Letters & punctuation
    //     6 - Numbers, letters and punctuation (everything)
    // 2 - Animate 1 segment around the display (default clockwise unless negative sign is used)
    // 3 - Animate 1 blank segment around the lit up display (default clockwise unless negative sign is used)
    // 4 - Animate move upwards (negative numbers makes animate move downwards)
    // 5 - Animate in an 8 fashion (negative number changes direction)
    // 6 - Animate all segments on (a,b,c,d,e,f,g order) (negative number makes it animate all segments off)
  private:
    // INTERNAL FUNCTIONS
    void _Clocking();  // Internal shift register function
    void _Latching();  // Internal shift register function
    void _Write(int _Numeral);  // Internal function for writing to displays

    // SEVEN SEGMENT
    int _sega;
    int _segb;
    int _segc;
    int _segd;
    int _sege;
    int _segf;
    int _segg;

    // SIXTEEN SEGMENT
    int _sega1;
    int _sega2;
    int _segd1;
    int _segd2;
    int _segg1;
    int _segg2;
    int _segh;
    int _segi;
    int _segj;
    int _segk;
    int _segl;
    int _segm;

    // SHIFT REGISTER
    int _bitNum;
    int _Data;
    int _Clock;
    int _Latch;
    
    int _segdp;
    int _displays; // Number of displays you have
    char _char;
    String _word;
    bool _cleardisp;
    int _segMode;  // The type of display that you have, see below
    // _segMode states are:
    // 1 - 7 segment straight wired display
    // 2 - 7 segment straight wired display, decimal point
    // 3 - 7 segment shift register display (8-bit shift register so includes decimal point even if your display doesn't have one, you just won't see anything)
    // 4 - 16 segment straight wired display
    // 5 - 16 segment straight wired display, decimal point
    // 6 - 16 segment shift register display (16-bit shift register so you can't use a decimal point with the shift register, it has to be wired to it's own I/O pin)
    // Future possibilities:
    // 7 - 14 segment straight wired display
    // 8 - 14 segment straight wired display, decimal point
    // 9 - 14 segment shift register display (16-bit shift register so includes decimal point and one extra output which isn't used)
    // Dot matrix display?
    bool _cathode;
    int _mode;
    int _semiMode;
    int _delayTime;
    int _Segments;
    static const int _numMatrix[84][8] PROGMEM;
    static const int _16numMatrix[84][16] PROGMEM;
};

#endif

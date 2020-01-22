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
    Segment(int sega, int segb, int segc, int segd, int sege, int segf, int segg, bool cathode = true);
    Segment(int sega, int segb, int segc, int segd, int sege, int segf, int segg, int segdp, bool cathode = true);
    Segment(int Data, int Clock, int Latch, bool cathode = true);
    void display(char charac);
    void clear(int displays = 1);
    void displayString(String word, int displays = 1, bool cleardisp = true);
    void example(int mode, int delayTime, int semiMode = 0);
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
    void _Clocking();
    void _Latching();
    void _Write(int _Numeral);
    int _bitNum;
    int _sega;
    int _segb;
    int _segc;
    int _segd;
    int _sege;
    int _segf;
    int _segg;
    int _segdp;
    int _Data;
    int _Clock;
    int _Latch;
    int _displays;
    char _char;
    String _word;
    bool _cleardisp;
    int _segMode;
    // _segMode states are:
    // 1 - 7 segment straight wired display
    // 2 - 7 segment straight wired display, decimal point
    // 3 - 7 segment shift register display (8-bit shift register so includes decimal point even if your display doesn't have one, you just won't see anything)
    // Future possibilities:
    // 4 - 14 segment straight wired display
    // 5 - 14 segment straight wired display, decimal point
    // 6 - 14 segment shift register display (16-bit shift register so includes decimal point and one extra output which isn't used)
    // 7 - 16 segment straight wired display
    // 8 - 16 segment straight wired display, decimal point
    // 9 - 16 segment shift register display (16-bit shift register so you can't use a decimal point unless it is wired up straight to the arduino board)
    // 10 - Dot matrix display
    bool _cathode;
    int _mode;
    int _semiMode;
    int _delayTime;
    static const int _numMatrix[86][8] PROGMEM;
};

#endif

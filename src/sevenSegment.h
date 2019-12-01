/*
   sevenSegment.h - Library for using 7 segment displays
   7 segment display must be wired up to 7 pins on the arduino, or use a shift register
   Created by Blake Tourneur, October 2, 2018.
   Released into the public domain
*/

#ifndef sevenSegment_h
#define sevenSegment_h

#include "Arduino.h"

class sevenSegment
{
  public:
    sevenSegment(int sega, int segb, int segc, int segd, int sege, int segf, int segg, bool cathode = true);
    sevenSegment(int sega, int segb, int segc, int segd, int sege, int segf, int segg, int segdp, bool cathode = true);
    sevenSegment(int Data, int Clock, int Latch, bool cathode = true);
    void display(char charac);
    void clear(int displays = 1);
    void displayString(String word, int displays = 1, bool cleardisp = true);
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
    static const int _numMatrix[62][8] PROGMEM;
};

#endif

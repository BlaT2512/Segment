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
    sevenSegment(int sega, int segb, int segc, int segd, int sege, int segf, int segg);
    sevenSegment(int Data, int Clock, int Latch);
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
    int _Data;
    int _Clock;
    int _Latch;
    int _displays;
    char _char;
    String _word;
    bool _cleardisp;
    static const int _numMatrix[60][8] PROGMEM;
};

#endif

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
    char _char;
    int _numMatrix[37][8]{
     //segments
     //g,f,e,d,c,b,a,0
      {0,1,1,1,1,1,1,0}, //ZERO
      {0,0,0,0,1,1,0,0}, //ONE
      {1,0,1,1,0,1,1,0}, //TWO
      {1,0,0,1,1,1,1,0}, //THREE
      {1,1,0,0,1,1,0,0}, //FOUR
      {1,1,0,1,1,0,1,0}, //FIVE
      {1,1,1,1,1,0,1,0}, //SIX
      {0,0,0,0,1,1,1,0}, //SEVEN
      {1,1,1,1,1,1,1,0}, //EIGHT
      {1,1,0,1,1,1,1,0}, //NINE
      {1,1,1,0,1,1,1,0}, //LETTER A
      {1,1,1,1,1,0,0,0}, //LETTER B
      {0,1,1,1,0,0,1,0}, //LETTER C
      {1,0,1,1,1,1,0,0}, //LETTER D
      {1,1,1,1,0,0,1,0}, //LETTER E
      {1,1,1,0,0,0,1,0}, //LETTER F
      {0,1,1,1,1,0,1,0}, //LETTER G
      {1,1,1,0,1,0,0,0}, //LETTER H
      {0,1,1,0,0,0,0,0}, //LETTER I
      {0,0,1,1,1,1,0,0}, //LETTER J
      {1,1,1,0,1,0,1,0}, //LETTER K
      {0,1,1,1,0,0,0,0}, //LETTER L
      {0,0,1,0,1,0,1,0}, //LETTER M
      {0,1,1,0,1,1,1,0}, //LETTER N
      {0,1,1,1,1,1,1,0}, //LETTER O
      {1,1,1,0,0,1,1,0}, //LETTER P
      {1,1,0,0,1,1,1,0}, //LETTER Q
      {0,1,1,0,0,1,1,0}, //LETTER R
      {1,1,0,1,1,0,1,0}, //LETTER S
      {1,1,1,1,0,0,0,0}, //LETTER T
      {0,1,1,1,1,1,0,0}, //LETTER U
      {0,1,0,1,1,1,0,0}, //LETTER V
      {0,1,0,1,0,1,0,0}, //LETTER W
      {1,1,1,0,1,1,0,0}, //LETTER X
      {1,1,0,1,1,1,0,0}, //LETTER Y
      {1,0,0,1,0,1,1,0}, //LETTER Z
      {0,0,0,0,0,0,0,0}  //BLANK
    };
};

#endif

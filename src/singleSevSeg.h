/*
   singleSevSeg.h - Library for using a single 7 segment display
   7 segment display must be wired up to 7 pins on the arduino
   Created by Blake Tourneur, October 2, 2018.
   Released into the public domain
*/

#ifndef singleSevSeg_h
#define singleSevSeg_h

#include "Arduino.h"

class singleSevSeg
{
  public:
    singleSevSeg(int sega, int segb, int segc, int segd, int sege, int segf, int segg);
    void ONE();
    void TWO();
    void THREE();
    void FOUR();
    void FIVE();
    void SIX();
    void SEVEN();
    void EIGHT();
    void NINE();
    void ZERO();
    void CLEAR();
  private:
    int _sega;
    int _segb;
    int _segc;
    int _segd;
    int _sege;
    int _segf;
    int _segg;
};

#endif

/*
   singleSevSeg.cpp - Library for using a single 7 segment display
   7 segment display must be wired up to 7 pins on the arduino
   Created by Blake Tourneur, October 2, 2018.
   Released into the public domain
*/

#include "Arduino.h"
#include "singleSevSeg.h"

singleSevSeg::singleSevSeg(int sega, int segb, int segc, int segd, int sege, int segf, int segg)
{
  pinMode(sega, OUTPUT);
  pinMode(segb, OUTPUT);
  pinMode(segc, OUTPUT);
  pinMode(segd, OUTPUT);
  pinMode(sege, OUTPUT);
  pinMode(segf, OUTPUT);
  pinMode(segg, OUTPUT);
  _sega = sega;
  _segb = segb;
  _segc = segc;
  _segd = segd;
  _sege = sege;
  _segf = segf;
  _segg = segg;
}

void singleSevSeg::ZERO()
{
  digitalWrite(_sega, HIGH);
  digitalWrite(_segb, HIGH);
  digitalWrite(_segc, HIGH);
  digitalWrite(_segd, HIGH);
  digitalWrite(_sege, HIGH);
  digitalWrite(_segf, HIGH);
  digitalWrite(_segg, LOW);
}

void singleSevSeg::ONE()
{
  digitalWrite(_sega, LOW);
  digitalWrite(_segb, HIGH);
  digitalWrite(_segc, HIGH);
  digitalWrite(_segd, LOW);
  digitalWrite(_sege, LOW);
  digitalWrite(_segf, LOW);
  digitalWrite(_segg, LOW);
}

void singleSevSeg::TWO()
{
  digitalWrite(_sega, HIGH);
  digitalWrite(_segb, HIGH);
  digitalWrite(_segc, LOW);
  digitalWrite(_segd, HIGH);
  digitalWrite(_sege, HIGH);
  digitalWrite(_segf, LOW);
  digitalWrite(_segg, HIGH);
}

void singleSevSeg::THREE()
{
  digitalWrite(_sega, HIGH);
  digitalWrite(_segb, HIGH);
  digitalWrite(_segc, HIGH);
  digitalWrite(_segd, HIGH);
  digitalWrite(_sege, LOW);
  digitalWrite(_segf, LOW);
  digitalWrite(_segg, HIGH);
}

void singleSevSeg::FOUR()
{
  digitalWrite(_sega, LOW);
  digitalWrite(_segb, HIGH);
  digitalWrite(_segc, HIGH);
  digitalWrite(_segd, LOW);
  digitalWrite(_sege, LOW);
  digitalWrite(_segf, HIGH);
  digitalWrite(_segg, HIGH);
}

void singleSevSeg::FIVE()
{
  digitalWrite(_sega, HIGH);
  digitalWrite(_segb, LOW);
  digitalWrite(_segc, HIGH);
  digitalWrite(_segd, HIGH);
  digitalWrite(_sege, LOW);
  digitalWrite(_segf, HIGH);
  digitalWrite(_segg, HIGH);
}

void singleSevSeg::SIX()
{
  digitalWrite(_sega, HIGH);
  digitalWrite(_segb, LOW);
  digitalWrite(_segc, HIGH);
  digitalWrite(_segd, HIGH);
  digitalWrite(_sege, HIGH);
  digitalWrite(_segf, HIGH);
  digitalWrite(_segg, HIGH);
}

void singleSevSeg::SEVEN()
{
  digitalWrite(_sega, HIGH);
  digitalWrite(_segb, HIGH);
  digitalWrite(_segc, HIGH);
  digitalWrite(_segd, LOW);
  digitalWrite(_sege, LOW);
  digitalWrite(_segf, LOW);
  digitalWrite(_segg, LOW);
}

void singleSevSeg::EIGHT()
{
  digitalWrite(_sega, HIGH);
  digitalWrite(_segb, HIGH);
  digitalWrite(_segc, HIGH);
  digitalWrite(_segd, HIGH);
  digitalWrite(_sege, HIGH);
  digitalWrite(_segf, HIGH);
  digitalWrite(_segg, HIGH);
}

void singleSevSeg::NINE()
{
  digitalWrite(_sega, HIGH);
  digitalWrite(_segb, HIGH);
  digitalWrite(_segc, HIGH);
  digitalWrite(_segd, HIGH);
  digitalWrite(_sege, LOW);
  digitalWrite(_segf, HIGH);
  digitalWrite(_segg, HIGH);
}

void singleSevSeg::CLEAR()
{
  digitalWrite(_sega, LOW);
  digitalWrite(_segb, LOW);
  digitalWrite(_segc, LOW);
  digitalWrite(_segd, LOW);
  digitalWrite(_sege, LOW);
  digitalWrite(_segf, LOW);
  digitalWrite(_segg, LOW);
}

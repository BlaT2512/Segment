/*
   sevenSeg.cpp - Library for using a single 7 segment display
   7 segment display must be wired up to 7 pins on the arduino
   Created by Blake Tourneur, October 2, 2018.
   Released into the public domain
*/

#include "Arduino.h"
#include "sevenSeg.h"

sevenSeg::sevenSeg(int sega, int segb, int segc, int segd, int sege, int segf, int segg)
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

void sevenSeg::ZERO()
{
  digitalWrite(_sega, HIGH);
  digitalWrite(_segb, HIGH);
  digitalWrite(_segc, HIGH);
  digitalWrite(_segd, HIGH);
  digitalWrite(_sege, HIGH);
  digitalWrite(_segf, HIGH);
  digitalWrite(_segg, LOW);
}

void sevenSeg::ONE()
{
  digitalWrite(_sega, LOW);
  digitalWrite(_segb, HIGH);
  digitalWrite(_segc, HIGH);
  digitalWrite(_segd, LOW);
  digitalWrite(_sege, LOW);
  digitalWrite(_segf, LOW);
  digitalWrite(_segg, LOW);
}

void sevenSeg::TWO()
{
  digitalWrite(_sega, HIGH);
  digitalWrite(_segb, HIGH);
  digitalWrite(_segc, LOW);
  digitalWrite(_segd, HIGH);
  digitalWrite(_sege, HIGH);
  digitalWrite(_segf, LOW);
  digitalWrite(_segg, HIGH);
}

void sevenSeg::THREE()
{
  digitalWrite(_sega, HIGH);
  digitalWrite(_segb, HIGH);
  digitalWrite(_segc, HIGH);
  digitalWrite(_segd, HIGH);
  digitalWrite(_sege, LOW);
  digitalWrite(_segf, LOW);
  digitalWrite(_segg, HIGH);
}

void sevenSeg::FOUR()
{
  digitalWrite(_sega, LOW);
  digitalWrite(_segb, HIGH);
  digitalWrite(_segc, HIGH);
  digitalWrite(_segd, LOW);
  digitalWrite(_sege, LOW);
  digitalWrite(_segf, HIGH);
  digitalWrite(_segg, HIGH);
}

void sevenSeg::FIVE()
{
  digitalWrite(_sega, HIGH);
  digitalWrite(_segb, LOW);
  digitalWrite(_segc, HIGH);
  digitalWrite(_segd, HIGH);
  digitalWrite(_sege, LOW);
  digitalWrite(_segf, HIGH);
  digitalWrite(_segg, HIGH);
}

void sevenSeg::SIX()
{
  digitalWrite(_sega, HIGH);
  digitalWrite(_segb, LOW);
  digitalWrite(_segc, HIGH);
  digitalWrite(_segd, HIGH);
  digitalWrite(_sege, HIGH);
  digitalWrite(_segf, HIGH);
  digitalWrite(_segg, HIGH);
}

void sevenSeg::SEVEN()
{
  digitalWrite(_sega, HIGH);
  digitalWrite(_segb, HIGH);
  digitalWrite(_segc, HIGH);
  digitalWrite(_segd, LOW);
  digitalWrite(_sege, LOW);
  digitalWrite(_segf, LOW);
  digitalWrite(_segg, LOW);
}

void sevenSeg::EIGHT()
{
  digitalWrite(_sega, HIGH);
  digitalWrite(_segb, HIGH);
  digitalWrite(_segc, HIGH);
  digitalWrite(_segd, HIGH);
  digitalWrite(_sege, HIGH);
  digitalWrite(_segf, HIGH);
  digitalWrite(_segg, HIGH);
}

void sevenSeg::NINE()
{
  digitalWrite(_sega, HIGH);
  digitalWrite(_segb, HIGH);
  digitalWrite(_segc, HIGH);
  digitalWrite(_segd, HIGH);
  digitalWrite(_sege, LOW);
  digitalWrite(_segf, HIGH);
  digitalWrite(_segg, HIGH);
}

void sevenSeg::CLEAR()
{
  digitalWrite(_sega, LOW);
  digitalWrite(_segb, LOW);
  digitalWrite(_segc, LOW);
  digitalWrite(_segd, LOW);
  digitalWrite(_sege, LOW);
  digitalWrite(_segf, LOW);
  digitalWrite(_segg, LOW);
}
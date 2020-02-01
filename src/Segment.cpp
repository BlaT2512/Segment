/*
   Segment.cpp - Library for using 7/14/16 segment displays
   Display must be wired up to parallel to the Arduino, or using a shift register
   Created by Blake Tourneur, October 2, 2018.
   Released into the public domain
*/

#include "Arduino.h"
#include "Segment.h"
#include "7seg_matrix.h"
#include "16seg_matrix.h"

Segment::Segment(int sega, int segb, int segc, int segd, int sege, int segf, int segg, bool cathode){ // 7seg, no dp
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
  _segMode = 1;
  _cathode = cathode;
}

Segment::Segment(int sega, int segb, int segc, int segd, int sege, int segf, int segg, int segdp, bool cathode){ // 7seg, dp
  pinMode(sega, OUTPUT);
  pinMode(segb, OUTPUT);
  pinMode(segc, OUTPUT);
  pinMode(segd, OUTPUT);
  pinMode(sege, OUTPUT);
  pinMode(segf, OUTPUT);
  pinMode(segg, OUTPUT);
  pinMode(segdp, OUTPUT);
  _sega = sega;
  _segb = segb;
  _segc = segc;
  _segd = segd;
  _sege = sege;
  _segf = segf;
  _segg = segg;
  _segdp = segdp;
  _segMode = 2;
  _cathode = cathode;
}

Segment::Segment(int sega1, int sega2, int segb, int segc, int segd1, int segd2, int sege, int segf, int segg1, int segg2, int segh, int segi, int segj, int segk, int segl, int segm, bool cathode = true){  // 16seg, no dp
  pinMode(sega1, OUTPUT);
  pinMode(sega2, OUTPUT);
  pinMode(segb, OUTPUT);
  pinMode(segc, OUTPUT);
  pinMode(segd1, OUTPUT);
  pinMode(segd2, OUTPUT);
  pinMode(sege, OUTPUT);
  pinMode(segf, OUTPUT);
  pinMode(segg1, OUTPUT);
  pinMode(segg2, OUTPUT);
  pinMode(segh, OUTPUT);
  pinMode(segi, OUTPUT);
  pinMode(segj, OUTPUT);
  pinMode(segk, OUTPUT);
  pinMode(segl, OUTPUT);
  pinMode(segm, OUTPUT);
  _sega1 = sega1;
  _sega2 = sega2;
  _segb = segb;
  _segc = segc;
  _segd1 = segd1;
  _segd2 = segd2;
  _sege = sege;
  _segf = segf;
  _segg1 = segg1;
  _segg2 = segg2;
  _segh = segh;
  _segi = segi;
  _segj = segj;
  _segk = segk;
  _segl = segl;
  _segm = segm;
  _segMode = 4;
  _cathode = cathode;
}

Segment::Segment(int sega1, int sega2, int segb, int segc, int segd1, int segd2, int sege, int segf, int segg1, int segg2, int segh, int segi, int segj, int segk, int segl, int segm, int segdp, bool cathode = true){  // 16seg, dp
  pinMode(sega1, OUTPUT);
  pinMode(sega2, OUTPUT);
  pinMode(segb, OUTPUT);
  pinMode(segc, OUTPUT);
  pinMode(segd1, OUTPUT);
  pinMode(segd2, OUTPUT);
  pinMode(sege, OUTPUT);
  pinMode(segf, OUTPUT);
  pinMode(segg1, OUTPUT);
  pinMode(segg2, OUTPUT);
  pinMode(segh, OUTPUT);
  pinMode(segi, OUTPUT);
  pinMode(segj, OUTPUT);
  pinMode(segk, OUTPUT);
  pinMode(segl, OUTPUT);
  pinMode(segm, OUTPUT);
  pinMode(segdp, OUTPUT);
  _sega1 = sega1;
  _sega2 = sega2;
  _segb = segb;
  _segc = segc;
  _segd1 = segd1;
  _segd2 = segd2;
  _sege = sege;
  _segf = segf;
  _segg1 = segg1;
  _segg2 = segg2;
  _segh = segh;
  _segi = segi;
  _segj = segj;
  _segk = segk;
  _segl = segl;
  _segm = segm;
  _segdp = segdp;
  _segMode = 5;
  _cathode = cathode;
}

Segment::Segment(int Data, int Clock, int Latch, int segdp, int Segments, bool cathode){ // Shift register display
  pinMode(Data, OUTPUT);
  pinMode(Clock, OUTPUT);
  pinMode(Latch, OUTPUT);
  _Data = Data;
  _Clock = Clock;
  _Latch = Latch;
  if (segdp > -1 && Segments == 16){  // If you are using a seperate decimal point pin for a 16-segment display
    _segdp = segdp;
  }
  else {
    _segdp = -1;
  }
  // Determine the segmode
  if (Segments == 7){
    _segMode = 3;
  }
  else if (Segments == 16){
    _segMode = 6;
  }
  _cathode = cathode;
}

void Segment::_Clocking(){
  digitalWrite(_Clock,1);
  delay(1);
  digitalWrite(_Clock,0);
}

void Segment::_Latching(){
  digitalWrite(_Latch,1);
  delay(1);
  digitalWrite(_Latch,0);
}

void Segment::_Write(int _Numeral){
  if (_segMode == 3 && _cathode) {
    for (_bitNum = 0;_bitNum < 8;_bitNum++){
      digitalWrite(_Data,pgm_read_word_near(_numMatrix[_Numeral] + _bitNum));
      _Clocking();
    }
    _Latching();
  }
  else if (_segMode == 3 && !_cathode) {
    for (_bitNum = 0;_bitNum < 8;_bitNum++){
      digitalWrite(_Data,!pgm_read_word_near(_numMatrix[_Numeral] + _bitNum));
      _Clocking();
    }
    _Latching();
  }
  if (_segMode == 6 && _cathode) {
    for (_bitNum = 0;_bitNum < 16;_bitNum++){
      digitalWrite(_Data,pgm_read_word_near(_numMatrix[_Numeral] + _bitNum));
      _Clocking();
    }
    _Latching();

    if (_segdp > -1){
      if (_Numeral == 60 || _Numeral == 61){
        digitalWrite(_segdp,1); // Decimal point ON
      }
      else {
        digitalWrite(_segdp,0); // Decimal point OFF
      }
    }
  }
  else if (_segMode == 6 && !_cathode) {
    for (_bitNum = 0;_bitNum < 16;_bitNum++){
      digitalWrite(_Data,!pgm_read_word_near(_numMatrix[_Numeral] + _bitNum));
      _Clocking();
    }
    _Latching();

    if (_segdp > -1){
      if (_Numeral == 60 || _Numeral == 61){
        digitalWrite(_segdp,0); // Decimal point ON
      }
      else {
        digitalWrite(_segdp,1); // Decimal point OFF
      }
    }
  }
  else if (_segMode == 1 && _cathode) {
    digitalWrite(_segg,pgm_read_word_near(_numMatrix[_Numeral] + 0));
    digitalWrite(_segf,pgm_read_word_near(_numMatrix[_Numeral] + 1));
    digitalWrite(_sege,pgm_read_word_near(_numMatrix[_Numeral] + 2));
    digitalWrite(_segd,pgm_read_word_near(_numMatrix[_Numeral] + 3));
    digitalWrite(_segc,pgm_read_word_near(_numMatrix[_Numeral] + 4));
    digitalWrite(_segb,pgm_read_word_near(_numMatrix[_Numeral] + 5));
    digitalWrite(_sega,pgm_read_word_near(_numMatrix[_Numeral] + 6));
  }
  else if (_segMode == 1 && !_cathode) {
    digitalWrite(_segg,!pgm_read_word_near(_numMatrix[_Numeral] + 0));
    digitalWrite(_segf,!pgm_read_word_near(_numMatrix[_Numeral] + 1));
    digitalWrite(_sege,!pgm_read_word_near(_numMatrix[_Numeral] + 2));
    digitalWrite(_segd,!pgm_read_word_near(_numMatrix[_Numeral] + 3));
    digitalWrite(_segc,!pgm_read_word_near(_numMatrix[_Numeral] + 4));
    digitalWrite(_segb,!pgm_read_word_near(_numMatrix[_Numeral] + 5));
    digitalWrite(_sega,!pgm_read_word_near(_numMatrix[_Numeral] + 6));
  }
  else if (_segMode == 2 && _cathode) {
    digitalWrite(_segg,pgm_read_word_near(_numMatrix[_Numeral] + 0));
    digitalWrite(_segf,pgm_read_word_near(_numMatrix[_Numeral] + 1));
    digitalWrite(_sege,pgm_read_word_near(_numMatrix[_Numeral] + 2));
    digitalWrite(_segd,pgm_read_word_near(_numMatrix[_Numeral] + 3));
    digitalWrite(_segc,pgm_read_word_near(_numMatrix[_Numeral] + 4));
    digitalWrite(_segb,pgm_read_word_near(_numMatrix[_Numeral] + 5));
    digitalWrite(_sega,pgm_read_word_near(_numMatrix[_Numeral] + 6));
    digitalWrite(_segdp,pgm_read_word_near(_numMatrix[_Numeral] + 7));
  }
  else if (_segMode == 2 && !_cathode) {
    digitalWrite(_segg,!pgm_read_word_near(_numMatrix[_Numeral] + 0));
    digitalWrite(_segf,!pgm_read_word_near(_numMatrix[_Numeral] + 1));
    digitalWrite(_sege,!pgm_read_word_near(_numMatrix[_Numeral] + 2));
    digitalWrite(_segd,!pgm_read_word_near(_numMatrix[_Numeral] + 3));
    digitalWrite(_segc,!pgm_read_word_near(_numMatrix[_Numeral] + 4));
    digitalWrite(_segb,!pgm_read_word_near(_numMatrix[_Numeral] + 5));
    digitalWrite(_sega,!pgm_read_word_near(_numMatrix[_Numeral] + 6));
    digitalWrite(_segdp,!pgm_read_word_near(_numMatrix[_Numeral] + 7));
  }
  else if (_segMode == 4 && _cathode) {
    digitalWrite(_segm,pgm_read_word_near(_16numMatrix[_Numeral] + 0));
    digitalWrite(_segl,pgm_read_word_near(_16numMatrix[_Numeral] + 1));
    digitalWrite(_segk,pgm_read_word_near(_16numMatrix[_Numeral] + 2));
    digitalWrite(_segj,pgm_read_word_near(_16numMatrix[_Numeral] + 3));
    digitalWrite(_segi,pgm_read_word_near(_16numMatrix[_Numeral] + 4));
    digitalWrite(_segh,pgm_read_word_near(_16numMatrix[_Numeral] + 5));
    digitalWrite(_segg1,pgm_read_word_near(_16numMatrix[_Numeral] + 6));
    digitalWrite(_segg1,pgm_read_word_near(_16numMatrix[_Numeral] + 7));
    digitalWrite(_segf,pgm_read_word_near(_16numMatrix[_Numeral] + 8));
    digitalWrite(_sege,pgm_read_word_near(_16numMatrix[_Numeral] + 9));
    digitalWrite(_segd2,pgm_read_word_near(_16numMatrix[_Numeral] + 10));
    digitalWrite(_segd1,pgm_read_word_near(_16numMatrix[_Numeral] + 11));
    digitalWrite(_segc,pgm_read_word_near(_16numMatrix[_Numeral] + 12));
    digitalWrite(_segb,pgm_read_word_near(_16numMatrix[_Numeral] + 13));
    digitalWrite(_sega2,pgm_read_word_near(_16numMatrix[_Numeral] + 14));
    digitalWrite(_sega1,pgm_read_word_near(_16numMatrix[_Numeral] + 15));
  }
  else if (_segMode == 4 && !_cathode) {
    digitalWrite(_segm,!pgm_read_word_near(_16numMatrix[_Numeral] + 0));
    digitalWrite(_segl,!pgm_read_word_near(_16numMatrix[_Numeral] + 1));
    digitalWrite(_segk,!pgm_read_word_near(_16numMatrix[_Numeral] + 2));
    digitalWrite(_segj,!pgm_read_word_near(_16numMatrix[_Numeral] + 3));
    digitalWrite(_segi,!pgm_read_word_near(_16numMatrix[_Numeral] + 4));
    digitalWrite(_segh,!pgm_read_word_near(_16numMatrix[_Numeral] + 5));
    digitalWrite(_segg1,!pgm_read_word_near(_16numMatrix[_Numeral] + 6));
    digitalWrite(_segg1,!pgm_read_word_near(_16numMatrix[_Numeral] + 7));
    digitalWrite(_segf,!pgm_read_word_near(_16numMatrix[_Numeral] + 8));
    digitalWrite(_sege,!pgm_read_word_near(_16numMatrix[_Numeral] + 9));
    digitalWrite(_segd2,!pgm_read_word_near(_16numMatrix[_Numeral] + 10));
    digitalWrite(_segd1,!pgm_read_word_near(_16numMatrix[_Numeral] + 11));
    digitalWrite(_segc,!pgm_read_word_near(_16numMatrix[_Numeral] + 12));
    digitalWrite(_segb,!pgm_read_word_near(_16numMatrix[_Numeral] + 13));
    digitalWrite(_sega2,!pgm_read_word_near(_16numMatrix[_Numeral] + 14));
    digitalWrite(_sega1,!pgm_read_word_near(_16numMatrix[_Numeral] + 15));
  }
  else if (_segMode == 5 && _cathode) {
    digitalWrite(_segm,pgm_read_word_near(_16numMatrix[_Numeral] + 0));
    digitalWrite(_segl,pgm_read_word_near(_16numMatrix[_Numeral] + 1));
    digitalWrite(_segk,pgm_read_word_near(_16numMatrix[_Numeral] + 2));
    digitalWrite(_segj,pgm_read_word_near(_16numMatrix[_Numeral] + 3));
    digitalWrite(_segi,pgm_read_word_near(_16numMatrix[_Numeral] + 4));
    digitalWrite(_segh,pgm_read_word_near(_16numMatrix[_Numeral] + 5));
    digitalWrite(_segg1,pgm_read_word_near(_16numMatrix[_Numeral] + 6));
    digitalWrite(_segg1,pgm_read_word_near(_16numMatrix[_Numeral] + 7));
    digitalWrite(_segf,pgm_read_word_near(_16numMatrix[_Numeral] + 8));
    digitalWrite(_sege,pgm_read_word_near(_16numMatrix[_Numeral] + 9));
    digitalWrite(_segd2,pgm_read_word_near(_16numMatrix[_Numeral] + 10));
    digitalWrite(_segd1,pgm_read_word_near(_16numMatrix[_Numeral] + 11));
    digitalWrite(_segc,pgm_read_word_near(_16numMatrix[_Numeral] + 12));
    digitalWrite(_segb,pgm_read_word_near(_16numMatrix[_Numeral] + 13));
    digitalWrite(_sega2,pgm_read_word_near(_16numMatrix[_Numeral] + 14));
    digitalWrite(_sega1,pgm_read_word_near(_16numMatrix[_Numeral] + 15));
    if (_segdp > -1){
      if (_Numeral == 60 || _Numeral == 61){
        digitalWrite(_segdp,1); // Decimal point ON
      }
      else {
        digitalWrite(_segdp,0); // Decimal point OFF
      }
    }
  }
  else if (_segMode == 5 && !_cathode) {
    digitalWrite(_segm,!pgm_read_word_near(_16numMatrix[_Numeral] + 0));
    digitalWrite(_segl,!pgm_read_word_near(_16numMatrix[_Numeral] + 1));
    digitalWrite(_segk,!pgm_read_word_near(_16numMatrix[_Numeral] + 2));
    digitalWrite(_segj,!pgm_read_word_near(_16numMatrix[_Numeral] + 3));
    digitalWrite(_segi,!pgm_read_word_near(_16numMatrix[_Numeral] + 4));
    digitalWrite(_segh,!pgm_read_word_near(_16numMatrix[_Numeral] + 5));
    digitalWrite(_segg1,!pgm_read_word_near(_16numMatrix[_Numeral] + 6));
    digitalWrite(_segg1,!pgm_read_word_near(_16numMatrix[_Numeral] + 7));
    digitalWrite(_segf,!pgm_read_word_near(_16numMatrix[_Numeral] + 8));
    digitalWrite(_sege,!pgm_read_word_near(_16numMatrix[_Numeral] + 9));
    digitalWrite(_segd2,!pgm_read_word_near(_16numMatrix[_Numeral] + 10));
    digitalWrite(_segd1,!pgm_read_word_near(_16numMatrix[_Numeral] + 11));
    digitalWrite(_segc,!pgm_read_word_near(_16numMatrix[_Numeral] + 12));
    digitalWrite(_segb,!pgm_read_word_near(_16numMatrix[_Numeral] + 13));
    digitalWrite(_sega2,!pgm_read_word_near(_16numMatrix[_Numeral] + 14));
    digitalWrite(_sega1,!pgm_read_word_near(_16numMatrix[_Numeral] + 15));
    if (_segdp > -1){
      if (_Numeral == 60 || _Numeral == 61){
        digitalWrite(_segdp,0); // Decimal point ON
      }
      else {
        digitalWrite(_segdp,1); // Decimal point OFF
      }
    }
  }
}

void Segment::display(char charac){
  _char = charac;
  if (_char == '0') _Write(0);
  else if (_char == '1') _Write(1);
  else if (_char == '2') _Write(2);
  else if (_char == '3') _Write(3);
  else if (_char == '4') _Write(4);
  else if (_char == '5') _Write(5);
  else if (_char == '6') _Write(6);
  else if (_char == '7') _Write(7);
  else if (_char == '8') _Write(8);
  else if (_char == '9') _Write(9);
  else if (_char == 'A' || _char == 'a') _Write(10);
  else if (_char == 'B' || _char == 'b') _Write(11);
  else if (_char == 'C' || _char == 'c') _Write(12);
  else if (_char == 'D' || _char == 'd') _Write(13);
  else if (_char == 'E' || _char == 'e') _Write(14);
  else if (_char == 'F' || _char == 'f') _Write(15);
  else if (_char == 'G' || _char == 'g') _Write(16);
  else if (_char == 'H' || _char == 'h') _Write(17);
  else if (_char == 'I' || _char == 'i') _Write(18);
  else if (_char == 'J' || _char == 'j') _Write(19);
  else if (_char == 'K' || _char == 'k') _Write(20);
  else if (_char == 'L' || _char == 'l') _Write(21);
  else if (_char == 'M' || _char == 'm') _Write(22);
  else if (_char == 'N' || _char == 'n') _Write(23);
  else if (_char == 'O' || _char == 'o') _Write(24);
  else if (_char == 'P' || _char == 'p') _Write(25);
  else if (_char == 'Q' || _char == 'q') _Write(26);
  else if (_char == 'R' || _char == 'r') _Write(27);
  else if (_char == 'S' || _char == 's') _Write(28);
  else if (_char == 'T' || _char == 't') _Write(29);
  else if (_char == 'U' || _char == 'u') _Write(30);
  else if (_char == 'V' || _char == 'v') _Write(31);
  else if (_char == 'W' || _char == 'w') _Write(32);
  else if (_char == 'X' || _char == 'x') _Write(33);
  else if (_char == 'Y' || _char == 'y') _Write(34);
  else if (_char == 'Z' || _char == 'z') _Write(35);
  else if (_char == ' ') _Write(36);
  else if (_char == '"') _Write(37);
  else if (_char == '#') _Write(38);
  else if (_char == '$') _Write(39);
  else if (_char == '%') _Write(40);
  else if (_char == '&') _Write(41);
  else if (_char == '\'' || _char == '`') _Write(42);
  else if (_char == '(' || _char == '[' || _char == '{') _Write(43);
  else if (_char == ')' || _char == ']' || _char == '}') _Write(44);
  else if (_char == '*') _Write(45);
  else if (_char == '+') _Write(46);
  else if (_char == ',') _Write(47);
  else if (_char == '-' || _char == '~') _Write(48);
  else if (_char == '/') _Write(49);
  else if (_char == ':') _Write(50);
  else if (_char == ';') _Write(51);
  else if (_char == '<') _Write(52);
  else if (_char == '=') _Write(53);
  else if (_char == '>') _Write(54);
  else if (_char == '?') _Write(55);
  else if (_char == '@') _Write(56);
  else if (_char == '\\') _Write(57);
  else if (_char == '^') _Write(58);
  else if (_char == '_') _Write(59);
  else if (_char == '!' && _segMode != 1 && _segMode != 4) _Write(60); // Your display has to have a decimal point to display this character
  else if (_char == '.' && _segMode != 1 && _segMode != 4) _Write(61); // Your display has to have a decimal point to display this character
}

void Segment::clear(int displays){
  _displays = displays;
  for (int i = 1; i <= _displays; i++) {
    display(' ');
    delay(10);
  }
  delay(100);
}

void Segment::example(int mode, int delayTime, int semiMode){
  _mode = mode;
  _delayTime = delayTime;
  _semiMode = semiMode;
  // See Segment.h lines 83-96 for what the different modes are
  if (_mode == 1){
    if (_semiMode == 1){
      for (int i = 0; i <= 9; i++) { // NUMBERS
        _Write(i);
        delay(_delayTime);
      }
    }
    else if (_semiMode == 2){
      for (char i = 'A'; i <= 'Z'; i++) { // ALPHABET
        display(i);
        delay(_delayTime);
      }
    }
    else if (_semiMode == 3){
      for (int i = 0; i <= 9; i++) { // NUMBERS
        _Write(i);
        delay(_delayTime);
      }
      for (char i = 'A'; i <= 'Z'; i++) { // ALPHABET
        display(i);
        delay(_delayTime);
      }
    }
    else if (_semiMode == 4){
      for (int i = 0; i <= 9; i++) { // NUMBERS
        _Write(i);
        delay(_delayTime);
      }
      for (int i = 36; i <= 59; i++) { // PUNCTUATION - ! and . are not displayed incase display does not have a decimal point
        _Write(i);
        delay(_delayTime);
      }
    }
    else if (_semiMode == 5){
      for (char i = 'A'; i <= 'Z'; i++) { // ALPHABET
        display(i);
        delay(_delayTime);
      }
      for (int i = 36; i <= 59; i++) { // PUNCTUATION
        _Write(i);
        delay(_delayTime);
      }
    }
    else if (_semiMode == 6){
      for (int i = 0; i <= 9; i++) { // NUMBERS
        _Write(i);
        delay(_delayTime);
      }
      for (char i = 'A'; i <= 'Z'; i++) { // ALPHABET
        display(i);
        delay(_delayTime);
      }
      for (int i = 36; i <= 59; i++) { // PUNCTUATION
        _Write(i);
        delay(_delayTime);
      }
    }
  }

  else if (_mode == -1){
    if (_semiMode == 1){
      for (int i = 9; i >= 0; i--) { // NUMBERS
        _Write(i);
        delay(_delayTime);
      }
    }
    else if (_semiMode == 2){
      for (char i = 'Z'; i >= 'A'; i--) { // ALPHABET
        display(i);
        delay(_delayTime);
      }
    }
    else if (_semiMode == 3){
      for (int i = 9; i >= 0; i--) { // NUMBERS
        _Write(i);
        delay(_delayTime);
      }
      for (char i = 'Z'; i >= 'A'; i--) { // ALPHABET
        display(i);
        delay(_delayTime);
      }
    }
    else if (_semiMode == 4){
      for (int i = 9; i >= 0; i--) { // NUMBERS
        _Write(i);
        delay(_delayTime);
      }
      for (int i = 59; i >= 36; i--) { // PUNCTUATION
        _Write(i);
        delay(_delayTime);
      }
    }
    else if (_semiMode == 5){
      for (char i = 'Z'; i >= 'A'; i--) { // ALPHABET
        display(i);
        delay(_delayTime);
      }
      for (int i = 59; i >= 36; i--) { // PUNCTUATION
        _Write(i);
        delay(_delayTime);
      }
    }
    else if (_semiMode == 6){
      for (int i = 9; i >= 0; i--) { // NUMBERS
        _Write(i);
        delay(_delayTime);
      }
      for (char i = 'Z'; i >= 'A'; i--) { // ALPHABET
        display(i);
        delay(_delayTime);
      }
      for (int i = 59; i >= 36; i--) { // PUNCTUATION
        _Write(i);
        delay(_delayTime);
      }
    }
  }

  else if (_mode == 2){
    for (int i = 62; i <= 67; i++) {
      _Write(i);
      delay(_delayTime);
    }
    _Write(62);
    delay(_delayTime);
  }

  else if (_mode == -2){
    _Write(62);
    delay(_delayTime);
    for (int i = 67; i >= 62; i--) {
      _Write(i);
      delay(_delayTime);
    }
  }

  else if (_mode == 3){
    for (int i = 71; i <= 76; i++) {
      _Write(i);
      delay(_delayTime);
    }
    _Write(71);
    delay(_delayTime);
  }

  else if (_mode == -3){
    _Write(71);
    delay(_delayTime);
    for (int i = 76; i >= 71; i--) {
      _Write(i);
      delay(_delayTime);
    }
  }

  else if (_mode == 4){
    _Write(65);
    delay(_delayTime);
    _Write(69);
    delay(_delayTime);
    _Write(68);
    delay(_delayTime);
    _Write(70);
    delay(_delayTime);
    _Write(62);
    delay(_delayTime);
  }

  else if (_mode == -4){
    _Write(62);
    delay(_delayTime);
    _Write(70);
    delay(_delayTime);
    _Write(68);
    delay(_delayTime);
    _Write(69);
    delay(_delayTime);
    _Write(65);
    delay(_delayTime);
  }

  else if (_mode == 5){
    _Write(62);
    delay(_delayTime);
    _Write(63);
    delay(_delayTime);
    _Write(68);
    delay(_delayTime);
    _Write(66);
    delay(_delayTime);
    _Write(65);
    delay(_delayTime);
    _Write(64);
    delay(_delayTime);
    _Write(68);
    delay(_delayTime);
    _Write(67);
    delay(_delayTime);
    _Write(62);
    delay(_delayTime);
  }

  else if (_mode == -5){
    _Write(62);
    delay(_delayTime);
    _Write(67);
    delay(_delayTime);
    _Write(68);
    delay(_delayTime);
    _Write(64);
    delay(_delayTime);
    _Write(65);
    delay(_delayTime);
    _Write(66);
    delay(_delayTime);
    _Write(68);
    delay(_delayTime);
    _Write(63);
    delay(_delayTime);
    _Write(62);
    delay(_delayTime);
  }

  else if (_mode == 6){
    clear();
    delay(_delayTime);
    _Write(62);
    delay(_delayTime);
    for (int i = 78; i <= 83; i++) {
      _Write(i);
      delay(_delayTime);
    }
  }

  else if (_mode == -6){
    for (int i = 83; i >= 78; i--) {
      _Write(i);
      delay(_delayTime);
    }
    _Write(62);
    delay(_delayTime);
    clear();
    delay(_delayTime);
  }
}

void Segment::displayString(String word, int displays, bool cleardisp){
  _displays = displays;
  _word = word;
  _cleardisp = cleardisp;

  // CLEAR THE DISPLAYS IF NEEDED
  if (_cleardisp){
      clear(_displays);
      delay(100);
  }

  // DETERMINE WHETHER THE STRING NEEDS TO BE SCROLLED
  if (_word.length() <= _displays){
      // STRING DOESN'T NEED TO BE SCROLLED
      for (int i = 0; i <= _word.length() - 1; i++) {
        display(_word.charAt(i));
        delay(10);
      }
  }
  else {
      // STRING NEEDS TO BE SCROLLED
      for (int i = 0; i <= _word.length() - 1; i++) {
        display(_word.charAt(i));
        delay(1000);
        //if (Serial.available()) break;
        
        if (i >= _word.length() - 1){ // If this is the last character
          delay(1000);
          //if (Serial.available()) break;
          delay(1000);
          //if (Serial.available()) break;
          delay(1000);
          //if (Serial.available()) break;
          clear();
          delay(1000);
          i = -1; // Start the cycle again on -1, as 1 will get added when it starts again making the variable 0
        }
        
        //if (Serial.available()) break;
      }
  }
}
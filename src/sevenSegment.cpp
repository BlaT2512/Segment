/*
   sevenSegment.cpp - Library for using 7 segment displays
   7 segment display must be wired up to 7 pins on the arduino, or use a shift register
   Created by Blake Tourneur, October 2, 2018.
   Released into the public domain
*/

#include "Arduino.h"
#include "sevenSegment.h"

sevenSegment::sevenSegment(int sega, int segb, int segc, int segd, int sege, int segf, int segg){
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

sevenSegment::sevenSegment(int Data, int Clock, int Latch){
  pinMode(Data, OUTPUT);
  pinMode(Clock, OUTPUT);
  pinMode(Latch, OUTPUT);
  _Data = Data;
  _Clock = Clock;
  _Latch = Latch;
}

void sevenSegment::_Clocking(){
  digitalWrite(_Clock,1);
  delay(1);
  digitalWrite(_Clock,0);
}

void sevenSegment::_Latching(){
  digitalWrite(_Latch,1);
  delay(1);
  digitalWrite(_Latch,0);
}

void sevenSegment::_Write(int _Numeral){
  for (_bitNum = 0;_bitNum < 8;_bitNum++){
    digitalWrite(_Data,_numMatrix[_Numeral][_bitNum]);
    _Clocking();
  }
  _Latching();
}

void sevenSegment::display(char charac){
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
}

void sevenSegment::clear(int displays){
  _displays = displays;
  for (int i = 1; i <= _displays; i++) {
    display(' ');
    delay(10);
  }
}

void sevenSegment::displayString(String word, int displays, bool cleardisp){
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
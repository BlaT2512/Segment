/*
   sevenSegment.cpp - Library for using 7 segment displays
   7 segment display must be wired up to 7 pins on the arduino, or use a shift register
   Created by Blake Tourneur, October 2, 2018.
   Released into the public domain
*/

#include "Arduino.h"
#include "sevenSegment.h"

const int sevenSegment::_numMatrix[62][8] PROGMEM {
     //segments
     //g,f,e,d,c,b,a,dp
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
      {0,0,0,0,0,0,0,0}, //BLANK
      {0,1,0,0,0,1,0,0}, //CHARACTER "
      {0,1,1,0,1,1,0,0}, //CHARACTER #
      {1,1,0,1,0,0,1,0}, //CHARACTER $
      {0,1,0,1,1,0,1,0}, //CHARACTER %
      {1,1,1,1,0,1,1,0}, //CHARACTER &
      {0,0,0,0,0,1,0,0}, //CHARACTER ' `
      {0,1,1,1,0,0,1,0}, //CHARACTER ( [ {
      {0,0,0,1,1,1,1,0}, //CHARACTER ) ] }
      {1,1,0,0,0,1,1,0}, //CHARACTER *
      {1,1,1,0,0,0,0,0}, //CHARACTER +
      {0,0,0,1,1,0,0,0}, //CHARACTER ,
      {1,0,0,0,0,0,0,0}, //CHARACTER - ~
      {1,0,0,0,0,1,0,0}, //CHARACTER /
      {1,0,0,1,0,0,0,0}, //CHARACTER :
      {1,0,0,1,1,0,0,0}, //CHARACTER ;
      {1,1,0,0,0,0,1,0}, //CHARACTER <
      {1,0,0,0,0,0,1,0}, //CHARACTER =
      {1,0,0,0,0,1,1,0}, //CHARACTER >
      {1,0,1,0,0,1,1,0}, //CHARACTER ?
      {1,0,1,1,1,1,1,0}, //CHARACTER @
      {1,1,0,0,0,0,0,0}, //CHARACTER (back slash)
      {0,1,0,0,0,1,1,0}, //CHARACTER ^
      {0,0,0,1,0,0,0,0}, //CHARACTER _
      {0,0,0,0,0,1,0,1}, //CHARACTER !
      {0,0,0,0,0,0,0,1}  //CHARACTER .
};

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
  _segMode = 1;
}

sevenSegment::sevenSegment(int sega, int segb, int segc, int segd, int sege, int segf, int segg, int segdp){
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
}

sevenSegment::sevenSegment(int Data, int Clock, int Latch){
  pinMode(Data, OUTPUT);
  pinMode(Clock, OUTPUT);
  pinMode(Latch, OUTPUT);
  _Data = Data;
  _Clock = Clock;
  _Latch = Latch;
  _segMode = 3;
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
  if (_segMode == 3) {
    for (_bitNum = 0;_bitNum < 8;_bitNum++){
      digitalWrite(_Data,pgm_read_word_near(_numMatrix[_Numeral] + _bitNum));
      _Clocking();
    }
    _Latching();
  }
  else if (_segMode == 1) {
    digitalWrite(_segg,pgm_read_word_near(_numMatrix[_Numeral] + 0));
    digitalWrite(_segf,pgm_read_word_near(_numMatrix[_Numeral] + 1));
    digitalWrite(_sege,pgm_read_word_near(_numMatrix[_Numeral] + 2));
    digitalWrite(_segd,pgm_read_word_near(_numMatrix[_Numeral] + 3));
    digitalWrite(_segc,pgm_read_word_near(_numMatrix[_Numeral] + 4));
    digitalWrite(_segb,pgm_read_word_near(_numMatrix[_Numeral] + 5));
    digitalWrite(_sega,pgm_read_word_near(_numMatrix[_Numeral] + 6));
  }
  else if (_segMode == 2) {
    digitalWrite(_segg,pgm_read_word_near(_numMatrix[_Numeral] + 0));
    digitalWrite(_segf,pgm_read_word_near(_numMatrix[_Numeral] + 1));
    digitalWrite(_sege,pgm_read_word_near(_numMatrix[_Numeral] + 2));
    digitalWrite(_segd,pgm_read_word_near(_numMatrix[_Numeral] + 3));
    digitalWrite(_segc,pgm_read_word_near(_numMatrix[_Numeral] + 4));
    digitalWrite(_segb,pgm_read_word_near(_numMatrix[_Numeral] + 5));
    digitalWrite(_sega,pgm_read_word_near(_numMatrix[_Numeral] + 6));
    digitalWrite(_segdp,pgm_read_word_near(_numMatrix[_Numeral] + 7));
  }
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
  else if (_char == '!' && _segMode > 1) _Write(60); // Your display has to have a decimal point to display this character
  else if (_char == '.' && _segMode > 1) _Write(61); // Your display has to have a decimal point to display this character
}

void sevenSegment::clear(int displays){
  _displays = displays;
  for (int i = 1; i <= _displays; i++) {
    display(' ');
    delay(10);
  }
  delay(100);
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
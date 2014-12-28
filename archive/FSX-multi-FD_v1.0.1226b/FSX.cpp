/*
FSX.cpp - Library for interfacting with FSX2multi program. (Flight Sim Data)
Created by Patrick Castro, December 26, 2014.
Released into the public domain.
*/

#include "Arduino.h"
#include "FSX.h"


FSX::FSX()
{
  
}

Display::Display()
{
  
}

char FSX::getChar()
{
  while(Serial.available() == 0);
  return((char)Serial.read());
}

void FSX::EQUALS()
{
  // COMM1 Frequency - The following section of code grabs the serial data with tag "=A" and stores each individual digit as an integer.                                                     */
  switch(CodeIn){case 'A': String com1_1, com1_2, com1_3, com1_4, com1_5, com1_dp; com1_1 = ""; com1_1 += getChar(); hunds_2 = com1_1.toInt(); com1_2 = ""; com1_2 += getChar(); tens_2 = com1_2.toInt(); com1_3 = ""; com1_3 += getChar(); ones_2 = com1_3.toInt(); com1_dp = ""; com1_dp += getChar(); com1_4 = ""; com1_4 += getChar(); tenth_2 = com1_4.toInt(); com1_5 = ""; com1_5 += getChar(); hundth_2 = com1_5.toInt(); String com1_string = ""; com1_string += com1_1; com1_string += com1_2; com1_string += com1_3; com1_string += com1_4; com1_string += com1_5; com1_int = com1_string.toInt(); break;} //End of "COM1 Standby" function
  
  // COMM1 Standby - The following section of code grabs the serial data with tag "=B" and stores each individual digit as an integer.                                                     */
  switch(CodeIn){case 'B': String com1sb_1, com1sb_2, com1sb_3, com1sb_4, com1sb_5, com1sb_dp; com1sb_1 = ""; com1sb_1 += getChar(); hunds_2 = com1sb_1.toInt(); com1sb_2 = ""; com1sb_2 += getChar(); tens_2 = com1sb_2.toInt(); com1sb_3 = ""; com1sb_3 += getChar(); ones_2 = com1sb_3.toInt(); com1sb_dp = ""; com1sb_dp += getChar(); com1sb_4 = ""; com1sb_4 += getChar(); tenth_2 = com1sb_4.toInt(); com1sb_5 = ""; com1sb_5 += getChar(); hundth_2 = com1sb_5.toInt(); String com1sb_string = ""; com1sb_string += com1sb_1; com1sb_string += com1sb_2; com1sb_string += com1sb_3; com1sb_string += com1sb_4; com1sb_string += com1sb_5; com1sb_int = com1sb_string.toInt(); break;} //End of "COM1 Standby" function
  
  // NAV1 Frequency - The following section of code grabs the serial data with tag "=E" and stores each individual digit as an integer.
  switch(CodeIn){case 'E': String nav1_1, nav1_2, nav1_3, nav1_4, nav1_5, nav1_dp; nav1_1 = ""; nav1_1 += getChar(); hunds_1 = nav1_1.toInt(); nav1_2 = ""; nav1_2 += getChar(); tens_1 = nav1_2.toInt(); nav1_3 = ""; nav1_3 += getChar(); ones_1 = nav1_3.toInt(); nav1_dp = ""; nav1_dp += getChar(); nav1_4 = ""; nav1_4 += getChar(); tenth_1 = nav1_4.toInt(); nav1_5 = ""; nav1_5 += getChar(); hundth_1 = nav1_5.toInt(); String nav1_string = ""; nav1_string += nav1_1; nav1_string += nav1_2; nav1_string += nav1_3; nav1_string += nav1_4; nav1_string += nav1_5; nav1_int = nav1_string.toInt(); break;} //End of "NAV1 Frequency" function

  // NAV1 Standby - The following section of code grabs the serial data with tag "=F" and stores each individual digit as an integer.                                                     */
  switch(CodeIn){case 'F': String nav1sb_1, nav1sb_2, nav1sb_3, nav1sb_4, nav1sb_5, nav1sb_dp; nav1sb_1 = ""; nav1sb_1 += getChar(); hunds_2 = nav1sb_1.toInt(); nav1sb_2 = ""; nav1sb_2 += getChar(); tens_2 = nav1sb_2.toInt(); nav1sb_3 = ""; nav1sb_3 += getChar(); ones_2 = nav1sb_3.toInt(); nav1sb_dp = ""; nav1sb_dp += getChar(); nav1sb_4 = ""; nav1sb_4 += getChar(); tenth_2 = nav1sb_4.toInt(); nav1sb_5 = ""; nav1sb_5 += getChar(); hundth_2 = nav1sb_5.toInt(); String nav1sb_string = ""; nav1sb_string += nav1sb_1; nav1sb_string += nav1sb_2; nav1sb_string += nav1sb_3; nav1sb_string += nav1sb_4; nav1sb_string += nav1sb_5; nav1sb_int = nav1sb_string.toInt(); break;} //End of "NAV1 Standby" function
}

void FSX::LESSTHAN()
{
  
}

void FSX::QUESTION()
{
  
}

void Display::begin(int pin)
{
  _clock = pin;
  _latch = (pin + 1);
  _data = (pin + 2);
  pinMode(_clock, OUTPUT);
  pinMode(_latch, OUTPUT);
  pinMode(_data, OUTPUT);
}

/*void FSX::segOut(unsigned int dig, unsigned int val, unsigned int mplx)
{
  _dig = dig;
  _val = val;
  _mplx = mplx;
  
  _shift = ((val<<11)+dig);
  
  if (_shift >= 256)
    {
      _val2 = (_shift>>8);
      _val3 = (_shift);
    }
    
  if (_shift <= 255)
    {
      _val2 = 0;
      _val3 = _shift;
    }
  
  digitalWrite(_latch, LOW);
  shiftOut(_data, _clock,MSBFIRST, _val2);
  shiftOut(_data, _clock,MSBFIRST, _val3);
  digitalWrite(_latch, HIGH);
  delayMicroseconds (_mplx);
  Serial.println(_val2);
  Serial.println(_val3);
}*/

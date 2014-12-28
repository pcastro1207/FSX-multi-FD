/***************************************************************/
/*  FSX.cpp - Library for displaying FSX flight sim data.      */
/*  Created by Patrick Castro, December 27, 2014.              */
/*  Released into the public domain.                           */
/***************************************************************/
#include "Arduino.h"
#include "FSX.h"

//define variables for course hold display
const unsigned int crsSetDisplay[] = {2,4,8};
byte crsSetVal[] = {0,0,0};

//define variables for speed hold display
const unsigned int spdSetDisplay[] = {16,32,64};
byte spdSetVal[] = {0,0,0};

//define variables for heading hold display
const unsigned int headSetDisplay[] = {128,256,512};
byte headSetVal[] = {0,0,0};

//define variables for altitude hold display
const unsigned int altSetDisplay[] = {1,2,4,8,16};
byte altSetVal[] = {0,0,0,0,0};

//define variables for vertical speed hold display
const unsigned int vertSpdSetDisplay[] = {32,64,128,256,512};
byte vertSpdSetVal[] = {0,0,0,0,0};

FSX::FSX(byte debug)
{
  _debug = debug;
}

int FSX::getChar()
{
  while(Serial.available() == 0);
  return((char)Serial.read());
}

int* FSX::getFsxVal(byte numOfChars)
{
  for (byte x = 0; x <= numOfChars; x++){array[x] = (int)getChar();}
  return array;
}

void FSX::EQUAL(int code)
{
  switch(code)
   {
     //byte num = 0;
     
     // Altitude Set - The following section of code grabs the serial data with tag "=b" and stores each individual digit in an integer array.
     case 'b':
       getFsxVal(5);
       for (int x; x <= 5; x++){altSetVal[x] = array[x];}
     //End of "Altitude Set"
   
     // Vertical Speed Set - The following section of code grabs the serial data with tag "=c" and stores each individual digit in an integer array.                                                     */
     case 'c':
       getFsxVal(5);
       for (int x; x <= 5; x++){vertSpdSetVal[x] = array[x];}
     //End of "Vertical Speed Set"
   
     // Heading Set - The following section of code grabs the serial data with tag "=d" and stores each individual digit in an integer array.                                                     */
     case 'd':
       getFsxVal(3);
       for (int x; x <= 3; x++){headSetVal[x] = array[x];}
     //End of "Heading Set"
   
     // Course Set - The following section of code grabs the serial data with tag "=e" and stores each individual digit in an integer array.                                                     */
     case 'e':
       getFsxVal(3);
       for (int x; x <= 3; x++){crsSetVal[x] = array[x];}
     //End of "Course Set"
   
     // Speed Set - The following section of code grabs the serial data with tag "=f" and stores each individual digit in an integer array.                                                     */
     case 'f':
       getFsxVal(3);
       for (int x; x <= 3; x++){spdSetVal[x] = array[x];}
     //End of "Speed Set"
   }
}

void FSX::LESSTHAN()
{
  
}

void FSX::QUESTION()
{
  
}

Display::Display(byte pin)
{
  _clock = pin;
  _latch = (pin + 1);
  _data = (pin + 2);
}

void Display::begin()
{
  pinMode(_clock, OUTPUT);
  pinMode(_latch, OUTPUT);
  pinMode(_data, OUTPUT);
}

void Display::segOut(byte dig, byte val, byte mplx)
{
  _dig = dig;
  _val = val;
  _mplx = mplx;
  
  _shift = ((val<<11)+dig);
  
  if (_shift >= 256){_val2 = (_shift>>8); _val3 = (_shift);}
  if (_shift <= 255){_val2 = 0; _val3 = _shift;}
  
  digitalWrite(_latch, LOW);
  shiftOut(_data, _clock,MSBFIRST, _val2);
  shiftOut(_data, _clock,MSBFIRST, _val3);
  digitalWrite(_latch, HIGH);
  delayMicroseconds (_mplx);
  Serial.println(_val2);
  Serial.println(_val3);
}

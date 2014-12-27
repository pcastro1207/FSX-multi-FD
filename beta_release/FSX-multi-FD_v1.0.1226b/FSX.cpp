/*
FSX.cpp - Library for interfacting with FSX2multi program. (Flight Sim Data)
Created by Patrick Castro, December 26, 2014.
Released into the public domain.
*/

#include "Arduino.h"
#include "FSX.h"


FSX::FSX(int clock, int latch, int data)
{
  pinMode(clock, OUTPUT);
  pinMode(latch, OUTPUT);
  pinMode(data, OUTPUT);
  _clock = clock;
  _latch = latch;
  _data = data;
}

//register pins function
void FSX::segOut(unsigned int dig, unsigned int val, unsigned int mplx)
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
}

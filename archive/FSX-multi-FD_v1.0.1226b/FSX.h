/*
  FSX.h - Library for interfacting with FSX2multi program. (Flight Sim Data)
  Created by Patrick Castro, December 26, 2014.
  Released into the public domain.
*/

#ifndef FSX_h
#define FSX_h

#include "Arduino.h"

class FSX
{
  public:
	FSX();
	char getChar();
        void EQUALS();
        void LESSTHAN();
        void QUESTION();
  private:
	
};

class Display
{
  public:
        Display();
        void begin(int pin);
        //void segOut(unsigned int dig, unsigned int val, unsigned int mplx);
  private:
  int _clock;
	int _latch;
	int _data;
	unsigned int _dig;
	unsigned int _val;
	byte _val2;
	byte _val3;
	unsigned int _mplx;
	unsigned int _shift;
};

#endif

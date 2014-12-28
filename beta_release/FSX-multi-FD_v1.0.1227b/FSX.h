/***************************************************************/
/*  FSX.h - Library for displaying FSX flight sim data.        */
/*  Created by Patrick Castro, December 27, 2014.              */
/*  Released into the public domain.                           */
/***************************************************************/
#ifndef FSX_h
#define FSX_h

#include "Arduino.h"

class FSX
{
  public:
	FSX(byte debug);
	int getChar();
        int* getFsxVal(byte val);
        void EQUAL(int code);
        void LESSTHAN();
        void QUESTION();
        int code;
        byte debug;
        byte numOfChars;
        byte val;
        int array[];
  private:
        byte _debug;
	byte _radioValCtr;
};

class Display
{
  public:
    Display(byte pin);
    void begin();
    void segOut(byte dig, byte val, byte mplx);
    byte dig;
    byte mplx;
    byte pin;
    byte val;
    unsigned int crsSetDisplay[];
    byte crsSetVal[3];
    unsigned int spdSetDisplay[];
    byte spdSetVal[3];
    unsigned int headSetDisplay[];
    byte headSetVal[3];
    unsigned int altSetDisplay[];
    byte altSetVal[5];
    unsigned int vertSpdSetDisplay[];
    byte vertSpdSetVal[5];
    
  private:
    int _clock;
    int _latch;
    int _data;
    unsigned int _dig;
    unsigned int _val;
    byte _val2;
    byte _val3;
    byte _mplx;
    unsigned int _shift;
};

#endif

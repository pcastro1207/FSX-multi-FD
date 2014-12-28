/***************************************************************/
/* FSX - Flight Director           Version: 1.0.1227b          */
/* By: Patrick Castro              Date: 12-27-14              */
/***************************************************************/

/* Define Global Variables */
byte debug = 0; //set to 1 for debug
int CodeIn; //used on all serial reads

//define variables for shift register outputs
byte register1 = 5, register2 = 8, register3 = 11;

//define variables for display multiplexing
int wait = 0, multiplex = 700;
/* End of Variable Definitions */

#include "FSX.h"

//initialize instance of class FSX & class Display
FSX main(0);
Display reg1(register1);
Display reg2(register2);
Display reg3(register3);



//define Arduino pins as INPUT or OUTPUT
void setup() //this function only runs once on device initialization
{
  reg1.begin(); //output pins for shift register (display set #1)
  reg2.begin(); //output pins for shift register (display set #2)
  reg3.begin(); //output pins for shift register (LED indicators)
  
  Serial.begin(115200); //serial baud rate (configure COM port settings on PC)
} //end of setup function



//main loop function
void loop() {
  //check for debug
  //if (debug = 1){debugMode()}
  
  //Only fetch data from serial buffer if data is recieved
  if (Serial.available())
  {
   CodeIn = main.getChar();
   if (CodeIn == '='){main.EQUAL(CodeIn);}
  } //enf of serial check
  
  byte numOfDig = 0;
  
  //multiplex Altitude Set display
  numOfDig = 5;
  for (byte x = 0; x <= numOfDig; x++)
  {
    reg2.segOut(reg2.altSetVal[x],reg2.altSetDisplay[x],multiplex);
  }
  
  //multiplex Vertical Speed Set display
  numOfDig = 5;
  for (byte x = 0; x <= numOfDig; x++)
  {
    reg2.segOut(reg2.vertSpdSetVal[x],reg2.vertSpdSetDisplay[x],multiplex);
  }
  
  //multiplex Heading Set display
  numOfDig = 3;
  for (byte x = 0; x <= numOfDig; x++)
  {
    reg1.segOut(reg1.headSetVal[x],reg1.headSetDisplay[x],multiplex);
  }
  
  //multiplex Course Set display
  numOfDig = 3;
  for (byte x = 0; x <= numOfDig; x++)
  {
    reg1.segOut(reg1.crsSetVal[x],reg1.crsSetDisplay[x],multiplex);
  }
  
  //multiplex Heading Set display
  numOfDig = 3;
  for (byte x = 0; x <= numOfDig; x++)
  {
    reg1.segOut(reg1.spdSetVal[x],reg1.spdSetDisplay[x],multiplex);
  }
  
} //end of main loop



//this function is used for debugging
void debugMode(){} //End of debug function

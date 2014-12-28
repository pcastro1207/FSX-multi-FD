/***************************************************************/
/* FSX - Flight Director           Version: 1.0.1226b          */
/* By: Patrick Castro              Date: 12-26-14              */
/***************************************************************/

#include "FSX.h"

/* Define Variables */
byte debug = 0; //set to 1 for debug
byte ledpin = 13; //LED onboard Arduino
int CodeIn; //used on all serial reads

//define variables for shift register outputs
int register1 = 2, register2 = 5, register3 = 8;

//define variables for course hold display
unsigned int dis1_1 = 2, dis1_2 = 4, dis1_3 = 8;
byte hunds_1, tens_1, ones_1;

//define variables for speed hold display
unsigned int dis2_1 = 16, dis2_2 = 32, dis2_3 = 64;
byte hunds_2, tens_2, ones_2;

//define variables for heading hold display
unsigned int dis3_1 = 128, dis3_2 = 256, dis3_3 = 512;
byte hunds_3, tens_3, ones_3;

//define variables for altitude hold display
unsigned int dis4_1 = 1, dis4_2 = 2, dis4_3 = 4, dis4_4 = 8, dis4_5 = 16, dp_4 = 16384;
byte hunds_4, tens_4, ones_4, tenth_4, hundth_4;

//define variables for vertical speed hold display
unsigned int dis5_1 = 32, dis5_2 = 64, dis5_3 = 128, dis5_4 = 256, dis5_5 = 512, dp_5 = 16384;
byte hunds_5, tens_5, ones_5, tenth_5, hundth_5;

//define variables for display multiplexing
int wait = 0, multiplex = 700;
/* End of Variable Definitions */

//initialize instance of class FSX
//FSX main();
FSX reg1(register1);
//FSX reg2();
//FSX reg3();



//define Arduino pins as INPUT or OUTPUT
void setup() //this function only runs once on device initialization
{
  reg1.begin(); //output pins for shift register (display set #1)
  //reg2.begin(register2); //output pins for shift register (display set #2)
  //reg3.begin(register3); //output pins for shift register (LED indicators)
  
  pinMode(ledpin, OUTPUT); //sets pin13 on Arduino as output to LED
  
  Serial.begin(115200); //serial baud rate (configure COM port settings on PC)
} //end of setup function



void loop() {
  //Only fetch data from serial buffer if data is recieved
  if (Serial.available())
  {
   //CodeIn = main.getChar();
   
  }
  
} //end of main loop


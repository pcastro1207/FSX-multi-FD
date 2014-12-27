/***************************************************************/
/* FSX - Flight Director           Version: 1.0.1226           */
/* By: Patrick Castro              Date: 12-26-14              */
/***************************************************************/

#include <FSX.h>

/* Define Variables */
byte debug = 0; //set to 1 for debug
byte ledpin = 13; //LED onboard Arduino
int CodeIn; //used on all serial reads

//define variables for shift register outputs
int clock1 = 2, latch1 = 3, data1 = 4; //display set #1 (crs, spd & heading)
int clock2 = 5, latch2 = 6, data2 = 7; //display set #2 (alt & vert spd)
int clock3 = 8, latch3 = 9, data3 = 10; //LED indicators

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

FSX regOne(clock1, latch1, data1);
//FSX regTwo(clock2, latch2, data2);
//FSX regThree(clock3, latch3, data3);

//define Arduino pins as INPUT or OUTPUT
void setup() //this function only runs once on device initialization
{
  /*
  //output pins for shift register (display set #1)
  pinMode(clock1, OUTPUT);
  pinMode(latch1, OUTPUT);
  pinMode(data1, OUTPUT);
  
  //output pins for shift register (display set #2)
  pinMode(clock2, OUTPUT);
  pinMode(latch2, OUTPUT);
  pinMode(data2, OUTPUT);
  
  //output pins for shift register (LED indicators)
  pinMode(clock3, OUTPUT);
  pinMode(latch3, OUTPUT);
  pinMode(data3, OUTPUT);
  */
  pinMode(ledpin, OUTPUT); //sets pin13 on Arduino as output to LED
  
  Serial.begin(115200); //serial baud rate (configure COM port settings on PC)
} //end of setup function



void loop() {
  
  
} //end of main loop


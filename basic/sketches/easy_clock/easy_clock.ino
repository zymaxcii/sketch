/*
 * Easy Clock
 * 
 * learnelectronics
 * 10 April 2017
 * 
 * adapted from a library example
 * "print_text" from MDMaxx72xx library
 * Copyright (C) 2012-16 Marco Colli.
 * 
 * www.youtube.com/c/learnelectronics
 * arduino0169@gmail.com
 */

#include <DS3231.h>
#include <Wire.h>
#include <MD_MAX72xx.h>
#include <SPI.h>
#define	PRINT(s, v)	{ Serial.print(F(s)); Serial.print(v); }
#define	MAX_DEVICES	4
#define	CLK_PIN		13  // or SCK
#define	DATA_PIN	11  // or MOSI
#define	CS_PIN		10  // or SS
/ Text parameters
#define  CHAR_SPACING  1 // pixels between characters


MD_MAX72XX mx = MD_MAX72XX(CS_PIN, MAX_DEVICES);
DS3231 Clock;

byte year, month, date, DoW, hour, minute, second;
// Global message buffers shared by Serial and Scrolling functions
#define	BUF_SIZE	10
char message[BUF_SIZE] = {"Hello!"};
bool newMessageAvailable = true;



void printText(uint8_t modStart, uint8_t modEnd, char *pMsg)

{
  uint8_t   state = 0;
  uint8_t	  curLen;
  uint16_t  showLen;
  uint8_t	  cBuf[8];
  int16_t   col = ((modEnd + 1) * COL_SIZE) - 1;

  mx.control(modStart, modEnd, MD_MAX72XX::UPDATE, MD_MAX72XX::OFF);

  do     // finite state machine to print the characters in the space available
  {
    switch(state)
    {
      case 0:	// Load the next character from the font table
        // if we reached end of message, reset the message pointer
        if (*pMsg == '\0')
        {
          showLen = col - (modEnd * COL_SIZE);  // padding characters
          state = 2;
          break;
        }

        // retrieve the next character form the font file
        showLen = mx.getChar(*pMsg++, sizeof(cBuf)/sizeof(cBuf[0]), cBuf);
        curLen = 0;
        state++;
        // !! deliberately fall through to next state to start displaying

      case 1:	// display the next part of the character
        mx.setColumn(col--, cBuf[curLen++]);

        // done with font character, now display the space between chars
        if (curLen == showLen)  
        {
          showLen = CHAR_SPACING;
          state = 2;
        }
        break;

      case 2: // initialize state for displaying empty columns
        curLen = 0;
        state++;
        // fall through

      case 3:	// display inter-character spacing or end of message padding (blank columns)
        mx.setColumn(col--, 0);
        curLen++;
        if (curLen == showLen) 
          state = 0;
        break;

      default:
        col = -1;   // this definitely ends the do loop
    }
  } while (col >= (modStart * COL_SIZE));

  mx.control(modStart, modEnd, MD_MAX72XX::UPDATE, MD_MAX72XX::ON);
}

void setup()
{
  mx.begin();
  Wire.begin();
  Serial.begin(57600);
 
}

void loop() 
{
Clock.getTime(year, month, date, DoW, hour, minute, second);
int temperature=(Clock.getTemperature()*1.8+32);
int lh = ((hour/10)%10);
int rh = (hour%10);
int lm = ((minute/10)%10);
int rm = (minute%10);
int lt = ((temperature/10)%10);
int rt = (temperature%10);


if (second==30 || second==00){
message[0]=' ';
message[1]=' ';
message[2]=char(lt)+48;
message[3]=char(rt)+48;
message[4]='F';
message[5]='\0';
printText(0, MAX_DEVICES-1, message);
delay(1000);
}
else{

message[0]=' ';
message[1]=' ';
message[2]=char(lh)+48;
message[3]=char(rh)+48;
message[4]=':';
message[5]=char(lm)+48;
message[6]=char(rm)+48;
message[7]='\0';
printText(0, MAX_DEVICES-1, message);
}

}





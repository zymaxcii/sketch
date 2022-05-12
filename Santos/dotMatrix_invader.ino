// dotMatrix_invader.ino

// invader.ino
// https://maker.pro/arduino/projects/dot-matrix-display-hackpack

#include "LedControl.h"

// LedControl lc=LedControl(13,11,12,1);    // original
LedControl lc=LedControl(12,11,10,1);

int a[5], k=0, rno=0;
unsigned long delayTime = 200;

byte invader1a[] =
{
B00011000,  			// First frame of invader #1
B00111100,
B01111110,
B11011011,
B11111111,
B00100100,
B01011010,
B10100101
};


byte invader1b[] =
{
B00011000, 			// Second frame of invader #1
B00111100,
B01111110,
B11011011,
B11111111,
B00100100,
B01011010,
B01000010
};


byte invader2a[] =
{
B00100100, 			// First frame of invader #2
B00100100,
B01111110,
B11011011,
B11111111,
B11111111,
B10100101,
B00100100
};


byte invader2b[] =
{
B00100100,		 	// Second frame of invader #2
B10100101,
B11111111,
B11011011,
B11111111,
B01111110,
B00100100,
B01000010
};


void lister()
{
  //  Makes a stack of the analog input from A0
  for (k=0; k<4; k++)
  {	
    a[k] = a[k+1];
  }
  
  a[4] = analogRead(A0)/75;
  Serial.print("Input = ");
  Serial.println(a[4]);
  delay(100);
}


int check()
{
  // Checks all the values in the stack and returns 1 if any value is different
  int flag = 0;
  for (k=0; k<4; k++)
  {
    if (a[k] != a[k+1])
    {
      flag = 1;
      break;
    }

  }
  return(flag);
}


void sinvader1a()		// Draws frame one from invader #1
{
  for (int i = 0; i < 8; i++)  
  {
    lc.setColumn(0, i, invader1a[i]);
  }
}


void sinvader1b()		// Draws frame two from invader #1
{
  for (int i = 0; i < 8; i++)
  {
    lc.setColumn(0, i, invader1b[i]);
  }
}


void sinvader2a()		// Draws frame one from invader #2
{
  for (int i = 0; i < 8; i++)  
  {
    lc.setColumn(0, i, invader2a[i]);
  }
}


void sinvader2b()		// Draws frame two from invader #2
{
  for (int i = 0; i < 8; i++)
  {
    lc.setColumn(0, i, invader2b[i]);
  }
}


void setup()
{
  lc.setIntensity(0, 5); 	 // Set intensity level
  lc.clearDisplay(0); 		 // Clear Display
  Serial.begin(9600);
}


void disp(long sel)
{
  // Displays invader depending on the arguments recived
  if (sel == 1)
  {
    sinvader1a();
    delay(delayTime);
    sinvader1b();
    delay(delayTime);
  }
  
  if (sel == 2)
  {
    sinvader2a();
    delay(delayTime);
    sinvader2b();
    delay(delayTime);
  }
}


void loop()
{
  int inc = -1, test;
  lister();
  test=check();
  Serial.print("Test = ");
  Serial.println(test);

  if (test==1)
  {
    lc.shutdown(0, false);	// Turns on the display
    disp(rno);
  }
  else
  {
    if (rno==0||rno==1)
      inc=-inc;

    rno=rno+inc;
    lc.shutdown(0,true);	// Turns off the display
  }
}

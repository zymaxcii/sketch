// 8led_spellMyName.ino
// more like spitting out ascii code
// https://www.instructables.com/how-make-8-leds-blinking-with-arduino/

// Turns on 8 LEDs to spell my name in Binary

// Pins 2-9 have my 8 LEDs connected to spell my name
// int led[8] = {2,3,4,5,6,7,8,9};
// int led[8] = {5,6,7,8,9,10,11,12};
int led[8] = {12,11,10,9,8,7,6,5};      // pin 12 is msb


// MyNameLength holds the length of my name in characters
// #define MyNameLength 4
// char name[MyNameLength]= {'M','a','r','k'};
#define MyNameLength 6
char name[MyNameLength]= {'0','1','2','3','4','5'};



void setup()
{               
  // initialize the digital pin as an output
  int i;
  for (i=0; i<8; i++)
  {
    pinMode(led[i], OUTPUT);    
  }
}



// LightUp routine lights up the 8 LEDs to spell out in binary the letter passed in
void LightUp(char letter)
{
  int i;
  for (i=0; i<8; i++)
  {
    // lets check the bit to see if it is on or off
    if ( (letter&(1<<i))!=0 )
    {
      digitalWrite(led[i],HIGH);
    }
    else
    {
      digitalWrite(led[i],LOW);
    }
  }
}


void loop()
{
  int i;

  for (i=0; i<MyNameLength; i++)
  {
    LightUp(name[i]);
    delay(1000);               // wait for a second
  }
  delay(3000);
}

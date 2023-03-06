// timer_elapsedMillis.ino
// status: compile , upload 


/*
 * Created: March 2016
 * By: Ab Kurk
 * Version:1
 * Description:
 * File Name:Timer_demo2.ino
 * This is part of a tutoral to show the difference
   between using a timer library elapsedMillis.h v.s. the delay() function. 
 * With a timer you won't halt your program and
   your buttons and input sensors will respond corectly.
   This demo uses the timer library.
 * Link to the Tutorial:
   http://www.thearduinomakerman.info/blog/2016/4/8/tutorial-delay-vs-timer
 * 
*/


#include <elapsedMillis.h>

elapsedMillis timeElapsed;   // global variable

#define button1Pin 9
#define led1Pin 13
#define led2Pin 12
#define led3Pin 11
#define led4Pin 10

int onoff = 0;               // 0 lights are off 1 lights are on


void setup()
{
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);
  pinMode(led4Pin, OUTPUT);
  
  pinMode(button1Pin, INPUT);
  Serial.begin(9600);
}


void loop()
{
  /*
   * If button is pressed the light turns on.
   * If the button is released lights will first turn off
   * and then sequentially turn on and then off 
   */
   
  if (digitalRead(button1Pin) == LOW)
  {
    // turn LEDS on
    Serial.println("on");
    
    digitalWrite(led1Pin, HIGH);     // active high
    digitalWrite(led2Pin, HIGH);
    digitalWrite(led3Pin, HIGH);  
    digitalWrite(led4Pin, HIGH);
    onoff = 1; 
  }
  else
  {
   if (digitalRead(button1Pin) == HIGH)
   {
     // turn LEDs off
     if (onoff == 1)
     {
       digitalWrite(led1Pin, LOW);    // off
       digitalWrite(led2Pin, LOW);
       digitalWrite(led3Pin, LOW);
       digitalWrite(led4Pin, LOW);
      
       onoff = 0; 
       timeElapsed = 0;      // reset timer to 0
     }
    }
    
    // walking LED
    if (timeElapsed < 1000)
    {
      digitalWrite(led1Pin, HIGH);
    }
    
    if (timeElapsed > 1000 && timeElapsed <2000)
    {
      // if more than a second has passed and less than 2
      // turn led 1 off and turn led 2 on
      digitalWrite(led1Pin, LOW);
      digitalWrite(led2Pin, HIGH);
    }
   
    if (timeElapsed > 2000 && timeElapsed < 3000)
    {
      // if more than a 2 seconds have passed and less than 3
      // turn led 2 off and turn led 3 on
      digitalWrite(led2Pin, LOW);
      digitalWrite(led3Pin, HIGH);
    }
    
    if (timeElapsed > 3000 && timeElapsed < 4000)
    {
      // if more than a 3 seconds have passed and less than 4
      // turn led 3 off and turn led 4 on
      digitalWrite(led3Pin, LOW);
      digitalWrite(led4Pin, HIGH);
    }
    
    if (timeElapsed > 4000)
    {
      // if more than a 4 seconds have passed
      // turn led 4 off and reset the timer to 0
      digitalWrite(led4Pin, LOW);
      timeElapsed = 0;
    }
  }
}

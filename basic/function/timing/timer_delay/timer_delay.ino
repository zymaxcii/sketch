// timer_delay.ino
// status: compile ok, upload ok
// with blocking delay, button is not very responsive


/*
 * Created: March 2016
 * By: Ab Kurk
 * Version:1
 * Description:
 * File Name:Timer_demo1.ino
 * This is part of a tutoral to show the difference
   between using a timer library elapsedMillis.h 
   v.s. the delay() function
 * With a timer you won't halt your program and
   your buttons and input sensors will respond corectly.
   This demo uses the timer the delay() funcion
 * Link To Demo:
   http://www.thearduinomakerman.info/blog/2016/4/8/tutorial-delay-vs-timer
 * 
*/


// 8 LED module with Mega, no jumpers:
// 39,41,43,45,47,49,51,53 

// The switch module with Mega, no jumpers:
// 10,11,12,13

// button and LED Pins
#define button1Pin 10
#define led1Pin 53
#define led2Pin 51
#define led3Pin 49
#define led4Pin 47

int onoff = 0;      // 0 lights are off 1 lights are on


void setup()
{
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);
  pinMode(led4Pin, OUTPUT);
  
  pinMode(button1Pin, INPUT_PULLUP);
  Serial.begin(9600);
}


void loop()
{
  if (digitalRead(button1Pin) == LOW)
  {
    // turn LEDS on
    Serial.println("on");
    digitalWrite(led1Pin, HIGH); 
    digitalWrite(led2Pin, HIGH);
    digitalWrite(led3Pin, HIGH);  
    digitalWrite(led4Pin, HIGH);
    onoff = 1; 
  }
  else
  {
    if(digitalRead(button1Pin) == HIGH)
    {
      // turn LEDs off
      if (onoff == 1)
      {
        digitalWrite(led1Pin, LOW);
        digitalWrite(led2Pin, LOW);
        digitalWrite(led3Pin, LOW);
        digitalWrite(led4Pin, LOW);
        onoff = 0; 
      }   
    }
    
    // walking LED
    digitalWrite(led1Pin, HIGH);    // on
    delay(1000);
    digitalWrite(led1Pin, LOW);     // off
    
    digitalWrite(led2Pin, HIGH);
    delay(1000);
    digitalWrite(led2Pin, LOW);
    
    digitalWrite(led3Pin, HIGH);
    delay(1000);
    digitalWrite(led3Pin, LOW);
    
    digitalWrite(led4Pin, HIGH);
    delay(1000);
    digitalWrite(led4Pin, LOW);
  }
}

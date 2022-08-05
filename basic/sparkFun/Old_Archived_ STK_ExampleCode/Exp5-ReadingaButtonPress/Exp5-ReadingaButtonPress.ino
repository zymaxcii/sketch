/*
SparkFun Tinker Kit 
Example sketch 05

PUSH BUTTONS

  Use pushbuttons for digital input

This sketch was written by SparkFun Electronics,
with lots of help from the Arduino community.
This code is completely free for any use.
Visit http://learn.sparkfun.com/products/2 for SIK information.
Visit http://www.arduino.cc to learn about Arduino.

*/


// First we'll set up constants for the pin numbers.
// This will make it easier to follow the code below.

 // pushbutton pin
 const int buttonPin = 3;

 //RGB LED pins
 const int redPin = 11;    
 const int greenPin = 10;
 const int bluePin = 9;


//create a variable to store a counter and set it to 0
int counter = 0;
void setup()
{
  // Set up the pushbutton pins to be an input:
  pinMode(buttonPin, INPUT);

  // Set up the RGB pins to be an outputs:
  pinMode(redPin, OUTPUT);  
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
}


void loop()
{
 // local variable to hold the pushbutton states
  int buttonState;  

  //read the digital state of buttonPin with digitalRead() function and store the           //value in buttonState variable
  buttonState = digitalRead(buttonPin);

  //if the button is pressed increment counter and wait a tiny bit to give us some          //time to release the button
  if (buttonState == LOW) // light the LED
  {
    counter++;
    delay(150);
  }

  //use the if satement to check the value of counter. If counter is equal to 0 all         //pins are off
  if(counter == 0)
  {
   digitalWrite(redPin,LOW);
   digitalWrite(greenPin,LOW);
   digitalWrite(bluePin,LOW);
  }

  //else if counter is equal to 1, redPin is HIGH
  else if(counter == 1)
  {
   digitalWrite(redPin,HIGH);
   digitalWrite(greenPin,LOW);
   digitalWrite(bluePin,LOW);
  }

  //else if counter is equal to 2 greenPin is HIGH
  else if(counter ==2)
  {
   digitalWrite(redPin,LOW);
   digitalWrite(greenPin,HIGH);
   digitalWrite(bluePin,LOW);
  }

  //else if counter is equal to 3 bluePin is HIGH
  else if(counter ==3)
  {
   digitalWrite(redPin,LOW);
   digitalWrite(greenPin,LOW);
   digitalWrite(bluePin,HIGH);
  }

  //else reset the counter to 0 (which turns all pins off)
  else
  {
   counter =0;
  }
}

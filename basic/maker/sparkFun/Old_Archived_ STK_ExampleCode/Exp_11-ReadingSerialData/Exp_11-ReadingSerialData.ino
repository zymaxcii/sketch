/*
SparkFun Tinker Kit 
Example sketch 11

Serial Color Mixing

Read Serial data from your computer and use it to set 
the RGB values of the RGB LED.


This sketch was written by SparkFun Electronics,
with lots of help from the Arduino community.
Visit http://learn.sparkfun.com/products/2 for SIK information.
Visit http://www.arduino.cc to learn about Arduino.
*/

//create variables for pin numbers. We are making them constants here, because they       //never change. 
const int RED_PIN = 5;
const int GREEN_PIN = 6;
const int BLUE_PIN = 9;

// How fast we plan to cycle through colors in milliseconds
int redVal = 0;
int greenVal= 0;
int blueVal = 0;


void setup()
{
//set the three pin variables as outputs
pinMode(RED_PIN, OUTPUT);
pinMode(GREEN_PIN, OUTPUT);
pinMode(BLUE_PIN, OUTPUT);

//Start the Serial port at 9600 baud rate
Serial.begin(9600);
Serial.println("Please enter your RGB in CSV format(Example: 255,100,0)");
}


void loop()
{
analogWrite(RED_PIN, redVal);
analogWrite(GREEN_PIN, greenVal);
analogWrite(BLUE_PIN, blueVal);

if(Serial.available()>0)
 {
  redVal = Serial.parseInt();
  greenVal = Serial.parseInt();
  blueVal = Serial.parseInt();
 }
}

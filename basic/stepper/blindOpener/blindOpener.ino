// blindOpener.ino

// https://www.the-diy-life.com/arduino-automatic-blind-opener-works-with-a-remote-control-alexa/

//The DIY Life
//Michael Klements
//26 March 2020

#include <IRremote.h>

int iRPin = 10;            //IR sensor connected to Pin 4
IRrecv irrecv(iRPin);      //Create an IR object of the class
decode_results results;

int stepPin = 15;          //Define stepper motor step pin
int dirPin = 14;           //Define stepper motor direction pin

int blindDir = 0;          //Reverse default up direction if needed
int blindLength = 80000;   //Number of steps for full blind length
int blindPosition = 0;     //Initial blind position, 0 is fully open
int blindSpeed = 1;        //Delay between pulses, smaller delay, higher speed


void setup()
{
  Serial.begin(9600);         //Only used to get HEX value for each button
  irrecv.enableIRIn();        //Start the IR receiver
  pinMode(stepPin, OUTPUT);   //Define the stepper motor pins
  pinMode(dirPin, OUTPUT);
}


void loop()
{
  if (irrecv.decode(&results))  //Wait for an IR signal to be received
  {
    Serial.println(results.value, HEX);   //Only used to get HEX value for each button
    driveMotor(results.value);    //Change the LED accordingly
    irrecv.resume();             //Wait for next signal
    delay(200);
  }
}


void driveMotor(unsigned long value)  //Function to read the IR code and decide what the motor should do
{
  switch (value)  //Determine which button has been pressed
  {
    case 0xFF02FD:    //Button + Pressed - Open Slightly
      if (blindPosition >= 2000)
      {
        moveMotor(0,2000);
        blindPosition = blindPosition - 2000;
      }
      break;
    case 0xFF9867:      //Button - Pressed - Close Slightly
      if (blindPosition <= blindLength-2000)
      {
        moveMotor(1,2000);
        blindPosition = blindPosition + 2000;
      }
      break;
    case 0xFF6897:      //Button 0 Pressed - Open Fully
      moveMotor(0,blindPosition);
      blindPosition = 0;
      break;
    case 0xFF30CF:    //Button 1 Pressed - Close Fully
      moveMotor(1,blindLength-blindPosition);
      blindPosition = blindLength;
      break;
    case 0xFF18E7:      //Button 2 Pressed - Blind Preset 2 (1/4 Closed)
      if (blindPosition > blindLength/4)
      {
        moveMotor(0,blindPosition-(blindLength/4));
      }
      else if (blindPosition < blindLength/4)
      {
        moveMotor(1,(blindLength/4)-blindPosition);
      }
      blindPosition = blindLength/4;
      break;
    case 0xFF7A85:      //Button 3 Pressed - Blind Preset 3 (1/2 Closed)
      if (blindPosition > blindLength/2)
      {
        moveMotor(0,blindPosition-(blindLength/2));
      }
      else if (blindPosition < blindLength/2)
      {
        moveMotor(1,(blindLength/2)-blindPosition);
      }
      blindPosition = blindLength/2;
      break;
  }
}


void moveMotor(int moveDir, int noSteps)  //Function to move the motor in direction moveDir and number of steps noSteps
{
  if (moveDir == blindDir)
    digitalWrite(dirPin, HIGH);
  else
    digitalWrite(dirPin, LOW);
  for (int i=0 ; i<=noSteps ; i++)
  {
    digitalWrite(stepPin, HIGH);
    delay(blindSpeed);
    digitalWrite(stepPin, LOW);
    delay(blindSpeed);
  }
}

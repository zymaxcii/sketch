// solenoid.ino

// Multi-solenoid cycle routine by Jeremy S. Cook
// W/ Arduino motor shield. Requires library found here: https://github.com/adafruit/Adafruit-Motor-Shield-library
// Modified from Public domain Adafruit Motor shield library

#include <AFMotor.h>

AF_DCMotor solenoid2(2);
AF_DCMotor solenoid3(3);
AF_DCMotor solenoid4(4);

void setup()
{
  Serial.begin(9600);              // set up Serial library at 9600 bps
  Serial.println("Motor test!");

  // turn on motor
  solenoid2.setSpeed(255);
  solenoid3.setSpeed(255);
  solenoid4.setSpeed(255);
  
}


void loop()
{
  solenoid2.run(BACKWARD);
  delay(75);
  solenoid2.run(RELEASE);
  //delay(75);
  solenoid3.run(FORWARD);
  delay(75);
  solenoid3.run(RELEASE);
  //delay(75);
  solenoid4.run(FORWARD);
  delay(75);
  solenoid4.run(RELEASE);
  delay(75);
}


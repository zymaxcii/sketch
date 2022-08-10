// servo_knobMS.ino
//
// https://mschoeffler.com/2017/09/25/tutorial-how-to-control-a-servo-motor-sg90-with-the-arduino-uno/
// (c) Michael Schoeffler 2017, http://www.mschoeffler.de
//
// pot values can change from 0 to 1023
// servo values also can change from 0 to 180 degress
// but servo can only move from 0 to around 165-170

// Boards to run the sketch:
// just a servo and a potentiometer

// servo sg90 or mg90:
// 
// pin # Name to Uno Pin
// =====================
// 1  Brown   GND
// 2  Red     +5V
// 3  Yellow  D9
// 
// potentiometer:
// 
// pin # Name to Uno Pin
// =====================
// 1  VCC     +5V
// 2  Output  A0
// 3  GND     GND
// 
// 

#include "Servo.h"

#define PIN_SERVO 9
#define PIN_KNOB A0

Servo servo;         // creates servo object to control SG90 servo

int value_knob  = 0; // value of the potentiometer/knob
int value_servo = 0; // control servo; should be between 5 and 175 degrees

void setup()
{
  servo.attach(PIN_SERVO);
  Serial.begin(9600);
}


void loop()
{
  value_knob = analogRead(PIN_KNOB); // between 0 and 1023
  Serial.print(value_knob);
  Serial.print(" -> ");

  // why 5 to 175?
  value_servo = map(value_knob, 0, 1023, 0, 180);  // map knob value range to servo value range
  Serial.println(value_servo); 
  servo.write(value_servo);                        // absolute position
  delay(20);                                       // give servo some time to rotate
}

// stepper_step.ino

// Example 6
// Includes the Arduino Stepper Library

#include <Stepper.h>

// Defines number of steps per rotation
const int stepsPerRevolution = 2038;

// Creates an instance of stepper class
// Pins entered in sequence IN1-IN3-IN2-IN4 for proper step sequence
Stepper myStepper = Stepper(stepsPerRevolution, 2, 3, 4, 5);


void setup()
{
  // nothing to do
}


void loop()
{
  // rotate cw slowly
  myStepper.setSpeed(100);
  myStepper.step(stepsPerRevolution);
  delay(1000);

  // rotate ccw quickly
  myStepper.setSpeed(700);
  myStepper.step(-stepsPerRevolution);
  delay(1000);
}

// Example 6
∕∕Includes the Arduino Stepper Library

#include <Stepper.h>
∕∕ Defines the number of steps per rotation
const int stepsPerRevolution = 2038;

∕∕ Creates an instance of stepper class
∕∕ Pins entered in sequence IN1-IN3-IN2-IN4 for proper step sequence
Stepper myStepper = Stepper(stepsPerRevolution, 2, 3, 4, 5);

void setup() {
  ∕∕ Nothing to do (Stepper Library sets pins as outputs)
}


void loop() {
  ∕∕ Rotate CW slowly
  myStepper.setSpeed(100);
  myStepper.step(stepsPerRevolution);
  delay(1000);
  
  ∕∕ Rotate CCW quickly
  myStepper.setSpeed(700);
  myStepper.step(-stepsPerRevolution);delay(1000);
}

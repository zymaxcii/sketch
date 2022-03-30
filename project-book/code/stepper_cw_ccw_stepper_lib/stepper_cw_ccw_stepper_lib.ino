// stepper_cw_ccw_stepper_lib.ino

// stepper_example_1.ino
//

// Example sketch to control a 28BYJ-48 stepper motor with ULN2003 driver board and Arduino UNO
// More info: https://www.makerguides.com
// Example 1 from MakersGuides.com

// Boards to run the sketch:
// just connect the stepper motor connector to ULN2003 stepper motor driver
// with separate 5V power supply

// ULN2003
// 
// pin # Name to Uno Pin
// =====================
// 1  IN1     D2
// 2  IN2     D3
// 3  IN3     D4
// 4  IN4     D5


#include <Stepper.h>

// Define number of steps per rotation
const int stepsPerRevolution = 2048;

Stepper myStepper = Stepper(stepsPerRevolution, 2, 4, 3, 5);


void setup()
{
  // Set speed to 5 rpm
  myStepper.setSpeed(5);
  Serial.begin(9600);
}


void loop()
{
  // Step one revolution in one direction
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  delay(1000);

  // Step one revolution in the other direction
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  delay(1000);
}


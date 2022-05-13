// stepper_rotate_cw_ccw.ino
//

// Boards to run the sketch:
// just connect the stepper motor connector to ULN2003 stepper motor driver
// with separate 5V power supply

// ULN2003
// 
// pin # Name to Uno Pin
// =====================
// 1  IN1     D2
// 2  IN2     D4
// 3  IN3     D3
// 4  IN4     D5

#include <Stepper.h>

// number of steps in one revolution of 28BYJ‐48
#define STEPS 2038

// IN1-IN3-IN2-IN4
// IN1-IN2-IN3-IN4 cannot reverse direction
Stepper stepper(STEPS, 2, 4, 3, 5);


void setup()
{
  // nothing to do
  Serial.begin(9600);
}


void loop()
{
  // forward direction
  Serial.println("Forward direction at 1 rpm, 2038 steps");
  stepper.setSpeed(1);     // 1 rpm; 100 not working
  stepper.step(2038);      // do 2038 steps ‐‐ corresponds to one revolution in one minute
  delay(1000);

  // reverse direction
  Serial.println("Reverse direction at 6 rpm, 2038 steps");

  // 6 rpm; 700 not working
  stepper.setSpeed(6);    
  
  // do 2038 steps in the other direction with faster speed
  // corresponds to one revolution in seconds
  stepper.step(-2038);     
}

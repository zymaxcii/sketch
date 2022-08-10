// stepper_cont_rotate.ino

// stepper_example_2.ino
//

// Example 2: continuous rotation
// Example sketch to control a 28BYJ-48 stepper motor with ULN2003 driver board
// AccelStepper and Arduino UNO: continuous rotation
// More info: https://www.makerguides.com

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



#include <AccelStepper.h>

#define motorPin1 2      // IN1 on the ULN2003 driver
#define motorPin2 3      // IN2 on the ULN2003 driver
#define motorPin3 4      // IN3 on the ULN2003 driver
#define motorPin4 5      // IN4 on the ULN2003 driver

// Define the AccelStepper interface type; 4 wire motor in half step mode
#define MotorInterfaceType 8

// Initialize with pin sequence IN1-IN3-IN2-IN4
// for using AccelStepper library with 28BYJ-48 stepper motor
AccelStepper stepper = AccelStepper(MotorInterfaceType, motorPin1, motorPin3, motorPin2,motorPin4);


void setup()
{
  // Set maximum steps per second
  stepper.setMaxSpeed(1000);
}


void loop()
{
  // Set motor speed in steps per second
  stepper.setSpeed(500);
  
  // Step motor with constant speed as set by setSpeed()
  stepper.runSpeed();
}


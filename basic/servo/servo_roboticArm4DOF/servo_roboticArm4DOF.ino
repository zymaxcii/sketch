// roboticArm4DOF.ino
// https://urbanarmor.org/2019/07/23/popsicle-stick-robotic-arm-alternate-format/

#include <Servo.h>

Servo servo1;        // Servos
Servo servo2;
Servo servo3;
Servo servo4;

// 4 pots
const int pot1 = A0; // Attach potentiometers
const int pot2 = A1; 
const int pot3 = A2;
const int pot4 = A3;


void setup()
{
  // Set up everything and will run once

  servo1.attach(3);     // Attach servos and define the pin modes
  servo2.attach(9);     // require pwm pins?
  servo3.attach(10);
  servo4.attach(11);
}


void loop()
{
  // put your main code here to run repeatedly
  
  int pot1Value = analogRead(pot1); // Read the values of the potentiometers
  int pot2Value = analogRead(pot2);
  int pot3Value = analogRead(pot3);
  int pot4Value = analogRead(pot4);
  
  int pot1Angle = map(pot1Value, 0, 1023, 0, 179); // Map pot values (0-1023) to angles (0-179 degrees)
  int pot2Angle = map(pot2Value, 0, 1023, 0, 179);
  int pot3Angle = map(pot3Value, 0, 1023, 0, 179);
  int pot4Angle = map(pot4Value, 0, 1023, 0, 179);
  
  servo1.write(pot1Angle); // Make the servos move to the mapped angles
  servo2.write(pot2Angle);
  servo3.write(pot3Angle);
  servo4.write(pot4Angle);
}

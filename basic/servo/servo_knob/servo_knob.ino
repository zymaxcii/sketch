// servo_knob.ino
// Move a servo by adjusting a 10kohms potentiometer
// similar to servo_knobMS.ino

/*
servo_knob.ino
Adafruit Arduino - Lesson 14. Knob
*/

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

#include <Servo.h>

int potPin   = 0;   // 0 or A0 both ok
int servoPin = 9;

Servo servo;


void setup()
{
  servo.attach(servoPin);
}


void loop()
{
  int reading = analogRead(potPin);  // 0 to 1023
  int angle = reading / 6;           // 0 to 180
  servo.write(angle);
}

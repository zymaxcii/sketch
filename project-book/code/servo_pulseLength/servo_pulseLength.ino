// servo_pulseLength.ino
// Move servo by specifying pulse length in microseconds
// from serial monitor

// test_sg90_servo.ino
// pulse width in microseconds: 500-2400

// Boards to run the sketch:
// just a servo

// servo sg90 or mg90:
// 
// pin # Name to Uno Pin
// =====================
// 1  Brown   GND
// 2  Red     +5V
// 3  Yellow  D9
// 

#include <Servo.h>

Servo servo1;  
long num = 500;     

void setup()
{
  servo1.attach(9);
  Serial.begin(9600); 
  Serial.print("Enter Pulse length in microseconds = ");
}


void loop() 
{ 
  if (Serial.available()>1)
  { 
    num= Serial.parseInt();   
    Serial.print(num);  
    Serial.println(" pulse length");
    Serial.print("Enter Pulse length = ");
  }
  
  servo1.writeMicroseconds(num);
  delay(15);
}

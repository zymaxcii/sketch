// servo_test180deg.ino
// https://forum.arduino.cc/t/servo-not-quite-going-to-180-degrees/392851/1
// The problem is that the servo never goes beyond the point of 2400us
// Entering something like 3000us moves it to 160 degrees, same position as 2400us

#include <Servo.h>

Servo servo1;  
long num = 500;     

void setup()
{
  servo1.attach(8);
  Serial.begin(9600); 
  Serial.print("Enter Pulse length = ");
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

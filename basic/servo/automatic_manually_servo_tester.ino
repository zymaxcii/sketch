// servo_tester.ino
// https://create.arduino.cc/projecthub/bbil40/automatic-servo-tester-with-arduino-nano-c694e0
// https://www.youtube.com/watch?v=aLTFXnuhtzQ&t=17s


#include <Servo.h>

Servo myservo1,myservo2;  // create 2 servo objects to control servos

int potpin = A0;  // analog pin used to connect the potentiometer
int butonpin = A1; // analog pin used to connect the push buton
int val;    // variable to read the value from the analog pin
bool press=LOW;  // variable to store the buton press 
int pos = 0;    // variable to store the servo position


void setup()
{
  myservo1.attach(3);  // attaches the servo1 on pin 3 to the servo1 object
  myservo2.attach(5);  // attaches the servo2 on pin 5 to the servo1 object
  Serial.begin(9600);  // generates serial connection
}


void loop()
{
  	press=digitalRead(butonpin);		   // reads the value of the buton (HIGH or LOW)
    Serial.println(press);
  if (press == 1)
  {                   // if push buton pressed automatic mode starts
    for (pos = 0; pos <= 180; pos += 1)
    { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo1.write(pos);              // tell servo1 to go to position in variable 'pos'
    myservo2.write(pos);              // tell servo2 to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
    for (pos = 180; pos >= 0; pos -= 1)
    { // goes from 180 degrees to 0 degrees
      myservo1.write(pos);              // tell servo1 to go to position in variable 'pos'
      myservo2.write(pos);              // tell servo2 to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
  }
  else
  {
    val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
    val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
    myservo1.write(val);                 // sets the servo1 position according to the scaled value
    myservo2.write(val);                 // sets the servo2 position according to the scaled value
    delay(15);                           // waits for the servo to get there
  }
}

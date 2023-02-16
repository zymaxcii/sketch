/*Servo Demo
 * learnelectronics
 * 12/14/2016
 * 
 * NOTE: Do not power more than 2
 * micro servos from the Arduino
 */

#include <Servo.h>                  //include the servo library

Servo myservo1;                     //define the servos
int pos = 0;                        //variable to store position



void setup() {
  // put your setup code here, to run once:

myservo1.attach(9);               //start the servo

}

void loop() {
  // put your main code here, to run repeatedly:

 for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo1.write(pos);              // tell servo to go to degrees in POS
    delay(15);                       // wait for servo to get there
  }

for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo1.write(pos);             
    delay(15);                      
  }


}

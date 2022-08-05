/*
SparkFun Tinker Kit
Circuit 10: Motor Basics

Learn how to control one motor with the motor driver. 

This sketch was written by SparkFun Electronics, with lots of help from the Arduino community.
This code is completely free for any use.

View circuit diagram and instructions at: https://learn.sparkfun.com/tutorials/activity-guide-for-sparkfun-tinker-kit/circuit-10-motor-basics
Download drawings and code at: https://github.com/sparkfun/SparkFun_Tinker_Kit_Code/
*/

//PIN VARIABLES
//the motor will be controlled by the motor A pins on the motor driver
const int AIN1 = 13;           //control pin 1 on the motor driver for the right motor
const int AIN2 = 12;            //control pin 2 on the motor driver for the right motor
const int PWMA = 11;            //speed control pin on the motor driver for the right motor

//VARIABLES
int motorSpeed = 0;       //starting speed for the motor

void setup() {
  //set the motor contro pins as outputs
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
}

void loop() {
    //drive motor forward (positive speed)
    digitalWrite(AIN1, HIGH);                         //set pin 1 to high
    digitalWrite(AIN2, LOW);                          //set pin 2 to low
    analogWrite(PWMA, 255);               //now that the motor direction is set, drive it at max speed
    delay(3000);
    
    //drive motor backward (negative speed)
    digitalWrite(AIN1, LOW);                          //set pin 1 to low
    digitalWrite(AIN2, HIGH);                         //set pin 2 to high
    analogWrite(PWMA, 255);               //now that the motor direction is set, drive it at max speed
    delay(3000);

    //stop motor
    digitalWrite(AIN1, LOW);                          //set pin 1 to low
    digitalWrite(AIN2, LOW);                          //set pin 2 to low
    analogWrite(PWMA, 0);               //now that the motor direction is set, stop motor
    delay(3000);
}


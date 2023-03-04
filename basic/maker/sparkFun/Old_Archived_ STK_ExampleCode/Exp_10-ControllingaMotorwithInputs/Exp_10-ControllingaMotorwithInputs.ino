/*
SparkFun Tinker Kit 
Example sketch 10

H-Bridge Motor Controller with Inputs

  Use the inputs to manually set the direction and speed of a motor.


This sketch was written by SparkFun Electronics,
with lots of help from the Arduino community.
This code is completely free for any use.
Visit http://learn.sparkfun.com/products/2 for SIK information.
Visit http://www.arduino.cc to learn more about Arduino.
*/
 //define the two direction logic pins and the speed / PWM pin
 const int DIR_A = 5;
 const int DIR_B = 4;
 const int PWM = 6;

 //define the input pins
 const int switchPin = 3;
 const int potPin = 0;

 void setup()
 {
  //set all pins as output
  pinMode(DIR_A, OUTPUT);
  pinMode(DIR_B, OUTPUT);
  pinMode(PWM, OUTPUT);
  //set the switchPin as INPUT
  pinMode(switchPin, INPUT);
  }

void loop()
{
//read the value from the potentiometer and divide
//it by 4 to get a 0-255 range. Store the value in
//the speed variable
int speed = analogRead(potPin) / 4;

 //read the value of the switch and store it in the
 //direction variable.


//if the value of direction is HIGH drive forward at
//a speed set by the speed variable, else drive reverse
//at a speed set by the speed variable.
if (digitalRead(switchPin) == HIGH)
{
  forward(speed);
}
else
 {
 reverse(speed);
 }
}

//create a custom function that defines moving forward
//the forward() function accepts one parameter and that is
//the speed at which you want to drive forward (0-255)
 void forward(int spd)
 {
 //motor contoller direction pins set to forward
 digitalWrite(DIR_A, HIGH);
 digitalWrite(DIR_B, LOW);

  //write the speed by using the parameter of spd
 analogWrite(PWM, spd);
  }

//create a custom function that defines moving in reverse
//the reverse() function accepts one parameter and that is
//the speed at which you want to drive in reverse (0-255)
void reverse(int spd)
{ 
//set motor controller pins to reverse
digitalWrite(DIR_A, LOW);
digitalWrite(DIR_B, HIGH);

 //write the speed by using the parameter of spd
 analogWrite(PWM, spd);
 }

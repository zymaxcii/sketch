// servo_arm_pcbway.ino

// robotic_arm.ino
// https://www.pcbway.com/project/shareproject/Robotic_Arm_1.html


#include <Servo.h>

Servo servo1, servo2, servo3, servo4; // assigning the servo's

int potpin1 = 5;     // assiging values of potentiometer to analog signals
int potpin2 = 4;
int potpin3 = 3;
int potpin4 = 2;
 
int val1;            // variables to read values from potentiometer
int val2;
int val3;
int val4;


void setup()
{
  servo1.attach(9); // assiging the  pins to servo motor
  servo2.attach(6);
  servo3.attach(5);
  servo4.attach(3);
}


void loop()
{
  // put your main code here, to run repeatedly
  val1= analogRead(potpin1); 
  val2= analogRead(potpin2); 
  val3= analogRead(potpin3); 
  val4= analogRead(potpin4); 

  val1= map(val1, 0,1023,0,175);
  val2= map(val2, 0,1023,0,175);
  val3= map(val3, 0,1023,0,175);
  val4= map(val4, 0,1023,0,175);

  servo1.write(val1);
  servo2.write(val2);
  servo3.write(val3);
  servo4.write(val4);
  delay(15);
}


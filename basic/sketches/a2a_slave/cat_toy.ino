/*
 * Laser Cat Toy w/ remote control
 * learnelectronics
 * 12-15/2016
 */



#include <Servo.h>                //include the servo library
Servo pan;                        //define the pan servo
Servo tilt;                       //define the tilt servo

int tiltPos = 90;                 //set servo initial position
int panPos = 90;                  //set servo initial position
int x=0;                          //int variable x
int y=0;                          //int variable y
int button=0;                     //int variable button
#define xAxis A0                  //set pins
#define yAxis A1                  //set pins
#define theButton 7               //set pins


void setup() {
  
 pan.attach(10);                  //attach the pan servo
  tilt.attach(11);                //attach the tilt servo
Serial.begin(9600);               //start comms
pinMode(theButton,INPUT_PULLUP);  //set button as input pullup
pinMode(9,OUTPUT);                //set laser as output
pan.write(panPos);                //send servos to initial positions
tilt.write(tiltPos);              //send servos to initial positions
digitalWrite(9,HIGH);             //turn on laser

}

void loop() {
  // put your main code here, to run repeatedly:

x = analogRead(xAxis);            //determine joystick postion
y = analogRead(yAxis);            //determine joystick postion
button = digitalRead(theButton);  //determine joystick postion

if(x<470){                        //pan down
  panPos = panPos -1;
}
  else if(x>500){                 //pan up
    panPos = panPos +1;
  }
else {
  panPos = panPos;                //do nothing
}

if(y<480){                        //tilt right
  tiltPos = tiltPos +1;
}
  else if(y>510){                 //tilt left
    tiltPos = tiltPos -1;
  }
else {                            //do nothing
  tiltPos = tiltPos;
}

if(button = 0){                   //reset servos if button is pushed
  panPos = 90;
  tiltPos = 90;
}


pan.write(panPos);                //current position stored
tilt.write(tiltPos);              //current position stored
delay(20);                        //speed control




}



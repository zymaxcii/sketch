/********************************************************
 * PID Basic Example
 * Reading analog input 0 to control analog PWM output 3
 ********************************************************/

#include <PID_v1.h>

//Define Variables we'll be connecting to
double Setpoint, Input, Output;

//Specify the links and initial tuning parameters
PID myPID(&Input, &Output, &Setpoint,2,5,1, DIRECT);

void setup()
{
  //initialize the variables we're linked to
  Input = analogRead(0);
  Setpoint = 512;  // original 100

  Serial.begin(9600);

  //turn the PID on
  myPID.SetMode(AUTOMATIC);
}

void loop()
{
  Input = analogRead(0);
  myPID.Compute();
  analogWrite(3,Output);

//  Serial.println(Setpoint);

  Serial.print(Input);
  Serial.print(",");
  Serial.println(Output);
}

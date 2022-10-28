// irf520.ino
/ /https://electropeak.com/learn/interfacing-irf520-mosfet-driver-module-switch-button-hcmodu0083-with-arduino/
/*
  IRF520-MOSFET-Driver
  made on 28 oct 2020
  by Amir Mohammad Shojaee @ Electropeak
  Home

*/
#define PWM 3
int pot;
int out;

void setup() {
  Serial.begin(9600);
  pinMode(PWM,OUTPUT);
 
}
 
 
void loop() {
  pot=analogRead(A0);
  out=map(pot,0,1023,0,255);
  analogWrite(PWM,out);
}

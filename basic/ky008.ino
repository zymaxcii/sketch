// ky008.ino
// https://surtrtech.com/2018/11/08/arduino-ky-008-laser-module/


//This code is to use with Laser module KY-008 it turns on for 2secs and turns of for 2secs
//Refer to SurtrTech.com for more information


int Laser = 6;

void setup() {
pinMode(Laser,OUTPUT);
}

void loop() {
digitalWrite(Laser,HIGH);
delay(2000);
digitalWrite(Laser,LOW);
delay(2000);

}

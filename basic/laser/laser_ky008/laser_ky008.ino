// laser_ky008.ino
// This code is to use with Laser module KY-008
// it turns on for 2 secs and turns off for 2 secs
// Refer to SurtrTech.com for more information

// Boards to run the sketch:
// just ky008 laser transmitter module on a breadboard

// ky-008:
// 
// pin # Name to Uno Pin
// =====================
// 1  -ve  GND
// 2  NC   NC
// 3  S    D6

int Laser = 6;

void setup()
{
  pinMode(Laser, OUTPUT);
}


void loop()
{
  digitalWrite(Laser,HIGH);
  delay(2000);
  digitalWrite(Laser,LOW);
  delay(2000);
}

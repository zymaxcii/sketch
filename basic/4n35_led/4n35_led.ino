// 4n35_led.ino
// Turn on a led by 4n35
// turn on LED for half a second, then off for half a second,repeatedly

// https://www.instructables.com/4N35/
//info@primerobotics.in
//www.primerobotics.in

// My hardware setup
// use my Mega board
// refer to 4N35 schematics in schematics folder

int OptoPin = 7;               // attach input of 4n35 to pin 7


void setup()
{
  pinMode(OptoPin, OUTPUT);    // set it as OUTPUT
}


void loop()
{
  digitalWrite(OptoPin, LOW);  // set OptoPin LOW to light up led
  delay(500);                  // delay 500ms

  digitalWrite(OptoPin, HIGH); // turn off the led
  delay(1000); 
}

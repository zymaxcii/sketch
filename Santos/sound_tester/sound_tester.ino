// sound_tester.ino
// microphone sound sensor
// can make it into a clap switch

/*
 * Rui Santos 
 * Complete Project Details http://randomnerdtutorials.com
*/

// my standard pin assignments
int ledPin = 4;          // red led
int sensorPin = 8;
boolean val = 0;


void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);
  Serial.begin (9600);
}


void loop()
{
  val = digitalRead(sensorPin);
  Serial.println (val);
  
  // when sensor detects a signal above threshold value, LED flashes
  if (val==HIGH)
  {
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }
}

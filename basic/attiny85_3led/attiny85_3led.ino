// attiny85_3led.ino
// https://www.electromaker.io/blog/article/introduction-to-the-attiny85-19


void setup()
{
  pinMode(0, OUTPUT);    // 3 leds connected to pins D0,D1,D2
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
}


void loop()
{
  digitalWrite(0, HIGH);
  delay(100);
  digitalWrite(1, HIGH);
  delay(100);
  digitalWrite(2, HIGH);
  delay(100);
  
  digitalWrite(2, LOW);
  delay(100);
  digitalWrite(1, LOW);
  delay(100);
  digitalWrite(0, LOW);
  delay(100);
}

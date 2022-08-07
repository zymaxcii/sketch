// ldp-1.ino
// https://www.jakelectronics.com/blog/photoresistor-basics-and-arduino-tutorial

// hardware setup
// ldp : A0

int light;

// compile error without this
void setup() {}

void loop()
{
  light = analogRead(0);
  Serial.println("light :");
  Serial.println(light);
}

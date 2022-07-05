// ldp-1.ino
// https://www.jakelectronics.com/blog/photoresistor-basics-and-arduino-tutorial

void loop()
{
  light = analogRead(0);
  Serial.println("lignt :");
  Serial.println(light);
}


// lm35_v1.ino
// test LM35 temperature sensor, version 1

// My standard hardware setup
// lm35
// ====
// Bottom facing flat side, right to left
// 1 GND
// 2 OUT A0
// 3 VCC +5V


int val;
int tempPin = A0;   // A0 or 0


void setup()
{
  Serial.begin(9600);
}


void loop()
{
  val = analogRead(tempPin);

  float mv = ( val/1024.0)*5000;
  float cel = mv/10;
  float farh = (cel*9)/5 + 32;

  Serial.print("Sensor value = ");
  Serial.print(val);
  Serial.println();

  Serial.print("Temperature = ");
  Serial.print(cel);
  Serial.print("*C");
  Serial.println();
  // delay(1000);
  
// uncomment this to get temperature in fahrenheit
  Serial.print("Temperature = ");
  Serial.print(farh);
  Serial.print("*F");
  Serial.println();
  Serial.println();
  delay(3000);
}

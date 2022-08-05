// proximitySensor.ino

// https://www.engineersgarage.com/arduino-ir-led-ir-photodiode-proximity-sensor/


unsigned int IRpin = 2;
unsigned int Indicatorpin = 3;

void blink_indicator()
{
  digitalWrite(Indicatorpin, HIGH);
  delay(200);
  digitalWrite(Indicatorpin, LOW);
  delay(200);
}


void setup()
{
  pinMode(IRpin, INPUT_PULLUP);
  pinMode(Indicatorpin, OUTPUT);
}


void loop()
{
  if (digitalRead(IRpin) == LOW) blink_indicator();
  else digitalWrite(Indicatorpin, LOW);
}

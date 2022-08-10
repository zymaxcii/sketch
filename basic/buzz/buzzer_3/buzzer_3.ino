// buzzer_3.ino

const int buzzPin = 3;

void setup()
{
  pinMode(buzzPin, OUTPUT);
}


void loop()
{
  tone(buzzPin,2000);
  delay(1000);

  tone(buzzPin,3000);
  delay(1000);

  tone(buzzPin,4000);
  delay(1000);

  tone(buzzPin,5000);
  delay(1000);
}

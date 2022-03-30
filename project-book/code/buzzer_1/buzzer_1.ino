// buzzer_1.ino

const int buzzPin = 3;


void setup() 
{
  pinMode(buzzPin, OUTPUT);          // buzzer
}

void loop()
{
  tone(buzzPin, 261); // Middle C
  delay(1000);

  tone(buzzPin, 277); // C#
  delay(1000);

  tone(buzzPin, 294); // D
  delay(1000);

  tone(buzzPin, 311); // D#
  delay(1000);

  tone(buzzPin, 330); // E
  delay(1000);
 
  tone(buzzPin, 349); // F
  delay(1000);

  tone(buzzPin, 370); // F#
  delay(1000);

  tone(buzzPin, 392); // G
  delay(1000);

  tone(buzzPin, 415); // G#
  delay(1000);

  tone(buzzPin, 440); // A
  delay(1000);
}


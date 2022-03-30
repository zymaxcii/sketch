// buzzer_2.ino

const int buzzPin = 3;

void setup()
{
pinMode(buzzPin, OUTPUT);
}

void loop()
{
  int notes[10] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440};
  //               mid C  C#   D    D#   E    F    F#   G    G#   A

  for (int i = 0; i < 10; i++)
  {
    tone(buzzPin, notes[i]);    // accesses spots on the array
    delay(1000);
  }
}

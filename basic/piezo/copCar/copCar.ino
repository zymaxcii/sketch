// copCar.ino
// https://github.com/8483/notes/blob/master/topics/arduino.md
// status: compile ok, upload ok


// my traffic light led module
int LED_RED  = 13;
int LED_BLUE = 11;
int BUZZER = 3;


void setup()
{
  pinMode(LED_RED,  OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(BUZZER, OUTPUT);
}


void loop()
{
  tone(BUZZER, 200, 250);
  digitalWrite(LED_RED, HIGH);
  delay(500);
  digitalWrite(LED_RED, LOW);

  tone(BUZZER, 400, 250);
  digitalWrite(LED_BLUE, HIGH);
  delay(500);
  digitalWrite(LED_BLUE, LOW);
}

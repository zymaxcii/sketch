// attiny85.ino
// https://www.nu42.com/2021/02/attiny85-chirper-red-keys-liyafy-hc35.html


void
setup() {
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);

  pinMode(4, OUTPUT);
  digitalWrite(4, LOW);
  delay(5000);
}

bool
key_pressed(int pin)
{
  return digitalRead(pin) == LOW;
}

void
blink(int times, int duration)
{
  for (int i = 0; i < times; ++i) {
    digitalWrite(4, HIGH);
    delay(duration);
    digitalWrite(4, LOW);
    delay(duration);
  }
}

void
loop() {
  if (key_pressed(0)) blink(50, 50);
  if (key_pressed(1)) blink(20, 125);
  if (key_pressed(2)) blink(10, 250);
  if (key_pressed(3)) blink(5, 500);
}

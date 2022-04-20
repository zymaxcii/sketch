// 8led_blink.ino
// https://www.instructables.com/how-make-8-leds-blinking-with-arduino/

int ledPins[] = {2,3,4,5,6,7,8,9};
int delayTime = 100;


void setup()
{
  for (int i = 0; i < 8; i++)
  {
    pinMode(ledPins[i], OUTPUT);
  }
}


void loop()
{
  // turn each led on
  digitalWrite(ledPins[0], HIGH);
  delay(delayTime);

  digitalWrite(ledPins[1], HIGH);
  delay(delayTime);

  digitalWrite(ledPins[2], HIGH);
  delay(delayTime);

  digitalWrite(ledPins[3], HIGH);
  delay(delayTime);

  digitalWrite(ledPins[4], HIGH);
  delay(delayTime);

  digitalWrite(ledPins[5], HIGH);
  delay(delayTime);

  digitalWrite(ledPins[6], HIGH);
  delay(delayTime);

  digitalWrite(ledPins[7], HIGH);
  delay(delayTime);


  // Turns Each LED Off
  digitalWrite(ledPins[7], LOW);
  delay(delayTime);

  digitalWrite(ledPins[6], LOW);
  delay(delayTime);

  digitalWrite(ledPins[5], LOW);
  delay(delayTime);

  digitalWrite(ledPins[4], LOW);
  delay(delayTime);

  digitalWrite(ledPins[3], LOW);
  delay(delayTime);

  digitalWrite(ledPins[2], LOW);
  delay(delayTime);

  digitalWrite(ledPins[1], LOW);
  delay(delayTime);

  digitalWrite(ledPins[0], LOW);
  delay(delayTime);
}

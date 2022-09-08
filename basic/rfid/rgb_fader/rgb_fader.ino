// rgb_fader.ino

/*
rgb_fader.ino
Adafruit Arduino - Lesson 7. RGB Fader
*/

// origin pins 11,10,9
// wrong pin took me 30 mins to troubleshoot
int redLEDPin   = 9;
int greenLEDPin = 10;
int blueLEDPin  = 11;

// origin 7,6,5
int redSwitchPin   = 12;
int greenSwitchPin = 13;
int blueSwitchPin  = 14;

int red   = 0;
int blue  = 0;
int green = 0;

void setup()
{
  pinMode(redLEDPin,   OUTPUT);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(blueLEDPin,  OUTPUT);

  pinMode(redSwitchPin,   INPUT_PULLUP);
  pinMode(greenSwitchPin, INPUT_PULLUP);
  pinMode(blueSwitchPin,  INPUT_PULLUP);

  Serial.begin(9600);
}


void loop()
{
  if (digitalRead(redSwitchPin) == LOW)
  {
    red ++;
    if (red > 255) red = 0;
  }

  if (digitalRead(greenSwitchPin) == LOW)
  {
    green ++;
    if (green > 255) green = 0;
  }

  if (digitalRead(blueSwitchPin) == LOW)
  {
    blue ++;
    if (blue > 255) blue = 0;
  }

  Serial.print(red);   Serial.print("  ");

  Serial.print(green); Serial.print("  ");
  Serial.print(blue);  Serial.print("  ");
  Serial.println(" ");
  
  analogWrite(redLEDPin,   red);
  analogWrite(greenLEDPin, green);
  analogWrite(blueLEDPin,  blue);
  delay(5);
}

// digital_hourglass.ino
// chapter 8
// digital hourglass

// led 3,4,5,6,7,8: tilt switch 9
// connect tilt switch to pin 13
// connect 6 leds to pins 3,4,5, 10,11,12 : 2,3,4,5,6,7 original
// tilt the board to restart the count down

const int switchPin = 9;          // tilt switch
unsigned long previousTime = 0;

int switchState = 0;
int prevSwitchState = 0;

int led = 3;                      // start from pin 3
long interval = 2000;           // the count: 600000; testing use 2000 ms


void setup()
{
  for (int x = 3; x<9; x++)
  {
    pinMode(x, OUTPUT);           // set pins 3-8 as output
  }

  pinMode(switchPin, INPUT_PULLUP);  // tilt switch
}


void loop()
{
  unsigned long currentTime = millis();

  if (currentTime - previousTime > interval)
  {
    previousTime = currentTime;    // reset

   digitalWrite(led, HIGH);
   led++;

   if (led == 8)
   {
     // do nothing
   }
  }
  
  switchState = digitalRead(switchPin);    // read tilt switch

  if (switchState != prevSwitchState)
  {
    for (int x = 3; x<9; x++)
    {
      digitalWrite(x, LOW);  // tilt detected, turn off all leds
    }
  
    led = 3;

    previousTime = currentTime;
  }
  
  prevSwitchState = switchState;
}

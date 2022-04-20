// 8led_flowing.ino
// Flowing LED Lights
// https://www.instructables.com/Flowing-LED-Lights-With-Arduino-Uno-R3/

/*
8 LEDs will light up one by one from left to right, and then go out one by
one from right to left. After that, the LEDs will light up one by one from right to left
and then go out one by one from left to right.
This process will repeat indefinitely.
*/

// Website:www.primerobotics.in


const int lowestPin = 2;   // the lowest one attach to
const int highestPin = 9;  // the highest one attach to 
int delayTime = 100;

void setup()
{
  // set pins 2 through 9 as output  
  for (int thisPin = lowestPin;thisPin <= highestPin;thisPin++)
  {
    pinMode(thisPin,OUTPUT);
  }
}


void loop()
{
  // turn led on from lowest to highest
  for (int thisPin = lowestPin; thisPin <= highestPin; thisPin++)
  {
    digitalWrite(thisPin,HIGH);    // turn led on
    delay(delayTime);
  }

  // fade from highest to lowest
  for (int thisPin = highestPin; thisPin >= lowestPin; thisPin--)
  {
    digitalWrite(thisPin, LOW);    // turn led off
    delay(delayTime);
  }

  for (int thisPin = highestPin; thisPin >= lowestPin; thisPin--)
  {
    digitalWrite(thisPin,HIGH);    // turn led on
    delay(delayTime);
  }

  for ( int thisPin = lowestPin; thisPin <= highestPin; thisPin++)
  {
    digitalWrite(thisPin, LOW);    // turn led off
    delay(delayTime);
  }
}

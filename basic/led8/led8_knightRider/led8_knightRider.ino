// led8_knightRider.ino

/*
 * Tutorial 3b: LED Knight Rider
 * 
 * Demonstrates the use of a for() loop.
 * Lights multiple LEDs in sequence, then in reverse.
 *
 * The circuit:
 *  - 6 LEDs attached to digital pins 2 through 7 with 330ohm resistors
 *
 * created 2006
 * by David A. Mellis
 * modified 30 Aug 2011
 * by Tom Igoe
 * modified 14 August 2013
 * by Blaise Jarrett
 *
 * This example code is in the public domain.
 *
 * Derivative work from:
 * http://www.arduino.cc/en/Tutorial/ForLoop
 *
*/

// Code requires leds to be connected to consecutive pins

// The time in ms each LED stays on for
// experiment with this number, the lower the number
// the faster the LEDs change
int timer = 100;               // try 100, 50, 500

void setup()
{
    // use a for loop to initialize each pin as an output
    // for (int thisPin = 2; thisPin < 8; thisPin++)
    // {
    //    pinMode(thisPin, OUTPUT);
    // }
    
    // with the 8 led module that plugs directly into mega
    // use a for loop to initialize each pin as an output
    for (int thisPin = 39; thisPin < 53; thisPin = thisPin + 2)
    {
        pinMode(thisPin, OUTPUT);
    }
}

void loop()
{
    // loop from the lowest pin to the highest
    // for (int thisPin = 2; thisPin < 8; thisPin++)
    for (int thisPin = 39; thisPin < 53; thisPin = thisPin + 2)
    {
        // turn the pin on
        digitalWrite(thisPin, HIGH);
        // wait to turn it off so we can see it
        delay(timer);
        // turn the pin off
        digitalWrite(thisPin, LOW);
    }

    // loop from the highest pin to the lowest
    // for (int thisPin = 7; thisPin > 1; thisPin--)
    for (int thisPin = 53; thisPin > 39; thisPin = thisPin - 2)
    {
        // turn the pin on
        digitalWrite(thisPin, HIGH);
        // wait to turn it off so we can see it
        delay(timer);
        // turn the pin off
        digitalWrite(thisPin, LOW);
    }
}

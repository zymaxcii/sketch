#include <Arduino.h>
#include <Servo.h>

// This is a more advanced example that avoids using delay() so that you can do
// other things while the motor animation is running. In this case, I've added
// a basic LED blink throughout the animation. Pin 17 is one of the built-in
// LEDs on the Pro Micro, but you can change to pin 13 for an Uno.

#define SERVO_PIN 6
#define LED_PIN   13

Servo s;

void setup()
{
  s.attach(SERVO_PIN);
  pinMode(LED_PIN, OUTPUT);
}

unsigned int animationStep = 0;
unsigned long lastAnimationMillis = 0;
int pos[] =           {  90,  80,  65,    120,   105,  110, 98,  68,  84,  74};
unsigned long d[] =   {3000,  500, 1200,  1530,  700,  200, 800, 450, 300, 670};

// Concurrent blink example:
unsigned long lastBlinkMillis = 0;
bool ledOn = false;

void loop()
{
  // Check if it's time for the next animation step
  if (millis() - lastAnimationMillis > d[animationStep])
  {
    // It's time to animate! Make a note of the current time that we're running this animation
    lastAnimationMillis = millis();

    // Move to the next animation step
    animationStep++;

    // If we've gone through all animation steps, restart at step 0
    if (animationStep >= sizeof(pos)/sizeof(pos[0])) {
      animationStep = 0;
    }

    // Move the servo to the new position for this step
    s.write(pos[animationStep]);
  }

  // Check if it's time to blink the LED
  if (millis() - lastBlinkMillis > 1000)
  {
    lastBlinkMillis = millis();
    ledOn = !ledOn;
    digitalWrite(LED_PIN, ledOn);
  }
}

// This code is public domain. Use it however you'd like. Attribution
// to Scott Bezek and the build video (https://youtu.be/tyLo3LW5UCo)
// is always appreciated.

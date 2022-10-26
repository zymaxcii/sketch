// ws2812_turnLight.ino
// What does it do?

// https://www.youtube.com/watch?v=rPvGLSuMaLA
// https://github.com/hendog993/Youtube_arduino/blob/master/LEDStrip.ino

// My standard hardware setup
// WS2812 strip
// ============
// VCC
// GND
// DIO D2


#include <FastLED.h>
#define LED_PIN 2
#define NUM_LEDS 12

CRGB leds[NUM_LEDS];


void setup()
{
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setMaxPowerInVoltsAndMilliamps(5, 500);
  FastLED.clear();
  FastLED.show();
}


void loop()
{
  // Turn lights from green to blue from left to right   R G B 
  for (int i=0; i<NUM_LEDS; i++)
  {
    leds[i] = CRGB(0, 255 - 4*i, 4*i );
    FastLED.setBrightness(2*i);
    FastLED.show();
    delay(50);
  }

  // Turn lights from blue to magenta from right to left 
  for (int i=NUM_LEDS; i>0; i--)
  {
    leds[i] = CRGB(4*i,0 , 255-4*i);
    FastLED.setBrightness(100-i);
    FastLED.show();
    delay(50);
  }
}


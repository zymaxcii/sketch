// max7219-dht11.ino
// Display temperature and humidity reading obtained from a DHT11 sensor
// Number of max7219 devices can be set before compilation
// Also can compile with or without uiswitch library

// https://miliohm.com/how-to-use-max7219-led-matrix-running-text-display-sensor-data-add-more-led-matrix-with-arduino/
// https://www.youtube.com/watch?v=TaqSaYI0aLI

/* Example 8x32 Matrix to print sensor data
   by miliohm.com
*/

// My standard hardware setup
// DIN D11
// CLK D13
// CS  D10
// Using hardware SPI DIN and CLK are fixed at D11 and D13 respectively
// So the only choice to make is CS to D10
//
// scroll speed pot A0
// scroll direction switch D2
// invert text switch D3
//
// DHT211 D6


#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>
#include "DHT.h"

#define DHTPIN 6
#define DHTTYPE DHT11          // DHT 11

DHT dht(DHTPIN, DHTTYPE);

float h;
float t;
char text;

// set to 1 if we are implementing the user interface pot, switch, etc
#define USE_UI_CONTROL 1

#if USE_UI_CONTROL
#include <MD_UISwitch.h>
#endif

// Turn on debug statements to the serial output
#define DEBUG 0

#if DEBUG
#define PRINT(s, x) { Serial.print(F(s)); Serial.print(x); }
#define PRINTS(x) Serial.print(F(x))
#define PRINTX(x) Serial.println(x, HEX)
#else
#define PRINT(s, x)
#define PRINTS(x)
#define PRINTX(x)
#endif


// Define the number of devices we have in the chain and the hardware interface
// NOTE: These pin numbers will probably not work with your hardware and may
// need to be adapted
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4
#define CLK_PIN   13
#define DATA_PIN  11
#define CS_PIN    10

// HARDWARE SPI
MD_Parola P = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);
// SOFTWARE SPI
//MD_Parola P = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);


// Scrolling parameters
#if USE_UI_CONTROL
const uint8_t SPEED_IN = A0;
const uint8_t DIRECTION_SET = 2;     // change the effect
const uint8_t INVERT_SET    = 3;     // change the invert

const uint8_t SPEED_DEADBAND = 5;
#endif // USE_UI_CONTROL


uint8_t scrollSpeed = 1000;            // default frame delay value,25
textEffect_t scrollEffect = PA_SCROLL_LEFT;
textPosition_t scrollAlign = PA_LEFT;
uint16_t scrollPause = 2000;         // in milliseconds

// Global message buffers shared by Serial and Scrolling functions
#define    BUF_SIZE    75

char curMessage[BUF_SIZE] = { "" };
char newMessage[BUF_SIZE] = { "" };
bool newMessageAvailable = true;

#if USE_UI_CONTROL

MD_UISwitch_Digital uiDirection(DIRECTION_SET);
MD_UISwitch_Digital uiInvert(INVERT_SET);

void doUI(void)
{
  // set the speed if it has changed
  {
    int16_t speed = map(analogRead(SPEED_IN), 0, 1023, 10, 150);

    if ((speed >= ((int16_t)P.getSpeed() + SPEED_DEADBAND)) ||
        (speed <= ((int16_t)P.getSpeed() - SPEED_DEADBAND)))
    {
      P.setSpeed(speed);
      scrollSpeed = speed;
      PRINT("\nChanged speed to ", P.getSpeed());
    }
  }

  if (uiDirection.read() == MD_UISwitch::KEY_PRESS) // SCROLL DIRECTION
  {
    PRINTS("\nChanging scroll direction");
    scrollEffect = (scrollEffect == PA_SCROLL_LEFT ? PA_SCROLL_RIGHT : PA_SCROLL_LEFT);
    P.setTextEffect(scrollEffect, scrollEffect);
    P.displayClear();
    P.displayReset();
  }

  if (uiInvert.read() == MD_UISwitch::KEY_PRESS)  // INVERT MODE
  {
    PRINTS("\nChanging invert mode");
    P.setInvert(!P.getInvert());
  }
}
#endif // USE_UI_CONTROL


void setup()
{
  Serial.begin(9600);
  dht.begin();

#if USE_UI_CONTROL
  uiDirection.begin();
  uiInvert.begin();
  pinMode(SPEED_IN, INPUT);

  doUI();
#endif // USE_UI_CONTROL

  P.begin();
  P.displayText(curMessage, scrollAlign, scrollSpeed, scrollPause, scrollEffect, scrollEffect);
}


void loop()
{
  sensorThings();
  char data[20];
  String bufferr;
  bufferr = "T:" + (String)t + " H:" + (String)h;
  bufferr.toCharArray(data, 20);
  strcpy(curMessage, data);
  displayHandle();
}

void sensorThings()
{
  h = dht.readHumidity();
  t = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t))
  {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
}


void displayHandle()
{
#if USE_UI_CONTROL
  doUI();
#endif // USE_UI_CONTROL
  if (P.displayAnimate())
  {
    P.displayReset();
  }
}

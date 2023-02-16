// keypad_oled_test.ino
// status: compile ?

// https://www.dropbox.com/sh/m6c40pu99fqxb5b/AABp8tOHcInZ4r7zDn9EbGfqa/keypad_example?dl=0&lst=

/*
 * Arduino 4x4 Keypad Read Example with OLED
 * 
 * learnelectronics
 * 06 April 2017
 * 
 * www.youtube.com/c/learnelectronics
 * arduino0169@gmail.com
 * 
 * note: connect ribbon cable to digital pins 2-9
 * starting at the far right to digital 2 and
 * finishing with far left on digital 9
 */


#include <Keypad.h>
#include <Wire.h>                 // I2C library for OLED
#include <Adafruit_SSD1306.h>     // OLED Driver library


#define OLED_RESET 4              //not really used

Adafruit_SSD1306 display(OLED_RESET);      // create instance

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] =
{
  {'1', '4', '7', '*'},
  {'2', '5', '8', '0'},
  {'3', '6', '9', '#'},
  {'A', 'B', 'C', 'D'}
};

byte rowPins[ROWS] = {26, 27, 28, 29};         // Mega board
byte colPins[COLS] = {22, 23, 24};

// create instance
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


void setup()
{
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);   // start oled @ hex addr 0x3C
  display.display();                           // show buffer
  display.clearDisplay();                      // clear buffer
}


void loop()
{
  display.setTextSize(3);                      // set text size (1-6)
  display.setTextColor(WHITE);                 // set text color
  display.setCursor(0,0);                      // cursor to upper left
  
  char key = keypad.getKey();
  
  if (key)
  {
    display.clearDisplay();
    display.println(key);
    display.display();                         // show buffer
  }
}

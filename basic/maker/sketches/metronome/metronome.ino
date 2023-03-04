#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
//---------------------------------------------------------------
#define BUZZER  10      // buzzer pin
#define MIN_BPM 20      // minimum bpm value
#define MAX_BPM 240     // maximum bpm value
#define POT A0          // pot analog pin
//---------------------------------------------------------------

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2
#define LOGO16_GLCD_HEIGHT 16 
#define LOGO16_GLCD_WIDTH  16 
static const unsigned char PROGMEM logo16_glcd_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000 };

//---------------------------------------------------------------
int bpm;                // bpm value
//---------------------------------------------------------------

void setup() {
  
  pinMode(BUZZER, OUTPUT);  // buzer pin as output
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  delay(2000);
}
//---------------------------------------------------------------

void loop() {

    bpm = map(analogRead(POT), 0, 1023, MIN_BPM, MAX_BPM);  
    display.clearDisplay();
    display.setTextSize(3);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.println(bpm);
    display.display();
    tone(BUZZER, 2000);       // does a "tick" for...
    delay(6000 / bpm);        // 10% of T (where T is the time between two BPSs)
    noTone(BUZZER);           // silence for...
    delay(54000 / bpm);       // 90% of T

}


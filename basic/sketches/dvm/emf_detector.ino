/* EMF/RF Detector
 *  learnelectronics
 *  06 Jan 17
 */

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

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

  int emfLevel = 0;
  int ledLevel = 0;


void setup()   {                
  Serial.begin(9600);
  pinMode(9, OUTPUT);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
 
  display.display();
  delay(2000);

  // Clear the buffer.
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("EMF Detector");
  display.display();
  delay(2000);
  display.clearDisplay();

}
 

void loop() {

emfLevel = analogRead(A7);
ledLevel = map(emfLevel,0,1024,0,255);

if(emfLevel >20){
   display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("EMF Level");
  display.setCursor(0,20);
  display.println(emfLevel);
  display.display();
  analogWrite(9,(ledLevel*5));
  display.clearDisplay();
}
  else{
     display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("EMF Level");
  display.setCursor(0,20);
  display.println("0");
  display.display();
  analogWrite(9,0);
  delay(100);
  display.clearDisplay();
  }

  delay(200);
  
 
  
}




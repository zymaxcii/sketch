

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

volatile int startTime;



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


void setup()   {                
  Serial.begin(9600);

  
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); 
  
  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  display.display();
  delay(2000);

  // Clear the buffer.
  display.clearDisplay();
  display.display();
pinMode(2,INPUT_PULLUP);
pinMode(8, OUTPUT);

randomSeed(analogRead(0));
int waitTime=random(1000,5000);
delay(waitTime);
digitalWrite(8, HIGH);
startTime=millis();
attachInterrupt(0,BANG,CHANGE);

}

void BANG(){
int thisTime=millis();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Your reaction time is");
  display.print(thisTime-startTime);
  display.print(" milliseconds");
  display.display();
}



void loop() {
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  
  display.println(millis());
  
  display.display();
}





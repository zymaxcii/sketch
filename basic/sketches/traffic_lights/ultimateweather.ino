//ULTIMATE ARDUINO WEATHER STATION
//V1.3
//learnelectronics
//12-11-2016

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "DHT.h"

#define DHTPIN 8 
#define DHTTYPE DHT11 
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

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



Adafruit_BMP280 bme; // I2C
DHT dht(DHTPIN, DHTTYPE);
  
void setup() {
  pinMode(9,OUTPUT);
  Serial.begin(9600);
  dht.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
   display.display();
  delay(2000);

  // Clear the buffer.
  display.clearDisplay();
  
  
  if (!bme.begin()) {  
    Serial.println("Could not find a valid BMP280 sensor, check wiring!");
    while (1);
  }
}
  
void loop() {

    float mytemp=(bme.readTemperature()*1.8 + 32);
    float mypress=(bme.readPressure()*.000295);
    float h = dht.readHumidity();
     display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.clearDisplay();
  display.print(mytemp);
  display.println(" F");
  display.print(mypress);
  display.println(" inhg");
  display.print(h);
  display.println(" %");
  display.display();
  delay(3000);
  if(mypress<29){
    display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.clearDisplay();
  display.println("STORM");
  display.println("WARN");
  display.display();
  digitalWrite(9,HIGH);
  delay(50);
  digitalWrite(9,LOW);
  delay(50);
   digitalWrite(9,HIGH);
  delay(50);
  digitalWrite(9,LOW);
  delay(50);
   digitalWrite(9,HIGH);
  delay(50);
  digitalWrite(9,LOW);
  delay(1000);
  
  }
  delay(1000);  
    
    
    
}

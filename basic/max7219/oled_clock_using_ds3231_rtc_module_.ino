//Marios Ideas
//DS3231 Tutorial
//Using DS3232.h library
//Formating date and time with dateFormat function (for Arduino board with >2kb SRAM)

#include <Wire.h>
#include <DS3231.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

DS3231 clock;
RTCDateTime dt;
String txt;
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET     -1// Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
Serial.begin(9600);
    clock.begin();
  // Set sketch compiling time
    clock.setDateTime(__DATE__, __TIME__);
   // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  display.display();
    delay(2000); // Pause for 2 seconds

    // Clear the buffer
  display.clearDisplay();
  display.display();

}



void loop() {
  dt = clock.getDateTime();

  display.fillRect(0,0,128,16,SSD1306_WHITE);
  display.fillRect(0,17,128,16,SSD1306_BLACK);
  display.fillRect(0,31,128,33,SSD1306_WHITE);

    display.setCursor(1,1); 
    display.setTextSize(2);
    display.setTextColor(SSD1306_BLACK); 
    display.println(clock.dateFormat("l", dt)); 

  display.setCursor(1,18); 
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE); 
  display.println(clock.dateFormat("M jS Y ", dt));

    display.setCursor(3,35); 
    display.setTextSize(3);  
    display.setTextColor(SSD1306_BLACK); 
    display.println(clock.dateFormat("H:i", dt));

  display.setCursor(100,35); 
  display.setTextSize(2);
  display.setTextColor(SSD1306_BLACK); 
  display.println(clock.dateFormat("s", dt));

  
  display.display();


 delay(1000);
}
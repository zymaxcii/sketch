// lcdi2c_demo.ino
// Flash backlight and scroll

// https://dronebotworkshop.com/lcd-displays-arduino/

// My standard hardware setup
// Uno: pins sda, scl; gnd and vcc

#include <Wire.h>                  // for i2c
#include <LiquidCrystal_I2C.h>

const int i2c_addr = 0x27;

LiquidCrystal_I2C lcd(i2c_addr, 20, 4);


void setup()
{
  lcd.init();                        // initialize the lcd
  lcd.backlight();                   // turn backlight on
  
  // Print on first row
  lcd.setCursor(0,0);
  lcd.print("Hello world!");
  
  // Wait 1 second
  delay(1000);
  
  // Print on second row
  lcd.setCursor(0,1);
  lcd.print("How are you?");
  
  // Wait 2 seconds
  delay(2000);
  
  // Clear the display
  lcd.clear();
}


void loop()
{
  // Demo 1 - flash backlight
  lcd.setCursor(0,0);
  lcd.print("Backlight demo");
  lcd.setCursor(0,1);
  lcd.print("Flash 4 times");
  
  delay(2000);
  lcd.clear();
  
  // Flash backlight 4 times
  for(int i = 0; i< 4; i++)
  {
    lcd.backlight();
    delay(250);
    lcd.noBacklight();
    delay(250);
  }

  // Turn backlight back on
  lcd.backlight();
    
  // Demo 2 - scroll
  lcd.setCursor(0,0);
  lcd.print("Scroll demo - ");
  delay(1500);
  
  // set the display to automatically scroll
  lcd.autoscroll();
  // print from 0 to 9:
  for (int thisChar = 0; thisChar < 10; thisChar++)
  {
    lcd.print(thisChar);
    delay(500);
  }
  // turn off automatic scrolling
  lcd.noAutoscroll();

  // clear screen 
  lcd.clear();
  
  // Delay
  delay(1000);
}

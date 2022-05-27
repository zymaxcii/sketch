// oled_draw.ino
// https://lastminuteengineers.com/oled-display-arduino-tutorial/


#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(-1);

void setup()   
{                
	// initialize with the I2C addr 0x3C
	display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  

	// Clear the buffer.
	display.clearDisplay();

	display.setTextSize(1);
	display.setTextColor(WHITE);
	display.setCursor(0,0);
	display.println("Rectangle");
	display.drawRect(0, 15, 60, 40, WHITE);
	display.display();
	delay(2000);
	display.clearDisplay();

	display.setTextSize(1);
	display.setTextColor(WHITE);
	display.setCursor(0,0);
	display.println("Filled Rectangle");
	display.fillRect(0, 15, 60, 40, WHITE);
	display.display();
	delay(2000);
	display.clearDisplay();

	display.setTextSize(1);
	display.setTextColor(WHITE);
	display.setCursor(0,0);
	display.println("Round Rectangle");
	display.drawRoundRect(0, 15, 60, 40, 8, WHITE);
	display.display();
	delay(2000);
	display.clearDisplay();

	display.setTextSize(1);
	display.setTextColor(WHITE);
	display.setCursor(0,0);
	display.println("Filled Round Rectangl");
	display.fillRoundRect(0, 15, 60, 40, 8, WHITE);
	display.display();
	delay(2000);
	display.clearDisplay();

	display.setTextSize(1);
	display.setTextColor(WHITE);
	display.setCursor(0,0);
	display.println("Circle");
	display.drawCircle(20, 35, 20, WHITE);
	display.display();
	delay(2000);
	display.clearDisplay();

	display.setTextSize(1);
	display.setTextColor(WHITE);
	display.setCursor(0,0);
	display.println("Filled Circle");
	display.fillCircle(20, 35, 20, WHITE);
	display.display();
	delay(2000);
	display.clearDisplay();

	display.setTextSize(1);
	display.setTextColor(WHITE);
	display.setCursor(0,0);
	display.println("Triangle");
	display.drawTriangle(30, 15, 0, 60, 60, 60, WHITE);
	display.display();
	delay(2000);
	display.clearDisplay();

	display.setTextSize(1);
	display.setTextColor(WHITE);
	display.setCursor(0,0);
	display.println("Filled Triangle");
	display.fillTriangle(30, 15, 0, 60, 60, 60, WHITE);
	display.display();
	delay(2000);
	display.clearDisplay();
}

void loop() {}

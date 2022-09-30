// lcdi2c-dht22.ino
// Display temperature and humidity from dht22 sensor

// https://dronebotworkshop.com/lcd-displays-arduino/

// My standard hardware setup
// Uno: pins sda, scl; gnd and vcc
// dht22

// Include Wire Library for I2C
#include <Wire.h>

// Include NewLiquidCrystal Library for I2C
#include <LiquidCrystal_I2C.h>

// Include DHT Libraries from Adafruit
// Dependant upon Adafruit_Sensors Library
#include "DHT.h";

// Define I2C Address - change if reqiuired
const int i2c_addr = 0x27;

// DHT-22
#define DHTPIN 7            // DHT-22 Output Pin connection
#define DHTTYPE DHT22       // DHT Type is DHT 22 (AM2302)

LiquidCrystal_I2C lcd(i2c_addr, 20, 4);

// Define Variables
float hum;                  // Stores humidity value in percent
float temp;                 // Stores temperature value in Celcius

// Setup DHT sensor for normal 16mhz Arduino
DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  lcd.init();                        // initialize the lcd
  lcd.backlight();                   // turn backlight on
  
  // Initialize DHT-22
  dht.begin();  
}


void loop()
{
  delay(2000);                    // Delay so DHT-22 sensor can stabilize
  
  hum = dht.readHumidity();       // Get Humidity value
  temp= dht.readTemperature();    // Get Temperature value
    
  // Clear the display
  lcd.clear();
    
  // Print temperature on top line
  lcd.setCursor(0,0);
  lcd.print("Temp:  ");
  lcd.print(temp);
  lcd.print(" C");
 
  // Print humidity on bottom line
  lcd.setCursor(0,1);
  lcd.print("Humid: ");
  lcd.print(hum);
  lcd.print(" %");
}

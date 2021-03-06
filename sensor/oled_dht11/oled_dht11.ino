// oled_dht11.ino
// display temperature and humidity in oled

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

#define DHTPIN 8
#define DHTTYPE DHT11       // blue
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

// Initialize DHT sensor for normal 16mhz Arduino
DHT dht(DHTPIN, DHTTYPE);


void setup()
{
  Wire.begin();
  dht.begin();              // initialize dht
  // initialize with I2C addr 0x3C for 128x32
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  Serial.begin(9600);
}


void displayTempHumid()
{
  delay(2000);
  // reading temperature or humidity takes about 250 milliseconds
  // sensor readings may also be up to 2 secs 'old' (a very slow sensor)
  float h = dht.readHumidity();
  
  // read temperature as Celsius
  float t = dht.readTemperature();
  
  // read temperature as Fahrenheit
  float f = dht.readTemperature(true);

  // check if any reads failed and exit early (to try again)
  if (isnan(h) || isnan(t) || isnan(f))
  {
    display.clearDisplay();      // clearing the display
    display.setTextColor(WHITE); // setting the color
    display.setTextSize(1);      // set the font size
    display.setCursor(5, 0);     // set the cursor coordinates
    display.print("Failed to read from DHT sensor!");
    return;
  }
  
  display.clearDisplay();
  display.setTextColor(WHITE);      // WHITE
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("Humidity: "); 
  display.print(h);
  display.print(" %\t");
  display.setCursor(0, 10);
  display.print("Temperature: "); 
  display.print(t);
  display.print(" C"); 
  display.setCursor(0, 20);
  display.print("Temperature: "); 
  display.print(f);
  display.print(" F"); 
}


void loop()
{
  displayTempHumid();
  display.display();
}

// tm1637-dht11.ino
// https://www.makerguides.com/tm1637-arduino-tutorial/


/* Arduino example sketch to display DHT11 temperature readings on a TM1637 4-digit 7-segment display. More info: www.www.makerguides.com */

// Include the libraries:
#include <TM1637Display.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

// Define the connections pins:
#define CLK 2
#define DIO 3
#define DHTPIN 4

// Create variable:
int temperature_celsius;
int temperature_fahrenheit;

// Create degree Celsius symbol:
const uint8_t celsius[] = {
  SEG_A | SEG_B | SEG_F | SEG_G,  // Circle
  SEG_A | SEG_D | SEG_E | SEG_F   // C
};

// Create degree Fahrenheit symbol:
const uint8_t fahrenheit[] = {
  SEG_A | SEG_B | SEG_F | SEG_G,  // Circle
  SEG_A | SEG_E | SEG_F | SEG_G   // F
};

// Set DHT type, uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11 
//#define DHTTYPE DHT22   // DHT 22  (AM2302)
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Create display object of type TM1637Display:
TM1637Display display = TM1637Display(CLK, DIO);
// Create dht object of type DHT:
DHT dht = DHT(DHTPIN, DHTTYPE);

void setup() {
  // Set the display brightness (0-7):
  display.setBrightness(0);
  // Clear the display:
  display.clear();
  // Setup sensor:
  dht.begin();
  // Begin serial communication at a baud rate of 9600:
  Serial.begin(9600);
  // Wait for console opening:
  delay(2000);
}

void loop() {
  // Read the temperature as Celsius and Fahrenheit:
  temperature_celsius = dht.readTemperature();
  temperature_fahrenheit = dht.readTemperature(true);
  // Print the temperature to the Serial Monitor:
  Serial.println(temperature_celsius);
  Serial.println(temperature_fahrenheit);

  // Show the temperature on the TM1637 display:
  display.showNumberDec(temperature_celsius, false, 2, 0);
  display.setSegments(celsius, 2, 2);

  delay(2000);

  display.showNumberDec(temperature_fahrenheit, false, 2, 0);
  display.setSegments(fahrenheit, 2, 2);

  delay(2000);
}

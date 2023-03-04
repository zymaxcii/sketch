// 18b20_tester.ino
// 2 sensors

#include <DallasTemperature.h>

// Example_Temperature.ino
/*********
  Rui Santos
  Complete project details at http://randomnerdtutorials.com  
  Based on the Dallas Temperature Library example
*********/


#include <OneWire.h>
#include <DallasTemperature.h>

// My standard connection to D8
#define ONE_WIRE_BUS 8

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature sensor 
DallasTemperature sensors(&oneWire);


void setup(void)
{
  Serial.begin(9600);
  // Start up the library
  sensors.begin();
}


void loop(void)
{ 
  // Call sensors.requestTemperatures() to issue a global temperature
  // and Requests to all devices on the bus
  sensors.requestTemperatures(); 
  
  Serial.print("Celsius temperature sensor 1: ");
  // Why "byIndex"? You can have more than one IC on the same bus
  // 0 refers to the first IC on the wire
  Serial.print(sensors.getTempCByIndex(0)); 
  Serial.print(" - Fahrenheit temperature sensor 1: ");
  Serial.println(sensors.getTempFByIndex(0));
  delay(5000);

  Serial.print("Celsius temperature sensor 2: ");
  Serial.print(sensors.getTempCByIndex(1)); 
  Serial.print(" - Fahrenheit temperature sensor 2: ");
  Serial.println(sensors.getTempFByIndex(1));
  delay(5000);
}

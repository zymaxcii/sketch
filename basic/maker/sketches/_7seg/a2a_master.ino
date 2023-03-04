#include <Wire.h>   //we need the wire library for I2C comms
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#define DHTPIN            8
#define DHTTYPE           DHT11
DHT_Unified dht(DHTPIN, DHTTYPE);

int temp = 0;
//------------------------------------------------------


void setup() {
  Wire.begin(); // leave blank to designate as master
  dht.begin();
}
//------------------------------------------------------


void loop() {
  
  sensors_event_t event;  
  dht.temperature().getEvent(&event);
  temp = (event.temperature);
  
  Wire.beginTransmission(8); // transmit to device #8
  Wire.write(temp);              // sends temp
  Wire.endTransmission();    // stop transmitting

  
  delay(500);
}

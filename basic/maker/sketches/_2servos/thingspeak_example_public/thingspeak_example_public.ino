
#include <WiFi101.h>
#include "DHT.h"
#include "ThingSpeak.h"

#define DHTPIN 12
#define DHTTYPE DHT11   // DHT 11


DHT dht(DHTPIN, DHTTYPE);
WiFiClient client;

char ssid[] = "MYNETWORK"; //  your network SSID (name)
char pass[] = "MYPASSWORD";    // your network password (use for WPA, or use as key for WEP)
int status = WL_IDLE_STATUS;

unsigned long myChannelNumber = 123456;
const char * myWriteAPIKey = "MYWRITEKEY";

void setup() {
  Serial.begin(9600);
  WiFi.setPins(8,7,4,2);
  WiFi.begin(ssid, pass);
  ThingSpeak.begin(client);
  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

 
  float h = dht.readHumidity();
  float f = dht.readTemperature(true);


  ThingSpeak.setField(1,f);
  ThingSpeak.setField(2,h);
  ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey); 

  /*
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.println(" %\t");
  Serial.print("Temperature: ");
  Serial.print(f);
  Serial.println(" *F\t");
*/
  delay(20000);
 
}

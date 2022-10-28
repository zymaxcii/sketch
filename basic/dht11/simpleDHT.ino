// https://www.hackster.io/hardikrathod/create-gui-to-visualize-temp-and-humidity-for-arduino-85a7aa


// Download 'SimpleDHT' library from the library manager to run this
// code successfully.
#include <SimpleDHT.h>

// for DHT22, 
//      VCC: 5V or 3V
//      GND: GND
//      DATA: 2
int pinDHT22 = 2;
SimpleDHT22 dht22;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // start working...
  
  // read without samples.
  // @remark We use read2 to get a float data, such as 10.1*C
  //    if user doesn't care about the accurate data, use read to get a byte data, such as 10*C.
  float temperature = 0;
  float humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht22.read2(pinDHT22, &temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT22 failed, err="); Serial.println(err);delay(2000);
    return;
  }
  
  Serial.print((float)temperature);
  Serial.print(",");
  Serial.println((float)humidity);
  
  // DHT22 sampling rate is 0.5HZ.
  delay(2500);
}

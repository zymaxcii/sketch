/*
 * Arduino Datalogging
 * 
 * learnelectronics
 * 19 April 2017
 * 
 * www.youtube.com/c/learnelectronics
 * arduino0169@gmail.com
 */




#include "DHT.h"                        //Library for DHT sensor
#include <SPI.h>                        //Serial library for SD card shield
#include <SD.h>                         //SD card library

#define DHTPIN 8                        //DHT sensor on pin Digital 8
#define DHTTYPE DHT22                   //DHT type (11,21,22)
DHT dht(DHTPIN, DHTTYPE);               //create instance of DHT called dht

const int chipSelect = 4;               //chip select on digital 4 for SD card shield

void setup() {

  Serial.begin(9600);                   //begin serial comms
  while (!Serial) {
    ;                                   // wait for serial port to connect. Needed for native USB port only
  }


  Serial.print("Initializing SD card...");

                                        // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }
  Serial.println("card initialized.");

    dht.begin();                        //begin the DHT sensor
}

void loop() {
    delay(2000);                        //wait a minimum of 2 seconds between reads
    float h = dht.readHumidity();       //read humidity from DHT
    float f = dht.readTemperature(true);//read temp in F from DHT
    
                                        // make a string for assembling the data to log:
  String dataString = "";

  dataString += String(h);
  dataString += ",";
  dataString += String(f);
  
  

                                        // open the file. note that only one file can be open at a time,
                                        // so you have to close this one before opening another.
  File dataFile = SD.open("datalog.txt", FILE_WRITE);

                                        // if the file is available, write to it:
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
                                        // print to the serial port too:
    Serial.println(dataString);
  }
                                        // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
  }
}










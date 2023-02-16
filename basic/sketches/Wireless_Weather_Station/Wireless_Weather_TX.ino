/*
 * Arduino Wireless Weather Station
 * Transmitter Code
 *
 * 
 * by learnelectronics
 * 21 MAR 2017
 * 
 * www.youtube.com/c/learnelectronics
 * arduino0169@gmail.com
 *
 */

//-----------------------------------------------------------------------------------------------------
//                                              LIBRARIES
//-----------------------------------------------------------------------------------------------------

#include <VirtualWire.h>                            //Library for the Radios
#include "DHT.h"                                    //Library for the DHT11 Sensor

//-----------------------------------------------------------------------------------------------------
//                                               DEFINES
//-----------------------------------------------------------------------------------------------------

#define DHTPIN  4                                   //DHT Output on D4
#define DHTTYPE DHT11                               //DHT Type (11,21,22)

//-----------------------------------------------------------------------------------------------------
//                                              VARIABLES
//-----------------------------------------------------------------------------------------------------
const int led_pin = 13;                             //LED on D13
const int transmit_pin = 12;                        //Radio input on D12
//-----------------------------------------------------------------------------------------------------
//                                           DATA STRUCTURES
//-----------------------------------------------------------------------------------------------------

// If you are not familiar with Data Structures visit this link http://www.cplusplus.com/doc/tutorial/structures/

struct package                                      //Struct Type Name
{
  float temperature ;                               //Struct Member
  float humidity ;                                  //Struct Member
};


typedef struct package Package;                     //Define name of
Package data;                                       //Object name

//-----------------------------------------------------------------------------------------------------
//                                            LIBRARY CALLS
//-----------------------------------------------------------------------------------------------------
DHT dht(DHTPIN, DHTTYPE);                           //Create instance of DHT called dht

//-----------------------------------------------------------------------------------------------------
//                                                SETUP
//-----------------------------------------------------------------------------------------------------
void setup()
{
    
    vw_set_tx_pin(transmit_pin);                    //initialize radio on D12
    vw_set_ptt_inverted(true);                      // Required for DR3100
    vw_setup(500);                                  // Bits per sec
    pinMode(led_pin, OUTPUT);                       //set LED for output
}

//-----------------------------------------------------------------------------------------------------
//                                              MAIN LOOP
//-----------------------------------------------------------------------------------------------------

void loop()
{
  digitalWrite(led_pin, HIGH);                      // Flash a light to show transmitting
  readSensor();                                     //Call readSensor function
  vw_send((uint8_t *)&data, sizeof(data));          //send data (struct array)
  vw_wait_tx();                                     // Wait until the whole message is gone
  digitalWrite(led_pin, LOW);                       //LED off
  delay(2000);                                      //wait 2 seconds
}
//-----------------------------------------------------------------------------------------------------
//                                              FUNCTIONS
//-----------------------------------------------------------------------------------------------------
void readSensor()                                   //readSensor function
{
 dht.begin();                                       //initialize dht
 delay(1000);                                       //wait 1 second
 data.humidity = dht.readHumidity();                //get humidity & store in Struct variable data.humidity
 data.temperature = dht.readTemperature();          //get temperature & store in Struct variable data.temperature
}


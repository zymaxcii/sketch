/*
 * Arduino Wireless Weather Station
 * Receiver Code
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
//                                            LIBRARIES
//-----------------------------------------------------------------------------------------------------

#include <VirtualWire.h>


//-----------------------------------------------------------------------------------------------------
//                                            VARIABLES
//-----------------------------------------------------------------------------------------------------
const int led=13;
const int receive_pin = 12;
char temperatureChar[10];
char humidityChar[10];

//-----------------------------------------------------------------------------------------------------
//                                          DATA STRUCTURE
//-----------------------------------------------------------------------------------------------------
struct package                                      //Struct Type Name
{
  float temperature = 0.0;                          //Struct Member                        
  float humidity = 0.0;                             //Struct Member
};


typedef struct package Package;                     //Define name of
Package data;                                       //Object name

//-----------------------------------------------------------------------------------------------------
//                                              SETUP
//-----------------------------------------------------------------------------------------------------
void setup()
{
    
Serial.begin(9600);                                 //start serial comms for output
    
    pinMode(led,OUTPUT);                            //LED set for output
    vw_set_rx_pin(receive_pin);                     //initialize receiver on pin D12
    vw_setup(500);                                  // Bits per sec
    vw_rx_start();                                  // Start the receiver PLL running
}


//-----------------------------------------------------------------------------------------------------
//                                            MAIN LOOP
//-----------------------------------------------------------------------------------------------------
void loop()
{
    uint8_t buf[sizeof(data)];                      //unsigned int 8 bit called buf with size specified in Struct member data
    uint8_t buflen = sizeof(data);                  //unsigned int 8 bit called buflen with size specified in Struct member data

if (vw_have_message())                              //Check for activity 
  {
    digitalWrite(led,HIGH);                         //flash LED
    vw_get_message(buf, &buflen);                   //get the data, store in variable buf with length of bufflen
    memcpy(&data,&buf,buflen);                      //memcpy ( void * destination, const void * source, size_t num );

    Serial.print("Temp     ");                      //print header to serial port
    Serial.print((data.temperature*1.8)+32);        //print temperature in F to serial port
    Serial.println("F");                            //print units to serial port with CR
    
    
    Serial.print("Humidity ");                      //print header to serial port
    Serial.print(data.humidity);                    //print humidity to serial port
    Serial.println("%");                            //print units to serial port with CR
    delay(100);                                     //wait 100 miliseconds
    digitalWrite(led,LOW);                          //led off
  }
}



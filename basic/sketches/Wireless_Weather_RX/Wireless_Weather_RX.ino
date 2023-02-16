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
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

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
  bool rain ;                                       //Struct Member
};


typedef struct package Package;                     //Define name of
Package data;                                       //Object name


//-----------------------------------------------------------------------------------------------------
//                                          Library Calls
//-----------------------------------------------------------------------------------------------------
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);

//-----------------------------------------------------------------------------------------------------
//                                              SETUP
//-----------------------------------------------------------------------------------------------------
void setup()
{
display.begin();                                      //display setup doo doo
display.setContrast(60);                              //display setup doo doo
display.display();                                    //display setup doo doo
display.clearDisplay();                               //display setup doo doo
display.setTextSize(1);                               //display setup doo doo
display.setTextColor(BLACK);                          //display setup doo doo   

Serial.begin(9600);                                   //start serial comms for output
    
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
 display.clearDisplay();
  
    uint8_t buf[sizeof(data)];                      //unsigned int 8 bit called buf with size specified in Struct member data
    uint8_t buflen = sizeof(data);                  //unsigned int 8 bit called buflen with size specified in Struct member data

if (vw_have_message())                              //Check for activity 
  {
    digitalWrite(led,HIGH);                         //flash LED
    vw_get_message(buf, &buflen);                   //get the data, store in variable buf with length of bufflen
    memcpy(&data,&buf,buflen);                      //memcpy ( void * destination, const void * source, size_t num );

/*
    display.print("Temp: ");                         //print header to serial port
    display.print((data.temperature*1.8)+32);        //print temperature in F to serial port
    display.println("F");                            //print units to serial port with CR
    display.print("Hum:  ");                         //print header to serial port
    display.print(data.humidity);                    //print humidity to serial port
    display.println("%");                            //print units to serial port with CR
    display.display();
*/    
    
display.setCursor(0,0);
display.print("Ext Condition");


display.setCursor(0,11);
display.print(" Temp    RH%");                                            //display headers
display.drawRoundRect(0, 18, 40, 18, 4, BLACK);                           //draw box for current temp
display.drawRoundRect(42, 18, 40, 18, 4, BLACK);                          //draw box for set temp
display.setCursor(10,22);                                                 //put cursor in 1st box
display.print((data.temperature*1.8)+32,1);                               //display current temp in F
display.setCursor(52,22);                                                 //put cursor in 2nd box
display.print(data.humidity,1);
display.setCursor(0,40);
if(data.rain){                                                            //if data.rain == 1
  display.print(" >>>>Rain<<<<");                                         //print rain
}
else{                                                                     //if it's 0
  display.print(" >>>>Dry <<<<");                                         //print dry
}
    
display.display();                                                        //show the display
    
    delay(100);                                      //wait 100 miliseconds
    digitalWrite(led,LOW);                           //led off
  }
}



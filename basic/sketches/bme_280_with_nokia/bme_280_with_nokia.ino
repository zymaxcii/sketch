/*
 * BME280 Temperature/Pressure/Humidity Sensor Demo
 * With Nokia 5110 Display
 * 
 * learnelectronics
 * 01 MAR 2017
 * 
 * www.youtube.com/c/learnelectronics
 * arduino0169@gmail.com
 */


// Software SPI for Nokia 5110
// pin 7  - Serial clock out (SCLK)
// pin 6  - Serial data out (DIN)
// pin 5  - Data/Command select (D/C)
// pin 4  - LCD chip select (CS)
// pin 3  - LCD reset (RST)

// I2C for BME280 Sensor
// pin A4 - SDA (Serial Data)
// pin A5 - SCK (Serial Clock)
// if you are using the DIYMALL or Adafruit BME 280
// Vcc    - +5V
// if you are using a board without a 3.3v regulator
// Vcc    - +3.3V
// for all boards
// Gnd    - Gnd
//-----------------------------------------------------------------------------------------------
//                                         LIBRARIES
//-----------------------------------------------------------------------------------------------


#include <Adafruit_Sensor.h>                    //adafruit unified sensor library
#include <Adafruit_BME280.h>                    //adafruit bme280 sensor library
#include <SPI.h>                                //Serial Interface library
#include <Adafruit_PCD8544.h>                   //adafruit nokia5110 library


//-----------------------------------------------------------------------------------------------
//                                         DEFINES
//-----------------------------------------------------------------------------------------------

#define BME_SCK 13                              //softspi clock on D13
#define BME_MISO 12                             //softspi miso on D12
#define BME_MOSI 11                             //softspi mosi on D11
#define BME_CS 10                               //softspi chip select on D10

#define SEALEVELPRESSURE_HPA (1013.25)          //pressure @ sea level



//-----------------------------------------------------------------------------------------------
//                                         OBJECTS
//-----------------------------------------------------------------------------------------------

Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3); //create instance of display
Adafruit_BME280 bme;                                        //create instance of bme

//-----------------------------------------------------------------------------------------------
//                                         VARIABLES
//-----------------------------------------------------------------------------------------------

float dewPoint = 0;                                         //float for dew point
float rh100 = 0;                                            //float for dew pt calc
float rh5 = 0;                                              //float for dew pt calc


//-----------------------------------------------------------------------------------------------
//                                         SETUP
//-----------------------------------------------------------------------------------------------

void setup()   {
  Serial.begin(9600);                                       //serial comms @ 9600baud
  bme.begin();                                              //start bme280
  display.begin();                                          //start display
  display.setContrast(60);                                  //contrast 0-100

  display.display();                                        //show display
  display.clearDisplay();                                   // clears the screen and buffer

}

//-----------------------------------------------------------------------------------------------
//                                         MAIN LOOP
//-----------------------------------------------------------------------------------------------

void loop() {

  display.clearDisplay();                                   // clears the screen and buffer
  display.setTextSize(1);                                   // set text size to 1
  display.setTextColor(BLACK);                              // set text color to black
  display.setCursor(0,0);                                   // cursor to upper left
  


    display.print("Temp: ");                                // print header to buffer
    display.print(bme.readTemperature()*1.8+32);            // print temp in F to buffer
    display.println(" F");                                  // print unit to buffer

    display.print("Pres: ");                                // print header to buffer

    display.print((bme.readPressure() / 100.0F)*0.02953);   // print press in inches of Hg to buffer
    display.println(" I");                                  // print unit to buffer

    display.print("Hmdt: ");                                // print header to buffer
    display.print(bme.readHumidity());                      // print rel humidity % to buffer
    display.println(" %");                                  // print unit to buffer

    /*
     *                      Dew Point Calculation
     *                            
     *                                  100-RH
     *                       Dpt = T - ---------
     *                                    5
     *                                    
     *                       Dpt = Dew Point
     *                       RH  = Relative Humidity
     *                       T   = Temperature in Celcius
     *                  C to F   = (C*1.8)+32
     */
    
    
    
    
    
    rh100 = 100-bme.readHumidity();                         //do the 100-RH
    rh5 = rh100/5;                                          //divide by 5
    dewPoint = bme.readTemperature() - rh5;                 // Dpt
    
 
    display.print("D.P.: ");                                // print header to buffer
    display.print(dewPoint*1.8+32);                         // print dew point in F to buffer
    display.println(" F");                                  // print unit to buffer
  
  display.display();                                        // show everything just printed to buffer
  delay(2000);                                              // wait time between measurements (2 sec)
}



/*
 * Arduino Current Control
 * 
 * learnelectronics
 * 08 MAR 2017
 * 
 * www.youtube.com/c/learnelectronics
 * arduino0169@gmail.com
 */


//-------------------------------------------------------------------------------------------------------
//                                             LIBRARIES
//-------------------------------------------------------------------------------------------------------
#include <Wire.h>                                     //for I2C comms with OLED & INA219
#include <Adafruit_SSD1306.h>                         //for OLED Screen
#include <INA219.h>


//-------------------------------------------------------------------------------------------------------
//                                               DEFINES
//-------------------------------------------------------------------------------------------------------
#define OLED_RESET 4                                  //reset pin for OLED not used
#define relay      5                                  //relay on digital 5



//-------------------------------------------------------------------------------------------------------
//                                          LIBRARY OBJECTS
//-------------------------------------------------------------------------------------------------------
Adafruit_SSD1306 display(OLED_RESET);                 //create instance of oled called display
INA219 monitor;                                       //create instance of ina219 called monitor



//-------------------------------------------------------------------------------------------------------
//                                            VARIABLES
//-------------------------------------------------------------------------------------------------------
int pot = 0.000;                                      //to store analog read of pot on A0
float iMax = 0.000;                                   //pot mapped value
float iSet = 0;                                       //iMax in milliAmps
float iNow = 0;                                       //the current curent (lol)

//-------------------------------------------------------------------------------------------------------
//                                                SETUP
//-------------------------------------------------------------------------------------------------------

void setup()   {                
  Serial.begin(9600);                                 //serial comms for debug
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);          //begin oled @ hex addy 0x3C
  monitor.begin();                                    //begin monitor
  display.display();                                  //prepare oled
  delay(2000);
  display.clearDisplay();
  pinMode(relay,OUTPUT);                              //set relay as output
  digitalWrite(relay,HIGH);                           //turn on relay


}

//-------------------------------------------------------------------------------------------------------
//                                             MAIN LOOP
//-------------------------------------------------------------------------------------------------------
void loop() {

  pot = analogRead(A0);                               //read A0
  iMax = map(pot,0,1023,0,3200);                      //map A0 to 3200 (ina219 max I = 3.2A)
  iSet = iMax/1000;                                   //store maxamps in milliamps
  iNow = (monitor.shuntCurrent());                    //get current current

  /*
   * 
   *                                                  //for debugging
  Serial.print("iSet ");
  Serial.println(iSet);
  Serial.print("iNow ");
  Serial.println(iNow);
  Serial.print("cut ");
  Serial.println(cut);
*/
 
  
  display.setTextSize(1);                            //set text size
  display.setTextColor(WHITE);                       //set text color
  display.setCursor(0,0);                            //cursr to upper left
  display.print("Max Amps:     ");                   //print title to buffer
  display.print(iSet,3);                             //print iSet to 3 places to buffer
  display.println(" A");                             //print units to buffer
  display.print("Current Amps: ");
  display.print(iNow);
  display.println(" A");
  display.display();                                 //show whats in buffer
  display.clearDisplay();                            //clear buffer so we dont overwrite

  if(iSet<iNow){                                      //if we are over our set current
    
    display.clearDisplay();                           //clear display
    digitalWrite(relay,LOW);                          //cut power to load
    display.println(" ");                             //give some info & warnings
    display.println("OVERCURRENT");
    display.println(" ");
    display.println("Reset Load");
    display.display();
    delay(50000);                                     //wait 50 seconds
  }
  
  
  
}





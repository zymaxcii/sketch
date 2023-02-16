/*
 * Arduino 4x4 Keypad Read Example with OLED
 * 
 * learnelectronics
 * 06 April 2017
 * 
 * www.youtube.com/c/learnelectronics
 * arduino0169@gmail.com
 * 
 * note: connect ribbon cable to digital pins 2-9
 * starting at the far right to digital 2 and
 * finishing with far left on digital 9
 */


//--------------------------------------------------------------------------------------------------------------------------
//                                                    LIBRARIES
//--------------------------------------------------------------------------------------------------------------------------
#include <Keypad.h>                                                           //keypad library
#include <Wire.h>                                                             //I2C library for OLED
#include <Adafruit_SSD1306.h>                                                 //OLED Driver library

//--------------------------------------------------------------------------------------------------------------------------
//                                                        DEFINES
//--------------------------------------------------------------------------------------------------------------------------
#define OLED_RESET 4                                                          //not really used

Adafruit_SSD1306 display(OLED_RESET);                                         //create instance of OLED called display

const byte ROWS = 4; //four rows                                              //declare rows
const byte COLS = 4; //three columns                                          //declare columns
char keys[ROWS][COLS] = {                                                     //declare 2 dimensional array to map keys
  {'1', '4', '7', '*'},
  {'2', '5', '8', '0'},
  {'3', '6', '9', '#'},
  {'A', 'B', 'C', 'D'}
};
byte rowPins[ROWS] = {5, 4, 3, 2};                                            //connect to the row pinouts of the keypad
byte colPins[COLS] = {9, 8, 7, 6};                                            //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );     //create instance of Keypad called keypad


//--------------------------------------------------------------------------------------------------------------------------
//                                                        SETUP
//--------------------------------------------------------------------------------------------------------------------------
void setup(){
  
  
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);                                  //start oled @ hex addy 0x3C
  display.display();                                                          //show buffer
  display.clearDisplay();                                                     //clear buffer
}

  //--------------------------------------------------------------------------------------------------------------------------
//                                                      MAIN LOOP
//--------------------------------------------------------------------------------------------------------------------------
void loop(){
  display.setTextSize(3);                                                     //set text size (1-6)
  display.setTextColor(WHITE);                                                //set text color
  display.setCursor(0,0);                                                     //cursor to upper left
  
  
  char key = keypad.getKey();                                                 //use keypad.getKey function to
                                                                              //to define the value of Char variable key
  
  if (key){                                                                   //if a key has been pressed
    display.clearDisplay();                                                   //clear last display
    display.println(key);                                                     //print the value of variable key
    display.display();                                                        //show buffer
    
  }
}

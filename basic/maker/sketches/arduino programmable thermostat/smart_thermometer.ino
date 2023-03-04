/*
 * Arduino Programmable Thermostat
 * 
 * learnelectronics
 * 11 MAR 2017
 * 
 * www.youtube.com/c/learnelectronics
 * arduino0169@gmail.com
 */

//----------------------------------------------------------------------------------------------------------------------------------------
//                                                             LIBRARIES
//---------------------------------------------------------------------------------------------------------------------------------------- 
#include <SPI.h>                                                        //spi library for 5110
#include <DS3231.h>                                                     //rtc library
#include <Wire.h>                                                       //I2C library for rtc
#include <Adafruit_GFX.h>                                               //graphix lib for drawing
#include <Adafruit_PCD8544.h>                                           //nokia 5110 display library

//----------------------------------------------------------------------------------------------------------------------------------------
//                                                             DEFINES
//----------------------------------------------------------------------------------------------------------------------------------------
#define RELAY A2                                                        //relay on pin A2
#define BUTTON 8                                                        //rot enc switch on pin D8

//----------------------------------------------------------------------------------------------------------------------------------------
//                                                            OBJECTS
//----------------------------------------------------------------------------------------------------------------------------------------
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);             //create instance of 5110 called display with soft spi
DS3231 Clock;                                                           //create instance of 3231 called clock

//----------------------------------------------------------------------------------------------------------------------------------------
//                                                             VARIABLES
//----------------------------------------------------------------------------------------------------------------------------------------
bool Century=false;                                                     //clock variables
bool h12;                                                               //clock variables
bool PM;                                                                //clock variables
byte ADay, AHour, AMinute, ASecond, ABits;                              //clock variables
bool ADy, A12h, Apm;                                                    //clock variables
bool menu = 0;                                                          //display menu or page
bool amDone = 0;
byte year, month, date, DoW, hour, minute, second;                      //clock variables
byte myHour1=12,myMin1=00,myTemp1=67,myHour2=19,myMin2=00,myTemp2=69;

byte tset = 67;                                                         //master temp set
String myMode = " Manual Heat ";                                        //mode (manual or program)
int temperature = 0;                                                    //clock variables
int select = 1;                                                         //selection variable
int menuState = 0;                                                      //show menu or main page variable

//----------------------------------------------------------------------------------------------------------------------------------------
//                                                              SETUP
//----------------------------------------------------------------------------------------------------------------------------------------
void setup()   {  
  Serial.begin(9600);                                                   //start serial comms
  Wire.begin();                                                         //start I2C
  display.begin();                                                      //start display
  /*
   *    Clock.setSecond(00);//Set the second                            //clock set uncomment to use
        Clock.setMinute(05);//Set the minute 
        Clock.setHour(11);  //Set the hour 
        Clock.setDoW(06);    //Set the day of the week
        Clock.setDate(11);  //Set the date of the month
        Clock.setMonth(03);  //Set the month of the year
        Clock.setYear(17);  //Set the year (Last two digits of the year)
   */

  pinMode(9,INPUT);                                                      //rot enc a
  pinMode(10,INPUT);                                                     //rot enc b
  pinMode(RELAY,OUTPUT);                                                 //set relay for output
  pinMode(BUTTON,INPUT);                                                 //set button for output
  digitalWrite(BUTTON,HIGH);                                             //set buton high (1)
  display.setContrast(60);                                               //set contrast (adjust as needed)
  display.display();                                                     // show splashscreen
  display.clearDisplay();                                                // clears the screen and buffer

 
}
//----------------------------------------------------------------------------------------------------------------------------------------
//                                                           MENU FUNCTION
//----------------------------------------------------------------------------------------------------------------------------------------
void myMenu(){                                                            //menu display mode
  menu= 1;                                                                //when 1 stays in menu
  amDone = 1;                                                             //when 1 stays in menu
  int x = 0;                                                              //for rot enc
  int y = 0;                                                              //for rot enc
  display.clearDisplay();                                                 // clears the screen and buffer
  display.setTextColor(BLACK);                                            //set text color to black
  display.setCursor(0,0);
  display.setTextSize(1);
  display.println("Program Menu");                                        //displays menu screen items
  display.println(" ");
  display.print("1- " );
  display.print(myHour1);
  display.print(":");
  display.print(myMin1);
  display.print(" | ");
  display.println(myTemp1);
 
  display.display();
  int clicker = digitalRead(BUTTON);                                      //read button
  if(clicker == 0){                                                       //if pressed
   delay(100);                                                            //delay for debounce
   if(digitalRead(BUTTON)== 1){                                           //if not pressed (equals a single press)
    menuState++;                                                          //increment menu item
   }
   
  }
switch (menuState) {                                                      //what to do for button presses
    case 1:                                                               //first press
 
      display.setCursor(20,26);                                           //cursor under hours
      display.print("^^");
      x = digitalRead(9);                                                 //read rot enc
      y = digitalRead(10);                                                //read rot enc
      if(x == 0 && y == 1){                                               // if clockwise
        myHour1++;                                                        //increment hour
      }
      else if (x == 1 && y == 0){                                         //if counter clockwise
         myHour1--;                                                       //decrement hour
  
      }
      else{                                                               //no rotation
        myHour1 = myHour1;                                                //no change
      }
      display.display();                                                  //update display
      break;
    case 2:                                                               //second press
      display.setCursor(35,26);                                           //cursor under minutes
      display.print("^^");
      x = digitalRead(9);
      y = digitalRead(10);
      if(x == 0 && y == 1){
        myMin1++;
      }
      else if (x == 1 && y == 0){
         myMin1--;
  
      }
      else{
        myMin1 = myMin1;
      }
      display.display();
      break;
    case 3:                                                               //third press
      display.setCursor(60,26);                                           //cursor under temp
      display.print("^^");
      x = digitalRead(9);
      y = digitalRead(10);
      if(x == 0 && y == 1){
        myTemp1++;
      }
      else if (x == 1 && y == 0){
         myTemp1--;
  
      }
      else{
        myTemp1 = myTemp1;
      }
      display.display();
    break;
   case 4:                                                                //fourth press
       myMode = "Program Heat";                                           //mode change
       menu= 0;                                                           //clear menu variables
       amDone = 0;                                                        //signal programming done
       menuState = 0;                                                     //reset menu
    break;
  }

Serial.print(clicker);
Serial.print(" ");
Serial.println(menuState);

  
  }




//----------------------------------------------------------------------------------------------------------------------------------------
//                                                            MAIN LOOP
//----------------------------------------------------------------------------------------------------------------------------------------

void loop() {
temperature=Clock.getTemperature();                                       //get current temp
Clock.getTime(year, month, date, DoW, hour, minute, second);              //get current time


select = digitalRead(BUTTON);                                             //was the button pressed
if (select == 0){                                                         //if pressed 
  menu = 1;                                                               //set menu variable to 1
}
else{                                                                     //if not
  menu = 0;                                                               //menu variable to 0
}
if(menu == 1 || amDone == 1){                                             //if button was pressed & have not completed programming
  myMenu();                                                               // go to my menu
}
else{                                                                     //if not
  pageDisplay();                                                          //show main page
}

if(myMode = "Program Heat"){                                              //if thermostat has been programmed
  if(hour>=myHour1 && minute>=myMin1){                                    //and hour and minute match set time
    tset=myTemp1;                                                         //master temp set set to programmed temp
  }
}
else{                                                                     //if not programmed
  tset=tset;                                                              //nothing changes
}


if(tset > ((temperature*1.8)+32)){                                        //if set temp is greater than current temp
  digitalWrite(RELAY,HIGH);                                               //turn on the heat
}
else{                                                                     //if not
  digitalWrite(RELAY,LOW);                                                //turn off the heat
}

}


//----------------------------------------------------------------------------------------------------------------------------------------
//                                                      PAGE DISPLAY FUNCTION
//----------------------------------------------------------------------------------------------------------------------------------------
void pageDisplay(){                                                       //main display page

display.clearDisplay();                                                   //clear
display.setTextColor(BLACK);                                              //set color
display.drawRoundRect(0, 0, 84, 10, 4, BLACK);                            //draw rounded box for time
display.setCursor(20,1);                                                  //put cursor in box
display.setTextSize(1);                                                   //set text size

display.print(hour, DEC);                                                 //display time in box
display.print(":");
display.print(minute, DEC);
display.print(":");
display.println(second, DEC);
display.setCursor(0,11);
display.print(" Temp    Set");                                            //display headers
display.drawRoundRect(0, 18, 40, 18, 4, BLACK);                           //draw box for current temp
display.drawRoundRect(42, 18, 40, 18, 4, BLACK);                          //draw box for set temp
display.setCursor(14,22);                                                 //put cursor in 1st box
display.print((temperature*1.8)+32,0);                                    //display current temp in F
display.setCursor(56,22);                                                 //put cursor in 2nd box
display.print(tset);                                                      //display set temp in F
display.setCursor(0,37);                                                  //drop down set cursor
display.setTextColor(WHITE, BLACK);                                       //set inverse text
display.print(myMode);                                                    //display mode
display.display();                                                        //display buffer contents

int a = digitalRead(9);                                                   //rot enc a
int b = digitalRead(10);                                                  //rot enc b


if(a == 0 && b == 1){                                                     //if clockwise
  tset++;                                                                 //increment temp
}
else if (a == 1 && b == 0){                                               //if counterclockwise
  tset--;                                                                 //decrement temp
  
}
else{                                                                     //if no movement
  tset = tset;                                                            //do nothing
}


  
}


// https://www.youtube.com/watch?v=U2JI582V5xk

/*********************************************************************
This is an example for our Monochrome OLEDs based on SSD1306 drivers

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/category/63_98

This example is for a 128x32 size display using I2C to communicate
3 pins are required to interface (2 I2C and one reset)

Adafruit invests time and resources providing this open source code, 
please support Adafruit and open-source hardware by purchasing 
products from Adafruit!

Written by Limor Fried/Ladyada  for Adafruit Industries.  
BSD license, check license.txt for more information
All text above, and the splash screen must be included in any redistribution
*********************************************************************/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSans9pt7b.h>
#include "String.h"
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);




static const unsigned char PROGMEM calc[] =
{0x01, 0xFF, 0xFF, 0x80, 0x03, 0x00, 0x00, 0xC0, 0x06, 0x00, 0x00, 0x60, 0x0C, 0x00, 0x00, 0x30,
0x08, 0x3F, 0xFC, 0x10, 0x08, 0xE0, 0x07, 0x10, 0x09, 0x80, 0x01, 0x90, 0x09, 0x00, 0x00, 0x90,
0x09, 0x00, 0x00, 0x90, 0x09, 0x00, 0x00, 0x90, 0x09, 0x00, 0x00, 0x90, 0x09, 0x00, 0x00, 0x90,
0x09, 0x00, 0x00, 0x90, 0x09, 0x80, 0x01, 0x90, 0x08, 0xE0, 0x07, 0x10, 0x08, 0x3F, 0xFC, 0x10,
0x08, 0x00, 0x00, 0x10, 0x08, 0x00, 0x00, 0x10, 0x08, 0x00, 0x00, 0x10, 0x08, 0x21, 0x84, 0x10,
0x08, 0x73, 0xCE, 0x10, 0x08, 0x5A, 0x5A, 0x10, 0x08, 0x73, 0xCE, 0x10, 0x08, 0x00, 0x00, 0x10,
0x08, 0x00, 0x00, 0x10, 0x08, 0x73, 0xCE, 0x10, 0x08, 0x5A, 0x5A, 0x10, 0x08, 0x73, 0xCE, 0x10,
0x0C, 0x21, 0x84, 0x30, 0x06, 0x00, 0x00, 0x60, 0x03, 0x00, 0x00, 0xC0, 0x01, 0xFF, 0xFF, 0x80

};

 int operacija=0;

void setup()   {                


Serial.begin(9600);
for(int i=0;i<17;i++)
pinMode(i,INPUT_PULLUP);
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)

 

  // Clear the buffer.
  display.clearDisplay();
  display.setFont(&FreeSans9pt7b);
    
  display.setTextColor(WHITE);
  display.setCursor(36,12);
  display.print("Arduino");
  display.setCursor(36,31);
  display.print("calculator!");
  display.drawBitmap(0, 0,  calc, 32, 32, 1);
  display.display();
delay(2000);
  display.clearDisplay();



    display.setFont();
  display.setTextSize(2);
 

  
}
int changeNumber=0;
int over=0;
String num1="";
String num2="";
String broj="";
int stis[17]={0} ;
void loop() {
  display.clearDisplay();
for(int i=0;i<15;i++)
  {
    over=0;
  if(digitalRead(i)==0)
      {
      if(stis[i]==0)
        {
          if(i<10)
          broj=broj+i;

          if(i==10)
          broj=broj+"+";

           if(i==11)
          broj=broj+"-";

           if(i==12)
          broj=broj+"*";

           if(i==13)
          broj=broj+"/";

           if(i==14)
          broj=broj+".";

          
          
          
          stis[i]=1;
        }
      }else{stis[i]=0;}  
  }

 if (digitalRead(16)==0)
 {
  if(stis[16]==0)
     {
      broj="";
      stis[16]=1;
      
      }
  
  }else{stis[16]=0;}

 if(digitalRead(15)==0)
    {
      float n1=0.0000;
      float n2=0.0000;
      float res=0.0000;
     
      if(stis[15]==0)
            {
            
            stis[15]=1;
            int duz=broj.length();
            for(int i=0;i<duz;i++)
                   
                   {
                    if(broj.charAt(i)=='+'){
                    changeNumber=1;
                    operacija=1;}

                    if(broj.charAt(i)=='-'){
                    changeNumber=1;
                    operacija=2;}

                     if(broj.charAt(i)=='*'){
                    changeNumber=1;
                    operacija=3;}

                      if(broj.charAt(i)=='/'){
                    changeNumber=1;
                    operacija=4;}


                    
                   if(changeNumber==0)
                   {
                    char slovo=broj.charAt(i);
                   num1=num1+slovo;
                   }
                  
                     if(changeNumber==2){
                     char slovo=broj.charAt(i);
                   num2=num2+slovo;}

                     if(changeNumber==1)
                    changeNumber=2;
                   
                   
                    }
                     n1=num1.toFloat();
                     n2=num2.toFloat();
                    
                     if(operacija==1){
                     res=n1+n2;}
                         if(operacija==2){
                     res=n1-n2;}
                         if(operacija==3){
                     res=n1*n2;}
                         if(operacija==4){
                     res=n1/n2;} 
                    
                     Serial.println(n1); Serial.println(n2);
                      Serial.println(n1/n2);
                    broj="";
                    int tenths=res/10;
                    float remain=res-(tenths*10);
                    broj=(String)res;
                    changeNumber=0;
                    num1="";
                    num2="";
                    operacija=0;
                    
            }
      
    }else{stis[15]=0;}
  
  display.setCursor(0,11  );
   if(broj=="")
   {
    display.println(0);
    }else{
   display.println(broj);}
      display.display();
}

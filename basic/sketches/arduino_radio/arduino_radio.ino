/*
 * Arduino Radio with si4703
 * 
 * learnelectronics
 * 7 April 2017
 * 
 * www.youtube.com/c/learnelectronics
 * arduino0169@gmail.com
 */

 
#include <SPI.h>                        //SPI library for the OLED
#include <Wire.h>                       //I2C Library for the si4703
#include <Adafruit_SH1106.h>            //OLED driver
#include <radio.h>                      //library for the radio
#include <si4703.h>                     //driver for the radio


#define OLED_MOSI   9                   //soft SPI
#define OLED_CLK   10                   //soft SPI
#define OLED_DC    11                   //soft SPI
#define OLED_CS    12                   //soft SPI
#define OLED_RESET 13                   //soft SPI

#define sup         3                   //station up on pin 3
#define sdn         4                   //station down on pin 4
#define vup         5                   //volume up on pin 5
#define vdn         6                   //volume down on pin 6


                                        //create instance of OLED called display
Adafruit_SH1106 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);
SI4703 radio;                           //create instance of si4703 called radio

int station = 10350;                    //initial station
byte volume = 4;                        //initial volume


void setup()   {                
  
  pinMode(vup,INPUT_PULLUP);            //set switches for input w/ internal pullup
  pinMode(vdn,INPUT_PULLUP);            //set switches for input w/ internal pullup
  pinMode(sup,INPUT_PULLUP);            //set switches for input w/ internal pullup
  pinMode(sdn,INPUT_PULLUP);            //set switches for input w/ internal pullup
  
  Serial.begin(9600);                   //start serial comms
  display.begin(SH1106_SWITCHCAPVCC);   //start OLED
  display.display();                    //show buffer
  delay(100);                           //wait
  display.clearDisplay();               //clear screen & buffer
  radio.init();                         //start radio

  
                                        //set radio to FM and station to station
  radio.setBandFrequency(RADIO_BAND_FM, station);
  radio.setVolume(volume);              //set volume
  radio.setMono(false);                 //mono set to false
  radio.setMute(false);                 //mute set to false
}


void loop() {

  display.clearDisplay();               //clear display & buffer
  display.setCursor(0,0);               //cursor to upper left
  display.setTextSize(1);               //text size 1
  display.setTextColor(WHITE);          //color white
  display.println("Arduino Radio");     //print header
  display.print("Band: ");              //print band header
  display.println("  FM Stereo");       //print band
  display.print("Freq:   ");            //print freq header
  display.println(station);             //print frequency
  display.print("Volume: ");            //print volume header
  display.print(volume);                //print volume
  display.display();                    //show what we just printed

  if(digitalRead(sup)==0){              //if we pressed station up
    station = station + 20;
    radio.setBandFrequency(RADIO_BAND_FM, station);
  }
  if(digitalRead(sdn)==0){              //if we pressed station down
    station = station - 20;
    radio.setBandFrequency(RADIO_BAND_FM, station);
  }
  if(digitalRead(vup)==0){              //if we pressed volume up
    volume++;
    radio.setVolume(volume);
  }
  if(digitalRead(vdn)==0){              //if we pressed volume down
    volume--;
    radio.setVolume(volume);
  }
}



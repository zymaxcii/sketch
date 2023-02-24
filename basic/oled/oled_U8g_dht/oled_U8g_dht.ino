// oled_U8g_dht.ino
// Display temperature on oled screen
// status: compile , upload 


#include "U8glib.h"

U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE|U8G_I2C_OPT_DEV_0);	// I2C / TWI 

#include <Arduino.h>
#include <dht.h>

dht DHT;
#define DHT22_PIN 8


void draw(void)
{
  int chk = DHT.read22(DHT22_PIN);
  float temp=DHT.temperature;
  float humi=DHT.humidity;

  u8g.setFont(u8g_font_helvR24);
  u8g.setPrintPos(5,25); 
  u8g.print(temp);
  u8g.setPrintPos(100,25); 
  u8g.print("c"); 
  u8g.setPrintPos(5,60); 
  u8g.print(humi);
  u8g.print("%");
  u8g.setFont(u8g_font_courB10);
  u8g.setPrintPos(90,8); 
  u8g.print("o");   
}


void setup(void) { }


void loop(void)
{
  // picture loop
  u8g.firstPage();  
  
  do
  {
    draw();
    
  } while( u8g.nextPage() );
  
  // rebuild the picture after some delay
  delay(1000);
}

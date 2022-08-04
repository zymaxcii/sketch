// spi_master.ino
// work with spi_slave.ino
// using 1 led and 1 switch
// use switch to light up led on the other side

// SPI COMMUNICATION BETWEEN TWO ARDUINO 
// CIRCUIT DIGEST
// https://circuitdigest.com/microcontroller-projects/arduino-spi-communication-tutorial

#include <SPI.h>                          // Library for SPI 

#define LED 7           
#define ipbutton 2
int buttonvalue;
int x;


void setup (void)
{
  Serial.begin(9600); 
  pinMode(ipbutton, INPUT_PULLUP); 
  pinMode(LED, OUTPUT);

  SPI.begin();                            // Begins SPI commnuication
  SPI.setClockDivider(SPI_CLOCK_DIV8);    // Sets clock for SPI communication at 8 (16/8=2Mhz)
  digitalWrite(SS, HIGH);                 // Setting SlaveSelect as HIGH (So master doesnt connnect with slave)
}


void loop(void)
{
  byte Mastersend,Mastereceive;          
  buttonvalue = digitalRead(ipbutton);     // Reads status of the pin 2

  if (buttonvalue == HIGH)                 // Logic for Setting x value (To be sent to slave) depending upon input from pin 2
  {
    x = 1;
  }
  else
  {
    x = 0;
  }

  digitalWrite(SS, LOW);                  // Starts communication with Slave connected to master
  Mastersend = x;
  
  Mastereceive=SPI.transfer(Mastersend);  // Send mastersend value to slave also receives value from slave

  if (Mastereceive == 1)                  // Logic for setting the LED output depending upon value received from slave
  {
    digitalWrite(LED,HIGH);               // Sets pin 7 HIGH
    Serial.println("Master LED ON");
  }
  else
  {
   digitalWrite(LED,LOW);                  // Sets pin 7 LOW
   Serial.println("Master LED OFF");
  }
  delay(1000);
}

// spi_slave.ino
// slave in spi communication test
// work with spi_master.ino
// using an led and a switch
// to light up led on the other side


// SPI COMMUNICATION BETWEEN TWO ARDUINO 
// CIRCUIT DIGEST
// Pramoth.T
// https://circuitdigest.com/microcontroller-projects/arduino-spi-communication-tutorial


#include <SPI.h>
#define LEDpin 7
#define buttonpin 2
volatile boolean received;
volatile byte Slavereceived, Slavesend;
int buttonvalue;
int x;


void setup()
{
  Serial.begin(9600);
  pinMode(buttonpin, INPUT_PULLUP);
  pinMode(LEDpin, OUTPUT);
  pinMode(MISO, OUTPUT);                   // Sets MISO as OUTPUT (Have to Send data to Master IN)

  SPCR |= _BV(SPE);                        // Turn on SPI in Slave Mode
  received = false;
  SPI.attachInterrupt();                   // Interuupt ON is set for SPI commnucation
}


// Interrupt service routine
ISR (SPI_STC_vect) 
{
  Slavereceived = SPDR;                    // Value received from master if store in variable slavereceived
  received = true;                         // Sets received as True 
}


void loop()
{ if (received)                            // Logic to SET LED ON OR OFF depending upon the value recerived from master
  {
    if (Slavereceived==1) 
    {
      digitalWrite(LEDpin, HIGH);          // Sets pin 7 as HIGH LED ON
      Serial.println("Slave LED ON");
    }
    else
    {
      digitalWrite(LEDpin, LOW);           // Sets pin 7 as LOW LED OFF
      Serial.println("Slave LED OFF");
    }
      
    buttonvalue = digitalRead(buttonpin);  // Reads the status of the pin 2

    if (buttonvalue == HIGH)               // Logic to set the value of x to send to master
    {
      x=1;
    }
    else
    {
      x=0;
    }

    Slavesend=x;                             
    SPDR = Slavesend;                           //Sends the x value to master via SPDR 
    delay(1000);
  }
}

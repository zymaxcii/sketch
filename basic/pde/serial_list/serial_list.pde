// serial_list.pde

import processing.serial.*;
Serial myPort;

void setup()
{
  println("Available serial ports:");
  println( Serial.list() );
  myPort = new Serial(this, Serial.list()[4], 9600);
}

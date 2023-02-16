// pde2ino.pde
// https://howtomechatronics.com/tutorials/arduino/processing/

import processing.serial.*;

Serial myPort;
String myText="";


void setup()
{
  size(300, 300);
  myPort = new Serial(this, "/dev/ttyUSB0", 9600);
  myPort.bufferUntil('\n');
}


void serialEvent (Serial myPort)
{
  myText = myPort.readStringUntil('\n');      // n or \n?
}


void draw()
{
  background(0,0,0);
  text(myText, 120, 120);
  // delay(50);
  myText="";

  if (mousePressed && (mouseButton == LEFT))
  {
    myPort.write('1');
  }
  
  if (mousePressed && (mouseButton == RIGHT))
  {
    myPort.write('0');
  }
}

//Sine out
//by Amanda Ghassaei
//https://www.instructables.com/id/Arduino-Audio-Output/
//Sept 2012

/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
*/

void setup(){
  //set digital pins 0-7 as outputs
  for (int i=0;i<8;i++){
    pinMode(i,OUTPUT);
  }
}

void loop(){
  for (int t=0;t<100;t++){//increment "t"
    PORTD = 127+127*sin(2*3.14*t/100);//send sine wave to DAC, centered around (127/255)*5 = 2.5V
    delayMicroseconds(50);//wait 50us
  }
}


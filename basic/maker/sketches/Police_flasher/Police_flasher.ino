/*
 * Police Style Flasher
 * 
 * learnelectronics
 * 17 MAY 2017
 * 
 * www.youtube.com/c/learnelectronics
 * arduino0169@gmail.com
 */

#define red1  4                                 //Red LED #1 is on pin 4
#define red2  5                                 //Red LED #2 is on pin 5
#define blue1 12                                //Blue LED #1 is on pin 12
#define blue2 13                                //Blue LED #2 is on pin 13

int onTime = 100;                               //LEDs stay on for 100 milliseconds
int offTime = 500;                              //LEDS stay off for 1/2 second



void setup() {

pinMode(red1,OUTPUT);                           //pin 4 set for OUTPUT
pinMode(red2,OUTPUT);                           //pin 5 set for OUTPUT
pinMode(blue1,OUTPUT);                          //pin 12 set for OUTPUT
pinMode(blue2,OUTPUT);                          //pin 13 set for OUTPUT

}

void loop() {
                                                //first flash red LEDs twice
digitalWrite(red1,HIGH);                        //Red LED #1 on
digitalWrite(red2,HIGH);                        //Red LED #2 on
delay(onTime);                                  //wait for value held in variable onTime
digitalWrite(red1,LOW);                         //Red LED #1 off
digitalWrite(red2,LOW);                         //Red LED #2 off
delay(onTime);                                  //wait for value held in variable onTime
digitalWrite(red1,HIGH);                        //do the above 6 steps again
digitalWrite(red2,HIGH);
delay(onTime);
digitalWrite(red1,LOW);
digitalWrite(red2,LOW);
delay(offTime);                                 //wait for value held in variable offTime
                                                //Now flash blue LEDs twice
digitalWrite(blue1,HIGH);
digitalWrite(blue2,HIGH);
delay(onTime);
digitalWrite(blue1,LOW);
digitalWrite(blue2,LOW);
delay(onTime);
digitalWrite(blue1,HIGH);
digitalWrite(blue2,HIGH);
delay(onTime);
digitalWrite(blue1,LOW);
digitalWrite(blue2,LOW);
delay(offTime);
}

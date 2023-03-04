/*
 * Arduino Night Security Light
 * 
 * learnelectronics
 * 8 MAY 2017
 * 
 * www.youtube.com/c/learnelectronics
 * arduino0169@gmail.com
 * 
 * Here's a link to get your own PIR sensor: http://amzn.to/2pZBkMB
 */

#define pir   3                               //PIR sensor is on Digital 3
#define relay 2                               //Relay on digital 2
#define level 600                             //cutoff between light & dark
#define light A0                              //LDR on analog 0


int lum = 0;                                  //variable to hold light level
bool detect = 0;                              //boolean variable for PIR on/off
void setup() {

  pinMode(pir,INPUT);                         //PIR sensor set for input
  pinMode(relay,OUTPUT);                      //relay set for output
  pinMode(light,INPUT);                       //LDR set for input
  Serial.begin(9600);                         //serial comms for debugging

}

void loop() {

lum = analogRead(light);                      //lum set to value of LDR
detect = digitalRead(pir);                    //PIR on or off?
//Serial.println(lum);
//Serial.println(detect);
//delay(1000);

if(lum<level){                                //is it dark?
  if(detect){                                 //is motion detected?
    digitalWrite(relay,HIGH);                 //if yes to both, activate relay
  }
  else{
    digitalWrite(relay,LOW);                  //if not, deactivate relay
  }
}
}

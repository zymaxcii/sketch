/* Control your Arduino with your phone
 *  
 *  learnelectronics
 *  
 *  4 FEB 17
 *  
 *  www/youtube.com/c/learnelectronics
 */

#define ledPin 7                      //pin led is connected to

char phone;                           //char variable named phone


void setup() {
  
pinMode(ledPin, OUTPUT);              //set ledPin for OUTPUT
Serial.begin(9600);                   //begin serial comms @ 9600 baud

}

void loop() {

  if (Serial.available() > 0) {       //if data is received
     phone = (char) Serial.read();    //store data in phone variable
  }
    switch (phone) {                  //switch/case to decide how to handle data

    case '1':                         //if we recieve a 1
      digitalWrite(ledPin, HIGH);     //light the led
      break;                          //end loop

    case '0':                         //if we recieve a 0
      digitalWrite(ledPin, LOW);      //turn off led
      break;                          //end loop
    }
    

}

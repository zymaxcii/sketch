/*
 * Secret Squirrel Magnetic Door Lock
 * learnelectronics
 * 18 FEB 2017
 * www.youtube.com/c/learnelectronics
 */

//-----------------------------------------------------------------------
//                                 LIBRARIES
//-----------------------------------------------------------------------

// none needed




//-----------------------------------------------------------------------
//                                 Defines
//-----------------------------------------------------------------------

#define hallSwitch  A7      // hall switch on pin analog 7
#define relay       4       // relay on pin digital 7

//-----------------------------------------------------------------------
//                                 VARIABLES
//-----------------------------------------------------------------------

int lock = 0;               //integer variable for data from hall switch

//-----------------------------------------------------------------------
//                                 SETUP
//-----------------------------------------------------------------------

void setup() {

pinMode(hallSwitch, INPUT);//set hall switch pin for INPUT
pinMode(relay, OUTPUT);    //set relay pin for OUTPUT
digitalWrite(relay,LOW);   //set realy low on power-up (door locked)
Serial.begin(9600);        // begin serial comms for debugging

}
//-----------------------------------------------------------------------
//                                 MAIN LOOP
//-----------------------------------------------------------------------

void loop() {

lock = analogRead(hallSwitch);  //set value of lock variable to read of hall
Serial.println(lock);           //send value to serial monitor to check levels

if(lock<100){                   //if value of lock is less than 100 (norm 700+)
  digitalWrite(relay,HIGH);     //energize relay (unlock door)
  delay(2000);                  //keep door open for 2 seconds
  digitalWrite(relay,LOW);      //relock door
}

delay(1000);                    //wait one second


}

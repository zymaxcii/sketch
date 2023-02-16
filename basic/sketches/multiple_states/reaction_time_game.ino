/* Reaction Time Game
 *  Using Hardware Interrupt
 *  learnelectronics
 *  12/12/2016
 */


volatile float startTime;                                 // When moving variables in and out of fuctions
                                                          //you must use "volatile" to keep them intact
  
void setup() {
  // put your setup code here, to run once:
  
Serial.begin(9600);                                       //turn on serial comms
pinMode(2,INPUT_PULLUP);                                  //set pin 2 as logic HIGH input
pinMode(13,OUTPUT);                                       //set pin 13 as output
Serial.println("press the button when you see the light");//give the player instructions
randomSeed(analogRead(A0));                               //seed the randowm num gen with random num
delay(random(1000,5000));                                 //wait between 1 & 5 seconds
digitalWrite(13,HIGH);                                    //turn on the light
startTime=millis();                                       //time since start in milliseconds
attachInterrupt(0,bang,LOW);                              //attach the interrupt to pin d2
}


void bang(){                                              //what happens when an interrupt is detected
detachInterrupt(0);                                       //debounce by not looking @ switch
Serial.println("BANG!");                                  //why not?

float endTime=millis();                                   //current time in milliseconds
Serial.print("Your reaction time is: ");                 //give results
Serial.print(endTime-startTime);                          //endtime - start time = eleapsed time
Serial.print(" milliseconds");                            //make it pretty



}





void loop() {
                                                          // nothing to see here lol

}

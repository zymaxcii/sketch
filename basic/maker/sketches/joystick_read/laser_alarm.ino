/* LASER Tripwire Alarm
 *  learnelectronics
 *  01-02-2017
 */
//---------------------------------------------------------------------------------
#define safeLED 2                         //green LED for not triggered
#define alertLED 3                        //red LED for when alarm is triggered
#define buzzer 4                          // buzzer for alarm
#define ldr A0                            //Light Dependent Resistor
int ldrValue = 0;                         //Value for LDR
int alarmState = 0;                       //State of Alarm

//----------------------------------------------------------------------------------

void setup() {
  // put your setup code here, to run once:
pinMode(safeLED, OUTPUT);                 // Set green LED to OUTPUT
pinMode(alertLED, OUTPUT);                // Set red LED to OUTPUT
pinMode(buzzer, OUTPUT);                  // Set buzzer to OUTPUT
Serial.begin(9600);                       // turn on serial comms
digitalWrite(safeLED,HIGH);               // turn on SAFE LED
delay(2000);                              // delay to arm


}
//----------------------------------------------------------------------------------
void alarm(){                             //ALARM FUNCTION
  alarmState = 1;                         // set alarm state to 1
  digitalWrite(alertLED, HIGH);           // turn alert LED on
  digitalWrite(safeLED,LOW);              // turn safe LED off
  tone(buzzer,3000,1000);                 // make anoying sound
  delay(500);
  tone(buzzer,1000,1000);
  delay(500);
}

//----------------------------------------------------------------------------------




void loop() {
  
if(alarmState == 1){                    //check alarm state, if 1, alarm has been triggered
  alarm();                              // so keep sounding the alarm
}

ldrValue = analogRead(ldr);             //get LDR vale
Serial.println(ldrValue);               // for debugging
if(ldrValue > 100){                     // threshold for alarm
  alarm();                              //sound alarm
}
else{
  digitalWrite(safeLED,HIGH);           // if all is well, re-run the loop
  }

}

/*
 * Potentiometer and Switch Box (POTB) - Serial Updater
 * For more details visit: http://www.oomlout.com/
 * 
 * Behaviour: Will feed the state of the 5 plugged in 
              potentiometers and three switches to a connected
              PC every 100 ms.
 
 *
 * Wiring: Twist Potentiometer (01) - analog 0
 *         Shoulder Potentiometer (02) - analog 1
 *         Elbow Potentiometer (03) - analog 2
 *         Wrist Potentiometer (04) - analog 3      
 *         Gripper Potentiometer (05) - analog 4
 *         Switch 1 - pin 02
 *         Switch 2 - pin 03 
 *         Switch 3 - pin 04
 *         
 * License: This work is licenced under the Creative Commons 
 *          Attribution-Share Alike 3.0 Unported License. To 
 *          view a copy of this licence, visit 
 *          http://creativecommons.org/licenses/by-sa/3.0/ 
 *          or send a letter to Creative Commons, 171 Second 
 *          Street, Suite 300, San Francisco, California 94105, 
 *          USA.
 *         
*/ 
 
//-------------------------------------------------------------------------
//START OF POTENTIMETER BOX PREAMBLE

//Defining constants corresponding to the pin each Potentiometer is plugged into 
//change to whatever you are using them for
#define TWIST_POT 1      
#define SHOULDER_POT 3   
#define ELBOW_POT 2      
#define WRIST_POT 4
#define GRIPPER_POT 0    

//Defining constants corresponding to the pin each Potentiometer is plugged into 
//change to whatever you are using them for
#define SWITCH_1 2
#define SWITCH_2 3
#define SWITCH_3 4


//Gets everything up and running
void setup()                  
{
  Serial.begin(9600);                //Starts the serial port
  potbSetup();                       //sets the state of all neccesary 
                                     //pins and adds servos to your sketch
}

//The main program loop
void loop()                     
{
  potbSendData();             //sends the current switch and potentiometer data
  delay(100);                //waits 100 ms
}


//------------------------------------------------------------------------
//START OF POTENTIOMETER AND SWITCH BOX (POTB) ROUTINES

/*
 * sets up the appropriate digital inputs and outputs for your potentiometer
 * and switch box
*/
void potbSetup(){
  pinMode(SWITCH_1, INPUT);          //sets the switch one pin to input
  digitalWrite(SWITCH_1, HIGH);      //turns on the internal pull up resistor
                                     //(this means it will read high when off and low when on 
  pinMode(SWITCH_2, INPUT);          //sets the switch one pin to input
  digitalWrite(SWITCH_2, HIGH);      //turns on the internal pull up resistor
                                     //(this means it will read high when off and low when on 
  pinMode(SWITCH_3, INPUT);          //sets the switch one pin to input
  digitalWrite(SWITCH_3, HIGH);      //turns on the internal pull up resistor
                                     //(this means it will read high when off and low when on 
}

void potbSendData(){
  Serial.print("POTB Data");
  Serial.print("%SWITCH_1=");
  Serial.print(getSwitchData(SWITCH_1));
  Serial.print(" %SWITCH_2=");
  Serial.print(getSwitchData(SWITCH_2));
  Serial.print(" %SWITCH_3=");
  Serial.print(getSwitchData(SWITCH_3));
  Serial.print(" %TWIST_POT=");
  Serial.print(getPotData(TWIST_POT));
  Serial.print(" %SHOULDER_POT=");
  Serial.print(getPotData(SHOULDER_POT));
  Serial.print(" %ELBOW_POT=");
  Serial.print(getPotData(ELBOW_POT));
  Serial.print(" %WRIST_POT=");
  Serial.print(getPotData(WRIST_POT));
  Serial.print(" %GRIPPER_POT=");
  Serial.print(getPotData(GRIPPER_POT));
  Serial.print(" ");  
  Serial.println();
}

int getPotData(int potNumber){
  return analogRead(potNumber);
}

int getSwitchData(int switchNumber){
 return digitalRead(switchNumber); 
}  


//END OF POTENTIOMETER AND SWITCH BOX (POTB) ROUTINES
/  /---------------------------------------------------------------------------

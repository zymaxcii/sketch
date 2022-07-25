// buzz_sweep.ino
// https://surtrtech.com/2018/01/29/how-to-use-a-buzzer-piezo-speaker-with-arduino/

//This code is to use with a buzzer if you're using the module with 3 pins wire the I/O with D8
//If you're using the other version wire the (+) pin with 8 
// Refer to https://surtrtech.com/ for more information

//Increasing sound freqency from 100Hz to 2KHz then decreasing frequency from 2KHz to 100Hz

int buzzer = 8;
 
void setup() {

  pinMode(buzzer,OUTPUT);
 
}
 
void loop() {
    for(int i=100 ; i<2000 ; i++){ // loop for to increase the sound frequency
         tone(buzzer, i);
         delay(10); //You can change the delay if you want to make it longer or shorter
    }
    for(int i=2000 ; i>100 ; i--){
         tone(buzzer, i);
         delay(10);
    } 
}

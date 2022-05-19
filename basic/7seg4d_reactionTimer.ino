// 7seg4d_reactionTimer.ino
// https://create.arduino.cc/projecthub/mike-mcroberts/reaction-timer-game-with-4-digit-7-segment-display-db77dd

/*******************************************************************
* Reaction Timer Game using a 7-Segment Display (4 digits minimum) *
* plus one button and a piezo sounder.                             *
* (c) 2020 Mike McRoberts    @TheArduinoGuy                        *
*                                                                  *
* Connect Anodes or Cathodes to pins 2,3,4 and 5.                  *                                                                 
* Segments A to G to pins 6 to 12  (13 for DP not used)            *
* Button to D14 (A0) and Pizeo to D15 (A1)                         *
*******************************************************************/

#include "LedControl.h"
#include "SevSeg.h"

#define NOTE_D3  147
#define NOTE_D4  294

const int Button_Pin = 14;
const int Piezo_Pin = 15;
int High_Score = 9999;
unsigned long timer;

SevSeg sevseg; //Instantiate a seven segment controller object

//####################################################################################################
void setup()
{
    Serial.begin(115200);

    byte numDigits = 4;
    byte digitPins[] = {2, 3, 4, 5};
    byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};
    bool resistorsOnSegments = true; // 'false' means resistors are on digit pins
    byte hardwareConfig = COMMON_CATHODE; // See README.md for options
    bool updateWithDelays = false; // Default 'false' is Recommended
    bool leadingZeros = false; // Use 'true' if you'd like to keep the leading zeros
    bool disableDecPoint = true; // Use 'true' if your decimal point doesn't exist or isn't connected

    sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments,
                 updateWithDelays, leadingZeros, disableDecPoint);
    sevseg.setBrightness(90);
    pinMode(Button_Pin, INPUT_PULLUP);
    randomSeed(analogRead(A5));
}


//####################################################################################################
void printNumber(int v)
{
    if (v > 9999) return;

    sevseg.setNumber(v, 0);
    sevseg.refreshDisplay(); // Must run repeatedly
}


//####################################################################################################
void Get_Ready()
{
    for (int repeat = 0; repeat < 6; repeat++)  // repeat 6 times
    {
    	tone(Piezo_Pin, repeat * 250, 20); //  play a rising tone
    	// flash 8888 
        printNumber(8888);
        millis_delay(50);
        sevseg.blank();
        millis_delay(50);
    }
}

//####################################################################################################
void Start_Counting()
{
    long counter = millis();
    int Score;
    int freq = 250;
    while (digitalRead(Button_Pin) == HIGH) // whilst the button is not pressed.....
    {
        Score = int(millis() - counter); //  increment the time
        if (Score > 9999)
        {
            fail();
            return;
        }
        printNumber(Score);
        if (freq < 2000)
        {
            tone(Piezo_Pin, freq);
            freq += 1;
        }
        else
        {
            noTone(Piezo_Pin);
        }
    }
    noTone(Piezo_Pin);

    if (Score < High_Score) // WIN!!!!!
    {
        High_Score = Score;
        win();
    }
    else  fail();  // Booooohhh!!!

    noTone(Piezo_Pin);
}


//####################################################################################################
void millis_delay(int wait_time)
{
    // wait n milliseconds whilst constantly refreshing the display
    timer = millis();
    while (millis() - timer < wait_time)
    {
        sevseg.refreshDisplay(); // Must run repeatedly
    }
}


//####################################################################################################
void fail()
{
    // play the fail notes
    tone(Piezo_Pin, NOTE_D4);
    millis_delay(500);
    tone(Piezo_Pin, NOTE_D3);
    millis_delay(1000);
    noTone(Piezo_Pin);
    millis_delay(2000);
}


//####################################################################################################
void win()
{
    for (int x = 0; x < 10; x++) //  repeat 10 times
    {
        int freq = 200;
        while (freq < 2000) // play rising tune
        {
            tone(Piezo_Pin, freq);
            freq += 150;
            millis_delay(50);
        }
    }
}


//####################################################################################################
void loop()
{
    int counter = 0;
    while (digitalRead(Button_Pin) == HIGH) // flash high score till button is pressed
    {
        if (counter == 0)    sevseg.blank(); //  between 0 and 10000 blank display
        if (counter == 10000) printNumber(High_Score); //  between 10000 and 20000 show high score
        sevseg.refreshDisplay(); // Must run repeatedly
        counter++;
        if (counter > 20000) counter = 0;
    }
    // once button has been pressed.......
    Get_Ready();
    delay(2000); // wait 2 seconds
    delay(random(8000)); // then add 0 to 8 random seconds
    Start_Counting(); //
}

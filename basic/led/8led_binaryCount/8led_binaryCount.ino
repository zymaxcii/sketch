// 8led_binaryCount.ino
// binary count with switch interrupt
// source: https://www.electroschematics.com/9809/arduino-8-bit-binary-led/
// This sketch uses consecutive pins for leds
// difficult to modify for the 8 led module that plugs directly into Mega

int button = 2;			    // pin to connect button
int presses = 0;		    // variable to store number of presses
long time = 0;			    // used for debounce
long debounce = 100;	    // how many ms to "debounce"
const byte numPins = 8;     // how many leds
int state;				    // used for HIGH or LOW
 
// pins to connect leds
// my standard pin assignments for 8 leds on uno and nano: 6,7,8,9,10,11,12,13
// pins 2,3,4,5 for switches; pin 2 with interrupt
// byte pins[] = {6,7,8,9,10,11,12,13};

// with the 8 led module and mega - no jumper wires no separate GND jumper
int ledPins[] = {39,41,43,45,47,49,51,53};



void setup()
{
	/* we setup all led pins as OUTPUT */
	for (int i = 0; i < numPins; i++)
	{
		pinMode(pins[i], OUTPUT);
	}
	
	pinMode(button, INPUT_PULLUP);
	/* use pin 2 which has interrupt 0 on Arduino UNO */
	attachInterrupt(0, count, LOW);
}


void loop()
{
	/* convert presses to binary and store it as a string */
	String binNumber = String(presses, BIN);
	
	/* get length of string */
	int binLength = binNumber.length();	
	
	if (presses <= 255)
	{
		// if we have less or equal to 255 presses
        // here is the scary code
		for (int i = 0, x = 1; i < binLength; i++, x+=2)
		{ 
			if (binNumber[i] == '0') state = LOW;
			if (binNumber[i] == '1') state = HIGH;
			digitalWrite(pins[i] + binLength - x, state);
		}	
	}
	else
	{
		// do something when we reach 255: reset
    presses = 0;
	}
}

// interrupt service routine
// function to count the presses
void count()
{ 
	// we debounce the button and increase the presses
	if (millis() - time > debounce)	presses++;
	time = millis();
}

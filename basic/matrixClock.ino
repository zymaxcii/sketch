// matrixClock.ino
// https://drive.google.com/file/d/1Nz4apvgg7oXS3Eafj7kWprBKA1WIexfp/view
// https://abidcg.blogspot.com/2019/05/hello-welcome-to-abid-cg-creator-blog.html

/*
Name:		ArduinoMatrixClock.ino
Created:	12.06.2018  20:56:49 
Author:	mylms.cz
*/

/*
https://www.mylms.cz/text-arduino-hod iny-s-maticovym-displejem/

D2 � BTN 1 (set internal_pullup)
D3 � BTN 2 (set internal_pullup)
D4 � matrix display, pin DIN
D5 � matrix display, pin CLK
D6 � matrix display, pin CS
A4 � RTC module, pin SDA
A5 � RTC module, pin SCL
GND � common for all modules
5V � common for all modules, 5V supply connected via 1N4148
*/



#include <EEPROM.h>
#include <Wire.h>
#include <LedControl.h>

//MATRIX DISPLAY
byte devices = 4;
LedControl lc = LedControl(4, 5,6, devices);	//DIN, CLK, CS, count of displays

//RTC DS3231
#define DS3231_I2C_ADDRESS 0x68 //address of DS3231 module
byte second, minute, hour, dayOfWeek, dayOfMonth, month, year; //global variables

//TIMMING
unsigned long presentTime;
unsigned long displayTime;	//drawing

//IO
#define BTN1 2
#define BTN2 3
bool lastInput1; //last state of #1 input 
bool lastInput2; //last state of #2 input 
bool presentInput1; //actual state of input #1
bool presentInput2; //actual state of input #2

//SYSTEM STATE
byte systemState;

//chars
byte znaky[95][8] = {
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },   // U+0020 (space)
{ 0x18, 0x3C, 0x3C, 0x18, 0x18, 0x00, 0x18, 0x00 },   // U+0021 (!)
{ 0x36, 0x36, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },   // U+0022 (")
{ 0x36, 0x36, 0x7F, 0x36, 0x7F, 0x36, 0x36, 0x00 },   // U+0023 (#)
{ 0x0C, 0x3E, 0x03, 0x1E, 0x30, 0x1F, 0x0C, 0x00 },   // U+0024 ($)
{ 0x00, 0x63, 0x33, 0x18, 0x0C, 0x66, 0x63, 0x00 },   // U+0025 (%)
{ 0x1C, 0x36, 0x1C, 0x6E, 0x3B, 0x33, 0x6E, 0x00 },   // U+0026 (&)
{ 0x06, 0x06, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00 },   // U+0027 (')
{ 0x18, 0x0C, 0x06, 0x06, 0x06, 0x0C, 0x18, 0x00 },   // U+0028 (()
{ 0x06, 0x0C, 0x18, 0x18, 0x18, 0x0C, 0x06, 0x00 },   // U+0029 ())
{ 0x00, 0x66, 0x3C, 0xFF, 0x3C, 0x66, 0x00, 0x00 },   // U+002A (*)
{ 0x00, 0x0C, 0x0C, 0x3F, 0x0C, 0x0C, 0x00, 0x00 },   // U+002B (+)
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x0C, 0x06 },   // U+002C (,)
{ 0x00, 0x00, 0x00, 0x3F, 0x00, 0x00, 0x00, 0x00 },   // U+002D (-)
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x0C, 0x00 },   // U+002E (.)
{ 0x60, 0x30, 0x18, 0x0C, 0x06, 0x03, 0x01, 0x00 },   // U+002F (/)
{ 0x3E, 0x63, 0x73, 0x7B, 0x6F, 0x67, 0x3E, 0x00 },   // U+0030 (0)
{ 0x0C, 0x0E, 0x0C, 0x0C, 0x0C, 0x0C, 0x3F, 0x00 },   // U+0031 (1)
{ 0x1E, 0x33, 0x30, 0x1C, 0x06, 0x33, 0x3F, 0x00 },   // U+0032 (2)
{ 0x1E, 0x33, 0x30, 0x1C, 0x30, 0x33, 0x1E, 0x00 },   // U+0033 (3)
{ 0x38, 0x3C, 0x36, 0x33, 0x7F, 0x30, 0x78, 0x00 },   // U+0034 (4)
{ 0x3F, 0x03, 0x1F, 0x30, 0x30, 0x33, 0x1E, 0x00 },   // U+0035 (5)
{ 0x1C, 0x06, 0x03, 0x1F, 0x33, 0x33, 0x1E, 0x00 },   // U+0036 (6)
{ 0x3F, 0x33, 0x30, 0x18, 0x0C, 0x0C, 0x0C, 0x00 },   // U+0037 (7)
{ 0x1E, 0x33, 0x33, 0x1E, 0x33, 0x33, 0x1E, 0x00 },   // U+0038 (8)
{ 0x1E, 0x33, 0x33, 0x3E, 0x30, 0x18, 0x0E, 0x00 },   // U+0039 (9)
{ 0x00, 0x0C, 0x0C, 0x00, 0x00, 0x0C, 0x0C, 0x00 },   // U+003A (:)
{ 0x00, 0x0C, 0x0C, 0x00, 0x00, 0x0C, 0x0C, 0x06 },   // U+003B (//)
{ 0x18, 0x0C, 0x06, 0x03, 0x06, 0x0C, 0x18, 0x00 },   // U+003C (<)
{ 0x00, 0x00, 0x3F, 0x00, 0x00, 0x3F, 0x00, 0x00 },   // U+003D (=)
{ 0x06, 0x0C, 0x18, 0x30, 0x18, 0x0C, 0x06, 0x00 },   // U+003E (>)
{ 0x1E, 0x33, 0x30, 0x18, 0x0C, 0x00, 0x0C, 0x00 },   // U+003F (?)
{ 0x3E, 0x63, 0x7B, 0x7B, 0x7B, 0x03, 0x1E, 0x00 },   // U+0040 (@)
{ 0x0C, 0x1E, 0x33, 0x33, 0x3F, 0x33, 0x33, 0x00 },   // U+0041 (A)
{ 0x3F, 0x66, 0x66, 0x3E, 0x66, 0x66, 0x3F, 0x00 },   // U+0042 (B)
{ 0x3C, 0x66, 0x03, 0x03, 0x03, 0x66, 0x3C, 0x00 },   // U+0043 (C)
{ 0x1F, 0x36, 0x66, 0x66, 0x66, 0x36, 0x1F, 0x00 },   // U+0044 (D)
{ 0x7F, 0x46, 0x16, 0x1E, 0x16, 0x46, 0x7F, 0x00 },   // U+0045 (E)
{ 0x7F, 0x46, 0x16, 0x1E, 0x16, 0x06, 0x0F, 0x00 },   // U+0046 (F)
{ 0x3C, 0x66, 0x03, 0x03, 0x73, 0x66, 0x7C, 0x00 },   // U+0047 (G)
{ 0x33, 0x33, 0x33, 0x3F, 0x33, 0x33, 0x33, 0x00 },   // U+0048 (H)
{ 0x1E, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x1E, 0x00 },   // U+0049 (I)
{ 0x78, 0x30, 0x30, 0x30, 0x33, 0x33, 0x1E, 0x00 },   // U+004A (J)
{ 0x67, 0x66, 0x36, 0x1E, 0x36, 0x66, 0x67, 0x00 },   // U+004B (K)
{ 0x0F, 0x06, 0x06, 0x06, 0x46, 0x66, 0x7F, 0x00 },   // U+004C (L)
{ 0x63, 0x77, 0x7F, 0x7F, 0x6B, 0x63, 0x63, 0x00 },   // U+004D (M)
{ 0x63, 0x67, 0x6F, 0x7B, 0x73, 0x63, 0x63, 0x00 },   // U+004E (N)
{ 0x1C, 0x36, 0x63, 0x63, 0x63, 0x36, 0x1C, 0x00 },   // U+004F (O)
{ 0x3F, 0x66, 0x66, 0x3E, 0x06, 0x06, 0x0F, 0x00 },   // U+0050 (P)
{ 0x1E, 0x33, 0x33, 0x33, 0x3B, 0x1E, 0x38, 0x00 },   // U+0051 (Q)
{ 0x3F, 0x66, 0x66, 0x3E, 0x36, 0x66, 0x67, 0x00 },   // U+0052 (R)
{ 0x1E, 0x33, 0x07, 0x0E, 0x38, 0x33, 0x1E, 0x00 },   // U+0053 (S)
{ 0x3F, 0x2D, 0x0C, 0x0C, 0x0C, 0x0C, 0x1E, 0x00 },   // U+0054 (T)
{ 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x3F, 0x00 },   // U+0055 (U)
{ 0x33, 0x33, 0x33, 0x33, 0x33, 0x1E, 0x0C, 0x00 },   // U+0056 (V)
{ 0x63, 0x63, 0x63, 0x6B, 0x7F, 0x77, 0x63, 0x00 },   // U+0057 (W)
{ 0x63, 0x63, 0x36, 0x1C, 0x1C, 0x36, 0x63, 0x00 },   // U+0058 (X)
{ 0x33, 0x33, 0x33, 0x1E, 0x0C, 0x0C, 0x1E, 0x00 },   // U+0059 (Y)
{ 0x7F, 0x63, 0x31, 0x18, 0x4C, 0x66, 0x7F, 0x00 },   // U+005A (Z)
{ 0x1E, 0x06, 0x06, 0x06, 0x06, 0x06, 0x1E, 0x00 },   // U+005B ([)
{ 0x03, 0x06, 0x0C, 0x18, 0x30, 0x60, 0x40, 0x00 },   // U+005C (\)
{ 0x1E, 0x18, 0x18, 0x18, 0x18, 0x18, 0x1E, 0x00 },   // U+005D (])
{ 0x08, 0x1C, 0x36, 0x63, 0x00, 0x00, 0x00, 0x00 },   // U+005E (^)
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF },   // U+005F (_)
{ 0x0C, 0x0C, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00 },   // U+0060 (`)
{ 0x00, 0x00, 0x1E, 0x30, 0x3E, 0x33, 0x6E, 0x00 },   // U+0061 (a)
{ 0x07, 0x06, 0x06, 0x3E, 0x66, 0x66, 0x3B, 0x00 },   // U+0062 (b)
{ 0x00, 0x00, 0x1E, 0x33, 0x03, 0x33, 0x1E, 0x00 },   // U+0063 (c)
{ 0x38, 0x30, 0x30, 0x3e, 0x33, 0x33, 0x6E, 0x00 },   // U+0064 (d)
{ 0x00, 0x00, 0x1E, 0x33, 0x3f, 0x03, 0x1E, 0x00 },   // U+0065 (e)
{ 0x1C, 0x36, 0x06, 0x0f, 0x06, 0x06, 0x0F, 0x00 },   // U+0066 (f)
{ 0x00, 0x00, 0x6E, 0x33, 0x33, 0x3E, 0x30, 0x1F },   // U+0067 (g)
{ 0x07, 0x06, 0x36, 0x6E, 0x66, 0x66, 0x67, 0x00 },   // U+0068 (h)
{ 0x0C, 0x00, 0x0E, 0x0C, 0x0C, 0x0C, 0x1E, 0x00 },   // U+0069 (i)
{ 0x30, 0x00, 0x30, 0x30, 0x30, 0x33, 0x33, 0x1E },   // U+006A (j)
{ 0x07, 0x06, 0x66, 0x36, 0x1E, 0x36, 0x67, 0x00 },   // U+006B (k)
{ 0x0E, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x1E, 0x00 },   // U+006C (l)
{ 0x00, 0x00, 0x33, 0x7F, 0x7F, 0x6B, 0x63, 0x00 },   // U+006D (m)
{ 0x00, 0x00, 0x1F, 0x33, 0x33, 0x33, 0x33, 0x00 },   // U+006E (n)
{ 0x00, 0x00, 0x1E, 0x33, 0x33, 0x33, 0x1E, 0x00 },   // U+006F (o)
{ 0x00, 0x00, 0x3B, 0x66, 0x66, 0x3E, 0x06, 0x0F },   // U+0070 (p)
{ 0x00, 0x00, 0x6E, 0x33, 0x33, 0x3E, 0x30, 0x78 },   // U+0071 (q)
{ 0x00, 0x00, 0x3B, 0x6E, 0x66, 0x06, 0x0F, 0x00 },   // U+0072 (r)
{ 0x00, 0x00, 0x3E, 0x03, 0x1E, 0x30, 0x1F, 0x00 },   // U+0073 (s)
{ 0x08, 0x0C, 0x3E, 0x0C, 0x0C, 0x2C, 0x18, 0x00 },   // U+0074 (t)
{ 0x00, 0x00, 0x33, 0x33, 0x33, 0x33, 0x6E, 0x00 },   // U+0075 (u)
{ 0x00, 0x00, 0x33, 0x33, 0x33, 0x1E, 0x0C, 0x00 },   // U+0076 (v)
{ 0x00, 0x00, 0x63, 0x6B, 0x7F, 0x7F, 0x36, 0x00 },   // U+0077 (w)
{ 0x00, 0x00, 0x63, 0x36, 0x1C, 0x36, 0x63, 0x00 },   // U+0078 (x)
{ 0x00, 0x00, 0x33, 0x33, 0x33, 0x3E, 0x30, 0x1F },   // U+0079 (y)
{ 0x00, 0x00, 0x3F, 0x19, 0x0C, 0x26, 0x3F, 0x00 },   // U+007A (z)
{ 0x38, 0x0C, 0x0C, 0x07, 0x0C, 0x0C, 0x38, 0x00 },   // U+007B ({)
{ 0x18, 0x18, 0x18, 0x00, 0x18, 0x18, 0x18, 0x00 },   // U+007C (|)
{ 0x07, 0x0C, 0x0C, 0x38, 0x0C, 0x0C, 0x07, 0x00 },   // U+007D (})
{ 0x6E, 0x3B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },   // U+007E (~)
};

byte bright = 0;
bool showDots;

void setup() {
	//COMMUNICATION
	Wire.begin(); //start I2C communication
	Serial.begin(9600);

	//IO
	pinMode(BTN1, INPUT_PULLUP);
	pinMode(BTN2, INPUT_PULLUP);

	bright = EEPROM.read(0);	//load light intensity from EEPROM
	delay(10);

	//SET ALL DISPLAYS
	for (byte address = 0; address<devices; address++) {
		lc.shutdown(address, false);	//powersaving
		lc.setIntensity(address, bright);	//set light intensity 0 - min, 15 - max
		lc.clearDisplay(address);		//clear display
	}

	//INIT TIME SETTING
	//SetRtc(15, 41, 8, 6, 30, 3, 18);	//sec, min, hour, dayOfWeek, dayOfMonth, month, year

	//Intro();	//show LMS!
}

void loop() {
	//store input to var
	presentInput1 = digitalRead(BTN1); 
 
	presentInput2 = digitalRead(BTN2);

	switch (systemState) {
	case 0:
		//SHOW ACTUAL TIME
		presentTime = millis();

		//"multasking"
		if (presentTime - displayTime >= 500) {
			displayTime = presentTime;

			GetRtc();		//get actual time
			WriteTime();	//write actual time to matrix display
		}

		if (!presentInput1 && !presentInput2) {
		  delay(20);
			systemState = 1;
			//go to "pre"menu
		}
		break;

	case 1:
		if (presentInput1 && presentInput2) {
    delay(20);
			systemState = 2; //Go to menu
			
			DrawSymbol(1, 0, 0);	//space
			DrawSymbol(0, 72 - 32, 0);	//H
		}
		break;

	case 2:
		//menu 1
		//set hours
		WriteTime();

		if (presentInput1 != lastInput1) {
			//change detected BTN1
      delay(20);
			if (presentInput1) {
        delay(20);
				//rising edge detected
				systemState = 3;

				DrawSymbol(3, 77 - 32, 0);	//M
				DrawSymbol(2, 0, 0);	//space
			}
		}

		if (presentInput2 != lastInput2) {
			//change detected BTN2
      delay(20);
			if (presentInput2) {
				//rising edge detected
				//add hour
				hour++;
				if (hour > 23) {
					hour = 0;
				}
			}
		}
		break;

	case 3:
		//menu 2
		//set minutes
		WriteTime();

		if (presentInput1 != lastInput1) {
      delay(20);
			//change detected BTN1
			if (presentInput1) {
				//rising edge detected
				systemState = 4;

				DrawSymbol(3, 66 - 32, 0);	//B
				DrawSymbol(2, 0, 0);	//space
				DrawSymbol(0, (bright % 10) + 16, 1);	//actual light intensity
				DrawSymbol(1, (bright / 10) + 16, 1);	//actual light intensity
			}
		}

		if (presentInput2 != lastInput2) {
      delay(20);
			//change detected BTN2
			if (presentInput2) {
				//rising edge detected
				//add hour
				minute++;
				if (minute > 59) {
					minute = 0;
				}
			}
		}
		break;

	case 4:
		//menu 3
		//set brightnes
		if (presentInput1 != lastInput1) {
			//change detected BTN1
      delay(20);
			if (presentInput1) {
				//rising edge detected
				systemState = 5;

				DrawSymbol(3, 83 - 32, 0);	//S
				DrawSymbol(2, 116 - 32, 0);	//t
				DrawSymbol(1, 114 - 32, 0);	//r
				DrawSymbol(0, 116 - 32, 0);	//t
			}
		}

		if (presentInput2 != lastInput2) {
			//change detected BTN2
      delay(20);
			if (presentInput2) {
				//rising edge detected
				//add hour
				bright++;
				if (bright > 15) {
					bright = 0;			
				}

				DrawSymbol(0, (bright % 10) + 16, 1);	//actual light intensity
				DrawSymbol(1, (bright / 10) + 16, 1);	//actual light intensity

				for (byte address = 0; address<devices; address++) {
					lc.setIntensity(address, bright);	//set light intensity 0 - min, 15 - max
				}
			}
		}
		break;

	case 5:
		//menu 4
		if (presentInput1 != lastInput1) {
			//change detected BTN1
      delay(20);
			if (presentInput1) {
				//rising edge detected
				SetRtc(0, minute, hour, dayOfWeek, dayOfMonth, month, year);	//set time and zero second
				EEPROM.write(0, bright);	//store actual light intensity to addr 0
				systemState = 0;
			}
		}

		break;

	}

	lastInput1 = presentInput1; //save current state to last state
	lastInput2 = presentInput2; //save current state to last state

	SerialComm();	//read data from PC
}

void GetButton() {
	DrawSymbol(3, 76 - 32, 0);	//L
	DrawSymbol(2, 77 - 32, 0);	//M
	DrawSymbol(1, 83 - 32, 0);	//S
	DrawSymbol(0, 1, 0);		//!
}

void WriteTime() {
	//write time to matrix display
	if (systemState == 0 || systemState == 2) {
   uint8_t hour12 = hour%12 == 0? 12 : hour%12;
		DrawSymbol(2, (hour12 % 10) + 16, 0);
		DrawSymbol(3, (hour12 / 10) + 16, 0);
	}

	if (systemState == 0 || systemState == 3) {
		DrawSymbol(0, (minute % 10) + 16, 1);
		DrawSymbol(1, (minute / 10) + 16, 1);
	}
	
	//blinking dots on display
	lc.setLed(2, 1, 7, showDots);  //addr, row, column
	lc.setLed(2, 2, 7, showDots);
	lc.setLed(2, 5, 7, showDots);
	lc.setLed(2, 6, 7, showDots);

	showDots = !showDots;
}

void Intro() {
	DrawSymbol(3, 76-32, 0);	//L
	DrawSymbol(2, 77-32, 0);	//M
	DrawSymbol(1, 83-32, 0);	//S
	DrawSymbol(0, 1, 0);		//!
	delay(2000);
}

void DrawSymbol(byte adr, byte symbol, byte offset) {
	//draw symbol
	//offset move the symbol to right side

	for (int i = 0; i <= 7; i++) {
		byte dataRow = znaky[symbol][i];
		dataRow = ByteRevers(dataRow) >> offset;
		lc.setRow(adr, i, dataRow);
	}
}

byte ByteRevers(byte in) {
	//font turning
	byte out;
	out = 0;
	if (in & 0x01) out |= 0x80;
	if (in & 0x02) out |= 0x40;
	if (in & 0x04) out |= 0x20;
	if (in & 0x08) out |= 0x10;
	if (in & 0x10) out |= 0x08;
	if (in & 0x20) out |= 0x04;
	if (in & 0x40) out |= 0x02;
	if (in & 0x80) out |= 0x01;
	return(out);
}

//Set RTC
void SetRtc(byte second, byte minute, byte hour, byte dayOfWeek, byte dayOfMonth, byte month, byte year) {
	Wire.beginTransmission(DS3231_I2C_ADDRESS);
	Wire.write(0); //set 0 to first register

	Wire.write(decToBcd(second)); //set second
	Wire.write(decToBcd(minute)); //set minutes 
	Wire.write(decToBcd(hour)); //set hours
	Wire.write(decToBcd(dayOfWeek)); //set day of week (1=su, 2=mo, 3=tu) 
	Wire.write(decToBcd(dayOfMonth)); //set day of month
	Wire.write(decToBcd(month)); //set month
	Wire.write(decToBcd(year)); //set year
	Wire.endTransmission();
}

//read RTC
void GetRtc() {
	Wire.beginTransmission(DS3231_I2C_ADDRESS);
	Wire.write(0); //write "0"
	Wire.endTransmission();

	Wire.requestFrom(DS3231_I2C_ADDRESS, 7);	//request - 7 bytes from RTC
	second = bcdToDec(Wire.read() & 0x7f);
	minute = bcdToDec(Wire.read());
	hour = bcdToDec(Wire.read() & 0x3f);
	dayOfWeek = bcdToDec(Wire.read());
	dayOfMonth = bcdToDec(Wire.read());
	month = bcdToDec(Wire.read());
	year = bcdToDec(Wire.read());
}

//conversion Dec to BCD 
byte decToBcd(byte val) {
	return((val / 10 * 16) + (val % 10));
}

//conversion BCD to Dec 
byte bcdToDec(byte val) {
	return((val / 16 * 10) + (val % 16));
}

//serial communication with PC
//set time via PC
void SerialComm() {
	//first letter - type of data
	//second letter - data (space = 0, ! = 1, etc. see ASCII table)

	if (Serial.available() > 0) {
		byte receivedCommand;
		receivedCommand = Serial.read();	//read first letter

		if (receivedCommand < 90) {
			//received data is less than 90 (letter Z)
			delay(10);	//wait for second letter

			byte receivedData;
			receivedData = Serial.read();
			receivedData -= 32;	//shift - 32 -> 32 = space

			switch (receivedCommand) {
			case 65:
				//year 65 = A
				year = receivedData;
				lc.setLed(3, 7, 0, true);	//show setting dot
				break;
			case 66:
				//month 66 = B
				month = receivedData;
				lc.setLed(3, 7, 1, true);	//show setting dot
				break;
			case 67:
				//dayOfMonth 67 = C
				dayOfMonth = receivedData;
				lc.setLed(3, 7, 2, true);	//show setting dot
				break;
			case 68:
				//hour 68 = D
				hour = receivedData;
				lc.setLed(3, 7, 3, true);	//show setting dot
				break;
			case 69:
				//minute 69 = E
				minute = receivedData;
				lc.setLed(3, 7, 4, true);	//show setting dot
				break;
			case 70:
				//second 70 = F
				second = receivedData;
				lc.setLed(3, 7, 5, true);	//show setting dot
				break;
			case 71:
				//dayofWeek 71 = G
				dayOfWeek = receivedData;
				lc.setLed(3, 7, 6, true);	//show setting dot
				break;
			}
			SetRtc(second, minute, hour, dayOfWeek, dayOfMonth, month, year);
		}

		//spl�chnout buffer do hajzlu
		Serial.flush();
	}
}


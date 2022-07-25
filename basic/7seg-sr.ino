// 7seg-sr.ino
// https://mytectutor.com/how-to-use-7-segment-display-with-arduino/


// Globals
const int dataPin = 4; // to 74HC595 pin 14
const int latchPin = 7; // to 74HC595 pin 12
const int clockPin = 8; //  to 74HC595 pin 11
// uncomment one of the following lines that describes your display
// and comment out the line that does not describe your display
// const char common = 'a'; // common anode
const char common = 'c'; // common cathode
unsigned int cnt = 0;
byte symbol, symbols[] = {
B11111100, // 0
B01100000, // 1
B11011010, // 2
B11110010, // 3
B01100110, // 4
B10110110, // 5
B10111110, // 6
B11100000, // 7
B11111110, // 8
B11110110, // 9
B11101110, // A
B00111110, // B
B10011100, // C
B01111010, // D
B10011110, // E
B10001110 // F
};
void setup() {
// initialize I/O pins
pinMode(dataPin, OUTPUT);
pinMode(latchPin, OUTPUT);
pinMode(clockPin, OUTPUT);
if( common == 'a' )
for(int i=0; i<sizeof(symbols); i++)
symbols[i] ^= B11111111;
}
void loop() {
symbol = symbols[cnt++%sizeof(symbols)] | (cnt%2);
digitalWrite(latchPin, LOW); // prepare shift register for data
shiftOut(dataPin, clockPin, LSBFIRST, symbol); // send data
digitalWrite(latchPin, HIGH); // update display
delay(500); // pause for 1/2 second
}

// arduino_dice.ino
// https://github.com/pimylifeup/arduino_dice/blob/master/arduinodice.ino

//Code by Gus @ pimylifeup.com

//Pin to to turn dice on & off
int button = 2;
//LED for DICE
int bottomLeft = 3;
int middleLeft = 4;
int upperLeft = 5;
int middle = 6;
int bottomRight = 7;
int middleRight = 8;
int upperRight = 9;

int state = 0;
long randNumber; 

//Initial setup
void setup(){
  pinMode(bottomLeft, OUTPUT);
  pinMode(middleLeft, OUTPUT);
  pinMode(upperLeft, OUTPUT);
  pinMode(middle, OUTPUT);
  pinMode(bottomRight, OUTPUT);
  pinMode(middleRight, OUTPUT);
  pinMode(upperRight, OUTPUT);
  
  pinMode(button, INPUT);
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

 void loop(){
	//Read our button if high then run dice
	if (digitalRead(button) == HIGH && state == 0){
		state = 1;
		randNumber = random(1, 7);
		delay(100);
		Serial.println(randNumber);

		if (randNumber == 6){
			six();
		}
		if (randNumber == 5){
			five();
		}
		if (randNumber == 4){
			four();
		}
		if (randNumber == 3){
			three();
		}
		if (randNumber == 2){
			two();
		}
		if (randNumber == 1){
			one();
		}
		delay(5000);
		clearAll();
		state = 0;
	}
}

//Create a function for each of our "sides" of the die
 void six()
{
  digitalWrite(bottomLeft, HIGH);
  digitalWrite(middleLeft, HIGH);
  digitalWrite(upperLeft, HIGH);
  digitalWrite(bottomRight, HIGH);
  digitalWrite(middleRight, HIGH);
  digitalWrite(upperRight, HIGH);
}

void five()
{
	digitalWrite(upperLeft, HIGH);
	digitalWrite(bottomLeft, HIGH);
	digitalWrite(middle, HIGH);
	digitalWrite(upperRight, HIGH);
	digitalWrite(bottomRight, HIGH);
}

void four()
{
	digitalWrite(upperLeft, HIGH);
	digitalWrite(bottomLeft, HIGH);
	digitalWrite(upperRight, HIGH);
	digitalWrite(bottomRight, HIGH);
}

void three()
{
	digitalWrite(upperLeft, HIGH);
	digitalWrite(middle, HIGH);
	digitalWrite(bottomRight, HIGH);
}

void two()
{
	digitalWrite(bottomRight, HIGH);
	digitalWrite(upperLeft, HIGH);
}

void one(){
	digitalWrite(middle, HIGH);
}

void clearAll(){
	digitalWrite(bottomLeft, LOW);
	digitalWrite(middleLeft, LOW);
	digitalWrite(upperLeft, LOW);
	digitalWrite(middle,LOW);
	digitalWrite(bottomRight, LOW);
	digitalWrite(middleRight, LOW);
	digitalWrite(upperRight, LOW);
}

int pinRelay = 10;              // The pin D10 is connected to the signal foot of the relay module  


void setup()
{
  pinMode(pinRelay, OUTPUT);    // Setting the pinRelay foot as an output state 
}

 
void loop()
{
  digitalWrite(pinRelay, HIGH);     // Output HIGH level, relay module closure  
  delay(5000);                      // Wait 5000 milliseconds
  
  digitalWrite(pinRelay, LOW);      // Output LOW level, relay module disconnect 
  delay(5000);                      // Wait 5000 milliseconds  
}


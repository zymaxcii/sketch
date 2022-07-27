int red_south = A5;
int yellow_south = A4;
int green_south = A3;

int red_north = 4;
int yellow_north = 5;
int green_north = 6;

int red_west = 0;
int yellow_west = 1;
int green_west = 2;

int red_east = 10;
int yellow_east = 9;
int green_east = 8;

void setup(){
  pinMode(red_south, OUTPUT);
  pinMode(yellow_south, OUTPUT);
  pinMode(green_south, OUTPUT);
  
  pinMode(red_north, OUTPUT);
  pinMode(yellow_north, OUTPUT);
  pinMode(green_north, OUTPUT);

  pinMode(red_west, OUTPUT);
  pinMode(yellow_west, OUTPUT);
  pinMode(green_west, OUTPUT);

  pinMode(red_east, OUTPUT);
  pinMode(yellow_east, OUTPUT);
  pinMode(green_east, OUTPUT);
}


void loop() {
    
  //TURN ON TRAFFIC LIGHTS BY TURNING ON ALL YELLOW

   
   //SOUTHROAD WILL GO FIRST
   //ON RED LIGHT (NORTH, EAST, WEST)
   digitalWrite(yellow_west, LOW);
   digitalWrite(green_west, LOW);
   digitalWrite(red_north, HIGH);
   digitalWrite(red_east, HIGH);
   digitalWrite(red_west, HIGH);   
   digitalWrite(green_south, HIGH);
   digitalWrite(yellow_south, LOW);
   digitalWrite(red_south, LOW);
   delay(500);
   //SOUTHROAD WILL GET READY FOR RED 
   //EASTROAD WILL GET READY FOR GREEN
   digitalWrite(yellow_south, HIGH);
   digitalWrite(green_south, LOW);
   digitalWrite(yellow_east, HIGH);
   digitalWrite(red_east, LOW);
   delay(150);
   //EASTROAD WILL GO 
   digitalWrite(green_east, HIGH);
   digitalWrite(red_south, HIGH);
   digitalWrite(yellow_south, LOW);
   digitalWrite(yellow_east, LOW);
   digitalWrite(red_north, HIGH);
   digitalWrite(red_west, HIGH);
   delay(500);
   //EASTROAD WILL GET READY FOR RED 
   //NORTHROAD WILL GET READY FOR GREEN
   digitalWrite(yellow_east, HIGH);
   digitalWrite(green_east, LOW);
   digitalWrite(yellow_north, HIGH);
   digitalWrite(red_north, LOW);
   delay(150);
   //NORTHROAD WILL GO 
   digitalWrite(green_north, HIGH);
   digitalWrite(red_south, HIGH);
   digitalWrite(red_east, HIGH);
   digitalWrite(yellow_east, LOW);
   digitalWrite(yellow_north, LOW);
   digitalWrite(red_north, LOW);
   digitalWrite(red_west, HIGH);
   delay(500);
   //NORTHROAD ROAD WILL GET READY FOR RED 
   //WESTROAD WILL GET READY FOR GREEN
   digitalWrite(yellow_north, HIGH);
   digitalWrite(green_north, LOW);
   digitalWrite(yellow_west, HIGH);
   digitalWrite(red_west, LOW);
   delay(150);
   //WESTROAD WILL GO 
   digitalWrite(green_west, HIGH);
   digitalWrite(red_south, HIGH);
   digitalWrite(red_east, HIGH);
   digitalWrite(yellow_west, LOW);
   digitalWrite(yellow_north, LOW);
   digitalWrite(red_north, HIGH);
   digitalWrite(red_west, LOW);
   delay(500); 
   //WESTROAD ROAD WILL GET READY FOR RED 
   //SOUTHROAD WILL GET READY FOR GREEN
   digitalWrite(yellow_west, HIGH);
   digitalWrite(green_west, LOW);
   digitalWrite(yellow_south, HIGH);
   digitalWrite(red_west, LOW);
   digitalWrite(red_south, LOW);
   delay(150);
}

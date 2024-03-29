// display 1234
// set cathode interface
int a = 1;
int b = 2;
int c = 3;
int d = 4;
int e = 5;
int f = 6;
int g = 7;
int dp = 8;

// Set anode interface
int d4 = 9;
int d3 = 10;
int d2 = 11;
int d1 = 12;

// Set variable
long n = 1230;
int  x = 100;
int del = 55;  // Here to fine tune the clock	 


void setup()
{
  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);
  pinMode(d4, OUTPUT);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(dp, OUTPUT);
}


void loop()
{
  Display(1, 1);

  Display(2, 2);
  
  Display(3, 3);
  
  Display(4, 4);
}


void WeiXuan(unsigned char n)
{
  switch(n)
  {
	case 1: 
	  digitalWrite(d1, HIGH);
 	  digitalWrite(d2, LOW);
	  digitalWrite(d3, LOW);
	  digitalWrite(d4, LOW);   
	  break;

	case 2: 
	  digitalWrite(d1, LOW);
 	  digitalWrite(d2, HIGH);
	  digitalWrite(d3, LOW);
	  digitalWrite(d4, LOW); 
      break;

	case 3: 
       digitalWrite(d1, LOW);
 	   digitalWrite(d2, LOW);
	   digitalWrite(d3, HIGH);
	   digitalWrite(d4, LOW); 
	   break;
	
	case 4: 
	   digitalWrite(d1, LOW);
 	   digitalWrite(d2, LOW);
	   digitalWrite(d3, LOW);
	   digitalWrite(d4, HIGH); 
	   break;
   
    default :
       digitalWrite(d1, LOW);
	   digitalWrite(d2, LOW);
	   digitalWrite(d3, LOW);
	   digitalWrite(d4, LOW);
       break; 
  }
}


void Num_0()
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
  digitalWrite(dp,HIGH);
}

void Num_1()
{
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(dp,HIGH);
}

void Num_2()
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
  digitalWrite(dp,HIGH);
}

void Num_3()
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
  digitalWrite(dp,HIGH);
}

void Num_4()
{
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(dp,HIGH);
}

void Num_5()
{
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(dp,HIGH);
}

void Num_6()
{
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(dp,HIGH);
}

void Num_7()
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(dp,HIGH);
}

void Num_8()
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(dp,HIGH);
}

void Num_9()
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(dp,HIGH);
}

void Clear()  // Clear the screen
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(dp,HIGH);
}

void pickNumber(unsigned char n)    // Choose the number of
{
  switch(n)
  {
   case 0: Num_0();
   break;
   
   case 1: Num_1();
   break;
   
   case 2: Num_2();
   break;
   
   case 3: Num_3();
   break;
   
   case 4: Num_4();
   break;
   
   case 5: Num_5();
   break;
   
   case 6: Num_6();
   break;
   
   case 7: Num_7();
   break;
   
   case 8: Num_8();
   break;
   
   case 9: Num_9();
   break;
   
   default: Clear();
   break; 
  }
}

// Show that x is the coordinate, Number is the number
void Display(unsigned char x, unsigned char Number)
{
  WeiXuan(x);
  pickNumber(Number);
  delay(1);
  Clear() ; // Vanishing
}

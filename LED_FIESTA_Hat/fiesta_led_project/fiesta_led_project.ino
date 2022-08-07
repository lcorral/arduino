//Simple code to cycle through LEDs
//This project is to decorate a sombrero for a work contest
//Lorenzo Corral
//3/16/2016

//Declare Variables
int led = 13;
int led2 = 12;
int led3 = 11;
void setup()
{
  
  pinMode(led, OUTPUT);
 
  
}

void loop()
{

  digitalWrite(led, HIGH);
 delay(100);
 digitalWrite(led, LOW);
 delay(100);
  
  digitalWrite(led2, HIGH);
  delay(100);
  digitalWrite(led2, LOW);
  delay(100);
  
  digitalWrite(led3, HIGH);
  //delay(100);
  //digitalWrite(led3, LOW);
  //delay(100);
  
}

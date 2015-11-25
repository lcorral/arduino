//Simple code to Blink an LED
//This is the simplest way of doing. not efficient.

//Declare your variables to be used
int led = 13;

void setup() 
{
  //put your setup code here, to run once:
  
  pinMode(led, OUTPUT);  //means pin 13 is an output

}

void loop() 
{
  //out your main code here, to run repetedly:

    digitalWrite(led, HIGH); //Gives 5V to pin 13
    delay(1000);  //This is a second
    digitalWrite(led, LOW);  //Turns pin 13 off
    delay(1000);  //Waits for a second before it turns it on again
    
}

//This program will read a digital input pin 2
//because i forget how to do this
//saving this code for future use

int pushButton = 2; //pushbutton is connected to digital pin 2
                    //this can be substituted for any sensor

void setup()
{
  Serial.begin(9600); //Initiates seriel communication at 9600 bits per second
  pinMode(pushButton, INPUT);  //Indicates the pushbutton is an input
}

void loop()
{
  int buttonstate = digitalRead(pushButton); //read the input pin
  
  Serial.println(buttonstate);  //display the state of the button
      //to open the serial monitor go to Tools then Seriel Monitor to see outputs
  
  delay(1);  //delay in between read for stability

}

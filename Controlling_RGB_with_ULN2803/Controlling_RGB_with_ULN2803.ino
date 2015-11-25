//This is to control an RGB LED with the ULN2803
//ULN2803 is the only chip that I had 
//around at the time of this project.

#define DelayTime 10 //time between colors
#define FadeDelay 10 //time to spend on each PWM level

void setup()
{
  // put your setup code here, to run once:
  pinMode(9, OUTPUT); //5
  pinMode(10, OUTPUT); //3
  pinMode(11, OUTPUT); //6
}

void loop()
{
  //red
  digitalWrite(9, HIGH);
  for(int x= 255; x>1; x--)
  {
    analogWrite(9,x);
    delay(FadeDelay);
  }
  delay(DelayTime);
  digitalWrite(9, LOW);
  //blue
  digitalWrite(10, HIGH);
  for(int x= 255; x>0; x--)
  {
    analogWrite(10,x);
    delay(FadeDelay);
  }
  delay(DelayTime);
  digitalWrite(10, LOW);
  //white
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  for(int x= 255; x>1; x--)
  {
    analogWrite(9,x);
    analogWrite(10,x);
    analogWrite(11,x);
    delay(FadeDelay);
  }
  delay(DelayTime);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
}

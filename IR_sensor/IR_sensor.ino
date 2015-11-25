//Simple testing of the sensor.
//This can be used with other types of sensors
//just plug into the same sensor pins

int const Red = 9; //pin 3 
int const Blue = 11; // pin 4
int const Green = 10; // pin 5
int const IR = 2;
int SENSOR = 0;

void setup(){ // sets up the program
  pinMode(Green, OUTPUT);
  pinMode(Blue, OUTPUT);
  pinMode(Red, OUTPUT);
// pinMode(IR, INPUT);
  Serial.begin(9600);
}
  
void loop() { //main loop of the program
 SENSOR = analogRead(IR);
  Serial.print("sensor = ");
  Serial.println(SENSOR);

if ( SENSOR > 200 ) {
  digitalWrite(Green, HIGH);
  digitalWrite(Blue, HIGH);
  digitalWrite(Red, LOW);
 //delay(1000);  //This is a second
}
else
{
digitalWrite(Green, LOW);
digitalWrite(Blue, HIGH);
digitalWrite(Red, HIGH);
}}

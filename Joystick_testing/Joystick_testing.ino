// Store the Arduino pin associated with each input

// Select button is triggered when joystick is pressed
const byte PIN_BUTTON_SELECT = 2; 

const byte PIN_BUTTON_RIGHT = 3;
const byte PIN_BUTTON_UP = 4;
const byte PIN_BUTTON_DOWN = 5;
const byte PIN_BUTTON_LEFT = 6;

const byte PIN_ANALOG_X = 0;
const byte PIN_ANALOG_Y = 1;

int led = 13; //sets led to pin 13

void setup() {
  Serial.begin(9600);

  pinMode(led, OUTPUT);
  
  pinMode(PIN_BUTTON_RIGHT, INPUT);  
  digitalWrite(PIN_BUTTON_RIGHT, HIGH);
 
  pinMode(PIN_BUTTON_LEFT, INPUT);  
  digitalWrite(PIN_BUTTON_LEFT, HIGH);
 
  pinMode(PIN_BUTTON_UP, INPUT);  
  digitalWrite(PIN_BUTTON_UP, HIGH);
 
  pinMode(PIN_BUTTON_DOWN, INPUT);  
  digitalWrite(PIN_BUTTON_DOWN, HIGH);
 
 // pinMode(PIN_BUTTON_SELECT, INPUT);  
 // digitalWrite(PIN_BUTTON_SELECT, HIGH);  
}


void loop() {
//  Serial.print("l:");
//  Serial.print(digitalRead(PIN_BUTTON_LEFT));
//  Serial.print(" ");
// 
//  Serial.print("r:");
//  Serial.print(digitalRead(PIN_BUTTON_RIGHT));
//  Serial.print(" ");
// 
//  Serial.print("u:");
//  Serial.print(digitalRead(PIN_BUTTON_UP));
//  Serial.print(" ");
// 
//  Serial.print("d:");
//  Serial.print(digitalRead(PIN_BUTTON_DOWN));
//  Serial.print(" ");

  Serial.print("x:");
  Serial.print(analogRead(PIN_ANALOG_X));
  Serial.print(" ");
 
  Serial.print("y:");
  Serial.print(analogRead(PIN_ANALOG_Y));
  Serial.print(" ");  
 
 if (analogRead(PIN_ANALOG_X) >500) //This position means anytime joystick goes up, 
                                     //LED turns on
 {
  digitalWrite(led, HIGH);
 }
 
 else digitalWrite(led, LOW);
//  Serial.print("s:");
//  Serial.print(digitalRead(PIN_BUTTON_SELECT));
//  Serial.print(" ");
 
  Serial.println();
}

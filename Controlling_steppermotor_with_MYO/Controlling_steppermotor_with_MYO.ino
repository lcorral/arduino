//THis is for use with MYO.
//As you perform different actions you can control the motor
//This can be used for anything else just replace the motor
//with whatever other device you have.

#include <MyoController.h>
#include <Stepper.h>

//----------------------------
const int stepsPerRevolution = 300;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8,9,10,11);            

int stepCount = 0;  // number of steps the motor has taken
//-----------------------------

#define FIST_PIN 4
#define WAVEIN_PIN 5
#define WAVEOUT_PIN 6
#define FINGERSSPREAD_PIN 7
#define DOUBLETAP_PIN 8

MyoController myo = MyoController();

void setup() {

  pinMode(FIST_PIN, OUTPUT);
  pinMode(WAVEIN_PIN, OUTPUT);
  pinMode(WAVEOUT_PIN, OUTPUT);
  pinMode(FINGERSSPREAD_PIN, OUTPUT);
  pinMode(DOUBLETAP_PIN, OUTPUT);
  
  myo.initMyo();
}

void loop()
{
   //Serial.println("HI"); //this is to see if i was actually in the loop
   myo.updatePose();
   switch ( myo.getCurrentPose() ) {
    case rest:
      digitalWrite(FIST_PIN,LOW); 
      digitalWrite(WAVEIN_PIN,LOW);
      digitalWrite(WAVEOUT_PIN,LOW);
      digitalWrite(FINGERSSPREAD_PIN,LOW);
      digitalWrite(DOUBLETAP_PIN,LOW);
      break;
    case fist:
      digitalWrite(FIST_PIN,HIGH);
      for(int i=0;i<50;i++)
      {
        myStepper.setSpeed(30);
        // step 1/100 of a revolution:
        myStepper.step(stepsPerRevolution/100);
      }
      break;
    case waveIn:
      digitalWrite(WAVEIN_PIN,HIGH);
      break;
    case waveOut:
      digitalWrite(WAVEOUT_PIN,HIGH);
      break;
    case fingersSpread:
      digitalWrite(FINGERSSPREAD_PIN,HIGH);
      break;
    case doubleTap:
      digitalWrite(DOUBLETAP_PIN,HIGH);
      break;
   } 
   delay(100);
}

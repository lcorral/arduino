#include <Adafruit_NeoPixel.h>

//Variables
#define PIN 6 //this is the data pin for the neopixel

//START Variables for PIR Sensor ---------
int calibrationTime = 30; //calibration time for the PIR sensor
long unsigned int lowIn; //Time when the sensor outputs a low impulse

//time in ms the sensor has to be low 
//before we assume motion has stopped
long unsigned int pause = 5000; 

boolean lockLow=true;
boolean takeLowTime;

int pirPin = 7; //input connected to PIR output

//END Variables for PIR Sensor ----


// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(16, PIN, NEO_GRB + NEO_KHZ800);


void setup() 
{
  
  strip.begin();
  strip.show(); //Initialize all pixels to 'off' 

  Serial.begin(9600);
  pinMode(pirPin, INPUT);

  Serial.print("calibrating sensor");
    for(int i = 0; i < calibrationTime; i++)
    {
      Serial.print(".");
      delay(1000);
    }
    Serial.println(" done");
    Serial.println("SENSOR ACTIVE");
    delay(50);  
}

void loop() 
{
  
  if(digitalRead(pirPin) == HIGH){
    colorWipe(strip.Color(0, 255, 0), 50); // Green
    if(lockLow){
        lockLow = false;
        Serial.println("---");
        Serial.print("motion detected at ");
        Serial.println(millis()/1000);
        Serial.println(" sec");
        delay(50);
               }
        takeLowTime = true;
                                }
  if(digitalRead(pirPin) == LOW)
  {
  colorWipe(strip.Color(255, 0, 0), 50); // Red
  
  if(takeLowTime){
        lowIn = millis();          //save the time of the transition from high to LOW
        takeLowTime = false;       //make sure this is only done at the start of a LOW phase
        }
       //if the sensor is low for more than the given pause, 
       //we assume that no more motion is going to happen
       if(!lockLow && millis() - lowIn > pause)
       {  
           //makes sure this block of code is only executed again after 
           //a new motion sequence has been detected
           lockLow = true;                        
           Serial.print("motion ended at ");      //output
           Serial.print((millis() - pause)/1000);
           Serial.println(" sec");
           delay(50);
           }
  }
                                
  
  
  
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}


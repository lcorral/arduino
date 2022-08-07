#include <Adafruit_NeoPixel.h>

// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6
#define PIN2           5

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      16

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2 = Adafruit_NeoPixel(NUMPIXELS, PIN2, NEO_GRB + NEO_KHZ800);

int delayval = 500; // delay for half a second

void setup() {


  pixels.begin(); // This initializes the NeoPixel library.
  pixels2.begin();
}

//In Order to Control a seperate NeoPixel you need to add the Following:
//#define PINn  n <-- This is the input to the NeoPixel 'n'
//Need to add another NeoPixel invocation
//Adafruit_NeoPixel pixelsn = Adafruit_NeoPixel(NUMPIXELS, PINn, NEO_GRB + NEO_KHZ800); <-- pixel function n for the input PINn
//Initiate the pixeln function
//pixelsn.begin();
//pixelsn.setPixelColor(i, pixels.Color(255,0,127)); //Set the colors for the NeoPixel
//pixelsn.show(); //Tell the hardware to show the Color.




void loop() {

  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.

  for(int i=0;i<NUMPIXELS;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels2.setPixelColor(i, pixels.Color(255,0,127)); // Moderately bright Tmobile Pink color.

    pixels.setPixelColor(i, pixels.Color(0,0,255)); // Moderately bright green color.


    pixels.show(); // This sends the updated pixel color to the hardware.
    pixels2.show();

    delay(delayval); // Delay for a period of time (in milliseconds).

  }
}

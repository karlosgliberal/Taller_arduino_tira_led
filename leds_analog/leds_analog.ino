#include "FastLED.h"

#define NUM_LEDS 16
#define DATA_PIN 4

CRGB leds[NUM_LEDS];

// this constant won't change:
const int  buttonPin = 2;    // the pin that the pushbutton is attached to
const int ledPin = 13;       // the pin that the LED is attached to

// Variables will change:
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  // initialize the button pin as a input:
  pinMode(buttonPin, INPUT);
  // initialize the LED as an output:
  pinMode(ledPin, OUTPUT);
  // initialize serial communication:
  Serial.begin(9600);
}


void loop() {
  // read the pushbutton input pin:
  int val = analogRead(2);
  int numLedsToLight = map(val, 0, 1023, 0, NUM_LEDS);
  Serial.print("number of button pushes:  ");
           // First, clear the existing led values
        FastLED.clear();
            CHSV spectrumcolor;
    spectrumcolor.hue =         222;
    spectrumcolor.saturation =  187;
    spectrumcolor.value =       255;
    
        for(int led = 0; led < numLedsToLight; led++) {
            hsv2rgb_spectrum( spectrumcolor, leds[led] );
            //leds[led].setHSV( 224, 187, 255);
            //leds[led].setHue( 224);
            //leds[led] = CRGB::Blue; 
        }
        FastLED.show();

}


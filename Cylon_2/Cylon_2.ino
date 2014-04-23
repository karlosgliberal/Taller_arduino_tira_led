#include "FastLED.h"

// How many leds in your strip?
#define NUM_LEDS 16
#define DATA_PIN 4

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() { 
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void loop() { 
	// First slide the led in one direction
	for(int i = 0; i < NUM_LEDS; i++) {
		// Set the i'th led to red 
		leds[i] = CRGB::Red;
		leds[i+1] = CRGB::White;
		// Show the leds
		FastLED.show();
		// now that we've shown the leds, reset the i'th led to black
		leds[i] = CRGB::Black;
                leds[i+1] = CRGB::Black;
		// Wait a little bit before we loop around and do it again
		delay(30);
	}

	// Now go in the other direction.  
	for(int i = NUM_LEDS-1; i >= 0; i--) {
		// Set the i'th led to red 
		leds[i] = CRGB::Red;
                leds[i+1] = CRGB::White;
		// Show the leds
		FastLED.show();
		// now that we've shown the leds, reset the i'th led to black
		leds[i] = CRGB::Black;
                leds[i+1] = CRGB::Black;
		// Wait a little bit before we loop around and do it again
		delay(30);
	}
}

#include "FastLED.h"

#define NUM_LEDS 16
#define DATA_PIN 4

CRGB leds[NUM_LEDS];

// this constant won't change:
const int  buttonPin = 2;    // the pin that the pushbutton is attached to
// Variables will change:
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  Serial.begin(9600);
}


void loop() {
  // Leemos el valor del pin 2 analogico
  int val = analogRead(2);
  //Funcion map para hacer la regla de 3 entre el valor del poteciometro y el numero de leds
  int numLedsToLight = map(val, 0, 1023, 0, NUM_LEDS);
  Serial.print("number of button pushes:  ");
  //borramos todo
  FastLED.clear();
  for(int led = 0; led < numLedsToLight; led++) {
     leds[led] = CRGB::Blue; 
  }
 FastLED.show();

}


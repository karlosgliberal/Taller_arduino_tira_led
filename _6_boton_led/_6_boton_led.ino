#include "FastLED.h"

#define NUM_LEDS 16
#define DATA_PIN 4

CRGB leds[NUM_LEDS];

// Definimos constantes 
const int  buttonPin = 2;    // definimos el pin2 para el boton
// Variables que cambiaremos:
int buttonPushCounter = 0;   // Contador de numero de veces pulado el boton
int buttonState = 0;         // Estado actual del boton
int lastButtonState = 0;     // estado anterior del boton

void setup() {
  //init de los leds
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  // Init del boton:
  pinMode(buttonPin, INPUT);
  //init del puerto serie para ver que ocurre
  Serial.begin(9600);
}


void loop() {
  // Leemos y guardamos el  boton
  buttonState = digitalRead(buttonPin);
  // Comparamos el estado del boton con el estado anterior
  if (buttonState != lastButtonState) {
    // Si es diferente incrementamos el boton
    if (buttonState == HIGH) {
      //buttonPushCounter = buttonPushCounter + 1;
      buttonPushCounter++;
      leds[buttonPushCounter] = CRGB::Red; 
      FastLED.show(); 
      Serial.println("on");
      Serial.print("number of button pushes:  ");
      Serial.println(buttonPushCounter);
    } 
  }
  lastButtonState = buttonState; 
}


#include "FastLED.h"

#define NUM_LEDS 16 // Número de leds de la tira
#define DATA_PIN 4  // El pin en la placa de arduino para conectar con el pin de datos de la tira

CRGB leds[NUM_LEDS];

void setup() {
      //Sistama prevenci´n por si los leds chupan todo el voltaje
      delay(2000);
      //Contructor de la libreria (Driver, el pin de los datos, 
      FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}


void loop() {  
  for(int i = 0; i < NUM_LEDS; i++) { 
    leds[i].r = 255/i; 
    leds[i].g = 255; 
    leds[i].b = 0; 
    FastLED.show();
    //delay(10); 
  } 
}

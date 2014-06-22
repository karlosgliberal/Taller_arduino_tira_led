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
  //¿Seguro que no se puede hacer de otra manera?
  for(int i = 0; i < NUM_LEDS; i++) {  
    leds[i] = CRGB::Black;
  }
  FastLED.show();
  
  
  for(int i = 0; i < NUM_LEDS; i++) {  
    leds[i] = CRGB::Red;
    FastLED.show();
    delay(500); 
  }
  //traspasa la memoria a los LEDs
  
  //Espera 30 mili segundos
  
}

#include "FastLED.h"

#define NUM_LEDS 16


#define DATA_PIN 4


CRGB leds[NUM_LEDS];

void setup() {
      //Sistama prevenci´n por si los leds chupan todo el voltaje
      delay(2000);
      //Contructor de la libreria (Driver, el pin de los datos, 
      //FastLED.addLeds<WS2811, DATA_PIN, CRGB>(leds, NUM_LEDS);
      FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
      //FastLED.addLeds<SM16716, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
}

void loop() {
  //¿Seguro que no se puede hacer de otra manera?
  for(int i = 0; i < NUM_LEDS; i++) {  
    leds[i] = CRGB::Black;
  }
  FastLED.show();
  delay(2000);
  
  for(int i = 0; i < NUM_LEDS; i++) {  
    leds[i] = CRGB::Red;
    FastLED.show();
    //delay(10); 
  }
  //traspasa la memoria a los LEDs
  
  //Espera 30 mili segundos
  
}

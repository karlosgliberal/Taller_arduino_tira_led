#include "FastLED.h"

#define NUM_LEDS 16


#define DATA_PIN 4
int ihue = 0;


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
  
  rainbow_fade();
   
  //traspasa la memoria a los LEDs
  FastLED.show(); 
  //Espera 30 mili segundos
  delay(30); 
}

void rainbow_fade() {                         //-m2-FADE ALL LEDS THROUGH HSV RAINBOW
    for(int i=0; i<25; i++) {
      ihue++;
      if (ihue > 255) {ihue = 0;}
      for(int idex = 0 ; idex < NUM_LEDS; idex++ ) {
        leds[idex] = CHSV(ihue, 255, 255);
      }
      LEDS.show();    
      delay(100);
    }
    
}

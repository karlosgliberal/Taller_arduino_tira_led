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
  leds[0] = CRGB::Blue;
  leds[1] = CRGB::Blue;
  leds[2] = CRGB::Blue;
  leds[3] = CRGB::Blue;
  leds[4] = CRGB::Blue;
  leds[5] = CRGB::Blue;
  leds[6] = CRGB::Blue;
  leds[7] = CRGB::Blue;
  leds[8] = CRGB::Blue;
  leds[9] = CRGB::Blue;
  leds[10] = CRGB::Blue;
  leds[11] = CRGB::Blue;
  leds[12] = CRGB::Blue;
  leds[13] = CRGB::Blue;
  leds[14] = CRGB::Blue;
  leds[15] = CRGB::Blue;

  //traspasa la memoria a los LEDs
  FastLED.show(); 
  //Espera 30 mili segundos
  delay(30); 
}

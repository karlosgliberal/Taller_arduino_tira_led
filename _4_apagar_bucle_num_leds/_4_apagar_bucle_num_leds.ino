#include "FastLED.h"

#define NUM_LEDS 16


#define DATA_PIN 4


CRGB leds[NUM_LEDS];

void setup() {
      Serial.begin(9600);
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
    Serial.print("i:");
    Serial.println(i);
    delay(500);
    leds[i] = CRGB::Black;
  }
  //traspasa la memoria a los LEDs
  FastLED.show(); 
  //Espera 30 mili segundos
  delay(30); 
}

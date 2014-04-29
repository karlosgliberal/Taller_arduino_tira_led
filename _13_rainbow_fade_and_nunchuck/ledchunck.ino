
#include <Wire.h>
#include "nunchuck_funcs.h"
#include "FastLED.h"


#define NUM_LEDS 5
#define DATA_PIN 4
#define INFO_LED_PIN 12

#define DEABAND 4 // Zona muerta del jouystick y acelerómetros

int ihue = 0;
int isat = 128;
int ivalue = 128;

int calc_ihue = 0;
int calc_isat = 0;
int joyx, joyy, accx,accy,accz,zbut,cbut;
int  hue_inc;

CRGB leds[NUM_LEDS];

void setup() {
  pinMode(INFO_LED_PIN, OUTPUT); 

  //Sistama prevenci´n por si los leds chupan todo el voltaje
  delay(2000);


  //Contructor de la libreria (Driver, el pin de los datos, 
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  nunchuck_setpowerpins();
  nunchuck_init(); 
  
  randomSeed(analogRead(0));

  Serial.begin(9600);
}

void loop() {
  digitalWrite(INFO_LED_PIN, HIGH);
  
  nunchuck_get_data(); 
  read_nunchuck();

  joyx = maprange(30, 229, -32, 32, joyx); //Mapeamos valores del joystick
  joyy = maprange(27, 220, -32, 32, joyy); //Mapeamos valores del joystick


  //Serial.print("\naccx: "); Serial.print((int)accx,DEC);
  //Serial.print("\taccy: "); Serial.print((int)accy,DEC);
  //Serial.print("\taccz: "); Serial.print((int)accz,DEC);
  //Serial.print("\tjoyx: "); Serial.print((int)joyx,DEC);
  //Serial.print("\tjoyy: "); Serial.print((int)joyy,DEC);
  //Serial.print("\tzbut: "); Serial.print((int)zbut,DEC);
  //Serial.print("\tcbut: "); Serial.println((int)cbut,DEC);
  

  //sp2 = b1 + (accy-a1)*(b2-b1)/(a2-a1);
  rainbow_fade();
  //traspasa la memoria a los LEDs
  FastLED.show(); 
  //Espera 100 mili segundos
  delay(100); 
  
}

void read_nunchuck(){
  joyx = nunchuck_joyx();
  joyy = nunchuck_joyy();
  accx = nunchuck_accelx();
  accy = nunchuck_accely();
  accz = nunchuck_accelz();  
  zbut = nunchuck_zbutton();
  cbut = nunchuck_cbutton();
}

void rainbow_fade() {  //-m2-FADE ALL LEDS THROUGH HSV RAINBOW
  //Joystick x y
  if(joyx > DEABAND){
    increase_hue(joyx);
  }else if(joyx < DEABAND *-1){
    decrease_hue(joyx *-1);      
  }
  if(joyy > DEABAND){
    increase_sat(joyy);
  }else if(joyy < DEABAND *-1){
    decrease_sat(joyy *-1);      
  }

  //C & Z buttons
  if(zbut==1){
    decrease_val(10);
  }else if(cbut==1){
    increase_val(10);
  }

  update_leds();
  
  //Z accel, random colors full hue and sat
  if(accz >200){
    for(int idex = 0 ; idex < NUM_LEDS; idex++ ) {      
      ihue = random(256);
      leds[idex] = CHSV(ihue, 255, 255);
      LEDS.show();
      delay(100);
    }
    delay(500);
  }
  delay(10);
}

/**
 * Map nunchuck values
 **/
int maprange(double a1,double a2,double b1,double b2,double s){
  return (int)(b1 + (s-a1)*(b2-b1)/(a2-a1));
}


int increase_hue(int hue_inc){
  ihue = ihue+hue_inc;
  if (ihue > 255) {ihue = 0;}
}

int decrease_hue(int hue_inc){
  ihue = ihue-hue_inc;
  if (ihue < 0) {ihue = 255;}
}

int increase_sat(int sat_inc){
  isat = isat+sat_inc;
  if (isat > 255) {isat = 255;}
}

int decrease_sat(int sat_inc){
  isat = isat-sat_inc;
  if (isat < 0) {isat = 0;}
}

int increase_val(int val_inc){
  ivalue = ivalue + val_inc;
  if (ivalue > 255) {ivalue = 255;}
}

int decrease_val(int val_inc){
  ivalue = ivalue - val_inc
  if (ivalue < 0) {ivalue = 0;}
}

void update_leds(){
  for(int idex = 0 ; idex < NUM_LEDS; idex++ ) {
    calc_ihue = ihue + (idex *20) - (NUM_LEDS *20);
    leds[idex] = CHSV(calc_ihue, isat, ivalue);
  }
  LEDS.show();  
}

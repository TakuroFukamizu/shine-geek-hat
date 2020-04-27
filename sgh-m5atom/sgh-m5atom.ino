#include <M5Atom.h>
#include <FastLED.h>

#define VOL_PIN 25
#define LED_PIN 33
#define NUM_STRIP_LEDS 1
#define MAX_BRIGHTNESS 128

CRGB leds[NUM_STRIP_LEDS];

void setup() {
//    M5.begin(true, false, true);
    M5.begin(true, false, false);
    pinMode(VOL_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);

    delay(50);
    
//    FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, NUM_STRIP_LEDS);
//    FastLED.setBrightness(20);
//    leds[0] = CRGB::White; 
//    FastLED.show();

    delay(50);
//    M5.dis.clear();
    Serial.println("end setup");
}

void loop() {
    Serial.print("- ");
    int vol = analogRead(VOL_PIN);
    int brightness = MAX_BRIGHTNESS * (vol / 4095.0);

    Serial.print("vol: ");
    Serial.print(vol);
    Serial.print(", brightness: ");
    Serial.println(brightness);

//    M5.dis.clear();
//    for(int i=0; i<NUM_LEDS; i++) {
//        M5.dis.drawpix(i, 0x00f000);
//    }
//    M5.dis.setBrightness(brightness);
    
    FastLED.setBrightness(brightness);
    leds[0] = CRGB::White; 
    FastLED.show();

    delay(100);
    M5.update();
}

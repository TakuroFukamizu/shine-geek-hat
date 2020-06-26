//#include <M5Atom.h>
#include <FastLED.h>

#define VOL_PIN 25
#define LED_PIN 33
#define NUM_STRIP_LEDS 1
#define MAX_BRIGHTNESS 256

//#define CHIPSET NEOPIXEL
#define CHIPSET WS2812 
#define COLOR_ORDER GRB

CRGB leds[NUM_STRIP_LEDS];

int brightness = 20;

void setup() {
//    M5.begin(true, false, true);
//    M5.begin(true, false, false);
    Serial.begin(115200);
    Serial.println("start init");
    pinMode(VOL_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);

    delay(50);
    
    Serial.println("setup led");
    FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_STRIP_LEDS);

    delay(50);
//    M5.dis.clear();
    Serial.println("end setup");
}

void loop() {
    Serial.print("- ");
    int vol = analogRead(VOL_PIN);
    brightness = MAX_BRIGHTNESS * (vol / 4095.0);

    Serial.print("vol: ");
    Serial.print(vol);
    Serial.print(", brightness: ");
    Serial.println(brightness);

//    M5.dis.clear();
//    M5.dis.drawpix(0, 0x00f000);
//    M5.dis.setBrightness(brightness);
    
    leds[0] = CRGB::Red;
    FastLED.setBrightness(brightness);
    FastLED.show();

    delay(100);
//    M5.update();
}

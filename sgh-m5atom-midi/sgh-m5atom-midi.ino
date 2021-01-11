#include <FastLED.h>
// #include <MIDI.h>
#include "src/midi/MIDI.h"

// Shine-Geek-Hat M5atom MIDI

#define PIN_RGB_LED 22
#define PIN_MIDI_IN 19
#define PIN_STATUS_LED 23
#define PIN_TOUCH 33
#define PIN_VOL_SW 21
#define PIN_VOL 25

// MIDI IN 用
HardwareSerial midiSerial(1);

// MIDIクラスのインスタンスとして"MIDI"を生成する。
MIDI_CREATE_INSTANCE(HardwareSerial, midiSerial, MIDI);

void handleNoteOn(byte channel, byte pitch, byte velocity)
{
    // ノートの鳴り始めにさせたいことを何でも書いて

    // できるだけコールバックの中は短くするように、
    // でないとloop関数が遅くなり、リアルタイム性能に悪影響が出てしまう
    Serial.println("NoteOn");
}

void handleNoteOff(byte channel, byte pitch, byte velocity)
{
    // ノートの鳴り終わりにさせたいことを何でも
    // ベロシティ0のノートオンメッセージもNoteOffとして解釈される(つまりここで処理される)点に注意
    Serial.println("NoteOff");
}

void setup() {
    Serial.begin(115200);
    // MIDI
    midiSerial.begin(31250, SERIAL_8N1, PIN_MIDI_IN, 10); // TXはダミー
    MIDI.setHandleNoteOn(handleNoteOn);
    MIDI.setHandleNoteOff(handleNoteOff);
    MIDI.begin(MIDI_CHANNEL_OMNI);
//    MIDI.turnThruOn();
  
    pinMode(PIN_STATUS_LED, OUTPUT);
    pinMode(PIN_TOUCH, INPUT);
    pinMode(PIN_VOL_SW, INPUT);
    pinMode(PIN_VOL, INPUT);

    Serial.println("Initialized.");
}

void loop() {
    // リアルタイム性の確保のため、MIDI.readをできるだけ早く呼ぶように
    MIDI.read();
}

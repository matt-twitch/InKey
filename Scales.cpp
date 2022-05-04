#include "Scales.h"
#include "Pins.h"
#include "ThisThread.h"
#include "mbed.h"
#include "N5110.h"

// constructor using uniform list initialisation
Scales::Scales() : _AMajor{220, 246.94, 277.18, 293.66, 329.63, 369.99, 415.3, 440}, _AMinor{220, 246.94, 261.63, 293.66, 329.63, 369.99, 415.3, 440}, _BMajor{246.94, 277.18, 311.13, 329.63, 369.99, 415.3, 466.16, 493.88}, _BMinor{246.94, 277.28, 293.66, 329.63, 369.99, 392, 440, 493.88}, _CMajor{261.63, 293.66, 329.63, 349.23, 392, 440, 493.88, 523.25}, _CMinor{261.63, 293.66, 311.13, 349.23, 392, 415.3, 493.88, 523.25}, _DMajor{293.66, 329.63, 369.99, 392, 440, 493.88, 554, 587.33}, _DMinor{293.66, 329.63, 349.23, 392, 440, 446.16, 523.25, 587.33}, _EMajor{329.63, 369.99, 415.3, 440, 493.88, 554.37, 622.25, 659.25}, _EMinor{329.63, 369.99, 392, 440, 493.88, 523.25, 587.33, 659.25}, _FMajor{349.23, 392, 440, 466.16, 523.25, 587.33, 659.25, 698.46}, _FMinor{349.23, 392, 415.3, 466.16, 523.25, 554.37, 622.25, 698.46}, _GMajor{196, 220, 246.99, 261.63, 293.66, 329.63, 369.99, 392}, _GMinor{196, 220, 233.08, 261.63, 293.66, 311.13, 349.23, 392}, _scale_counter{5} {}
// scale counter mutator method
void Scales::set_scale_counter() {
    // Modified from Calculate function from Map Class by Cornelius Bezuidenhout, 2016
    _scale_counter = ((scale_control.read() - 0)*(14 - 1)/(1 - 0) + 1);
    if(_scale_counter == 1){
        lcd.clear();
        lcd.printString("    A Major ", 0, 2);
        lcd.refresh();
    }
    if(_scale_counter == 2){
        lcd.clear();
        lcd.printString("    A Minor ", 0, 2);
        lcd.refresh();
    }
    if(_scale_counter == 3){
        lcd.clear();
        lcd.printString("    B Major ", 0, 2);
        lcd.refresh();
    }
    if(_scale_counter == 4){
        lcd.clear();
        lcd.printString("    B Minor ", 0, 2);
        lcd.refresh();
    }
    if(_scale_counter == 5){
        lcd.clear();
        lcd.printString("    C Major ", 0, 2);
        lcd.refresh();
    }
    if(_scale_counter == 6){
        lcd.clear();
        lcd.printString("    C Minor ", 0, 2);
        lcd.refresh();
    }
    if(_scale_counter == 7){
        lcd.clear();
        lcd.printString("    D Major ", 0, 2);
        lcd.refresh();
    }
    if(_scale_counter == 8){
        lcd.clear();
        lcd.printString("    D Minor ", 0, 2);
        lcd.refresh();
    }
    if(_scale_counter == 9){
        lcd.clear();
        lcd.printString("    E Major ", 0, 2);
        lcd.refresh();
    }
    if(_scale_counter == 10){
        lcd.clear();
        lcd.printString("    E Minor ", 0, 2);
        lcd.refresh();
    }
    if(_scale_counter == 11){
        lcd.clear();
        lcd.printString("    F Major ", 0, 2);
        lcd.refresh();
    }
    if(_scale_counter == 12){
        lcd.clear();
        lcd.printString("    F Minor ", 0, 2);
        lcd.refresh();
    }
    if(_scale_counter == 13){
        lcd.clear();
        lcd.printString("    G Major ", 0, 2);
        lcd.refresh();
    }
    if(_scale_counter == 14){
        lcd.clear();
        lcd.printString("    G Minor ", 0, 2);
        lcd.refresh();
    }
}
// fetches note 1 from specified scale array
float Scales::get_note1() {
    float note;
    if (_scale_counter == 1){
        note = _AMajor[0];
    }
    if (_scale_counter == 2){
        note = _AMinor[0];
    }
    if (_scale_counter == 3){
        note = _BMajor[0];
    }
    if (_scale_counter == 4){
        note = _BMinor[0];
    }
    if (_scale_counter == 5){
        note = _CMajor[0];
    }
    if (_scale_counter == 6){
        note = _CMinor[0];
    }
    if (_scale_counter == 7){
        note = _DMajor[0];
    }
    if (_scale_counter == 8){
        note = _DMinor[0];
    }
    if (_scale_counter == 9){
        note = _EMajor[0];
    }
    if (_scale_counter == 10){
        note = _EMinor[0];
    }
    if (_scale_counter == 11){
        note = _FMajor[0];
    }
    if (_scale_counter == 12){
        note = _FMinor[0];
    }
    if (_scale_counter == 13){
        note = _GMajor[0];
    }
    if (_scale_counter == 14){
        note = _GMinor[0];
    }
    return note;
}
// fetches note 2 from specified scale array
float Scales::get_note2() {
    float note;
    if (_scale_counter == 1){
        note = _AMajor[1];
    }
    if (_scale_counter == 2){
        note = _AMinor[1];
    }
    if (_scale_counter == 3){
        note = _BMajor[1];
    }
    if (_scale_counter == 4){
        note = _BMinor[1];
    }
    if (_scale_counter == 5){
        note = _CMajor[1];
    }
    if (_scale_counter == 6){
        note = _CMinor[1];
    }
    if (_scale_counter == 7){
        note = _DMajor[1];
    }
    if (_scale_counter == 8){
        note = _DMinor[1];
    }
    if (_scale_counter == 9){
        note = _EMajor[1];
    }
    if (_scale_counter == 10){
        note = _EMinor[1];
    }
    if (_scale_counter == 11){
        note = _FMajor[1];
    }
    if (_scale_counter == 12){
        note = _FMinor[1];
    }
    if (_scale_counter == 13){
        note = _GMajor[1];
    }
    if (_scale_counter == 14){
        note = _GMinor[1];
    }
    return note;
}
// fetches note 3 from specified scale array
float Scales::get_note3() {
    float note;
    if (_scale_counter == 1){
        note = _AMajor[2];
    }
    if (_scale_counter == 2){
        note = _AMinor[2];
    }
    if (_scale_counter == 3){
        note = _BMajor[2];
    }
    if (_scale_counter == 4){
        note = _BMinor[2];
    }
    if (_scale_counter == 5){
        note = _CMajor[2];
    }
    if (_scale_counter == 6){
        note = _CMinor[2];
    }
    if (_scale_counter == 7){
        note = _DMajor[2];
    }
    if (_scale_counter == 8){
        note = _DMinor[2];
    }
    if (_scale_counter == 9){
        note = _EMajor[2];
    }
    if (_scale_counter == 10){
        note = _EMinor[2];
    }
    if (_scale_counter == 11){
        note = _FMajor[2];
    }
    if (_scale_counter == 12){
        note = _FMinor[2];
    }
    if (_scale_counter == 13){
        note = _GMajor[2];
    }
    if (_scale_counter == 14){
        note = _GMinor[2];
    }
    return note;
}
// fetches note 4 from specified scale array
float Scales::get_note4() {
    float note;
    if (_scale_counter == 1){
        note = _AMajor[3];
    }
    if (_scale_counter == 2){
        note = _AMinor[3];
    }
    if (_scale_counter == 3){
        note = _BMajor[3];
    }
    if (_scale_counter == 4){
        note = _BMinor[3];
    }
    if (_scale_counter == 5){
        note = _CMajor[3];
    }
    if (_scale_counter == 6){
        note = _CMinor[3];
    }
    if (_scale_counter == 7){
        note = _DMajor[3];
    }
    if (_scale_counter == 8){
        note = _DMinor[3];
    }
    if (_scale_counter == 9){
        note = _EMajor[3];
    }
    if (_scale_counter == 10){
        note = _EMinor[3];
    }
    if (_scale_counter == 11){
        note = _FMajor[3];
    }
    if (_scale_counter == 12){
        note = _FMinor[3];
    }
    if (_scale_counter == 13){
        note = _GMajor[3];
    }
    if (_scale_counter == 14){
        note = _GMinor[3];
    }
    return note;
}
// fetches note 5 from specified scale array
float Scales::get_note5() {
    float note;
    if (_scale_counter == 1){
        note = _AMajor[4];
    }
    if (_scale_counter == 2){
        note = _AMinor[4];
    }
    if (_scale_counter == 3){
        note = _BMajor[4];
    }
    if (_scale_counter == 4){
        note = _BMinor[4];
    }
    if (_scale_counter == 5){
        note = _CMajor[4];
    }
    if (_scale_counter == 6){
        note = _CMinor[4];
    }
    if (_scale_counter == 7){
        note = _DMajor[4];
    }
    if (_scale_counter == 8){
        note = _DMinor[4];
    }
    if (_scale_counter == 9){
        note = _EMajor[4];
    }
    if (_scale_counter == 10){
        note = _EMinor[4];
    }
    if (_scale_counter == 11){
        note = _FMajor[4];
    }
    if (_scale_counter == 12){
        note = _FMinor[4];
    }
    if (_scale_counter == 13){
        note = _GMajor[4];
    }
    if (_scale_counter == 14){
        note = _GMinor[4];
    }
    return note;
}
// fetches note 6 from specified scale array
float Scales::get_note6() {
    float note;
    if (_scale_counter == 1){
        note = _AMajor[5];
    }
    if (_scale_counter == 2){
        note = _AMinor[5];
    }
    if (_scale_counter == 3){
        note = _BMajor[5];
    }
    if (_scale_counter == 4){
        note = _BMinor[5];
    }
    if (_scale_counter == 5){
        note = _CMajor[5];
    }
    if (_scale_counter == 6){
        note = _CMinor[5];
    }
    if (_scale_counter == 7){
        note = _DMajor[5];
    }
    if (_scale_counter == 8){
        note = _DMinor[5];
    }
    if (_scale_counter == 9){
        note = _EMajor[5];
    }
    if (_scale_counter == 10){
        note = _EMinor[5];
    }
    if (_scale_counter == 11){
        note = _FMajor[5];
    }
    if (_scale_counter == 12){
        note = _FMinor[5];
    }
    if (_scale_counter == 13){
        note = _GMajor[5];
    }
    if (_scale_counter == 14){
        note = _GMinor[5];
    }
    return note;
}
// fetches note 7 from specified scale array
float Scales::get_note7() {
    float note;
    if (_scale_counter == 1){
        note = _AMajor[6];
    }
    if (_scale_counter == 2){
        note = _AMinor[6];
    }
    if (_scale_counter == 3){
        note = _BMajor[6];
    }
    if (_scale_counter == 4){
        note = _BMinor[6];
    }
    if (_scale_counter == 5){
        note = _CMajor[6];
    }
    if (_scale_counter == 6){
        note = _CMinor[6];
    }
    if (_scale_counter == 7){
        note = _DMajor[6];
    }
    if (_scale_counter == 8){
        note = _DMinor[6];
    }
    if (_scale_counter == 9){
        note = _EMajor[6];
    }
    if (_scale_counter == 10){
        note = _EMinor[6];
    }
    if (_scale_counter == 11){
        note = _FMajor[6];
    }
    if (_scale_counter == 12){
        note = _FMinor[6];
    }
    if (_scale_counter == 13){
        note = _GMajor[6];
    }
    if (_scale_counter == 14){
        note = _GMinor[6];
    }
    return note;
}
// fetches note 8 from specified scale array
float Scales::get_note8() {
    float note;
    if (_scale_counter == 1){
        note = _AMajor[7];
    }
    if (_scale_counter == 2){
        note = _AMinor[7];
    }
    if (_scale_counter == 3){
        note = _BMajor[7];
    }
    if (_scale_counter == 4){
        note = _BMinor[7];
    }
    if (_scale_counter == 5){
        note = _CMajor[7];
    }
    if (_scale_counter == 6){
        note = _CMinor[7];
    }
    if (_scale_counter == 7){
        note = _DMajor[7];
    }
    if (_scale_counter == 8){
        note = _DMinor[7];
    }
    if (_scale_counter == 9){
        note = _EMajor[7];
    }
    if (_scale_counter == 10){
        note = _EMinor[7];
    }
    if (_scale_counter == 11){
        note = _FMajor[7];
    }
    if (_scale_counter == 12){
        note = _FMinor[7];
    }
    if (_scale_counter == 13){
        note = _GMajor[7];
    }
    if (_scale_counter == 14){
        note = _GMinor[7];
    }
    return note;
}
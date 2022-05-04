#ifndef SCALES_H
#define SCALES_H

#include <vector>
#include "Pins.h"
#include "mbed.h"

class Scales {
    public:
    Scales(); // constructor
    ~Scales(); // destructor
    void set_scale_counter(); // sets scale_counter value (mutator)
    // gets scale (accessors)
    float get_note1();
    float get_note2();
    float get_note3();
    float get_note4();
    float get_note5();
    float get_note6();
    float get_note7();
    float get_note8();
    private:
    int _scale_counter;// scale counter
    // stores notes in the scale
    const float _AMajor[8];
    const float _AMinor[8];
    const float _BMajor[8];
    const float _BMinor[8];  
    const float _CMajor[8];
    const float _CMinor[8];
    const float _DMajor[8];
    const float _DMinor[8];
    const float _EMajor[8];
    const float _EMinor[8];
    const float _FMajor[8];
    const float _FMinor[8];
    const float _GMajor[8];
    const float _GMinor[8];
};
#endif
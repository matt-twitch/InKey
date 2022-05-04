#include "PwmOut.h"
#include "N5110.h"
#include "mbed.h"

#ifndef PINS_H
#define PINS_H

// scale control button
extern InterruptIn change_scale;
extern AnalogIn scale_control;
// keyboard
extern DigitalIn note1;
extern DigitalIn note2;
extern DigitalIn note3;
extern DigitalIn note4;
extern DigitalIn note5;
extern DigitalIn note6;
extern DigitalIn note7;
extern DigitalIn note8;
// record and playback buttons
extern DigitalIn Record;
extern DigitalIn Stop;
extern InterruptIn Play;
extern InterruptIn Clear_buffer;
// octave control
extern InterruptIn octave_up;
extern InterruptIn octave_down;
// speaker
extern PwmOut Speaker;
// lcd
extern N5110 lcd;

extern Serial pc;
#endif
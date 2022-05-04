#include "InterruptIn.h"
#include "PinNames.h"
#include "PwmOut.h"
#include "mbed.h"
#include "Pins.h"

// scale control buttons
InterruptIn change_scale(PA_7);
// scale control
AnalogIn scale_control(PC_5);
// keyboard 
DigitalIn note1(PC_0);
DigitalIn note2(PC_1);
DigitalIn note3(PB_0);
DigitalIn note4(PA_4);
DigitalIn note5(PA_1);
DigitalIn note6(PC_3);
DigitalIn note7(PB_13);
DigitalIn note8(PB_14);
// record and play back
DigitalIn Record(PA_12);
DigitalIn Stop(PB_6);
InterruptIn Play(PB_1);
InterruptIn Clear_buffer(PA_11);
// octave control
InterruptIn octave_up(PC_6);
InterruptIn octave_down(PB_8);
// speaker
PwmOut Speaker(PC_8);
// lcd
N5110 lcd(PC_7, PA_9, PB_10, PB_5, PB_3, PA_10);
#include "mbed.h"
#include "Pins.h"
#include "N5110.h"

#ifndef FUNCS_H
#define FUNCS_H


void note_on(float frequency); // function to play note: modified from "pwm-buzzer-example", Andrew Knowles 2021
void note_off(); // note off function
void buttons_init(); // button initialisation
void lcd_init(); // lcd initialisation
void start_sound(); // strat up sound
void welcome_msg(); // welcome message
bool start_record(); // starts recording into buffer
bool stop_record(); // stops recording

#endif
#include "Scales.h"
#include "Pins.h"
#include "funcs.h"
#include "Recorder.h"
#include <vector>
#include "mbed.h"
#include "mbed_power_mgmt.h"

Serial pc(USBTX, USBRX);

volatile int g_scale_change = 0; // flag for scale change
volatile int g_play = 0; // flag for playback
volatile int g_clear_buffer = 0; // flag for clear buffer
volatile int g_octave_up = 0; // flag for octave up
volatile int g_octave_down = 0; // flag for octave down
void scale_change_isr(); // scale change ISR prototype
void play_isr(); // playback isr prototype
void clear_buffer_isr(); // clear buffer isr prototype
void octave_up_isr(); // octave up isr prototype
void octave_down_isr(); // octave down isr prototype
// main() runs in its own thread in the OS
int main(){
    buttons_init(); // initialise buttons
    lcd_init(); // initialises lcd
    // sets flags for isrs
    change_scale.rise(&scale_change_isr); 
    Play.rise(&play_isr);
    Clear_buffer.rise(&clear_buffer_isr);
    octave_up.rise(&octave_up_isr);
    octave_down.rise(&octave_down_isr);
    bool record = false; // flag for record 
    Scales scales; // calls scales class
    Recorder recorder; // class record clas
    float current_scale[8]; // array to store current scale
    current_scale[0] = scales.get_note1(); 
    current_scale[1] = scales.get_note2();
    current_scale[2] = scales.get_note3();
    current_scale[3] = scales.get_note4();
    current_scale[4] = scales.get_note5();
    current_scale[5] = scales.get_note6();
    current_scale[6] = scales.get_note7();
    current_scale[7] = scales.get_note8();
    start_sound(); // plays start up sound
    welcome_msg(); // displays welcome message
    // process block
    while (true){
        if(Record.read() == 1){
            record = start_record();
        }
        if(Stop.read() == 1){
            record = stop_record();
        }
        if(g_scale_change == 1){ // changes scale when a change has been detected 
            scales.set_scale_counter(); // sets counter value
            current_scale[0] = scales.get_note1();
            current_scale[1] = scales.get_note2();
            current_scale[2] = scales.get_note3();
            current_scale[3] = scales.get_note4();
            current_scale[4] = scales.get_note5();
            current_scale[5] = scales.get_note6();
            current_scale[6] = scales.get_note7();
            current_scale[7] = scales.get_note8();
            g_scale_change = 0; // resets flag when change_scale button no longer activated
        }
        if(g_play == 1){ // checks to see if record is enabled
            lcd.clear();
            lcd.printString(" Playing back! ", 0, 2);
            lcd.refresh();
            recorder.get_buffer();
            ThisThread::sleep_for(1000);
            g_play = 0;
            lcd.clear();
        }
        if(g_clear_buffer == 1){ // checks to see if the buffer needs to be cleared
            lcd.clear();
            lcd.printString(" Recording ", 0, 2);
            lcd.printString(" Cleared! ", 0 ,3);
            lcd.refresh();
            recorder.clear_buffer();
            ThisThread::sleep_for(2000);
            g_clear_buffer = 0;
        }
        if(g_octave_up == 1){
            for(int i = 0 ; i <= 8 ; i ++){
                current_scale[i] = current_scale[i]*2;
            }
            g_octave_up = 0;
        }
        if(g_octave_down == 1){
            for(int i = 0 ; i <= 8 ; i ++){
                current_scale[i] = current_scale[i]/2;
            }
            g_octave_down = 0;
        }
        // plays note when relevent button on keyboard is pressed
        if(note1.read() == 1){ 
            if(record == true){
                recorder.set_buffer(current_scale[0]);
                recorder.set_buffer_size();
            }
            note_on(current_scale[0]);
            note_off();
        }
        if(note2.read() == 1){
            if(record == true){
                recorder.set_buffer(current_scale[1]);
                recorder.set_buffer_size();
            }
            note_on(current_scale[1]);
            note_off();
        }
        if(note3.read() == 1){
            if(record == true){
                recorder.set_buffer(current_scale[2]);
                recorder.set_buffer_size();
            }
            note_on(current_scale[2]);
            note_off();
        }
        if(note4.read() == 1){
            if(record == true){
                recorder.set_buffer(current_scale[3]);
                recorder.set_buffer_size();
            }
            note_on(current_scale[3]);
            note_off();
        }
        if(note5.read() == 1){
            if(record == true){
                recorder.set_buffer(current_scale[4]);
                recorder.set_buffer_size();
            }
            note_on(current_scale[4]);
            note_off();
        }
        if(note6.read() == 1){
            note_on(current_scale[5]);
            if(record == true){
                recorder.set_buffer(current_scale[5]);
                recorder.set_buffer_size();
            }
            note_off();
        }
        if(note7.read() == 1){
            note_on(current_scale[6]);
            if(record == true){
                recorder.set_buffer(current_scale[6]);
                recorder.set_buffer_size();
            }
            note_off();
        }
        if(note8.read() == 1){
            note_on(current_scale[7]);
            if(record == true){
                recorder.set_buffer(current_scale[7]);
                recorder.set_buffer_size();
            }
            note_off();
        }
    }
}
void scale_change_isr(){ // triggers scale change ISR
    g_scale_change = 1;
}
void play_isr(){ // triggers audio playback
    g_play = 1;
}
void clear_buffer_isr(){ // triggers clearing of buffer
    g_clear_buffer = 1;
}
void octave_up_isr(){ // triggers octave up
    g_octave_up = 1;
}
void octave_down_isr(){ // triggers octave down
    g_octave_down = 1;
}
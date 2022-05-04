#include "Recorder.h"
#include "funcs.h"

// constructor
Recorder::Recorder() : _buffer{0}, _buffer_size{0} {};
// mutator method to record into buffer
void Recorder::set_buffer(float input){
    _buffer.push_back(input); 
}
// mutator method to set buffer size
void Recorder::set_buffer_size(){
    _buffer_size++;
}
// mutator to clear buffer
void Recorder::clear_buffer(){
    _buffer.clear();
    _buffer_size = 0;
}
// accesor method for playback
void Recorder::get_buffer(){
    for(int i = 1 ; i <= _buffer_size ; i++){
        note_on(_buffer[i]);
        note_off();
    }
}
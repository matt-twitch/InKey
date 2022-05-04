#ifndef RECORDER_H
#define RECORDER_H

#include "Pins.h"
#include "mbed.h"
#include <vector>

class Recorder{
    public:
       Recorder(); // constructor
       ~Recorder(); // destructor
       void set_buffer(float input); // mutator method to input notes to record buffer
       void set_buffer_size(); // mutator method to record buffer size
       void clear_buffer(); // mutator to clear buffer
       void get_buffer(); // accessor for audio playback
    private:
        std::vector<float> _buffer; // vector-based audio buffer for storing notes
        int _buffer_size; // buffer size counter
};

#endif
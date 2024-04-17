#ifndef STATES_H
#define STATES_H
#include <stdint.h>
#include <stdbool.h>

enum mode_state {
    DEFAULT_MODE,
    HUE_MODE,
    SATURATION_MODE,
    VALUE_MODE,
};

extern volatile enum button_state {
    DEFAULT,
    DOUBLE_CLICK,
    LONG_CLICK
} button_state;

struct hsv{
    uint16_t hue;          
    uint8_t saturation; 
    uint8_t value; 
};

struct rgb{
    uint16_t red;          
    uint8_t green; 
    uint8_t blue; 
};

extern struct hsv hsv_color;

extern enum mode_state mode;

#endif 


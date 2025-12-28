#pragma once
#include "../lib/TFT_eSPI/TFT_eSPI.h"

// Display 
#define LANDSCAPE_MODE 1

extern int DISPLAY_H;
extern int DISPLAY_W;
extern TFT_eSPI tft;

inline void set_display_height(void)
{
    DISPLAY_H = tft.height();
}

inline void set_display_width(void)
{
    DISPLAY_W = tft.width();
}

// MCU
#define ESP32_BAUD_RATE 115200
#define ADC_PIN 34


// LVGL
#define FLUSH_BUFFER_LINES 40
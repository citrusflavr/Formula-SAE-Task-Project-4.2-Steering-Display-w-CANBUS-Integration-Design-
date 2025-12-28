#include "../lib/lvgl/lvgl.h"
#include "../lib/TFT_eSPI/TFT_eSPI.h"
#include "ui/ui.h"
#include "ui/vars.h"
#include "driver/twai.h"
#include "driver/gpio.h"

#include "config.h"
#include "Ticker.h"


// Voltage Divider Ratio
#define DIVIDER_RATIO (5.6f / (5.6f + 2.2f)) // 2.2k / 5.6k (bottom / (top + bottom))

#define DEBUG true

Ticker ticker;

// GLOBAL
TFT_eSPI tft = TFT_eSPI();
    // do not touch; initialized by set_display_...()
    // wtf is this?? this is fucking garbage. change this IMMEDIATELY after this shit actually works.
int DISPLAY_W = 0;
int DISPLAY_H = 0;


#if LV_USE_LOG
static inline void lv_log_callback(
    const char* buffer
)
{
    Serial.print("LVGL LOG: ");
    Serial.println(buffer);

    return;
}
#endif

void lvgl_tick()
{
    lv_tick_inc(1);
}

// Blocks I/O until finished, but shouldn't really matter
// in this case.
void display_flush(
    lv_disp_drv_t*    display,
    const lv_area_t*  area,
    lv_color_t*       color_p
)
{
    uint32_t width  = lv_area_get_width(area);
    uint32_t height = lv_area_get_height(area);

#if DEBUG
    Serial.print("Flush Width: ");
    Serial.println(width);

    Serial.print("Flush Height: ");
    Serial.println(height);
#endif
    tft.startWrite();

    tft.setAddrWindow(
        area->x1,
        area->y1,
        width,
        height
    );

    tft.pushPixels(
        (uint16_t*)color_p,
        width * height
    );

    tft.endWrite();
    
    lv_disp_flush_ready(display);
    return;
}


static uint32_t tick(void)
{
    return millis();
}


/* void do_fucking_everything_except_brake_bias(twai_message_t message)
{
    if (message.rtr || message.extd)
        return;

    uint32_t message_id = message.identifier;

    switch (message_id)
    {
    case 0x118:
    {
        uint8_t index = 0;

        index = message.data[0];
        set_var_rpm(index);

        index = message.data[2];
        set_var_mph(index);

        index = message.data[3];
        set_var_coolant_temp(index);

        break;
    }

    case 0x64D:
    {
        uint8_t index = 0;

        index = message.data[6];
        index = index & 0x0F;
        set_var_gear(index);

        break;
    }


    default:
        return; // Not a CAN BUS message that I care about
    }
}

void do_fucking_everything_related_to_brake_bias()
{
    uint32_t raw_data  = analogRead(ADC_PIN);          //0-4095 at 12 bits
    float    volts_adc = (raw_data / 4095.0f) * 3.3f;  // makes the bits back into voltage when it reached adc

    float volts_sensor = volts_adc / DIVIDER_RATIO;    // turns it back to original voltage before the resistor divider

    // pretend i parse it here

    int  written = 0;                  // because snprintf returns int and is not designed for embedded.
    char brake_bias_front_string[10];
    char brake_bias_rear_string [10];

    written = snprintf(
        brake_bias_front_string,
        10,
        "%.1f%%",
        volts_sensor // pretend this is parsed data
    );

    if (!(written >= 10))
    {
        set_var_brake_bias_front(brake_bias_front_string);
    }
    else
    {
        Serial.println("Truncation happened while attempting to write to brake bias front's buffer. Check buffer size\n");
    }

    written = snprintf(
        brake_bias_rear_string,
        10,
        "%.1f%%",
        volts_sensor //again, pretend this is parsed data
    );

    if (!(written >= 10))
    {
        set_var_brake_bias_rear(brake_bias_rear_string);
    }
    else
    {
        Serial.println("Truncation happened while attempting to write to brake bias front's buffer. Check buffer size");
    } 

    return;
}
 */
void hang_program()
{
    Serial.print("Press ENTER to continue: ");

    while (Serial.available())
        (void)Serial.read();

    while (true)
    {
        if (Serial.available())
        {
            int lol = Serial.read();

            if (lol == '\n'
            || lol == '\r')
                break;
        }

        delay(1);
    }
}

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(ESP32_BAUD_RATE);

    analogReadResolution   (12);
    analogSetPinAttenuation(ADC_PIN, ADC_11db);

    //twai init shit (can controller)
    static const twai_general_config_t general_config = TWAI_GENERAL_CONFIG_DEFAULT(
        GPIO_NUM_27,
        GPIO_NUM_35,
        TWAI_MODE_LISTEN_ONLY);

    static const twai_timing_config_t timing_config = TWAI_TIMING_CONFIG_1MBITS    ();
    static const twai_filter_config_t filter_config = TWAI_FILTER_CONFIG_ACCEPT_ALL();

    if (twai_driver_install(
            &general_config,
            &timing_config,
            &filter_config) == ESP_OK)
    {
        Serial.println("TWAI Driver install OK");
    }

    else
    {
		Serial.println("TWAI Driver install error");
        hang_program();
    }

    if (twai_start() == ESP_OK)
        Serial.println("TWAI OK");
    else
    {
        Serial.println("TWAI ERR: Failed to Start");
        hang_program();
    }

    // tft_espi init shit
    tft.init();
    set_display_height();
    set_display_width ();
    tft.setRotation (LANDSCAPE_MODE);
    tft.setSwapBytes(true); // MCU is little-endian; Display controller expects big-endian
    tft.fillScreen  (TFT_YELLOW);

    // lvgl init shit
    lv_init();
#if LV_USE_LOG
    lv_log_register_print_cb(lv_log_callback);
#endif

    static lv_color_t* draw_buffer;
    draw_buffer = (lv_color_t*)heap_caps_malloc(
        DISPLAY_W * FLUSH_BUFFER_LINES * sizeof(lv_color_t),
        MALLOC_CAP_DMA | MALLOC_CAP_INTERNAL
    );

    static lv_disp_draw_buf_t display_draw_buffer;
    lv_disp_draw_buf_init(
        &display_draw_buffer,
        draw_buffer,
        NULL,
        DISPLAY_W * FLUSH_BUFFER_LINES
    );

    static lv_disp_drv_t display_drv;
    lv_disp_drv_init(&display_drv);
    display_drv.hor_res  = tft.width();
    display_drv.ver_res  = tft.height();
    display_drv.flush_cb = display_flush;
    display_drv.draw_buf = &display_draw_buffer;

    lv_disp_t* display = lv_disp_drv_register(&display_drv);
    if (display != NULL)
        Serial.println("LVGL OK");
    else
    {
        Serial.println("LVGL ERR: Display failed to init");
        hang_program();
    }

#if DEBUG
    Serial.print("LV MEM SIZE: ");
    Serial.println(LV_MEM_SIZE);
#endif

    ticker.attach_ms(1, lvgl_tick);
    ui_init();
    Serial.println("Setup Complete");
}

void loop()
{
    // put your main code here, to run repeatedly:

    twai_message_t message;

    if (twai_receive(&message, pdMS_TO_TICKS(100)) == ESP_OK)
    {
        Serial.println("Received a message");
        //do_fucking_everything_except_brake_bias(message);
    }
#if DEBUG
    else
    {
        Serial.println("No messages recieved");
    }
#endif

    //do_fucking_everything_related_to_brake_bias();
    lv_timer_handler();
    ui_tick         ();
    delay           (1);
}

#include "../ui/vars.h"
#include <stdint.h>
#include <string.h>


int32_t mph                = 0;
int32_t rpm                = 0;
int32_t gear               = 0;  // NOTE: CAN BUS message for gear is actually a signed 4 bit message
int32_t coolant_temp       = 0;
char   brake_bias_front[100]    = {0};     
char   brake_bias_rear [100]    = {0};


int32_t get_var_mph()
{
    return mph;
}

void set_var_mph(int32_t input_mph)
{
     mph = input_mph;
}

int32_t get_var_rpm()
{
    return rpm;
}

void set_var_rpm(int32_t input_rpm)
{
    rpm = input_rpm;
}


int32_t get_var_gear()
{
    return gear;
}

void set_var_gear(int32_t input_gear)
{
    gear = input_gear;
}


int32_t get_var_coolant_temp()
{
    return coolant_temp;
}

void set_var_coolant_temp(int32_t input_coolant_temp)
{
    coolant_temp = input_coolant_temp;
}


const char* get_var_brake_bias_front()
{
    return brake_bias_front;
}

void set_var_brake_bias_front(const char* input_brake_bias_front)
{
    if(!input_brake_bias_front)
        return;

    strncpy(brake_bias_front, input_brake_bias_front, sizeof(brake_bias_front) / sizeof(char));
    brake_bias_front[sizeof(brake_bias_front) / sizeof(char) - 1] = 0;
}


const char* get_var_brake_bias_rear()
{
    return brake_bias_rear;
}

void set_var_brake_bias_rear(const char* input_brake_bias_rear)
{
    if (!input_brake_bias_rear)
        return;
    strncpy(brake_bias_rear, input_brake_bias_rear, sizeof(brake_bias_rear) / sizeof(char));
    brake_bias_rear[sizeof(brake_bias_rear) / sizeof(char) - 1] = 0;
}
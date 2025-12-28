#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"


#include <string.h>
#include <ctype.h>

objects_t objects;
lv_obj_t *tick_value_change_obj;
uint32_t active_theme_index = 0;

void create_screen_main() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 320);
    {
        lv_obj_t *parent_obj = obj;
        {
            // label_RPM
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_rpm = obj;
            lv_obj_set_pos(obj, 217, 8);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_dim1415_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "RPM");
        }
        {
            // container_GEAR
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.container_gear = obj;
            lv_obj_set_pos(obj, 169, 95);
            lv_obj_set_size(obj, 143, 225);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffdedb05), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // text_GEAR
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.text_gear = obj;
            lv_obj_set_pos(obj, 212, 116);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_dim1415_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "GEAR");
        }
        {
            // label_GEAR
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_gear = obj;
            lv_obj_set_pos(obj, 0, 65);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_dim1415_128, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            lv_obj_set_pos(obj, 312, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            static lv_point_t line_points[] = {
                { 0, 0 },
                { 0, 319 }
            };
            lv_line_set_points(obj, line_points, 2);
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            lv_obj_set_pos(obj, 168, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            static lv_point_t line_points[] = {
                { 0, 0 },
                { 0, 319 }
            };
            lv_line_set_points(obj, line_points, 2);
        }
        {
            // text_RPM
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.text_rpm = obj;
            lv_obj_set_pos(obj, 1, -103);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_dim1415_48, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            lv_obj_set_pos(obj, 313, 81);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            static lv_point_t line_points[] = {
                { 0, 0 },
                { 166, 0 }
            };
            lv_line_set_points(obj, line_points, 2);
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            lv_obj_set_pos(obj, 0, 80);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            static lv_point_t line_points[] = {
                { 0, 0 },
                { 167, 0 }
            };
            lv_line_set_points(obj, line_points, 2);
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            lv_obj_set_pos(obj, 312, 160);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            static lv_point_t line_points[] = {
                { 0, 0 },
                { 167, 0 }
            };
            lv_line_set_points(obj, line_points, 2);
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            lv_obj_set_pos(obj, 0, 160);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            static lv_point_t line_points[] = {
                { 0, 0 },
                { 168, 0 }
            };
            lv_line_set_points(obj, line_points, 2);
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            lv_obj_set_pos(obj, 312, 236);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            static lv_point_t line_points[] = {
                { 0, 0 },
                { 167, 0 }
            };
            lv_line_set_points(obj, line_points, 2);
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            lv_obj_set_pos(obj, 0, 237);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            static lv_point_t line_points[] = {
                { 0, 0 },
                { 168, 0 }
            };
            lv_line_set_points(obj, line_points, 2);
        }
        {
            // label_MPH
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_mph = obj;
            lv_obj_set_pos(obj, 13, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_dim1415_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "MPH");
        }
        {
            // label_COOLANT_TEMP
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_coolant_temp = obj;
            lv_obj_set_pos(obj, 13, 242);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_dim1415_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "C. TEMP");
        }
        {
            // coolant_temp
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.coolant_temp = obj;
            lv_obj_set_pos(obj, 31, 266);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_dim1415_48, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            // label_coolant_temp_unit
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_coolant_temp_unit = obj;
            lv_obj_set_pos(obj, 115, 266);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_dim1415_48, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "F");
        }
        {
            // mph
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.mph = obj;
            lv_obj_set_pos(obj, -154, -106);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_dim1415_48, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            // label_brake_bias
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_brake_bias = obj;
            lv_obj_set_pos(obj, 397, 5);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_dim1415_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "B. BIAS");
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            lv_obj_set_pos(obj, 395, 31);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            static lv_point_t line_points[] = {
                { 0, 0 },
                { 0, 50 }
            };
            lv_line_set_points(obj, line_points, 2);
        }
        {
            // brake_bias_front
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.brake_bias_front = obj;
            lv_obj_set_pos(obj, 313, 33);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_dim1415_48, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            // brake_bias_rear
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.brake_bias_rear = obj;
            lv_obj_set_pos(obj, 197, -103);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_dim1415_48, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
    }
    
    tick_screen_main();
}

/* void tick_screen_main() {
    {
        const char *new_val = get_var_gear();
        const char *cur_val = lv_label_get_text(objects.label_gear);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_gear;
            lv_label_set_text(objects.label_gear, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_rpm();
        const char *cur_val = lv_label_get_text(objects.text_rpm);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.text_rpm;
            lv_label_set_text(objects.text_rpm, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_coolant_temp();
        const char *cur_val = lv_label_get_text(objects.coolant_temp);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.coolant_temp;
            lv_label_set_text(objects.coolant_temp, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_mph();
        const char *cur_val = lv_label_get_text(objects.mph);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.mph;
            lv_label_set_text(objects.mph, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_brake_bias_front();
        const char *cur_val = lv_label_get_text(objects.brake_bias_front);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.brake_bias_front;
            lv_label_set_text(objects.brake_bias_front, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_brake_bias_rear();
        const char *cur_val = lv_label_get_text(objects.brake_bias_rear);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.brake_bias_rear;
            lv_label_set_text(objects.brake_bias_rear, new_val);
            tick_value_change_obj = NULL;
        }
    }
} */

#include <stdio.h>
#include <inttypes.h>

void tick_screen_main() {
    static char gear_buffer[10];
    static char rpm_buffer [10];
    static char c_temp_buffer[10];
    static char mph_buffer [10];

    {
        int gear_val = get_var_gear();
        if(
            gear_val >= 0 &&
            gear_val <= 255 &&
            isalpha((unsigned char)gear_val)
        )
        {
            snprintf(
                gear_buffer,
                sizeof(gear_buffer),
                "%c",
                (char)get_var_gear()
            );
        }
        else
        {
            snprintf(
                gear_buffer,
                sizeof(gear_buffer),
                "%d",
                get_var_gear()
            ); 
        }


        const char *cur_val = lv_label_get_text(objects.label_gear);
        if (strcmp(gear_buffer, cur_val) != 0) {
            tick_value_change_obj = objects.label_gear;
            lv_label_set_text(objects.label_gear, gear_buffer);
            tick_value_change_obj = NULL;
        }
    }

    {
        snprintf(
            rpm_buffer,
            sizeof(rpm_buffer),
            "%d",
            get_var_rpm()
        ); 

        const char *cur_val = lv_label_get_text(objects.text_rpm);
        if (strcmp(rpm_buffer, cur_val) != 0) {
            tick_value_change_obj = objects.text_rpm;
            lv_label_set_text(objects.text_rpm, rpm_buffer);
            tick_value_change_obj = NULL;
        }
    }
    {
        snprintf(
            c_temp_buffer,
            sizeof(c_temp_buffer),
            "%d",
            get_var_coolant_temp()
        );

        const char *cur_val = lv_label_get_text(objects.coolant_temp);
        if (strcmp(c_temp_buffer, cur_val) != 0) {
            tick_value_change_obj = objects.coolant_temp;
            lv_label_set_text(objects.coolant_temp, c_temp_buffer);
            tick_value_change_obj = NULL;
        }
    }

    {
        snprintf(
            mph_buffer,
            sizeof(mph_buffer),
            "%d",
            get_var_mph()
        );

        const char *cur_val = lv_label_get_text(objects.mph);
        if (strcmp(mph_buffer, cur_val) != 0) {
            tick_value_change_obj = objects.mph;
            lv_label_set_text(objects.mph, mph_buffer);
            tick_value_change_obj = NULL;
        }
    }

    {
        const char *new_val = get_var_brake_bias_front();
        const char *cur_val = lv_label_get_text(objects.brake_bias_front);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.brake_bias_front;
            lv_label_set_text(objects.brake_bias_front, new_val);
            tick_value_change_obj = NULL;
        }
    }

    {
        const char *new_val = get_var_brake_bias_rear();
        const char *cur_val = lv_label_get_text(objects.brake_bias_rear);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.brake_bias_rear;
            lv_label_set_text(objects.brake_bias_rear, new_val);
            tick_value_change_obj = NULL;
        }
    }
}




typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
};
void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
void tick_screen_by_id(enum ScreensEnum screenId) {
    tick_screen_funcs[screenId - 1]();
}

void create_screens() {
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_main();
}

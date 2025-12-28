#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <../../lvgl/lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *main;
    lv_obj_t *label_rpm;
    lv_obj_t *container_gear;
    lv_obj_t *text_gear;
    lv_obj_t *label_gear;
    lv_obj_t *text_rpm;
    lv_obj_t *label_mph;
    lv_obj_t *label_coolant_temp;
    lv_obj_t *coolant_temp;
    lv_obj_t *label_coolant_temp_unit;
    lv_obj_t *mph;
    lv_obj_t *label_brake_bias;
    lv_obj_t *brake_bias_front;
    lv_obj_t *brake_bias_rear;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_MAIN = 1,
};

void create_screen_main();
void tick_screen_main();

void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/
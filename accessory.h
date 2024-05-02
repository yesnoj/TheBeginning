#include "core/lv_obj_style.h"
#include "lv_api_map_v8.h"
#include "font/lv_font.h"
#include "misc/lv_area.h"
#include "widgets/msgbox/lv_msgbox.h"
#include <cstddef>
#include "core/lv_obj_tree.h"
#include "core/lv_obj.h"
#include "misc/lv_event.h"
#include "misc/lv_types.h"
#include "misc/lv_style.h"
#include <sys/_stdint.h>
/**
 * @file accessory.h
 *
 */


#ifndef ACCESSORY_H
#define ACCESSORY_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
 
#include <lvgl.h>

/**********************
 *      MACROS
 **********************/

//OLD GUI APPROACH
/*
void event_btn_back(lv_event_t * e)
{
    switch(currentState)
    {
      case Display_State_0_Start:
        //TDB
      break;
      case Display_State_1_Program:
        previousState = Display_State_1_Program;
        currentState  = Display_State_0_Start;
      break;
      case Display_State_1_1_Cleaning:
        previousState = Display_State_1_1_Cleaning;
        currentState  = Display_State_1_Program;
      break;
      case Display_State_1_2_Develop:
        previousState = Display_State_1_2_Develop;
        currentState  = Display_State_1_Program;
      break;
            case Display_State_2_Film:
              previousState = Display_State_2_Film;
              currentState  = Display_State_1_2_Develop;
            break;
      case Display_State_1_3_MDC:
        previousState = Display_State_1_3_MDC;
        currentState  = Display_State_1_Program;
      break;
      case Display_State_1_1_1_Cleaning_Tank:
        previousState = Display_State_1_1_1_Cleaning_Tank;
        currentState  = Display_State_1_1_Cleaning;
      break;
    };
    
  isEnteringInPage = 1;
  LV_LOG_USER("CurrentState: %d , isEnteringInPage : %d",currentState, isEnteringInPage);
}
*/

static void event_cb(lv_event_t * e)
{
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t * obj = (lv_obj_t *)lv_event_get_target(e);
  lv_obj_t * objCont = (lv_obj_t *)lv_obj_get_parent(obj);
  lv_obj_t * mboxCont = (lv_obj_t *)lv_obj_get_parent(objCont);

    //const char *label = lv_msgbox_get_active_btn(mbox);
    //LV_UNUSED(label);
    lv_msgbox_close(mboxCont);
    lv_obj_delete(mboxCont);
    //LV_LOG_USER("Button %s clicked", lv_label_get(label));
}



static lv_obj_t * create_radiobutton(lv_obj_t * mBoxParent, const char * txt, const int32_t x, const int32_t y, const int32_t size, const lv_font_t * font, const lv_color_t borderColor, const lv_color_t bgColor)
{
	lv_obj_t * obj = (lv_obj_t *)lv_checkbox_create(mBoxParent);
  lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE);
	lv_obj_set_style_text_font(obj, font, LV_PART_MAIN);
	lv_checkbox_set_text(obj, txt);
	lv_obj_align(obj, LV_ALIGN_RIGHT_MID, x, y);


	lv_coord_t font_h = lv_font_get_line_height(font);
	lv_coord_t pad = (size - font_h) / 2;
	lv_obj_set_style_pad_left(obj, pad, LV_PART_INDICATOR);
	lv_obj_set_style_pad_right(obj, pad, LV_PART_INDICATOR);
	lv_obj_set_style_pad_top(obj, pad, LV_PART_INDICATOR);
	lv_obj_set_style_pad_bottom(obj, pad, LV_PART_INDICATOR);

  lv_obj_set_style_border_color(obj, borderColor, LV_PART_INDICATOR | LV_STATE_DEFAULT);
  lv_obj_set_style_border_color(obj, borderColor, LV_PART_INDICATOR | LV_STATE_CHECKED);
  lv_obj_set_style_bg_color(obj, bgColor, LV_PART_INDICATOR | LV_STATE_CHECKED);

	lv_obj_update_layout(obj);
	return obj;
}

void createMessageBox(char *title, char *text, char *button1Text, char *button2Text)
{
    
    messageBox = lv_msgbox_create(NULL);
    lv_msgbox_add_title(messageBox, title);
    lv_obj_set_style_bg_color(messageBox, lv_palette_main(LV_PALETTE_YELLOW), LV_PART_MAIN);
    //lv_msgbox_add_header_button(messageBox, NULL);
    lv_msgbox_add_text(messageBox, text); 
    

    lv_obj_t * btn;
    btn = lv_msgbox_add_footer_button(messageBox, button1Text);
    lv_obj_add_event_cb(btn, event_cb, LV_EVENT_CLICKED, NULL);
    btn = lv_msgbox_add_footer_button(messageBox, button2Text);
    lv_obj_add_event_cb(btn, event_cb, LV_EVENT_CLICKED, NULL);
    
}

void kb_event_cb(lv_event_t* e)
 {
    lv_event_code_t code = lv_event_get_code(e);
	  //lv_keyboard_t * kb = (lv_keyboard_t *)obj;

     if (code == LV_EVENT_CANCEL) {
         if (keyboard) {
            lv_textarea_set_text(keyboard_textArea, "");
            lv_obj_add_flag(lv_obj_get_parent(keyboard), LV_OBJ_FLAG_HIDDEN);
            lv_obj_remove_flag(mBoxParent, LV_OBJ_FLAG_HIDDEN);
         }
     }
      if (code == LV_EVENT_READY) {
         if (keyboard) {
            lv_textarea_set_text(mBoxNameTextArea, lv_textarea_get_text(keyboard_textArea));
            lv_textarea_set_text(keyboard_textArea, "");
            lv_obj_add_flag(lv_obj_get_parent(keyboard), LV_OBJ_FLAG_HIDDEN);
            lv_obj_remove_flag(mBoxParent, LV_OBJ_FLAG_HIDDEN);
            LV_LOG_USER(lv_textarea_get_text(keyboard_textArea));
         }
     }
 }


void event_checkbox_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = (lv_obj_t *)lv_event_get_target(e);
    if(code == LV_EVENT_VALUE_CHANGED) {
        LV_UNUSED(obj);
        const char * txt = lv_checkbox_get_text(obj);
        const char * state = lv_obj_get_state(obj) & LV_STATE_CHECKED ? "Checked" : "Unchecked";
        LV_UNUSED(txt);
        LV_UNUSED(state);
        LV_LOG_USER("%s: %s", txt, state);
    }
}

void create_keyboard(lv_obj_t * keyBoardParent)
{   
    keyBoardParent = lv_obj_class_create_obj(&lv_msgbox_backdrop_class, lv_layer_top());
    lv_obj_class_init_obj(keyBoardParent);
    lv_obj_remove_flag(keyBoardParent, LV_OBJ_FLAG_IGNORE_LAYOUT);
    lv_obj_set_size(keyBoardParent, LV_PCT(100), LV_PCT(100));

    keyboard = lv_keyboard_create(keyBoardParent);

    lv_obj_add_event_cb(keyboard, kb_event_cb, LV_EVENT_ALL, NULL);

    static const char * kb_map[] = {"Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", " ", "\n",
                                    "A", "S", "D", "F", "G", "H", "J", "K", "L",  " ", "\n",
                                    " "," ", "Z", "X", "C", "V", "B", "N", "M"," "," ","\n",
                                    LV_SYMBOL_CLOSE, LV_SYMBOL_BACKSPACE,  " ", " ", LV_SYMBOL_OK, NULL
                                   };

    /*Set the relative width of the buttons and other controls*/
    static const lv_buttonmatrix_ctrl_t kb_ctrl[] = {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, LV_BUTTONMATRIX_CTRL_HIDDEN,
                                                     4, 4, 4, 4, 4, 4, 4, 4, 4, LV_BUTTONMATRIX_CTRL_HIDDEN,
                                                     LV_BUTTONMATRIX_CTRL_HIDDEN, LV_BUTTONMATRIX_CTRL_HIDDEN, 4, 4, 4, 4, 4, 4, 4, LV_BUTTONMATRIX_CTRL_HIDDEN, LV_BUTTONMATRIX_CTRL_HIDDEN,
                                                     2, 2 | 2, 6, LV_BUTTONMATRIX_CTRL_HIDDEN | 2, 2
                                                    };

    /*Create a keyboard and add the new map as USER_1 mode*/

    lv_keyboard_set_map(keyboard, LV_KEYBOARD_MODE_USER_1, kb_map, kb_ctrl);
    lv_keyboard_set_mode(keyboard, LV_KEYBOARD_MODE_USER_1);

    keyboard_textArea = lv_textarea_create(keyBoardParent);
    lv_obj_align(keyboard_textArea, LV_ALIGN_TOP_MID, 0, 10);
    //lv_obj_add_event_cb(keyboard_textArea, ta_event_cb, LV_EVENT_ALL, keyboard);
    lv_textarea_set_placeholder_text(keyboard_textArea, keyboard_placeholder_text);
    lv_obj_set_size(keyboard_textArea, lv_pct(90), 80);
    lv_obj_add_state(keyboard_textArea, LV_STATE_FOCUSED);
    lv_keyboard_set_textarea(keyboard, keyboard_textArea);

    lv_obj_set_style_text_font(keyboard, &lv_font_montserrat_26, 0);
    lv_obj_set_style_text_font(keyboard_textArea, &lv_font_montserrat_30, 0);
    
    //lv_obj_add_flag(keyboard_textArea, LV_OBJ_FLAG_HIDDEN);
   // lv_obj_add_flag(keyboard, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(keyBoardParent, LV_OBJ_FLAG_HIDDEN);
}


lv_obj_t * create_text(lv_obj_t * parent, const char * icon, const char * txt)
{
    lv_obj_t * obj =  (lv_obj_t *)lv_menu_cont_create(parent);

    lv_obj_t * img = NULL;
    lv_obj_t * label = NULL;

    if(icon) {
        img = lv_image_create(obj);
        lv_image_set_src(img, icon);
        //lv_obj_set_size(img, 46, 46);
    }

    if(txt) {
        label = lv_label_create(obj);
        lv_label_set_text(label, txt);
        lv_label_set_long_mode(label, LV_LABEL_LONG_SCROLL_CIRCULAR);
        lv_obj_set_flex_grow(label, 1);
        lv_obj_align(label, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
    }


    return obj;
}


lv_obj_t * create_slider(lv_obj_t * parent, const char * icon, const char * txt, int32_t min, int32_t max,
                                int32_t val)
{
    lv_obj_t * obj =  (lv_obj_t *) create_text(parent, icon, txt);

    lv_obj_t * slider =  (lv_obj_t *) lv_slider_create(obj);
    lv_obj_set_flex_grow(slider, 1);
    lv_slider_set_range(slider, min, max);
    lv_slider_set_value(slider, val, LV_ANIM_OFF);

    if(icon == NULL) {
        lv_obj_add_flag(slider, LV_OBJ_FLAG_FLEX_IN_NEW_TRACK);
    }

    return obj;
}

lv_obj_t * create_switch(lv_obj_t * parent, const char * icon, const char * txt, bool chk)
{
    lv_obj_t * obj =  (lv_obj_t *) create_text(parent, icon, txt);

    lv_obj_t * sw = (lv_obj_t *)lv_switch_create(obj);
    lv_obj_add_state(sw, chk ? LV_STATE_CHECKED : 0);

    return obj;
}



void LVGL_TaskManager(){
    delay(1);
    lv_tick_inc(1);
    lv_task_handler(); /* let the GUI do its work */
}


void sd_init()
{
    SD_SPI.begin(SD_SCLK, SD_MISO, SD_MOSI);
    if (!SD.begin(SD_CS, SD_SPI, 40000000))
    {
        LV_LOG_USER("SD Card Failed");
        while (1)
            delay(1000);
    }
    else
    {
        LV_LOG_USER("Card Mount Successed");
    }
    LV_LOG_USER("SD init over.");
}

void createQuestionMark(lv_obj_t * parent,lv_obj_t * element,lv_event_cb_t e, const int32_t x, const int32_t y){
    questionMark = lv_label_create(parent);
    lv_obj_set_size(questionMark, lv_font_get_line_height(&FilMachineFontIcons_15) * 1.5, lv_font_get_line_height(&FilMachineFontIcons_15) * 1.5);       
    lv_label_set_text(questionMark, questionMark_icon);
    lv_obj_add_event_cb(questionMark, e, LV_EVENT_CLICKED, element);
    lv_obj_set_style_text_font(questionMark, &FilMachineFontIcons_15, 0);                     
    lv_obj_align_to(questionMark, element, LV_ALIGN_OUT_RIGHT_MID, x, y);
    lv_obj_add_flag(questionMark, LV_OBJ_FLAG_CLICKABLE);
}

float convertCelsiusoToFahrenheit(uint32_t tempC){
  return ((tempC * 1.8) + 32); 
}

char createRollerValues(lv_obj_t * roller,const int32_t maxVal){
  char buf[1000];
  char buffer [33];
  buf[0] = '\0';
  for (uint32_t i = 0; i < maxVal; i++) {
    itoa(i,buffer,10);
    strcat(buf,buffer);
    strcat(buf,"\n");
  }
  lv_roller_set_options(roller,buf,LV_ROLLER_MODE_NORMAL);
  //return buf;
}

//THIS NOT WORKS!
char * convertFloatToTemp(double temp){
  char * tempFloat[sizeof(double)];
  dtostrf(temp,3,1,* tempFloat);
  return * tempFloat;
}

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*ACCESSORY_H*/

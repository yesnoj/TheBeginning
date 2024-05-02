#include "font/lv_font.h"
#include <sys/_stdint.h>
#include "misc/lv_palette.h"
#include "core/lv_obj_pos.h"
#include "misc/lv_color.h"
#include "misc/lv_types.h"
/**
 * @file element_temperaturePopup.h
 *
 */
#include "widgets/menu/lv_menu.h"
#include "core/lv_obj_style.h"
#include "misc/lv_area.h"

#ifndef ELEMENT_TEMPERATUREPOPUP_H
#define ELEMENT_TEMPERATUREPOPUP_H

#ifdef __cplusplus
extern "C" {
#endif

//ESSENTIAL INCLUDES

//ACCESSORY INCLUDES

lv_obj_t * mBoxTempPopupContainer;
lv_obj_t * mBoxTempPopupTitle;
lv_obj_t * mBoxTempPopupButton;
lv_obj_t * mBoxTempPopupButtonLabel;
lv_obj_t * mBoxTempPopupRollerContainer;


static void event_tuneTempPopup(lv_event_t * e)
{
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t * obj = (lv_obj_t *)lv_event_get_target(e);
  lv_obj_t * objCont = (lv_obj_t *)lv_obj_get_parent(obj);
  lv_obj_t * mboxCont = (lv_obj_t *)lv_obj_get_parent(objCont);
  lv_obj_t * godFatherCont = (lv_obj_t *)lv_obj_get_parent(mboxCont);
  lv_obj_t * data = (lv_obj_t *)lv_event_get_user_data(e);

    if(code == LV_EVENT_CLICKED){
        if(obj == mBoxTempPopupButton)
        {
            if(data == tempSensorTuneButton){
              LV_LOG_USER("SET BUTTON from tempSensorTuneButton");
              lv_style_reset(&style_mBoxTempPopupTitleLine);
              lv_style_reset(&style_rollerTemp);
              lv_msgbox_close(godFatherCont);
              lv_obj_delete(godFatherCont);
            }
            if(data == processTempTextArea){
              LV_LOG_USER("SET BUTTON from processTempTextArea");
              itoa(rolleTempSelected, tempBuffer, 10);
              lv_style_reset(&style_mBoxTempPopupTitleLine);
              lv_textarea_set_text(processTempTextArea,tempBuffer);
              lv_style_reset(&style_rollerTemp);
              lv_msgbox_close(godFatherCont);
              lv_obj_delete(godFatherCont);
            }
            if(data == processToleranceTextArea){
              LV_LOG_USER("SET BUTTON from processToleranceTextArea");
              
              lv_style_reset(&style_mBoxTempPopupTitleLine);
              lv_textarea_set_text(processToleranceTextArea, tempBuffer);
              lv_style_reset(&style_rollerTemp);
              lv_msgbox_close(godFatherCont);
              lv_obj_delete(godFatherCont);
            }
        }
    }

    if(code == LV_EVENT_VALUE_CHANGED){
      if(obj == tempRoller){
          //if we want to want the index of the selected element
          rolleTempSelected = lv_roller_get_selected(obj) + 1;
          LV_LOG_USER("ROLLER value: %d", rolleTempSelected);

          
          lv_roller_get_selected_str(obj, tempBuffer, sizeof(tempBuffer));
          //if roller has strings to be read
          //lv_roller_get_selected_str(obj, rollerElementSelected, sizeof(rollerElementSelected));
          //LV_LOG_USER("ROLLER value: %s", rollerElementSelected);
      }
    }
}       


void temperaturePopupCreate(const char * tempOptions,lv_obj_t *whoCallMe){
  /*********************
  *    PAGE HEADER
  *********************/
   LV_LOG_USER("Tune popup create");  
   mBoxTempPopupParent = lv_obj_class_create_obj(&lv_msgbox_backdrop_class, lv_layer_top());
   lv_obj_class_init_obj(mBoxTempPopupParent);
   lv_obj_remove_flag(mBoxTempPopupParent, LV_OBJ_FLAG_IGNORE_LAYOUT);
   lv_obj_set_size(mBoxTempPopupParent, LV_PCT(100), LV_PCT(100));

         mBoxTempPopupContainer = lv_obj_create(mBoxTempPopupParent);
         lv_obj_align(mBoxTempPopupContainer, LV_ALIGN_CENTER, 0, 0);
         lv_obj_set_size(mBoxTempPopupContainer, 250, 220); 
         lv_obj_remove_flag(mBoxTempPopupContainer, LV_OBJ_FLAG_SCROLLABLE); 

         mBoxTempPopupTitle = lv_label_create(mBoxTempPopupContainer);         
         lv_label_set_text(mBoxTempPopupTitle, tuneTempPopupTitle_text); 
         lv_obj_set_style_text_font(mBoxTempPopupTitle, &lv_font_montserrat_22, 0);              
         lv_obj_align(mBoxTempPopupTitle, LV_ALIGN_TOP_MID, 0, - 10);


   /*Create style*/
   lv_style_init(&style_mBoxTempPopupTitleLine);
   lv_style_set_line_width(&style_mBoxTempPopupTitleLine, 2);
   lv_style_set_line_rounded(&style_mBoxTempPopupTitleLine, true);

   /*Create a line and apply the new style*/
   mBoxTempPopupTitleLine = lv_line_create(mBoxTempPopupContainer);
   lv_line_set_points(mBoxTempPopupTitleLine, mBoxTitleLine_points, 2);
   lv_obj_add_style(mBoxTempPopupTitleLine, &style_mBoxTempPopupTitleLine, 0);
   lv_obj_align(mBoxTempPopupTitleLine, LV_ALIGN_TOP_MID, 0, 23);


  /*********************
  *    PAGE ELEMENTS
  *********************/

  mBoxTempPopupRollerContainer = lv_obj_create(mBoxTempPopupContainer);
  lv_obj_align(mBoxTempPopupRollerContainer, LV_ALIGN_TOP_MID, 0, 30);
  lv_obj_set_size(mBoxTempPopupRollerContainer, 235, 170); 
  lv_obj_set_style_border_opa(mBoxTempPopupRollerContainer, LV_OPA_TRANSP, 0);
  //lv_obj_set_style_border_color(mBoxTempPopupRollerContainer, lv_color_hex(GREEN_DARK), 0);
  lv_obj_remove_flag(mBoxTempPopupContainer, LV_OBJ_FLAG_SCROLLABLE);

  
  lv_style_init(&style_rollerTemp);
  lv_style_set_text_font(&style_rollerTemp, &lv_font_montserrat_30);
  lv_style_set_bg_color(&style_rollerTemp, lv_color_hex(LIGHT_BLUE));
  lv_style_set_border_width(&style_rollerTemp, 2);
  lv_style_set_border_color(&style_rollerTemp, lv_color_hex(LIGHT_BLUE_DARK));
  
  tempRoller = lv_roller_create(mBoxTempPopupRollerContainer);
  lv_roller_set_options(tempRoller, tempOptions, LV_ROLLER_MODE_NORMAL);
  lv_roller_set_visible_row_count(tempRoller, 4);
  lv_obj_set_width(tempRoller, 120);
  lv_obj_set_height(tempRoller, 100);
  lv_obj_align(tempRoller, LV_ALIGN_CENTER, 0, -30);
  lv_obj_add_event_cb(tempRoller, event_tuneTempPopup, LV_EVENT_ALL, NULL);
  lv_obj_add_style(tempRoller, &style_rollerTemp, LV_PART_SELECTED);  
  lv_roller_set_selected(tempRoller, 0, LV_ANIM_OFF);   
  lv_obj_set_style_border_color(tempRoller, lv_color_hex(WHITE), LV_PART_MAIN);

   mBoxTempPopupButton = lv_button_create(mBoxTempPopupRollerContainer);
   lv_obj_set_size(mBoxTempPopupButton, BUTTON_TUNE_WIDTH, BUTTON_TUNE_HEIGHT);
   lv_obj_align(mBoxTempPopupButton, LV_ALIGN_BOTTOM_MID, 0 , 0);
   lv_obj_add_event_cb(mBoxTempPopupButton, event_tuneTempPopup, LV_EVENT_CLICKED, whoCallMe);

         mBoxTempPopupButtonLabel = lv_label_create(mBoxTempPopupButton);         
         lv_label_set_text(mBoxTempPopupButtonLabel, tuneTempPopupButton_text); 
         lv_obj_set_style_text_font(mBoxTempPopupButtonLabel, &lv_font_montserrat_18, 0);              
         lv_obj_align(mBoxTempPopupButtonLabel, LV_ALIGN_CENTER, 0, 0);
}

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*ELEMENT_TEMPERATUREPOPUP_H*/
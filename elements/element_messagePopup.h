#include "font/lv_font.h"
#include <sys/_stdint.h>
#include "misc/lv_palette.h"
#include "core/lv_obj_pos.h"
#include "misc/lv_color.h"
#include "misc/lv_types.h"
/**
 * @file element_messagePopup.h
 *
 */
#include "widgets/menu/lv_menu.h"
#include "core/lv_obj_style.h"
#include "misc/lv_area.h"

#ifndef ELEMENT_MESSAGEPOPUP_H
#define ELEMENT_MESSAGEPOPUP_H

#ifdef __cplusplus
extern "C" {
#endif

//ESSENTIAL INCLUDES

//ACCESSORY INCLUDES

lv_obj_t * mBoxPopupContainer;
lv_obj_t * mBoxPopupTitle;
lv_obj_t * mBoxPopupButton;
lv_obj_t * mBoxPopupButtonLabel;
lv_obj_t * mBoxPopupTextContainer;
lv_obj_t * mBoxPopupText;

       

static void event_messagePopup(lv_event_t * e)
{
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t * obj = (lv_obj_t *)lv_event_get_target(e);
  lv_obj_t * objCont = (lv_obj_t *)lv_obj_get_parent(obj);
  lv_obj_t * mboxCont = (lv_obj_t *)lv_obj_get_parent(objCont);

  lv_style_reset(&style_mBoxPopupTitleLine);
  lv_msgbox_close(mboxCont);
  lv_obj_delete(mboxCont);
}       

void messagePopupCreate(const char * popupTitleText,const char * popupText){
  /*********************
  *    PAGE HEADER
  *********************/
   LV_LOG_USER("Message popup create");  
   mBoxPopupParent = lv_obj_class_create_obj(&lv_msgbox_backdrop_class, lv_layer_top());
   lv_obj_class_init_obj(mBoxPopupParent);
   lv_obj_remove_flag(mBoxPopupParent, LV_OBJ_FLAG_IGNORE_LAYOUT);
   lv_obj_set_size(mBoxPopupParent, LV_PCT(100), LV_PCT(100));

         mBoxPopupContainer = lv_obj_create(mBoxPopupParent);
         lv_obj_align(mBoxPopupContainer, LV_ALIGN_CENTER, 0, 0);
         lv_obj_set_size(mBoxPopupContainer, 320, 240); 
         lv_obj_remove_flag(mBoxPopupContainer, LV_OBJ_FLAG_SCROLLABLE); 

         mBoxPopupTitle = lv_label_create(mBoxPopupContainer);         
         lv_label_set_text(mBoxPopupTitle, popupTitleText); 
         lv_obj_set_style_text_font(mBoxPopupTitle, &lv_font_montserrat_22, 0);              
         lv_obj_align(mBoxPopupTitle, LV_ALIGN_TOP_MID, 0, - 10);


   /*Create style*/
   lv_style_init(&style_mBoxPopupTitleLine);
   lv_style_set_line_width(&style_mBoxPopupTitleLine, 2);
   lv_style_set_line_rounded(&style_mBoxPopupTitleLine, true);

   /*Create a line and apply the new style*/
   mBoxPopupTitleLine = lv_line_create(mBoxPopupContainer);
   lv_line_set_points(mBoxPopupTitleLine, mBoxTitleLine_points, 2);
   lv_obj_add_style(mBoxPopupTitleLine, &style_mBoxPopupTitleLine, 0);
   lv_obj_align(mBoxPopupTitleLine, LV_ALIGN_TOP_MID, 0, 23);


  /*********************
  *    PAGE ELEMENTS
  *********************/

   mBoxPopupTextContainer = lv_obj_create(mBoxPopupContainer);
   lv_obj_align(mBoxPopupTextContainer, LV_ALIGN_TOP_MID, 0, 30);
   lv_obj_set_size(mBoxPopupTextContainer, 305, 180); 
   lv_obj_set_style_border_opa(mBoxPopupTextContainer, LV_OPA_TRANSP, 0);
   //lv_obj_set_style_border_color(mBoxPopupTextContainer, lv_color_hex(GREEN_DARK), 0);
   lv_obj_set_scroll_dir(mBoxPopupTextContainer, LV_DIR_VER);

         mBoxPopupText = lv_label_create(mBoxPopupTextContainer);         
         lv_label_set_text(mBoxPopupText, popupText); 
         lv_obj_set_style_text_font(mBoxPopupText, &lv_font_montserrat_20, 0);              
         lv_obj_align(mBoxPopupText, LV_ALIGN_TOP_MID, 0, -18);
         lv_obj_set_size(mBoxPopupText, 295, LV_SIZE_CONTENT);
         lv_label_set_long_mode(mBoxPopupText, LV_LABEL_LONG_WRAP);
         lv_obj_set_style_text_align(mBoxPopupText , LV_TEXT_ALIGN_CENTER, 0);


   mBoxPopupButton = lv_button_create(mBoxPopupContainer);
   lv_obj_set_size(mBoxPopupButton, BUTTON_POPUP_CLOSE_WIDTH, BUTTON_POPUP_CLOSE_HEIGHT);
   lv_obj_align(mBoxPopupButton, LV_ALIGN_TOP_RIGHT, 7 , -10);
   lv_obj_add_event_cb(mBoxPopupButton, event_messagePopup, LV_EVENT_CLICKED, mBoxApplyFilterButton);

         mBoxPopupButtonLabel = lv_label_create(mBoxPopupButton);         
         lv_label_set_text(mBoxPopupButtonLabel, closePopup_icon); 
         lv_obj_set_style_text_font(mBoxPopupButtonLabel, &FilMachineFontIcons_20, 0);              
         lv_obj_align(mBoxPopupButtonLabel, LV_ALIGN_CENTER, 0, 0);
}

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*ELEMENT_MESSAGEPOPUP_H*/
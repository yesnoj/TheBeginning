
/**
 * @file page_checkup.h
 *
 */

#include "core/lv_obj_style.h"
#include "misc/lv_area.h"

#ifndef PAGE_CHECKUP_H
#define PAGE_CHECKUP_H

#ifdef __cplusplus
extern "C" {
#endif

//ESSENTIAL INCLUDES


//ACCESSORY INCLUDES


static lv_obj_t * checkupParent;

static lv_obj_t * checkupContainer;
static lv_obj_t * checkupNextStepsContainer;
static lv_obj_t * checkupProcessNameContainer;
static lv_obj_t * checkupStepContainer;
static lv_obj_t * checkupWaterFillContainer;
static lv_obj_t * checkupReachTempContainer;
static lv_obj_t * checkupTankAndFilmContainer;
static lv_obj_t * checkupStepSourceContainer;
static lv_obj_t * checkupTempControlContainer;
static lv_obj_t * checkupWaterTempContainer;
static lv_obj_t * checkupNextStepContainer;

static lv_obj_t * checkupProcessName;
static lv_obj_t * checkupNextStepsLabel;
static lv_obj_t * checkupWaterFillLabel;
static lv_obj_t * checkupReachTempLabel;
static lv_obj_t * checkupTankAndFilmLabel;
static lv_obj_t * checkupMachineWillDoLabel;
static lv_obj_t * checkupStopStepsButtonLabel;
static lv_obj_t * checkupCloseButtonLabel;
static lv_obj_t * checkupStepSourceLabel;
static lv_obj_t * checkupTempControlLabel;
static lv_obj_t * checkupWaterTempLabel;
static lv_obj_t * checkupNextStepLabel;
static lv_obj_t * checkupStopAfterButtonLabel;
static lv_obj_t * checkupStopNowButtonLabel;

static lv_obj_t * checkupStepSourceValue;
static lv_obj_t * checkupTempControlValue;
static lv_obj_t * checkupWaterTempValue;
static lv_obj_t * checkupNextStepValue;

static lv_obj_t * checkupWaterFillStatusIcon;
static lv_obj_t * checkupReachTempStatusIcon;
static lv_obj_t * checkupTankAndFilmStatusIcon;

static lv_obj_t * checkupStopAfterButton;
static lv_obj_t * checkupStopNowButton;
static lv_obj_t * checkupStopStepsButton;
static lv_obj_t * checkupCloseButton;

void event_checkup(lv_event_t * e){
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t * obj = (lv_obj_t *)lv_event_get_target(e);
  lv_obj_t * objCont = (lv_obj_t *)lv_obj_get_parent(obj);
  lv_obj_t * mboxCont = (lv_obj_t *)lv_obj_get_parent(objCont);
  lv_obj_t * mboxParent = (lv_obj_t *)lv_obj_get_parent(mboxCont);
  lv_obj_t * data = (lv_obj_t *)lv_event_get_user_data(e);

}

uint8_t isProcessing = 0; 

void checkup()
{  
   
      checkupParent = lv_obj_class_create_obj(&lv_msgbox_backdrop_class, lv_layer_top());
      lv_obj_class_init_obj(checkupParent);
      lv_obj_remove_flag(checkupParent, LV_OBJ_FLAG_IGNORE_LAYOUT);
      lv_obj_set_size(checkupParent, LV_PCT(100), LV_PCT(100));

      checkupContainer = lv_obj_create(checkupParent);
      lv_obj_align(checkupContainer, LV_ALIGN_CENTER, 0, 0);
      lv_obj_set_size(checkupContainer, LV_PCT(100), LV_PCT(100)); 
      lv_obj_remove_flag(checkupContainer, LV_OBJ_FLAG_SCROLLABLE); 

            checkupCloseButton = lv_button_create(checkupContainer);
            lv_obj_set_size(checkupCloseButton, BUTTON_POPUP_CLOSE_WIDTH * 1.2, BUTTON_POPUP_CLOSE_HEIGHT * 1.2);
            lv_obj_align(checkupCloseButton, LV_ALIGN_TOP_RIGHT, 7 , -10);
            lv_obj_add_event_cb(checkupCloseButton, event_checkup, LV_EVENT_CLICKED, checkupCloseButton);
            lv_obj_set_style_bg_color(checkupCloseButton, lv_color_hex(GREEN_DARK), LV_PART_MAIN);
            lv_obj_move_foreground(checkupCloseButton);


                  checkupCloseButtonLabel = lv_label_create(checkupCloseButton);         
                  lv_label_set_text(checkupCloseButtonLabel, closePopup_icon); 
                  lv_obj_set_style_text_font(checkupCloseButtonLabel, &FilMachineFontIcons_30, 0);              
                  lv_obj_align(checkupCloseButtonLabel, LV_ALIGN_CENTER, 0, 0);


            checkupProcessNameContainer = lv_obj_create(checkupContainer);
            lv_obj_remove_flag(checkupProcessNameContainer, LV_OBJ_FLAG_SCROLLABLE); 
            lv_obj_align(checkupProcessNameContainer, LV_ALIGN_TOP_LEFT, -10, -15);
            lv_obj_set_size(checkupProcessNameContainer, 350, 50); 
            //lv_obj_set_style_border_color(checkupProcessNameContainer, lv_color_hex(GREEN_DARK), 0);
            lv_obj_set_style_border_opa(checkupProcessNameContainer, LV_OPA_TRANSP, 0);

                  checkupProcessName = lv_label_create(checkupProcessNameContainer);         
                  lv_label_set_text(checkupProcessName, "E6 six baths"); 
                  lv_obj_set_width(checkupProcessName, 300);
                  lv_obj_set_style_text_font(checkupProcessName, &lv_font_montserrat_30, 0);              
                  lv_obj_align(checkupProcessName, LV_ALIGN_TOP_LEFT, -10, -8);
                  lv_label_set_long_mode(checkupProcessName, LV_LABEL_LONG_SCROLL_CIRCULAR);

            
        //LEFT SIDE OF SCREEN
        if(isProcessing == 0){
            checkupNextStepsContainer = lv_obj_create(checkupContainer);
            lv_obj_remove_flag(checkupNextStepsContainer, LV_OBJ_FLAG_SCROLLABLE); 
            lv_obj_align(checkupNextStepsContainer, LV_ALIGN_TOP_LEFT, -10, 35);
            lv_obj_set_size(checkupNextStepsContainer, 225, 265); 
            lv_obj_set_style_border_color(checkupNextStepsContainer, lv_color_hex(WHITE), 0);
            //lv_obj_set_style_border_opa(checkupNextStepsContainer, LV_OPA_TRANSP, 0);

                  checkupNextStepsLabel = lv_label_create(checkupNextStepsContainer);         
                  lv_label_set_text(checkupNextStepsLabel, checkupNexStepsTitle_text); 
                  lv_obj_set_width(checkupNextStepsLabel, LV_SIZE_CONTENT);
                  lv_obj_set_style_text_font(checkupNextStepsLabel, &lv_font_montserrat_22, 0);              
                  lv_obj_align(checkupNextStepsLabel, LV_ALIGN_TOP_LEFT, -10, -8);

                  checkupMachineWillDoLabel = lv_label_create(checkupNextStepsContainer);
                  lv_label_set_text(checkupMachineWillDoLabel, checkupTheMachineWillDo_text); 
                  lv_obj_set_width(checkupMachineWillDoLabel, LV_SIZE_CONTENT);
                  lv_obj_set_style_text_font(checkupMachineWillDoLabel, &lv_font_montserrat_18, 0);              
                  lv_obj_align(checkupMachineWillDoLabel, LV_ALIGN_TOP_LEFT, -10, 17);

                  checkupWaterFillContainer = lv_obj_create(checkupNextStepsContainer);
                  lv_obj_remove_flag(checkupWaterFillContainer, LV_OBJ_FLAG_SCROLLABLE); 
                  lv_obj_align(checkupWaterFillContainer, LV_ALIGN_TOP_LEFT, -10, 45);
                  lv_obj_set_size(checkupWaterFillContainer, 195, 45); 
                  //lv_obj_set_style_border_color(checkupWaterFillContainer, lv_color_hex(GREEN_DARK), 0);
                  lv_obj_set_style_border_opa(checkupWaterFillContainer, LV_OPA_TRANSP, 0);


                          checkupWaterFillStatusIcon = lv_label_create(checkupWaterFillContainer);         
                          lv_label_set_text(checkupWaterFillStatusIcon, dotStep_Icon); 
                          lv_obj_set_style_text_font(checkupWaterFillStatusIcon, &FilMachineFontIcons_15, 0);              
                          lv_obj_align(checkupWaterFillStatusIcon, LV_ALIGN_LEFT_MID, -15, 0);

                          checkupWaterFillLabel = lv_label_create(checkupWaterFillContainer);         
                          lv_label_set_text(checkupWaterFillLabel, checkupFillWater_text); 
                          lv_obj_set_width(checkupWaterFillLabel, 168);
                          lv_obj_set_style_text_font(checkupWaterFillLabel, &lv_font_montserrat_18, 0);              
                          lv_obj_align(checkupWaterFillLabel, LV_ALIGN_LEFT_MID, 2, 0);
                          lv_label_set_long_mode(checkupWaterFillLabel, LV_LABEL_LONG_SCROLL_CIRCULAR);


                  checkupReachTempContainer = lv_obj_create(checkupNextStepsContainer);
                  lv_obj_remove_flag(checkupReachTempContainer, LV_OBJ_FLAG_SCROLLABLE); 
                  lv_obj_align(checkupReachTempContainer, LV_ALIGN_TOP_LEFT, -10, 90);
                  lv_obj_set_size(checkupReachTempContainer, 195, 45); 
                  //lv_obj_set_style_border_color(checkupReachTempContainer, lv_color_hex(GREEN_DARK), 0);
                  lv_obj_set_style_border_opa(checkupReachTempContainer, LV_OPA_TRANSP, 0);

                          checkupReachTempStatusIcon = lv_label_create(checkupReachTempContainer);         
                          lv_label_set_text(checkupReachTempStatusIcon, arrowStep_Icon); 
                          lv_obj_set_style_text_font(checkupReachTempStatusIcon, &FilMachineFontIcons_15, 0);              
                          lv_obj_align(checkupReachTempStatusIcon, LV_ALIGN_LEFT_MID, -15, 0);


                          checkupReachTempLabel = lv_label_create(checkupReachTempContainer);         
                          lv_label_set_text(checkupReachTempLabel, checkupReachTemp_text); 
                          lv_obj_set_width(checkupReachTempLabel, 168);
                          lv_obj_set_style_text_font(checkupReachTempLabel, &lv_font_montserrat_18, 0);              
                          lv_obj_align(checkupReachTempLabel, LV_ALIGN_LEFT_MID, 2, 0);
                          lv_label_set_long_mode(checkupReachTempLabel, LV_LABEL_LONG_SCROLL_CIRCULAR);



                  checkupTankAndFilmContainer = lv_obj_create(checkupNextStepsContainer);
                  lv_obj_remove_flag(checkupTankAndFilmContainer, LV_OBJ_FLAG_SCROLLABLE); 
                  lv_obj_align(checkupTankAndFilmContainer, LV_ALIGN_TOP_LEFT, -10, 135);
                  lv_obj_set_size(checkupTankAndFilmContainer, 195, 45); 
                  //lv_obj_set_style_border_color(checkupTankAndFilmContainer, lv_color_hex(GREEN_DARK), 0);
                  lv_obj_set_style_border_opa(checkupTankAndFilmContainer, LV_OPA_TRANSP, 0);

                          checkupTankAndFilmStatusIcon = lv_label_create(checkupTankAndFilmContainer);         
                          lv_label_set_text(checkupTankAndFilmStatusIcon, checkStep_Icon); 
                          lv_obj_set_style_text_font(checkupTankAndFilmStatusIcon, &FilMachineFontIcons_15, 0);              
                          lv_obj_align(checkupTankAndFilmStatusIcon, LV_ALIGN_LEFT_MID, -15, 0);


                          checkupTankAndFilmLabel = lv_label_create(checkupTankAndFilmContainer);         
                          lv_label_set_text(checkupTankAndFilmLabel, checkupTankRotation_text); 
                          lv_obj_set_width(checkupTankAndFilmLabel, 168);
                          lv_obj_set_style_text_font(checkupTankAndFilmLabel, &lv_font_montserrat_18, 0);              
                          lv_obj_align(checkupTankAndFilmLabel, LV_ALIGN_LEFT_MID, 2, 0);
                          lv_label_set_long_mode(checkupTankAndFilmLabel, LV_LABEL_LONG_SCROLL_CIRCULAR);


                  checkupStopStepsButton = lv_button_create(checkupNextStepsContainer);
                  lv_obj_set_size(checkupStopStepsButton, BUTTON_PROCESS_WIDTH, BUTTON_PROCESS_HEIGHT);
                  lv_obj_align(checkupStopStepsButton, LV_ALIGN_BOTTOM_MID, 0, 10);
                  lv_obj_add_event_cb(checkupStopStepsButton, event_checkup, LV_EVENT_CLICKED, checkupStopStepsButton);
                  lv_obj_set_style_bg_color(checkupStopStepsButton, lv_color_hex(RED_DARK), LV_PART_MAIN);
                  lv_obj_move_foreground(checkupStopStepsButton);


                          checkupStopStepsButtonLabel = lv_label_create(checkupStopStepsButton);         
                          lv_label_set_text(checkupStopStepsButtonLabel, checkupStop_text); 
                          lv_obj_set_style_text_font(checkupStopStepsButtonLabel, &lv_font_montserrat_22, 0);              
                          lv_obj_align(checkupStopStepsButtonLabel, LV_ALIGN_CENTER, 0, 0);

        }
        else{

            checkupNextStepsContainer = lv_obj_create(checkupContainer);
            lv_obj_remove_flag(checkupNextStepsContainer, LV_OBJ_FLAG_SCROLLABLE); 
            lv_obj_align(checkupNextStepsContainer, LV_ALIGN_TOP_LEFT, -10, 35);
            lv_obj_set_size(checkupNextStepsContainer, 225, 265); 
            lv_obj_set_style_border_color(checkupNextStepsContainer, lv_color_hex(WHITE), 0);
            //lv_obj_set_style_border_opa(checkupNextStepsContainer, LV_OPA_TRANSP, 0);


                  checkupNextStepsLabel = lv_label_create(checkupNextStepsContainer);         
                  lv_label_set_text(checkupNextStepsLabel, checkupProcessingTitle_text); 
                  lv_obj_set_width(checkupNextStepsLabel, LV_SIZE_CONTENT);
                  lv_obj_set_style_text_font(checkupNextStepsLabel, &lv_font_montserrat_22, 0);              
                  lv_obj_align(checkupNextStepsLabel, LV_ALIGN_TOP_LEFT, -10, -8);


                  checkupStepSourceContainer = lv_obj_create(checkupNextStepsContainer);
                  lv_obj_remove_flag(checkupStepSourceContainer, LV_OBJ_FLAG_SCROLLABLE); 
                  lv_obj_align(checkupStepSourceContainer, LV_ALIGN_TOP_LEFT, -10, 17);
                  lv_obj_set_size(checkupStepSourceContainer, 215, 45); 
                  //lv_obj_set_style_border_color(checkupStepSourceContainer, lv_color_hex(GREEN_DARK), 0);
                  lv_obj_set_style_border_opa(checkupStepSourceContainer, LV_OPA_TRANSP, 0);


                          checkupStepSourceLabel = lv_label_create(checkupStepSourceContainer);         
                          lv_label_set_text(checkupStepSourceLabel, checkupStepSource_text); 
                          lv_obj_set_style_text_font(checkupStepSourceLabel, &lv_font_montserrat_18, 0);              
                          lv_obj_align(checkupStepSourceLabel, LV_ALIGN_LEFT_MID, -15, 0);

                          checkupStepSourceValue = lv_label_create(checkupStepSourceContainer);         
                          lv_label_set_text(checkupStepSourceValue, &processSourceList[1][0]); 
                          lv_obj_set_width(checkupStepSourceValue, LV_SIZE_CONTENT);
                          lv_obj_set_style_text_font(checkupStepSourceValue, &lv_font_montserrat_20, 0);              
                          lv_obj_align(checkupStepSourceValue, LV_ALIGN_RIGHT_MID, 10, 0);


                  checkupTempControlContainer = lv_obj_create(checkupNextStepsContainer);
                  lv_obj_remove_flag(checkupTempControlContainer, LV_OBJ_FLAG_SCROLLABLE); 
                  lv_obj_align(checkupTempControlContainer, LV_ALIGN_TOP_LEFT, -10, 62);
                  lv_obj_set_size(checkupTempControlContainer, 215, 45); 
                  //lv_obj_set_style_border_color(checkupTempControlContainer, lv_color_hex(GREEN_DARK), 0);
                  lv_obj_set_style_border_opa(checkupTempControlContainer, LV_OPA_TRANSP, 0);


                          checkupTempControlLabel = lv_label_create(checkupTempControlContainer);         
                          lv_label_set_text(checkupTempControlLabel, checkupTempControl_text); 
                          lv_obj_set_style_text_font(checkupTempControlLabel, &lv_font_montserrat_18, 0);              
                          lv_obj_align(checkupTempControlLabel, LV_ALIGN_LEFT_MID, -15, 0);

                          checkupTempControlValue = lv_label_create(checkupTempControlContainer);         
                          lv_label_set_text(checkupTempControlValue, &processTempControlList[1][0]); 
                          lv_obj_set_width(checkupTempControlValue, LV_SIZE_CONTENT);
                          lv_obj_set_style_text_font(checkupTempControlValue, &lv_font_montserrat_20, 0);              
                          lv_obj_align(checkupTempControlValue, LV_ALIGN_RIGHT_MID, 10, 0);



                  checkupWaterTempContainer = lv_obj_create(checkupNextStepsContainer);
                  lv_obj_remove_flag(checkupWaterTempContainer, LV_OBJ_FLAG_SCROLLABLE); 
                  lv_obj_align(checkupWaterTempContainer, LV_ALIGN_TOP_LEFT, -10, 107);
                  lv_obj_set_size(checkupWaterTempContainer, 215, 45); 
                  //lv_obj_set_style_border_color(checkupWaterTempContainer, lv_color_hex(GREEN_DARK), 0);
                  lv_obj_set_style_border_opa(checkupWaterTempContainer, LV_OPA_TRANSP, 0);


                          checkupWaterTempLabel = lv_label_create(checkupWaterTempContainer);         
                          lv_label_set_text(checkupWaterTempLabel, checkupWaterTemp_text); 
                          lv_obj_set_style_text_font(checkupWaterTempLabel, &lv_font_montserrat_18, 0);              
                          lv_obj_align(checkupWaterTempLabel, LV_ALIGN_LEFT_MID, -15, 0);

                          checkupWaterTempValue = lv_label_create(checkupWaterTempContainer);         
                          lv_label_set_text(checkupWaterTempValue, "36.4°C"); 
                          lv_obj_set_width(checkupWaterTempValue, LV_SIZE_CONTENT);
                          lv_obj_set_style_text_font(checkupWaterTempValue, &lv_font_montserrat_20, 0);              
                          lv_obj_align(checkupWaterTempValue, LV_ALIGN_RIGHT_MID, 10, 0);



                  checkupNextStepContainer = lv_obj_create(checkupNextStepsContainer);
                  lv_obj_remove_flag(checkupNextStepContainer, LV_OBJ_FLAG_SCROLLABLE); 
                  lv_obj_align(checkupNextStepContainer, LV_ALIGN_TOP_LEFT, -10, 152);
                  lv_obj_set_size(checkupNextStepContainer, 215, 45); 
                  //lv_obj_set_style_border_color(checkupNextStepContainer, lv_color_hex(GREEN_DARK), 0);
                  lv_obj_set_style_border_opa(checkupNextStepContainer, LV_OPA_TRANSP, 0);


                          checkupNextStepLabel = lv_label_create(checkupNextStepContainer);         
                          lv_label_set_text(checkupNextStepLabel, checkupNextStep_text); 
                          lv_obj_set_style_text_font(checkupNextStepLabel, &lv_font_montserrat_18, 0);              
                          lv_obj_align(checkupNextStepLabel, LV_ALIGN_LEFT_MID, -15, 0);

                          checkupNextStepValue = lv_label_create(checkupNextStepContainer);         
                          lv_label_set_text(checkupNextStepValue, "Pre-bleach"); 
                          lv_obj_set_width(checkupNextStepValue, 105);
                          lv_obj_set_style_text_font(checkupNextStepValue, &lv_font_montserrat_20, 0);              
                          lv_obj_align(checkupNextStepValue, LV_ALIGN_RIGHT_MID, 10, 0);
                          lv_label_set_long_mode(checkupNextStepValue, LV_LABEL_LONG_SCROLL_CIRCULAR);


                  checkupStopNowButton = lv_button_create(checkupNextStepsContainer);
                  lv_obj_set_size(checkupStopNowButton, BUTTON_PROCESS_WIDTH, BUTTON_PROCESS_HEIGHT);
                  lv_obj_align(checkupStopNowButton, LV_ALIGN_BOTTOM_LEFT, -10, 10);
                  lv_obj_add_event_cb(checkupStopNowButton, event_checkup, LV_EVENT_CLICKED, checkupStopStepsButton);
                  lv_obj_set_style_bg_color(checkupStopNowButton, lv_color_hex(RED_DARK), LV_PART_MAIN);
                  lv_obj_move_foreground(checkupStopNowButton);


                          checkupStopNowButtonLabel = lv_label_create(checkupStopNowButton);         
                          lv_label_set_text(checkupStopNowButtonLabel, checkupStopNow_text); 
                          lv_obj_set_style_text_font(checkupStopNowButtonLabel, &lv_font_montserrat_16, 0);              
                          lv_obj_align(checkupStopNowButtonLabel, LV_ALIGN_CENTER, 0, 0);

                  
                  checkupStopAfterButton = lv_button_create(checkupNextStepsContainer);
                  lv_obj_set_size(checkupStopAfterButton, BUTTON_PROCESS_WIDTH, BUTTON_PROCESS_HEIGHT);
                  lv_obj_align(checkupStopAfterButton, LV_ALIGN_BOTTOM_RIGHT, 10, 10);
                  lv_obj_add_event_cb(checkupStopAfterButton, event_checkup, LV_EVENT_CLICKED, checkupStopAfterButton);
                  lv_obj_set_style_bg_color(checkupStopAfterButton, lv_color_hex(RED_DARK), LV_PART_MAIN);
                  lv_obj_move_foreground(checkupStopAfterButton);


                          checkupStopAfterButtonLabel = lv_label_create(checkupStopAfterButton);         
                          lv_label_set_text(checkupStopAfterButtonLabel, checkupStopAfter_text); 
                          lv_obj_set_style_text_font(checkupStopAfterButtonLabel, &lv_font_montserrat_16, 0);              
                          lv_obj_align(checkupStopAfterButtonLabel, LV_ALIGN_CENTER, 0, 0);
        }

            //RIGHT SIDE OF SCREEN
            checkupStepContainer = lv_obj_create(checkupContainer);
            lv_obj_remove_flag(checkupStepContainer, LV_OBJ_FLAG_SCROLLABLE); 
            lv_obj_align(checkupStepContainer, LV_ALIGN_TOP_LEFT, 217, 35);
            lv_obj_set_size(checkupStepContainer, 240, 265); 
            lv_obj_set_style_border_color(checkupStepContainer, lv_palette_main(LV_PALETTE_GREEN), 0);
            //lv_obj_set_style_border_opa(checkupStepContainer, LV_OPA_TRANSP, 0);



         

/*

*/




/*********************
 *    PAGE HEADER
 *********************/


  



/*********************
 *    PAGE ELEMENTS
 *********************/
    


 

    
}






#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*PAGE_CHECKUP_H*/
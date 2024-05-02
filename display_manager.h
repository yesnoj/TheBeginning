/**
 * @file display_manager.h
 *
 */


#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "definitions.h"
#include "pages.h"
//#include "pages/page_home.h"
//#include "pages/page_program.h"


void displayManager()
{
  
   switch(currentState)
    {
      case Display_State_0_Start:
        isEnteringInPage = 0;
        homePage();
      break;
      case Display_State_1_Program:
        isEnteringInPage = 0;
        //programPage();
        menu();
      break;
            case Display_State_1_1_Cleaning:
              isEnteringInPage = 0;
              tankSizePage();
            break;
                  case Display_State_1_1_1_Cleaning_Tank:
                    isEnteringInPage = 0;
                    cleaning();
                  break;
            case Display_State_1_2_Develop:
              isEnteringInPage = 0;
              //developing();
              filmsPage();
              //TBD
            break;
            case Display_State_1_3_MDC:
              isEnteringInPage = 0;
              //TBD
            break;
    };
  LV_LOG_USER("currentState: %d , isEnteringInPage : %d",currentState, isEnteringInPage);
}

void updateValues(){
  if(millis() > (actualMillis) + 1000){
    actualMillis = millis();
    testVal1 = rand() % 101;
    testVal2 = rand() % 101;
    testVal3 = rand() % 101;
    sprintf(text1, "%d", testVal1);
    sprintf(text2, "%d", testVal2);
    sprintf(text3, "%d", testVal3);
    
    if(currentState == Display_State_1_1_1_Cleaning_Tank){
        lv_label_set_text(totalProgress_value, text1);
        lv_bar_set_value(totalProgress_bar, testVal1, LV_ANIM_OFF);

        lv_label_set_text(cycleProgress_value, text2);
        lv_bar_set_value(cycleProgress_bar, testVal2, LV_ANIM_OFF);

        lv_label_set_text(stepProgress_value, text3);
        lv_bar_set_value(stepProgress_bar, testVal3, LV_ANIM_OFF);
      }
    if(currentState == Display_State_9_Developing){
        lv_label_set_text(totalProgress_value, text1);
        lv_bar_set_value(totalProgress_bar, testVal1, LV_ANIM_OFF);

        lv_label_set_text(cycleProgress_value, text2);
        lv_bar_set_value(cycleProgress_bar, testVal2, LV_ANIM_OFF);

        lv_label_set_text(stepProgress_value, text3);
        lv_bar_set_value(stepProgress_bar, testVal3, LV_ANIM_OFF);
      }
   //LV_LOG_USER(text);
  }
}

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*DISPLAY_MANAGER_H*/

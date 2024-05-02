#include "misc/lv_color.h"
#include "core/lv_obj_style_gen.h"
#include "misc/lv_types.h"
/**
 * @file page_menu.h
 *
 */
#include "widgets/menu/lv_menu.h"
#include "core/lv_obj_style.h"
#include "misc/lv_area.h"

#ifndef PAGE_MENU_H
#define PAGE_MENU_H

#ifdef __cplusplus
extern "C" {
#endif

//ESSENTIAL INCLUDES


//ACCESSORY INCLUDES

#define TAB_PROCESSES 1
#define TAB_SETTINGS  2
#define TAB_TOOLS     3

static u_int8_t oldSelection = 0;
static u_int8_t newSelection = 0;

static lv_obj_t * processesTab;
static lv_obj_t * settingsTab;
static lv_obj_t * toolsTab;

static lv_obj_t * iconLabel;
static lv_obj_t * label;

static void back_event_handler(lv_event_t * e);
static void switch_handler(lv_event_t * e);
lv_obj_t * root_page;

static void event_tab_switch(lv_event_t * e)
{
  lv_event_code_t code = lv_event_get_code(e);

  if(code == LV_EVENT_CLICKED) {
    if(newTabSelected == NULL && oldTabSelected == NULL){
      newTabSelected = oldTabSelected = (lv_obj_t *)lv_event_get_target(e);
      newSelection = oldSelection = (u_int8_t)lv_obj_get_index(newTabSelected);
      lv_obj_set_style_bg_color(newTabSelected, lv_color_hex(GREEN_DARK), 0);

      LV_LOG_USER("FIRST TIME");
    }
    else {
        oldTabSelected = newTabSelected;
        oldSelection = newSelection;
        newTabSelected = (lv_obj_t *)lv_event_get_target(e);
        newSelection = (u_int8_t)lv_obj_get_index(newTabSelected);
        LV_LOG_USER("NEXT TIME");
    }
    
  
    if(newSelection != oldSelection) 
      { 
        //FIRST HIDE THE CORRECT SECTION
        if(oldSelection == TAB_PROCESSES){
            lv_obj_add_flag(processesSection, LV_OBJ_FLAG_HIDDEN);
        }
        if(oldSelection == TAB_SETTINGS){
            lv_obj_add_flag(settingsSection, LV_OBJ_FLAG_HIDDEN);
        }
        if(oldSelection == TAB_TOOLS){
            lv_obj_add_flag(toolsSection, LV_OBJ_FLAG_HIDDEN);
        }

        //THEN SHOW THE NEW SECTION
        if(newSelection == TAB_PROCESSES){
            lv_obj_set_style_bg_color(newTabSelected, lv_color_hex(GREEN_DARK), 0);
            lv_obj_remove_local_style_prop(oldTabSelected, LV_STYLE_BG_COLOR, 0);
            
            processes();
        }
        if(newSelection == TAB_SETTINGS){
            lv_obj_set_style_bg_color(newTabSelected, lv_color_hex(ORANGE_DARK), 0);
            lv_obj_remove_local_style_prop(oldTabSelected, LV_STYLE_BG_COLOR, 0); 

            settings();
        }
        if(newSelection == TAB_TOOLS){
            lv_obj_set_style_bg_color(newTabSelected, lv_color_hex(BLUE_DARK), 0);
            lv_obj_remove_local_style_prop(oldTabSelected, LV_STYLE_BG_COLOR, 0); 

            tools();
        }
      }
    
    LV_LOG_USER("OLD PRESSED %d",(int*)lv_obj_get_index(oldTabSelected));
    LV_LOG_USER("NEW PRESSED %d",(int*)lv_obj_get_index(newTabSelected));
     
  }   
}    


void menu(){
    lv_obj_del(lv_screen_active());
    screen_mainMenu = lv_obj_create(NULL);
    lv_scr_load(screen_mainMenu);

    processes();


    processesTab = lv_obj_create(screen_mainMenu);
    lv_obj_set_pos(processesTab, 5, 7);                            
    lv_obj_set_size(processesTab, 130, 97);   
    lv_obj_add_event_cb(processesTab, event_tab_switch, LV_EVENT_CLICKED, processesTab);
    lv_obj_set_style_border_color(processesTab, lv_color_hex(GREY), 0);
    lv_obj_set_style_border_opa(processesTab, LV_OPA_50, 0);
    lv_obj_remove_flag(processesTab, LV_OBJ_FLAG_SCROLLABLE);      

          iconLabel = lv_label_create(processesTab);          
          lv_label_set_text(iconLabel, tabProcess_icon);                  
          lv_obj_set_style_text_font(iconLabel, &FilMachineFontIcons_40, 0);
          lv_obj_align(iconLabel, LV_ALIGN_CENTER, 0, -10);


          label = lv_label_create(processesTab);         
          lv_label_set_text(label, tabProcess_label); 
          lv_obj_set_style_text_font(label, &lv_font_montserrat_18, 0);              
          lv_obj_align(label, LV_ALIGN_CENTER, 0, 29);
          lv_obj_send_event(processesTab, LV_EVENT_CLICKED, processesTab);



    settingsTab = lv_obj_create(screen_mainMenu);
    lv_obj_set_pos(settingsTab, 5, 7 + 6 + 97);                            
    lv_obj_set_size(settingsTab, 130, 97);   
    lv_obj_add_event_cb(settingsTab, event_tab_switch, LV_EVENT_CLICKED, settingsTab);
    lv_obj_set_style_border_color(settingsTab, lv_color_hex(GREY), 0);
    lv_obj_set_style_border_opa(settingsTab, LV_OPA_50, 0);
    lv_obj_remove_flag(settingsTab, LV_OBJ_FLAG_SCROLLABLE);      

          iconLabel = lv_label_create(settingsTab);          
          lv_label_set_text(iconLabel, tabSetting_icon);                  
          lv_obj_set_style_text_font(iconLabel, &FilMachineFontIcons_40, 0);
          lv_obj_align(iconLabel, LV_ALIGN_CENTER, 0, -10);

          label = lv_label_create(settingsTab);         
          lv_label_set_text(label, tabSetting_label); 
          lv_obj_set_style_text_font(label, &lv_font_montserrat_18, 0);              
          lv_obj_align(label, LV_ALIGN_CENTER, 0, 29);



    toolsTab = lv_obj_create(screen_mainMenu);
    lv_obj_set_pos(toolsTab, 5, 7 + 12 + (2 * 97));                            
    lv_obj_set_size(toolsTab, 130, 97);   
    lv_obj_add_event_cb(toolsTab, event_tab_switch, LV_EVENT_CLICKED, toolsTab);
    lv_obj_set_style_border_color(toolsTab, lv_color_hex(GREY), 0);
    lv_obj_set_style_border_opa(toolsTab, LV_OPA_50, 0);
    lv_obj_remove_flag(toolsTab, LV_OBJ_FLAG_SCROLLABLE);      

          iconLabel = lv_label_create(toolsTab);          
          lv_label_set_text(iconLabel, tabTools_icon);                  
          lv_obj_set_style_text_font(iconLabel, &FilMachineFontIcons_40, 0);
          lv_obj_align(iconLabel, LV_ALIGN_CENTER, 0, -10);


          label = lv_label_create(toolsTab);         
          lv_label_set_text(label, tabTools_label); 
          lv_obj_set_style_text_font(label, &lv_font_montserrat_18, 0);              
          lv_obj_align(label, LV_ALIGN_CENTER, 0, 29);


}



// void menuTestmy (void)
// {

// /*Create a Tab view object*/
//     lv_obj_t * tabview;
//     tabview = lv_tabview_create(lv_screen_active());
//     lv_tabview_set_tab_bar_position(tabview, LV_DIR_LEFT);
//     lv_tabview_set_tab_bar_size(tabview, 80);

//     lv_obj_set_style_bg_color(tabview, lv_palette_lighten(LV_PALETTE_RED, 2), 0);

//     lv_obj_t * tab_buttons = lv_tabview_get_tab_bar(tabview);
//     lv_obj_set_style_bg_color(tab_buttons, lv_palette_darken(LV_PALETTE_GREY, 3), 0);
//     lv_obj_set_style_text_color(tab_buttons, lv_palette_lighten(LV_PALETTE_GREY, 5), 0);
//     lv_obj_set_style_border_side(tab_buttons, LV_BORDER_SIDE_RIGHT, LV_PART_ITEMS | LV_STATE_CHECKED);

//     /*Add 3 tabs (the tabs are page (lv_page) and can be scrolled*/
//     lv_obj_t * tab1 = lv_tabview_add_tab(tabview, "Tab 1");
//     lv_obj_t * tab2 = lv_tabview_add_tab(tabview, "Tab 2");
    

//     lv_obj_set_style_bg_color(tab2, lv_palette_lighten(LV_PALETTE_AMBER, 3), 0);
//     lv_obj_set_style_bg_opa(tab2, LV_OPA_COVER, 0);

//     /*Add content to the tabs*/
//     lv_obj_t * label = lv_label_create(tab1);
//     lv_label_set_text(label, "First tab");

//     label = lv_label_create(tab2);
//     lv_label_set_text(label, "Second tab");

//    //label = lv_label_create(tab3);
//     //lv_label_set_text(label, "Third tab");

//     lv_font_t * imgfont = lv_imgfont_create(80, get_imgfont_path, NULL);

//  if(imgfont == NULL) {
//         LV_LOG_ERROR("imgfont init error");
//         return;
//     }

//     imgfont->fallback = LV_FONT_DEFAULT;

//     //lv_obj_t * label1 = lv_label_create(lv_screen_active());
//     lv_label_set_text(label, "12\uF600\uF617AB");
//     lv_obj_set_style_text_font(label, imgfont, LV_PART_MAIN);
//     lv_obj_center(label);

//     lv_obj_t * tab3 = lv_tabview_add_tab(tabview, (char *)label);
//     label = lv_label_create(tab3);
    
//     lv_obj_remove_flag(lv_tabview_get_content(tabview), LV_OBJ_FLAG_SCROLLABLE);
// /*
//     lv_obj_t * menu = lv_menu_create(lv_screen_active());
//     lv_obj_set_size(menu, lv_display_get_horizontal_resolution(NULL), lv_display_get_vertical_resolution(NULL));
//     lv_menu_set_mode_root_back_button(menu, LV_MENU_ROOT_BACK_BUTTON_DISABLED);
//     lv_obj_center(menu);


//     lv_obj_t * container;
//     lv_obj_t * section;

//     lv_obj_t * imageButton;
//     lv_obj_t * label;


//     // create sub page for item 0
//     lv_obj_t* item_0 = lv_menu_page_create(menu, "item 0");
//     section = lv_menu_section_create(item_0);

//     // create sub page for item 1
//     lv_obj_t* item_1 = lv_menu_page_create(menu, "item 1");
//     section = lv_menu_section_create(item_1);


//     // create sidebar
//     lv_obj_t* sidebar = lv_menu_page_create(menu, "FilMachine");

//     // create sidebar element for item 0
//     section = lv_menu_section_create(sidebar);
//     cont = lv_menu_cont_create(section);
//    // label = lv_label_create(cont);
//    // lv_label_set_text(label, "Processes");
    
    
//     //lv_obj_t * container = lv_obj_create(cont);
//     //lv_obj_set_size(container, 150, 100);

    
//     LV_IMG_DECLARE(logo_img);
//     lv_obj_t * logo = lv_img_create(cont);
//     lv_img_set_src(logo, &logo_img);
//     lv_obj_set_pos(logo, 40, 100); 
//     lv_obj_align(logo, LV_ALIGN_LEFT_MID, 0, 0);
//     lv_img_set_zoom(logo, 64);


//     label = lv_label_create(cont);
//     lv_label_set_text(label, "Processes");
//     //lv_label_set_long_mode(label, LV_LABEL_LONG_SCROLL_CIRCULAR);
//     lv_obj_set_flex_grow(label, 1);
//     lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);



//     //lv_menu_set_load_page_event(menu, cont, item_0);
    
 

    

//     // create sidebar element for item 1
//     section = lv_menu_section_create(sidebar);
//     cont = lv_menu_cont_create(section);
    
//     label = lv_label_create(cont);
//     lv_label_set_text(label, "Configuration");
//     //lv_menu_set_load_page_event(menu, cont, item_1);


//     // create sidebar element for item 1
//     section = lv_menu_section_create(sidebar);
//     cont = lv_menu_cont_create(section);
//     label = lv_label_create(cont);
//     lv_label_set_text(label, "Tools");
//    // lv_menu_set_load_page_event(menu, cont, item_1);

//     // set sidebar
//     lv_menu_set_sidebar_page(menu, sidebar);
//     // cast menu from lv_obj_t* to lv_menu_t* to access members of the latter
//     lv_menu_t* menu_t = (lv_menu_t*)menu;
//     // set sidebar width
//     lv_obj_set_width(menu_t->sidebar, LV_PCT(30));


//     */


// }



// void menuTest(void)
// {
//     lv_obj_t * menu = lv_menu_create(lv_screen_active());

//     lv_color_t bg_color = lv_obj_get_style_bg_color(menu, 0);
//     /*
//     if(lv_color_brightness(bg_color) > 127) {
//         lv_obj_set_style_bg_color(menu, lv_color_darken(lv_obj_get_style_bg_color(menu, 0), 10), 0);
//     }
//     else {
//         lv_obj_set_style_bg_color(menu, lv_color_darken(lv_obj_get_style_bg_color(menu, 0), 50), 0);
//     }
//     */
//     //lv_menu_set_mode_root_back_button(menu, LV_MENU_ROOT_BACK_BUTTON_ENABLED);
//     //lv_obj_add_event_cb(menu, back_event_handler, LV_EVENT_CLICKED, menu);
//     lv_obj_set_size(menu, lv_display_get_horizontal_resolution(NULL), lv_display_get_vertical_resolution(NULL));
//     lv_obj_center(menu);

//     lv_obj_t * cont;
//     lv_obj_t * section;

//     /*Create sub pages*/
//     lv_obj_t * sub_mechanics_page = lv_menu_page_create(menu, NULL);
//     lv_obj_set_style_pad_hor(sub_mechanics_page, lv_obj_get_style_pad_left(lv_menu_get_main_header(menu), 0), 0);
//     lv_menu_separator_create(sub_mechanics_page);
//     section = lv_menu_section_create(sub_mechanics_page);
//     create_slider(section, LV_SYMBOL_SETTINGS, "Velocity", 0, 150, 120);
//     create_slider(section, LV_SYMBOL_SETTINGS, "Acceleration", 0, 150, 50);
//     create_slider(section, LV_SYMBOL_SETTINGS, "Weight limit", 0, 150, 80);

//     lv_obj_t * sub_sound_page = lv_menu_page_create(menu, NULL);
//     lv_obj_set_style_pad_hor(sub_sound_page, lv_obj_get_style_pad_left(lv_menu_get_main_header(menu), 0), 0);
//     lv_menu_separator_create(sub_sound_page);
//     section = lv_menu_section_create(sub_sound_page);
//     create_switch(section, LV_SYMBOL_AUDIO, "Sound", false);

//     lv_obj_t * sub_display_page = lv_menu_page_create(menu, NULL);
//     lv_obj_set_style_pad_hor(sub_display_page, lv_obj_get_style_pad_left(lv_menu_get_main_header(menu), 0), 0);
//     lv_menu_separator_create(sub_display_page);
//     section = lv_menu_section_create(sub_display_page);
//     create_slider(section, LV_SYMBOL_SETTINGS, "Brightness", 0, 150, 100);

//     lv_obj_t * sub_software_info_page = lv_menu_page_create(menu, NULL);
//     lv_obj_set_style_pad_hor(sub_software_info_page, lv_obj_get_style_pad_left(lv_menu_get_main_header(menu), 0), 0);
//     section = lv_menu_section_create(sub_software_info_page);
//     create_text(section, NULL, "Version 1.0", LV_MENU_ITEM_BUILDER_VARIANT_1);

//     lv_obj_t * sub_legal_info_page = lv_menu_page_create(menu, NULL);
//     lv_obj_set_style_pad_hor(sub_legal_info_page, lv_obj_get_style_pad_left(lv_menu_get_main_header(menu), 0), 0);
//     section = lv_menu_section_create(sub_legal_info_page);
//     for(uint32_t i = 0; i < 15; i++) {
//         create_text(section, NULL,
//                     "This is a long long long long long long long long long text, if it is long enough it may scroll.",
//                     LV_MENU_ITEM_BUILDER_VARIANT_1);
//     }

//     lv_obj_t * sub_about_page = lv_menu_page_create(menu, NULL);
//     lv_obj_set_style_pad_hor(sub_about_page, lv_obj_get_style_pad_left(lv_menu_get_main_header(menu), 0), 0);
//     lv_menu_separator_create(sub_about_page);
//     section = lv_menu_section_create(sub_about_page);
//     cont = create_text(section, NULL, "Software information", LV_MENU_ITEM_BUILDER_VARIANT_1);
//     lv_menu_set_load_page_event(menu, cont, sub_software_info_page);
//     cont = create_text(section, NULL, "Legal information", LV_MENU_ITEM_BUILDER_VARIANT_1);
//     lv_menu_set_load_page_event(menu, cont, sub_legal_info_page);

//     lv_obj_t * sub_menu_mode_page = lv_menu_page_create(menu, NULL);
//     lv_obj_set_style_pad_hor(sub_menu_mode_page, lv_obj_get_style_pad_left(lv_menu_get_main_header(menu), 0), 0);
//     lv_menu_separator_create(sub_menu_mode_page);
//     section = lv_menu_section_create(sub_menu_mode_page);
//     cont = create_switch(section, LV_SYMBOL_AUDIO, "Sidebar enable", true);
//     lv_obj_add_event_cb(lv_obj_get_child(cont, 2), switch_handler, LV_EVENT_VALUE_CHANGED, menu);

//     /*Create a root page*/
//     root_page = lv_menu_page_create(menu, "Settings");
//     lv_obj_set_style_pad_hor(root_page, lv_obj_get_style_pad_left(lv_menu_get_main_header(menu), 0), 0);
//     section = lv_menu_section_create(root_page);
//     cont = create_text(section, LV_SYMBOL_SETTINGS, "Mechanics", LV_MENU_ITEM_BUILDER_VARIANT_1);
//     lv_menu_set_load_page_event(menu, cont, sub_mechanics_page);
//     cont = create_text(section, LV_SYMBOL_AUDIO, "Sound", LV_MENU_ITEM_BUILDER_VARIANT_1);
//     lv_menu_set_load_page_event(menu, cont, sub_sound_page);
//     cont = create_text(section, LV_SYMBOL_SETTINGS, "Display", LV_MENU_ITEM_BUILDER_VARIANT_1);
//     lv_menu_set_load_page_event(menu, cont, sub_display_page);

//     create_text(root_page, NULL, "Others", LV_MENU_ITEM_BUILDER_VARIANT_1);
//     section = lv_menu_section_create(root_page);
//     cont = create_text(section, NULL, "About", LV_MENU_ITEM_BUILDER_VARIANT_1);
//     lv_menu_set_load_page_event(menu, cont, sub_about_page);
//     cont = create_text(section, LV_SYMBOL_SETTINGS, "Menu mode", LV_MENU_ITEM_BUILDER_VARIANT_1);
//     lv_menu_set_load_page_event(menu, cont, sub_menu_mode_page);

//     lv_menu_set_sidebar_page(menu, root_page);

//     lv_obj_send_event(lv_obj_get_child(lv_obj_get_child(lv_menu_get_cur_sidebar_page(menu), 0), 0), LV_EVENT_CLICKED,
//                       NULL);
//}

static void back_event_handler(lv_event_t * e)
{
    lv_obj_t * obj = (lv_obj_t*)lv_event_get_target(e);
    lv_obj_t * menu = (lv_obj_t*)lv_event_get_user_data(e);

    if(lv_menu_back_button_is_root(menu, obj)) {
        lv_obj_t * mbox1 = lv_msgbox_create(NULL);
        lv_msgbox_add_title(mbox1, "Hello");
        lv_msgbox_add_text(mbox1, "Root back btn click.");
        lv_msgbox_add_close_button(mbox1);
    }
}

static void switch_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * menu = (lv_obj_t*)lv_event_get_user_data(e);
    lv_obj_t * obj = (lv_obj_t*)lv_event_get_target(e);
    if(code == LV_EVENT_VALUE_CHANGED) {
        if(lv_obj_has_state(obj, LV_STATE_CHECKED)) {
            lv_menu_set_page(menu, NULL);
            lv_menu_set_sidebar_page(menu, root_page);
            lv_obj_send_event(lv_obj_get_child(lv_obj_get_child(lv_menu_get_cur_sidebar_page(menu), 0), 0), LV_EVENT_CLICKED,
                              NULL);
        }
        else {
            lv_menu_set_sidebar_page(menu, NULL);
            lv_menu_clear_history(menu); /* Clear history because we will be showing the root page later */
            lv_menu_set_page(menu, root_page);
        }
    }
}








#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*PAGE_MENU_H*/

/**
 * @file pages.h
 *
 */


#ifndef PAGES_H
#define PAGES_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/


#include "definitions.h"
#include "elements/element_rollerPopup.h"
#include "elements/element_messagePopup.h"
#include "elements/element_step.h"
#include "accessory.h"

//NEW GUI APPROACH
#include "elements/element_filterPopup.h"
#include "pages/page_tools.h"
#include "pages/page_settings.h"
#include "pages/page_stepDetail.h"
#include "pages/page_checkup.h"
#include "pages/page_processDetail.h"
#include "elements/element_process.h"
#include "pages/page_processes.h"
#include "pages/page_menu.h"
#include "pages/page_home.h"


//OLD GUI APPROACH
/*
#include "pages/OldGuiApproach/page_program.h"
#include "pages/OldGuiApproach/page_tankSize.h"
#include "pages/OldGuiApproach/page_cleaning.h"
#include "pages/OldGuiApproach/page_developing.h"
#include "pages/OldGuiApproach/page_films.h"
*/

//always after the include pages above
//#include "display_manager.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*PAGES_H*/
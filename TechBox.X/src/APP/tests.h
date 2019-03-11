/* ************************************************************************** */
/** Descriptive File Name

  @Author
	Peter T.L. Nthite

  @Date
	25 July 2018

  @Company
    Fidelity Cashmaster

  @File Name
    tests.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#ifndef _TESTS_H    /* Guard against multiple inclusion */
#define _TESTS_H


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */
#include "../../mcc_generated_files/mcc.h"
#include <stdint.h>



/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Constants                                                         */
/* ************************************************************************** */
/* ************************************************************************** */
#define TESTS_MAX_ANTICUT_FAILURES	100
#define TESTS_MAX_INK_FAILURES		3

#define TESTS_0V_MIN_VOLT			0
#define TESTS_1V_MIN_VOLT			900
#define TESTS_2V_MIN_VOLT			1900
#define TESTS_3V_MIN_VOLT			2900
#define TESTS_4V_MIN_VOLT			3500
#define TESTS_5V_MIN_VOLT			TESTS_4V_MIN_VOLT

#define TESTS_0V_MAX_VOLT			400
#define TESTS_1V_MAX_VOLT			1250
#define TESTS_2V_MAX_VOLT			2250
#define TESTS_3V_MAX_VOLT			3250
#define TESTS_4V_MAX_VOLT			4250
#define TESTS_5V_MAX_VOLT			TESTS_4V_MAX_VOLT

#define TEST_HEART_BEAT		   		23 	// * 100ms


// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************

/*  A brief description of a section can be given directly below the section
	banner.
 */
typedef enum TESTS_ANTICUT_T
{
	TESTS_STATE_ANTICUT_IDLE,
	TESTS_STATE_ANTICUT_START,
	TESTS_STATE_ANTICUT_RUN_HIGH,
	TESTS_STATE_ANTICUT_LOW,
	TESTS_STATE_ANTICUT_RUN_LOW,
	TESTS_STATE_ANTICUT_STOP,
}stateAntiCut_t;

typedef enum TESTS_INK_T
{
	TESTS_STATE_INK_IDLE,
	TESTS_STATE_INK_START,
	TESTS_STATE_INK_RUN,
	TESTS_STATE_INK_RELOAD,
	TESTS_STATE_INK_STOP,
}stateInk_t;


// *****************************************************************************
// *****************************************************************************
// Section: Interface Functions
// *****************************************************************************
// *****************************************************************************
void TESTS_Initialize(void);
void TESTS_AntiCut(void);
void TESTS_Ink(void);
stateAntiCut_t TESTS_GetAntiCutState(void);
stateAntiCut_t TESTS_GetInkState(void);
void TESTS_StartAntiCut (void);
void TESTS_StartInk (void);
bool TESTS_SwitchOffAntiCutLeds();
bool TESTS_SwitchOffInkLeds();
void TESTS_Leds(void);
void TESTS_AntiCutLEDsOFF(void);
void TESTS_InkLEDsOFF(void);



#endif /* _TESTS_H */

/* *****************************************************************************
 End of File
 */

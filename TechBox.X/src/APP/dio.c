/* ************************************************************************** */
/** Descriptive File Name

  @Author
	Peter T.L. Nthite

  @Date
	25 July 2018

  @Company
    Fidelity Cashmaster

  @File Name
    dio.c

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */
#include "app.h"
#include "../General/general.h"
#include "../../mcc_generated_files/mcc.h"

//#define THIS_CLASS						DIAG_NF_CLASS

/* This section lists the other files that are included in this file.
 */

/* TODO:  Include other files here if needed. */


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */

#define FAILURES_MAX_ANTICUT	3
#define FAILURES_MAX_IR			3
#define FAILURES_MAX_INK		3


/*  A brief description of a section can be given directly below the section
    banner.
 */

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Local function prototypes                                         */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */
/*volatile*/ dioPin_t DIO_AntiCut, DIO_AntiCutDrive, DIO_Reflex, DIO_Ink;
dioList_t	dioPins;
void dioBtnInitialize (dioPin_t* btn, uint8_t debounceVal, 
		//unsigned 			*pin,
		//pinType_t			type,
		pfnGetState			getStatefn,
		pfnCallBack 		actvateFn, 
		pfnCallBack 		callBckfn,
		pfnGetState			getOffLeds,
		pfnCallBack 		swOffLeds);
void dioAddPin(dioPin_t *pin);

//static dioPin_t *pinArray[MAXPINLIST];
 
 
/* ************************************************************************** */
/* ************************************************************************** */
// Section: Interface Functions                                               */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */
void DIO_Initialize (void)
{
	dioBtnInitialize(&DIO_AntiCut, DIO_DEBOUNCE_VALUE, 
					//BUTTON_AntiCut_GetValue(),
					//PIN_BUTTON,
					TESTS_GetAntiCutState, 
					TESTS_StartAntiCut, 
					TESTS_AntiCut,
					TESTS_SwitchOffAntiCutLeds,
					TESTS_AntiCutLEDsOFF);
	dioBtnInitialize(&DIO_Ink, DIO_DEBOUNCE_VALUE, 
					//BUTTON_Ink_GetValue(),
					//PIN_BUTTON,
					TESTS_GetInkState, 
					TESTS_StartInk, 
					TESTS_Ink,
					TESTS_SwitchOffInkLeds,
					TESTS_InkLEDsOFF);
	
	/*dioBtnInitialize(&DIO_AntiCutDrive, DIO_DEBOUNCE_VALUE, 
					//&PORTAbits.RA7, //DIO_AntiCutDriveIn_GetValue(),
					//PIN_BUTTON,
					NULL, 
					NULL, 
					NULL,
					NULL,
					NULL);*/
	
	memset(&dioPins, 0, MAXPINLIST);
	
	dioPins.timer 	= TIMERS_u16GetTicksNow();
	dioPins.state 	= Running;
	
	dioAddPin(&DIO_AntiCut);
	dioAddPin(&DIO_Ink);
}




 
/* ************************************************************************** */
/* ************************************************************************** */
// Section: Local Functions                                                   */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

void DIO_AntiCutTestDone(void)
{
	DIO_AntiCut.state = DIO_LOW;
}

void DIO_InkTestDone(void)
{
	DIO_Ink.state = DIO_LOW;
}

void DIO_Manager(void)
{
	uint8_t index = 0;
	
	if(dioPins.state == Running)
	{
		for(index = 0; index < dioPins.count;  index++)
		{
			if(dioPins.pinList[index]->state == DIO_HIGH)
			{
				if(0 == (uint8_t)(dioPins.pinList[index]->getStatefn()))
				{
					dioPins.pinList[index]->activateFn();
				}
				dioPins.pinList[index]->testFn();
			}
			else
			{
				if(0 != (uint8_t)(dioPins.pinList[index]->getSwOffLeds()))
				{
					dioPins.pinList[index]->switchOffLeds();
				}
			}
		}
	}
}

void dioBtnInitialize (dioPin_t* btn, uint8_t debounceVal, 
		//unsigned 			*pin,
		//pinType_t			type,
		pfnGetState			getStatefn,
		pfnCallBack 		actvateFn, 
		pfnCallBack 		callBckfn,
		pfnGetState			getOffLeds,
		pfnCallBack 		swOffLeds)
{
	btn->state 			= DIO_LOW;
	btn->debounceValue 	= debounceVal;
	//btn->pin			= pin;
	//btn->type			= type;
	btn->getStatefn		= getStatefn;
	btn->activateFn 	= actvateFn;
	btn->testFn 		= callBckfn;
	btn->getSwOffLeds 	= getOffLeds;
	btn->switchOffLeds 	= swOffLeds;
	btn->timer 			= TIMERS_u16GetTicksNow();
}

void dioAddPin(dioPin_t *pin)
{
	//dioPin_t *pin;
	if (pin == NULL)
	{
		return;
	}
	
	if(pin->debounceValue == 0)
	{
		return;
	}
	
	if(dioPins.count < MAXPINLIST)
	{
		dioPins.pinList[dioPins.count] = pin;
		dioPins.count++;
	}
}


/* *****************************************************************************
 End of File
 */


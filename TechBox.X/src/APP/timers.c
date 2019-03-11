/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Fidelity Cashmaster

  @File Name
    timers.c

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

/*  A brief description of a section can be given directly below the section
    banner.
 */
#define DONT_COMPILE	0
/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Local function prototypes                                         */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */
//extern volatile unsigned int Tick_1min;
//volatile uint8_t	u8TickCounter;
volatile uint16_t	u16TickCounter;
//volatile uint32_t	u32TickCounter;



/* ************************************************************************** */
/* ************************************************************************** */
// Section: Interface Functions                                               */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */
// Initialise the timer chain
void TIMERS_Initialize()
{
    //LinkedListInit(&TimerList);
	/*u8TickCounter = */u16TickCounter = /*u32TickCounter =*/ 0;
}

#if DONT_COMPILE
uint8_t TIMERS_u8GetTicksNow(void)
{
	return u8TickCounter;
}

/** 
  @Function
    uint8_t TIMER_u8CalcTickDiff(uint8_t u8PreviousTick)

  @Summary
    Calculates the number of ticks that has occured since
    previous value and returns the 16bit difference.

  @Remarks
    Refer to the example_file.h interface header for function usage details.
 */
uint8_t TIMERS_u8CalcTickDiff(uint8_t u8PreviousTick)
{
	uint8_t u8Temp, res;
	
	u8Temp = u8TickCounter;
	
	if(u8Temp >=  u8PreviousTick)
	{
		res = (uint8_t)(u8Temp -  u8PreviousTick);
	}
	else
	{
		res = (uint8_t)(~( u8PreviousTick - u8Temp));
	}
	return (res);
}
#endif

uint16_t TIMERS_u16GetTicksNow(void)
{
	return u16TickCounter;
}

/** 
  @Function
    uint16_t TIMER_u16CalcTickDiff(uint16_t u16PreviousTick) 

  @Summary
    Calculates the number of ticks that has occured since
    previous value and returns the 16bit difference.

  @Remarks
    Refer to the example_file.h interface header for function usage details.
 */
uint16_t TIMERS_u16CalcTickDiff(uint16_t u16PreviousTick)
{
	uint16_t u16Temp, res;
	
	u16Temp = u16TickCounter;
	
	if(u16Temp >=  u16PreviousTick)
	{
		res = (uint16_t)(u16Temp -  u16PreviousTick);
	}
	else
	{
		res = (uint16_t)(~( u16PreviousTick - u16Temp));
	}
	return (res);
}

#if DONT_COMPILE
uint32_t TIMERS_u32GetTicksNow(void)
{
	return u32TickCounter;
}

/** 
  @Function
    uint32_t TIMER_u32CalcTickDiff(uint32_t u32PreviousTick) 

  @Summary
    Calculates the number of ticks that has occured since
    previous value and returns the 32bit difference.

  @Remarks
    Refer to the example_file.h interface header for function usage details.
 */
uint32_t TIMERS_u32CalcTickDiff(uint32_t u32PreviousTick)
{
	uint32_t u32Temp, res;
	
	u32Temp = u32TickCounter;
	
	if(u32Temp >=  u32PreviousTick)
	{
		res = (uint32_t)(u32Temp - u32PreviousTick);
	}
	else
	{
		res = (uint32_t)(~( u32PreviousTick - u32Temp));
	}
	return (res);
}
#endif




/* ************************************************************************** */
/* ************************************************************************** */
// Section: Local Functions                                                   */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */


/* *****************************************************************************
 End of File
 */


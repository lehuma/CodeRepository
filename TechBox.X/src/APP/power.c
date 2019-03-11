/* ************************************************************************** */
/** Descriptive File Name

  @Author
	Peter T.L. Nthite

  @Date
	25 July 2018

  @Company
    Fidelity Cashmaster

  @File Name
    infra_red.c

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

#define THIS_CLASS						DIAG_NF_CLASS

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

static uint16_t powerTimer;

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Local function prototypes                                         */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

 
 
/* ************************************************************************** */
/* ************************************************************************** */
// Section: Interface Functions                                               */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

void POWER_Initialize(void)
{
	powerTimer = TIMERS_u16GetTicksNow();
}

void POWER_ResetTimer(void)
{
	powerTimer = TIMERS_u16GetTicksNow();
}

void POWER_Manager(void)
{
	if( TIMERS_u16CalcTickDiff(powerTimer) > TIMERS_MIN_3 )
	{
		// Check for IDLE in all states
	}
	else if ( TIMERS_u16CalcTickDiff(powerTimer) > TIMERS_MIN_5 )
	{
		// SLEEP
	}
	
}


 
 
 
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


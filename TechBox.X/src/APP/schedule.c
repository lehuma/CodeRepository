/* ************************************************************************** */
/** Descriptive File Name

  @Author
	Peter T.L. Nthite

  @Date
	25 July 2018

  @Company
    Fidelity Cashmaster

  @File Name
    schedule.c

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

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Local function prototypes                                         */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

static schedule_t *schedArray[MAXSCHEDULES];
static scheduleList_t schedList;
 
 
/* ************************************************************************** */
/* ************************************************************************** */
// Section: Interface Functions                                               */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

void SCHEDULE_Initialize() // create initial schedule list
{
    //
    schedList.HighInterval = 0;
    schedList.schedTick = 0;
    schedList.count = 0;
    schedList.timer = TIMERS_u16GetTicksNow();
    schedList.schedState = Stopped; // don't process list
    schedList.schedules = schedArray[0]; // the first one
}

void SCHEDULE_Subscribe(schedule_t *_sched, unsigned short clk, void (*funcptr)())
{
    //
    if (schedList.count < MAXSCHEDULES) 
    {
        if (clk > 0) 
        {
            //schedList.schedules[schedList.count] = _sched;
            _sched->interval = clk;
            _sched->funcptr = funcptr;

            schedArray[schedList.count] = _sched;
            if (_sched->interval > schedList.HighInterval) 
            {
                schedList.HighInterval = _sched->interval;
            }
            schedList.count++;
        }
    }
}

void SCHEDULE_Start()
{
    //
    schedList.schedState = Running;
}

void SCHEDULE_Stop()
{
    //
    schedList.schedState = Stopped;
}

void SCHEDULE_Process()
{
    //
    unsigned int i;
    //Schedule *schedPtr;

    if (schedList.schedState == Running)
    {
		if( TIMERS_u16CalcTickDiff(schedList.timer) >= TIMERS_MS_100 )
        {
			schedList.timer = TIMERS_u16GetTicksNow();
            schedList.schedTick++;
            if (schedList.count > 0)
            {
                for (i = 0; i < schedList.count; i++)
                {
                    //
                    if (schedList.schedTick % (schedArray[i]->interval) == 0)
                    {
                        // call the function
                        schedArray[i]->funcptr();
                    }
                }
            }
            if (schedList.schedTick >= schedList.HighInterval)
            {
                schedList.schedTick = 0;
            }
        }
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


/* ************************************************************************** */
/** Descriptive File Name

  @Author
	Peter T.L. Nthite

  @Date
	25 July 2018

  @Company
    Fidelity Cashmaster

  @File Name
    schedule.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#ifndef _SCHEDULE_H    /* Guard against multiple inclusion */
#define _SCHEDULE_H


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */
#include "list.h"
 
 


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Constants                                                         */
/* ************************************************************************** */
/* ************************************************************************** */
#define MAXSCHEDULES 5



// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************

/*  A brief description of a section can be given directly below the section
	banner.
 */
typedef struct Schedule
{
    unsigned short interval;    // how long between calls
    void (*funcptr)();          // function to call
} schedule_t;


typedef struct ScheduleList
{
    uint8_t 	count;           // how many schedules in list
    uint16_t 	HighInterval;    // the biggest interval
    uint16_t 	schedTick;
    uint16_t 	timer;
    listState_t	schedState;
    schedule_t *schedules;     // the schedules
} scheduleList_t;



    

// *****************************************************************************
// *****************************************************************************
// Section: Interface Functions
// *****************************************************************************
// *****************************************************************************
    // the pseudo scheduler functions
    void SCHEDULE_Initialize(); // create initial schedule list
    
    void SCHEDULE_Subscribe(schedule_t *_sched, unsigned short clk, void (*funcptr)());
    //char AddSchedule(Schedule *_sched); // create a schedule
    
    void SCHEDULE_Start();
    void SCHEDULE_Stop();
    
    void SCHEDULE_Process();
	


#endif /* _SCHEDULE_H */

/* *****************************************************************************
 End of File
 */

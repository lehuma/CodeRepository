/* ************************************************************************** */
/** Descriptive File Name

  @Author
	Peter T.L. Nthite

  @Date
	16 August 2018

  @Company
    Fidelity Cashmaster

  @File Name
    list.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#ifndef _LIST_H    /* Guard against multiple inclusion */
#define _LIST_H


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section _LISTs the other files that are included in this file.
 */



/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Constants                                                         */
/* ************************************************************************** */
/* ************************************************************************** */



// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************

/*  A brief description of a section can be given directly below the section
	banner.
 */
// Schedule states
typedef enum 
{
    Stopped = 0, 
	Running, 
	Paused, 
	Expired, 
	Triggered
} listState_t;


    

// *****************************************************************************
// *****************************************************************************
// Section: Interface Functions
// *****************************************************************************
// *****************************************************************************


#endif /* _LIST_H */

/* *****************************************************************************
 End of File
 */

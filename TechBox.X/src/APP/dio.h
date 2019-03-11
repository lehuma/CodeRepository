/* ************************************************************************** */
/** Descriptive File Name

  @Author
	Peter T.L. Nthite

  @Date
	25 July 2018

  @Company
    Fidelity Cashmaster

  @File Name
    dio.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#ifndef _DIO_H    /* Guard against multiple inclusion */
#define _DIO_H


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

#define	DIO_DEBOUNCE_VALUE	50
#define MAXPINLIST 3

// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************

/*  A brief description of a section can be given directly below the section
	banner.
 */
 
typedef void (*pfnCallBack)(void);
typedef uint8_t (*pfnGetState)(void);

typedef enum PIN_T
{
	PIN_BUTTON,
	PIN_INPUT
} pinType_t;

typedef struct DIO_PIN_TAG
{
	bool 		volatile	state;
	uint8_t		volatile	debounceValue;
	uint16_t	volatile	timer;
	//unsigned volatile	pin;
	//pinType_t			type;
	pfnGetState			getStatefn;
	pfnCallBack			activateFn;
	pfnCallBack			testFn;
	pfnGetState			getSwOffLeds;
	pfnCallBack			switchOffLeds;
} dioPin_t;

typedef struct DIO_LIST
{
	listState_t	state;
	uint8_t		count;
	uint16_t	timer;
	dioPin_t	*pinList[MAXPINLIST];
}dioList_t;
    

// *****************************************************************************
// *****************************************************************************
// Section: Interface Functions
// *****************************************************************************
// *****************************************************************************
void DIO_Initialize (void);
void DIO_Manager(void);
void DIO_AntiCutTestDone(void);
void DIO_InkTestDone(void);


#endif /* _DIO_H */

/* *****************************************************************************
 End of File
 */

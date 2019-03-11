/* ************************************************************************** */
/** Descriptive File Name

  @Author
	Peter T.L. Nthite

  @Date
	25 July 2018

  @Company
    Fidelity Cashmaster

  @File Name
    aio.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#ifndef _AIO_H    /* Guard against multiple inclusion */
#define _AIO_H


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */



/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Constants                                                         */
/* ************************************************************************** */
/* ************************************************************************** */
#define READ_VOLTAGE_TIME   3 	// * 100ms
#define READ_CURRENT_TIME   40 	// * 100ms
#define READ_BATTERY_TIME   40 	// * 100ms



// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************

/*  A brief description of a section can be given directly below the section
	banner.
 */
typedef enum STATES_T
{
	ANALOG_IDLE,
	READ_BATTERY,
	READ_REFLEX,
	READ_INK,
	READ_DETONATOR
} aioStates_t;

typedef enum AIO_DAC_VOLTS
{
	_0V	= 0x00,
	_1V	= 0x06,
	_2V	= 0x0D,
	_3V	= 0x13,
	_4V	= 0x1A,
	_5V	= 0x1F
} aio_dac_volts_t;

typedef struct AIO_INK_T
{
	bool			fNewValue;
	adc_result_t	inkValue;
} aioInkVal_t;
    

// *****************************************************************************
// *****************************************************************************
// Section: Interface Functions
// *****************************************************************************
// *****************************************************************************
void AIO_Initialize(void);
void AIO_ReadVoltages(void);
//adc_result_t AIO_ReadInk(void);
aioInkVal_t *AIO_GetInk(void);

#endif /* _AIO_H */

/* *****************************************************************************
 End of File
 */

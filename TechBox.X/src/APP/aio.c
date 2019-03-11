/* ************************************************************************** */
/** Descriptive File Name

  @Author
	Peter T.L. Nthite

  @Date
	25 July 2018

  @Company
    Fidelity Cashmaster

  @File Name
    aio.c

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

/*  A brief description of a section can be given directly below the section
    banner.
 */
aioStates_t aioStates;

adc_result_t batteryVoltage, detonator;
aioInkVal_t	inkValues;
uint16_t timerBatLed;


schedule_t readAnalogsSchedule;
uint8_t	dacValue, dacCounter;


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Local function prototypes                                         */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */
void readBattery(void);
void readReflex(void);
void readInk(void);
void readDetonator(void);

 
 
/* ************************************************************************** */
/* ************************************************************************** */
// Section: Interface Functions                                               */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

void AIO_Initialize(void)
{
    batteryVoltage = detonator = 0;
    aioStates = READ_BATTERY;
	dacValue = dacCounter = 0;
	
	inkValues.inkValue = 0;
	inkValues.fNewValue = false;

	timerBatLed = TIMERS_u16GetTicksNow();
	
    SCHEDULE_Subscribe(&readAnalogsSchedule,READ_VOLTAGE_TIME,AIO_ReadVoltages);
}
 
void AIO_ReadVoltages(void)
{
	if (batteryVoltage < 5000)
	{
		// Switch on the LED
		LED_Bat_SetHigh();
	}
	else
	{
		if(TIMERS_u16CalcTickDiff(timerBatLed) < TIMERS_SEC_4)
		{
			//LED_Bat_Toggle();
			LED_Bat_SetLow();
		}
		else
		{
			timerBatLed = TIMERS_u16GetTicksNow();
			//LED_Bat_SetLow();
			LED_Bat_Toggle();
		}
	}
	
	if (detonator > 4000)
	{
		LED_Detonator_SetHigh();
	}
	else
	{
		LED_Detonator_SetLow();
	}

	switch(aioStates)
	{
		case READ_BATTERY:
		{
			readBattery();
			aioStates = READ_BATTERY;//READ_REFLEX;
			break;
		}
		
		case READ_REFLEX:
		{
			readReflex();
			aioStates = READ_INK;
			break;
		}
		
		case READ_INK:
		{
			readInk();
			aioStates = READ_DETONATOR;
			break;
		}

		case READ_DETONATOR:
		{
			readDetonator();
			aioStates = READ_BATTERY;
			break;
		}

		default:
		{
			aioStates = READ_BATTERY;
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
void readBattery(void)
{
    char Msg[50]= {0};
    char value[15] = {0};
	
    batteryVoltage = ADC_GetConversion(AIO_Battery);
    MYSTRING_word_to_ascii(batteryVoltage, value, sizeof(value));
    MYSTRING_StrCopy(Msg, "\n\rB: ", 9);
    MYSTRING_StrCat(Msg, value);
	
	batteryVoltage = (adc_result_t)((batteryVoltage * 4.89) * 16600)/10000;
	
    MYSTRING_word_to_ascii(batteryVoltage, value, sizeof(value));
    MYSTRING_StrCat(Msg, " ");
    MYSTRING_StrCat(Msg, value);
    SERIAL_WriteBuffer(Msg,strlen(Msg));
}

void readDetonator(void)
{
    char Msg[50]= {0};
    char value[15] = {0};
	
    detonator = ADC_GetConversion(AIO_Detonator);
    MYSTRING_word_to_ascii(detonator, value, sizeof(value));
    MYSTRING_StrCopy(Msg, "\n\rD: ", 9);
    MYSTRING_StrCat(Msg, value);
	
	detonator = (adc_result_t)((detonator * 4.89) * 16600)/10000;
	
    MYSTRING_word_to_ascii(detonator, value, sizeof(value));
    MYSTRING_StrCat(Msg, " ");
    MYSTRING_StrCat(Msg, value);
    SERIAL_WriteBuffer(Msg,strlen(Msg));
}

void readReflex(void)
{
    char Msg[50]= {0};
    char value[6] = {0};
	adc_result_t reflexSensor;

    reflexSensor = (adc_result_t)(ADC_GetConversion(AIO_Reflex) * 4.89);
	
	// Reflex sensor not connected
	if(reflexSensor > 5000)
	{
		LED_ReflexCon_SetLow();
		LED_ReflexBlocked_SetLow();
	}
	
	// Reflex sensor is connected
	else if(reflexSensor > 4000)
	{
		LED_ReflexCon_SetHigh();
		LED_ReflexBlocked_SetLow();
	}
	
	// Reflex sensor is blocked
	else if(reflexSensor < 3000)
	{
		LED_ReflexCon_SetHigh();
		LED_ReflexBlocked_SetHigh();
	}		
	
    MYSTRING_word_to_ascii(reflexSensor, value, sizeof(value));
    MYSTRING_StrCopy(Msg, "\n\rRf: ", 9);
    MYSTRING_StrCat(Msg, value);
    SERIAL_WriteBuffer(Msg,strlen(Msg));
}

void readInk(void)
{
    char Msg[50]= {0};
    char value[6] = {0};
	adc_result_t voltage;

    voltage = (adc_result_t)(ADC_GetConversion(AIO_Influx) * 4.89);
	inkValues.inkValue = voltage;
	inkValues.fNewValue = true;

    MYSTRING_word_to_ascii(voltage, value, sizeof(value));
    MYSTRING_StrCopy(Msg, "\n\rIk: ", 9);
    MYSTRING_StrCat(Msg, value);
    SERIAL_WriteBuffer(Msg,strlen(Msg));
}

aioInkVal_t *AIO_GetInk(void)
{
	return &inkValues;
}


 
/* *****************************************************************************
 End of File
 */


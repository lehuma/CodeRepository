/* ************************************************************************** */
/** Descriptive File Name

  @Author
	Peter T.L. Nthite

  @Date
	25 July 2018

  @Company
    Fidelity Cashmaster

  @File Name
    tests.c

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
stateAntiCut_t stateAntiCut;
stateInk_t stateInk;
uint16_t testAntiCutLedTimer,testInkLedTimer, testInkCount;	
uint16_t testAntiCutTimer, testInkTimer;	
uint16_t testAntiCutFailures,testInkFailures;
adc_result_t minVolt, maxVolt;
aio_dac_volts_t testVoltage;

schedule_t heartBeatSchedule;

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Local function prototypes                                         */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

void TESTS_HeartBeat(void);

 
/* ************************************************************************** */
/* ************************************************************************** */
// Section: Interface Functions                                               */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

void TESTS_Initialize(void)
{
	minVolt 		= maxVolt = _0V;
	stateAntiCut 	= TESTS_STATE_ANTICUT_IDLE;
	stateInk 		= TESTS_STATE_INK_IDLE;
	DIO_AntiCutOut_SetLow();
	LED_AntiCutFail_SetLow();
	LED_AntiCutPass_SetLow();
	
	DAC_SetOutput(_0V);
	LED_InkFail_SetLow();
	LED_InkPass_SetLow();
    SCHEDULE_Subscribe(&heartBeatSchedule,TEST_HEART_BEAT,TESTS_HeartBeat);
}


void TESTS_AntiCut(void)
{
	switch(stateAntiCut)
	{
		case TESTS_STATE_ANTICUT_IDLE:
		{
			if( TIMERS_u16CalcTickDiff(testAntiCutTimer) > TIMERS_MIN_2 )
			{
				LED_AntiCutFail_SetLow();
				LED_AntiCutPass_SetLow();
			}

			break;
		}
		
		case TESTS_STATE_ANTICUT_START:
		{
			stateAntiCut 		= TESTS_STATE_ANTICUT_RUN_HIGH;
			testAntiCutTimer 	= TIMERS_u16GetTicksNow();
			testAntiCutFailures = 0;
			DIO_AntiCutOut_SetHigh();
			LED_AntiCutFail_SetHigh();
			LED_AntiCutPass_SetLow();
			break;
		}
		
		case TESTS_STATE_ANTICUT_RUN_HIGH:
		{
			if( TIMERS_u16CalcTickDiff(testAntiCutTimer) < TIMERS_SEC_5 )
			{
				if(DIO_AntiCutIn_GetValue() == DIO_LOW)
				{
					testAntiCutFailures++;
				}
			}
			else if (testAntiCutFailures >= TESTS_MAX_ANTICUT_FAILURES)
			{
				testAntiCutTimer 	= TIMERS_u16GetTicksNow();
				stateAntiCut 		= TESTS_STATE_ANTICUT_STOP;
			}
			else
			{
				testAntiCutTimer 	= TIMERS_u16GetTicksNow();
				stateAntiCut 		= TESTS_STATE_ANTICUT_LOW;
			}
			break;
		}
		
		case TESTS_STATE_ANTICUT_LOW:
		{
			stateAntiCut 		= TESTS_STATE_ANTICUT_RUN_LOW;
			testAntiCutTimer 	= TIMERS_u16GetTicksNow();
			testAntiCutFailures = 0;
			DIO_AntiCutOut_SetLow();
			break;
		}
		
		case TESTS_STATE_ANTICUT_RUN_LOW:
		{
			if( TIMERS_u16CalcTickDiff(testAntiCutTimer) < TIMERS_SEC_5 )
			{
				if(DIO_AntiCutIn_GetValue() == DIO_HIGH)
				{
					testAntiCutFailures++;
				}
			}
			else
			{
				stateAntiCut 		= TESTS_STATE_ANTICUT_STOP;
				testAntiCutTimer 	= TIMERS_u16GetTicksNow();
			}
			break;
		}
		
		case TESTS_STATE_ANTICUT_STOP:
		{
			stateAntiCut 		= TESTS_STATE_ANTICUT_IDLE;
			testAntiCutTimer 	= TIMERS_u16GetTicksNow();
			DIO_AntiCutTestDone();
			
			if(testAntiCutFailures >= TESTS_MAX_ANTICUT_FAILURES)
			{
				LED_AntiCutFail_SetHigh();
				LED_AntiCutPass_SetLow();
			}
			else
			{
				LED_AntiCutFail_SetLow();
				LED_AntiCutPass_SetHigh();
			}
			break;
		}
		
		default:
		{
			break;
		}
	}
	
	if((stateAntiCut != TESTS_STATE_ANTICUT_IDLE) || (stateAntiCut != TESTS_STATE_ANTICUT_STOP))
	{
		if( TIMERS_u16CalcTickDiff(testAntiCutLedTimer) > TIMERS_SEC_1 )
		{
			testAntiCutLedTimer = TIMERS_u16GetTicksNow();
			LED_AntiCutFail_Toggle();
			LED_AntiCutPass_Toggle();
		}
	}
}

void TESTS_Ink(void)
{
	aioInkVal_t *volts = AIO_GetInk();
	
	switch(stateInk)
	{
		case TESTS_STATE_INK_IDLE:
		{
			if( TIMERS_u16CalcTickDiff(testInkTimer) > TIMERS_MIN_2 )
			{
				LED_InkFail_SetLow();
				LED_InkPass_SetLow();
			}

			break;
		}
		
		case TESTS_STATE_INK_START:
		{
			stateInk 		= TESTS_STATE_INK_RUN;
			testVoltage 	= _0V;
			testInkTimer 	= TIMERS_u16GetTicksNow();
			minVolt 		= TESTS_0V_MIN_VOLT;
			maxVolt 		= TESTS_0V_MAX_VOLT;
			testInkCount 	= testInkFailures = 0;
			LED_InkFail_SetLow();
			LED_InkPass_SetHigh();
			DAC_SetOutput(testVoltage);
			break;
		}
		
		case TESTS_STATE_INK_RUN:
		{
			if(testInkCount < 3)
			{
				if( TIMERS_u16CalcTickDiff(testInkTimer) > TIMERS_SEC_2 )
				{
					testInkTimer = TIMERS_u16GetTicksNow();

					if(volts->fNewValue == true)
					{
						testInkCount++;
						volts->fNewValue = false;
						if((volts->inkValue < minVolt) || (volts->inkValue > maxVolt))
						{
							testInkFailures++;
						}
					}
				}
			}
			else if (testInkFailures >= TESTS_MAX_INK_FAILURES)
			{
				stateInk = TESTS_STATE_INK_STOP;
			}
			else
			{
				stateInk = TESTS_STATE_INK_RELOAD;
			}
			break;
		}
		
		case TESTS_STATE_INK_RELOAD:
		{
			stateInk 		= TESTS_STATE_INK_RUN;
			testInkCount 	= testInkFailures = 0;
			testInkTimer 	= TIMERS_u16GetTicksNow();
			
			switch(testVoltage)
			{
				case _0V:
				{
					minVolt 	= TESTS_1V_MIN_VOLT;
					maxVolt 	= TESTS_1V_MAX_VOLT;
					testVoltage = _1V;
					DAC_SetOutput(testVoltage);
					break;
				}
				
				case _1V:
				{
					minVolt 	= TESTS_2V_MIN_VOLT;
					maxVolt 	= TESTS_2V_MAX_VOLT;
					testVoltage = _2V;
					DAC_SetOutput(testVoltage);
					break;
				}
				
				case _2V:
				{
					minVolt 	= TESTS_3V_MIN_VOLT;
					maxVolt 	= TESTS_3V_MAX_VOLT;
					testVoltage = _3V;
					DAC_SetOutput(testVoltage);
					break;
				}
				
				case _3V:
				{
					minVolt 	= TESTS_4V_MIN_VOLT;
					maxVolt 	= TESTS_4V_MAX_VOLT;
					testVoltage = _4V;
					DAC_SetOutput(testVoltage);
					break;
				}
				
				case _4V:
				{
					minVolt 	= TESTS_5V_MIN_VOLT;
					maxVolt 	= TESTS_5V_MAX_VOLT;
					testVoltage = _5V;
					DAC_SetOutput(testVoltage);
					break;
				}
				
				case _5V:
				{
					minVolt 	= TESTS_0V_MIN_VOLT;
					maxVolt 	= TESTS_0V_MAX_VOLT;
					stateInk 	= TESTS_STATE_INK_STOP;
					testVoltage = _0V;
					DAC_SetOutput(testVoltage);
					break;
				}
				default:
				{
				}
			}
			break;
		}
		
		case TESTS_STATE_INK_STOP:
		{
			stateInk 		= TESTS_STATE_INK_IDLE;
			testInkTimer 	= TIMERS_u16GetTicksNow();
			DIO_InkTestDone();
			
			if(testInkFailures >= TESTS_MAX_INK_FAILURES)
			{
				LED_InkFail_SetHigh();
				LED_InkPass_SetLow();
			}
			else
			{
				LED_InkFail_SetLow();
				LED_InkPass_SetHigh();
			}
			break;
		}
		
		default:
		{
			break;
		}
	}
	
	if((stateInk != TESTS_STATE_INK_IDLE) || (stateInk != TESTS_STATE_INK_STOP))
	{
		if( TIMERS_u16CalcTickDiff(testInkLedTimer) > TIMERS_SEC_1 )
		{
			testInkLedTimer = TIMERS_u16GetTicksNow();
			LED_InkFail_Toggle();
			LED_InkPass_Toggle();
		}
	}
}

stateAntiCut_t TESTS_GetAntiCutState(void)
{
	return stateAntiCut;
}

void TESTS_StartAntiCut (void)
{
	stateAntiCut = TESTS_STATE_ANTICUT_START;
}

stateAntiCut_t TESTS_GetInkState(void)
{
	return stateInk;
}

void TESTS_StartInk (void)
{
	stateInk = TESTS_STATE_INK_START;
}

bool TESTS_SwitchOffAntiCutLeds()
{
	return (bool)(TIMERS_u16CalcTickDiff(testAntiCutTimer) > TIMERS_MIN_1);
}

bool TESTS_SwitchOffInkLeds()
{
	return (bool)(TIMERS_u16CalcTickDiff(testInkTimer) > TIMERS_MIN_1);
}

void TESTS_AntiCutLEDsOFF(void)
{
	LED_AntiCutFail_SetLow();
	LED_AntiCutPass_SetLow();
}

void TESTS_InkLEDsOFF(void)
{
	LED_InkFail_SetLow();
	LED_InkPass_SetLow();
}


void TESTS_Leds(void)
{
	LED_AntiCutPass_SetHigh();
	LED_AntiCutFail_SetHigh();
	
	LED_ReflexBlocked_SetHigh();
	LED_ReflexCon_SetHigh();
	
	LED_InkFail_SetHigh();
	LED_InkPass_SetHigh();
	
	LED_Bat_SetHigh();
	
	testInkLedTimer = 15000;
	while( testInkLedTimer-- > 0 )
	{
		//1
	}
	LED_Bat_SetLow();
	
	testInkLedTimer = 10000;
	while( testInkLedTimer-- > 0 )
	{
		//2
	}
	LED_ReflexBlocked_SetLow();
	
	testInkLedTimer = 10000;
	while( testInkLedTimer-- > 0 )
	{
		//3
	}
	LED_ReflexCon_SetLow();
	
	testInkLedTimer = 10000;
	while( testInkLedTimer-- > 0 )
	{
		//4
	}
	LED_AntiCutPass_SetLow();
	
	testInkLedTimer = 10000;
	while( testInkLedTimer-- > 0 )
	{
		//5
	}
	LED_AntiCutFail_SetLow();
	
	testInkLedTimer = 10000;
	while( testInkLedTimer-- > 0 )
	{
		//6
	}
	LED_InkPass_SetLow();
	
	testInkLedTimer = 10000;
	while( testInkLedTimer-- > 0 )
	{
		//7
	}
	LED_InkFail_SetLow();
	
	testInkLedTimer = TIMERS_u16GetTicksNow();	
	
}

void TESTS_HeartBeat(void)
{
    char Msg[]= "TechBox v1 HeartBeat";

	SERIAL_WriteBuffer(Msg,strlen(Msg));
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


/**
  TMR0 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    tmr0.c

  @Summary
    This is the generated driver implementation file for the TMR0 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This source file provides APIs for TMR0.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC18F26K22
        Driver Version    :  2.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45
        MPLAB 	          :  MPLAB X 4.15
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

/**
  Section: Included Files
*/

#include <xc.h>
#include "tmr0.h"

#include "../src/APP/app.h"
/**
  Section: Global Variables Definitions
*/

void (*TMR0_InterruptHandler)(void);

volatile uint8_t timer0ReloadVal;
extern volatile timerFlags timerXFlags;

extern volatile uint8_t     u8TickCounter;
extern volatile uint16_t	u16TickCounter;
extern volatile uint32_t	u32TickCounter;

extern volatile dioPin_t DIO_AntiCut,DIO_AntiCutDrive, DIO_Reflex, DIO_Ink;

/**
  Section: TMR0 APIs
*/
volatile unsigned int timer0TickCount;
volatile unsigned int Tick_10ms;
volatile unsigned int Tick_1sec;
volatile unsigned int Tick_1min;

volatile unsigned char tick0;
volatile unsigned char tick1;
volatile unsigned char tick2;
const unsigned char tick10msNum = 10/TMR0_granularity;

void TMR0_Initialize(void)
{
    // Set TMR0 to the options selected in the User Interface
    
    // TMR0H 0; 
    TMR0H = 0x00;

    // TMR0L 217; 
    TMR0L = 0xD9;


    // Load TMR0 value to the 8-bit reload variable
    timer0ReloadVal = 217;
    
    // initialize the system tick counter
    timer0TickCount = 0;
    Tick_10ms = Tick_1sec = Tick_1min = 0;
    u8TickCounter = u16TickCounter = u32TickCounter = 0;
    tick0 = 0;
    tick1 = 0;
    tick2 = 0;

    // Clear Interrupt flag before enabling the interrupt
    INTCONbits.TMR0IF = 0;

    // Enabling TMR0 interrupt.
    INTCONbits.TMR0IE = 1;

    // Set Default Interrupt Handler
    TMR0_SetInterruptHandler(TMR0_DefaultInterruptHandler);

    // T0PS 1:64; T08BIT 8-bit; T0SE Increment_hi_lo; T0CS FOSC/4; TMR0ON enabled; PSA assigned; 
    T0CON = 0xD5;
}

void TMR0_StartTimer(void)
{
    // Start the Timer by writing to TMR0ON bit
    T0CONbits.TMR0ON = 1;
}

void TMR0_StopTimer(void)
{
    // Stop the Timer by writing to TMR0ON bit
    T0CONbits.TMR0ON = 0;
}

uint8_t TMR0_ReadTimer(void)
{
    uint8_t readVal;

    // read Timer0, low register only
    readVal = TMR0L;

    return readVal;
}

void TMR0_WriteTimer(uint8_t timerVal)
{
    // Write to the Timer0 registers, low register only
    TMR0L = timerVal;
 }

void TMR0_Reload(void)
{
    //Write to the Timer0 register
    TMR0L = timer0ReloadVal;
}


void TMR0_ISR(void)
{

    // clear the TMR0 interrupt flag
    INTCONbits.TMR0IF = 0;

    // reload TMR0
    TMR0L = timer0ReloadVal;

    if(TMR0_InterruptHandler)
    {
        TMR0_InterruptHandler();
    }

    // add your TMR0 interrupt custom code
}


void TMR0_SetInterruptHandler(void (* InterruptHandler)(void)){
    TMR0_InterruptHandler = InterruptHandler;
}

void TMR0_DefaultInterruptHandler(void)
{
    // add your TMR0 interrupt custom code
    // or set custom function using TMR0_SetInterruptHandler()
    
    timer0TickCount++;
    
    tick0++; // count the ticks for the period
    u8TickCounter++;
    u16TickCounter++;
    u32TickCounter++;
	
	//IO_RA7_Toggle();
	
	switch(BUTTON_Ink_GetValue())
	{
		case DIO_LOW:
		{
			DIO_Ink.debounceValue = DIO_DEBOUNCE_VALUE;
			break;
		}
		
		case DIO_HIGH:
		{
			if( DIO_Ink.debounceValue-- == 0)
			{
				DIO_Ink.state = DIO_HIGH;
				DIO_Ink.testTimer = u16TickCounter;
			}
			break;
		}
	}
    
	switch(BUTTON_Reflex_GetValue())
	{
		case DIO_LOW:
		{
			DIO_Reflex.debounceValue = DIO_DEBOUNCE_VALUE;
			break;
		}
		
		case DIO_HIGH:
		{
			if( DIO_Reflex.debounceValue-- == 0)
			{
				DIO_Reflex.state = DIO_HIGH;
				DIO_Reflex.testTimer = u16TickCounter;
			}
			break;
		}
	}
    
	switch(BUTTON_AntiCut_GetValue())
	{
		case DIO_LOW:
		{
			DIO_AntiCut.debounceValue = DIO_DEBOUNCE_VALUE;
			break;
		}
		
		case DIO_HIGH:
		{
			if(DIO_AntiCut.debounceValue > 0)
			{
				if( DIO_AntiCut.debounceValue-- == 0)
				{
					DIO_AntiCut.state = DIO_HIGH;
					DIO_AntiCut.testTimer = u16TickCounter;
				}
			}
			else
			{
				DIO_AntiCut.state = DIO_HIGH;
				DIO_AntiCut.testTimer = u16TickCounter;
			}
			break;
		}
	}
    
	switch(DIO_AntiCutDriveIn_GetValue())
	{
		case DIO_LOW:
		{
			DIO_AntiCutDrive.debounceValue = DIO_DEBOUNCE_VALUE;
			LED_AntiCutDrive_SetLow();
			break;
		}
		
		case DIO_HIGH:
		{
			if(DIO_AntiCutDrive.debounceValue > 0)
			{
				if( DIO_AntiCutDrive.debounceValue-- == 0)
				{
					DIO_AntiCutDrive.state = DIO_HIGH;
					DIO_AntiCutDrive.testTimer = u16TickCounter;
					LED_AntiCutDrive_SetHigh();
				}
			}
			else
			{
				LED_AntiCutDrive_SetHigh();
			}
			break;
		}
	}
    
    if (tick0 >= tick10msNum)
    {
        tick0 = 0;
        Tick_10ms++;
        timerXFlags.tick10ms++;
        //timerFlg1.ef.tick10ms = ~timerFlg1.ef.tick10ms; // toggle
        tick1++;
        if (tick1 >= 100) // 1 second = 100 * 10ms
        {
            tick1 = 0;
            Tick_1sec++;
            timerXFlags.tick1sec++;
            //timerFlg1.ef.tick1sec = ~timerFlg1.ef.tick1sec; // toggle
            tick2++;
            if (tick2 >= 60)
            {
                tick2 = 0;
                Tick_1min++;
                //timerFlg1.ef.tick1min = ~timerFlg1.ef.tick1min;
            }
        }
    }
}

/**
  End of File
*/
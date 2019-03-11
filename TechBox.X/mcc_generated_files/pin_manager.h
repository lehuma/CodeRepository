/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define LED_ON 		1
#define LED_OFF     0

#define DIO_HIGH    1
#define DIO_LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set AIO_Influx aliases
#define AIO_Influx_TRIS                 TRISAbits.TRISA0
#define AIO_Influx_LAT                  LATAbits.LATA0
#define AIO_Influx_PORT                 PORTAbits.RA0
#define AIO_Influx_ANS                  ANSELAbits.ANSA0
#define AIO_Influx_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define AIO_Influx_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define AIO_Influx_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define AIO_Influx_GetValue()           PORTAbits.RA0
#define AIO_Influx_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define AIO_Influx_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define AIO_Influx_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define AIO_Influx_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set AIO_Reflex aliases
#define AIO_Reflex_TRIS                 TRISAbits.TRISA1
#define AIO_Reflex_LAT                  LATAbits.LATA1
#define AIO_Reflex_PORT                 PORTAbits.RA1
#define AIO_Reflex_ANS                  ANSELAbits.ANSA1
#define AIO_Reflex_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define AIO_Reflex_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define AIO_Reflex_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define AIO_Reflex_GetValue()           PORTAbits.RA1
#define AIO_Reflex_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define AIO_Reflex_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define AIO_Reflex_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define AIO_Reflex_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set RA2 procedures
#define RA2_SetHigh()               do { LATAbits.LATA2 = 1; } while(0)
#define RA2_SetLow()                do { LATAbits.LATA2 = 0; } while(0)
#define RA2_Toggle()                do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define RA2_GetValue()              PORTAbits.RA2
#define RA2_SetDigitalInput()       do { TRISAbits.TRISA2 = 1; } while(0)
#define RA2_SetDigitalOutput()      do { TRISAbits.TRISA2 = 0; } while(0)
#define RA2_SetAnalogMode()         do { ANSELAbits.ANSA2 = 1; } while(0)
#define RA2_SetDigitalMode()        do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set AIO_Detonator aliases
#define AIO_Detonator_TRIS                 TRISAbits.TRISA3
#define AIO_Detonator_LAT                  LATAbits.LATA3
#define AIO_Detonator_PORT                 PORTAbits.RA3
#define AIO_Detonator_ANS                  ANSELAbits.ANSA3
#define AIO_Detonator_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define AIO_Detonator_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define AIO_Detonator_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define AIO_Detonator_GetValue()           PORTAbits.RA3
#define AIO_Detonator_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define AIO_Detonator_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define AIO_Detonator_SetAnalogMode()      do { ANSELAbits.ANSA3 = 1; } while(0)
#define AIO_Detonator_SetDigitalMode()     do { ANSELAbits.ANSA3 = 0; } while(0)

// get/set DIO_AntiCutOut aliases
#define DIO_AntiCutOut_TRIS                 TRISAbits.TRISA4
#define DIO_AntiCutOut_LAT                  LATAbits.LATA4
#define DIO_AntiCutOut_PORT                 PORTAbits.RA4
#define DIO_AntiCutOut_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define DIO_AntiCutOut_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define DIO_AntiCutOut_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define DIO_AntiCutOut_GetValue()           PORTAbits.RA4
#define DIO_AntiCutOut_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define DIO_AntiCutOut_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)

// get/set AIO_Battery aliases
#define AIO_Battery_TRIS                 TRISAbits.TRISA5
#define AIO_Battery_LAT                  LATAbits.LATA5
#define AIO_Battery_PORT                 PORTAbits.RA5
#define AIO_Battery_ANS                  ANSELAbits.ANSA5
#define AIO_Battery_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define AIO_Battery_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define AIO_Battery_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define AIO_Battery_GetValue()           PORTAbits.RA5
#define AIO_Battery_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define AIO_Battery_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define AIO_Battery_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define AIO_Battery_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set DIO_AntiCutIn aliases
#define DIO_AntiCutIn_TRIS                 TRISAbits.TRISA6
#define DIO_AntiCutIn_LAT                  LATAbits.LATA6
#define DIO_AntiCutIn_PORT                 PORTAbits.RA6
#define DIO_AntiCutIn_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define DIO_AntiCutIn_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define DIO_AntiCutIn_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define DIO_AntiCutIn_GetValue()           PORTAbits.RA6
#define DIO_AntiCutIn_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define DIO_AntiCutIn_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)

// get/set DIO_AntiCutDriveIn aliases
#define DIO_AntiCutDriveIn_TRIS                 TRISAbits.TRISA7
#define DIO_AntiCutDriveIn_LAT                  LATAbits.LATA7
#define DIO_AntiCutDriveIn_PORT                 PORTAbits.RA7
#define DIO_AntiCutDriveIn_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define DIO_AntiCutDriveIn_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define DIO_AntiCutDriveIn_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define DIO_AntiCutDriveIn_GetValue()           PORTAbits.RA7
#define DIO_AntiCutDriveIn_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define DIO_AntiCutDriveIn_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)

// get/set BUTTON_Ink aliases
#define BUTTON_Ink_TRIS                 TRISBbits.TRISB0
#define BUTTON_Ink_LAT                  LATBbits.LATB0
#define BUTTON_Ink_PORT                 PORTBbits.RB0
#define BUTTON_Ink_WPU                  WPUBbits.WPUB0
#define BUTTON_Ink_ANS                  ANSELBbits.ANSB0
#define BUTTON_Ink_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define BUTTON_Ink_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define BUTTON_Ink_Toggle()             do { LATBbits.LATB0 = (unsigned)~LATBbits.LATB0; } while(0)
#define BUTTON_Ink_GetValue()           PORTBbits.RB0
#define BUTTON_Ink_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define BUTTON_Ink_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define BUTTON_Ink_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define BUTTON_Ink_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define BUTTON_Ink_SetAnalogMode()      do { ANSELBbits.ANSB0 = 1; } while(0)
#define BUTTON_Ink_SetDigitalMode()     do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set BUTTON_Reflex aliases
#define BUTTON_Reflex_TRIS                 TRISBbits.TRISB1
#define BUTTON_Reflex_LAT                  LATBbits.LATB1
#define BUTTON_Reflex_PORT                 PORTBbits.RB1
#define BUTTON_Reflex_WPU                  WPUBbits.WPUB1
#define BUTTON_Reflex_ANS                  ANSELBbits.ANSB1
#define BUTTON_Reflex_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define BUTTON_Reflex_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define BUTTON_Reflex_Toggle()             do { LATBbits.LATB1 = (unsigned)~LATBbits.LATB1; } while(0)
#define BUTTON_Reflex_GetValue()           PORTBbits.RB1
#define BUTTON_Reflex_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define BUTTON_Reflex_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define BUTTON_Reflex_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define BUTTON_Reflex_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define BUTTON_Reflex_SetAnalogMode()      do { ANSELBbits.ANSB1 = 1; } while(0)
#define BUTTON_Reflex_SetDigitalMode()     do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set BUTTON_AntiCut aliases
#define BUTTON_AntiCut_TRIS                 TRISBbits.TRISB2
#define BUTTON_AntiCut_LAT                  LATBbits.LATB2
#define BUTTON_AntiCut_PORT                 PORTBbits.RB2
#define BUTTON_AntiCut_WPU                  WPUBbits.WPUB2
#define BUTTON_AntiCut_ANS                  ANSELBbits.ANSB2
#define BUTTON_AntiCut_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define BUTTON_AntiCut_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define BUTTON_AntiCut_Toggle()             do { LATBbits.LATB2 = (unsigned)~LATBbits.LATB2; } while(0)
#define BUTTON_AntiCut_GetValue()           PORTBbits.RB2
#define BUTTON_AntiCut_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define BUTTON_AntiCut_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define BUTTON_AntiCut_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define BUTTON_AntiCut_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define BUTTON_AntiCut_SetAnalogMode()      do { ANSELBbits.ANSB2 = 1; } while(0)
#define BUTTON_AntiCut_SetDigitalMode()     do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set LED_InkFail aliases
#define LED_InkFail_TRIS                 TRISBbits.TRISB3
#define LED_InkFail_LAT                  LATBbits.LATB3
#define LED_InkFail_PORT                 PORTBbits.RB3
#define LED_InkFail_WPU                  WPUBbits.WPUB3
#define LED_InkFail_ANS                  ANSELBbits.ANSB3
#define LED_InkFail_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define LED_InkFail_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define LED_InkFail_Toggle()             do { LATBbits.LATB3 = (unsigned)~LATBbits.LATB3; } while(0)
#define LED_InkFail_GetValue()           PORTBbits.RB3
#define LED_InkFail_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define LED_InkFail_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define LED_InkFail_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define LED_InkFail_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define LED_InkFail_SetAnalogMode()      do { ANSELBbits.ANSB3 = 1; } while(0)
#define LED_InkFail_SetDigitalMode()     do { ANSELBbits.ANSB3 = 0; } while(0)

// get/set LED_InkPass aliases
#define LED_InkPass_TRIS                 TRISBbits.TRISB4
#define LED_InkPass_LAT                  LATBbits.LATB4
#define LED_InkPass_PORT                 PORTBbits.RB4
#define LED_InkPass_WPU                  WPUBbits.WPUB4
#define LED_InkPass_ANS                  ANSELBbits.ANSB4
#define LED_InkPass_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define LED_InkPass_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define LED_InkPass_Toggle()             do { LATBbits.LATB4 = (unsigned)~LATBbits.LATB4; } while(0)
#define LED_InkPass_GetValue()           PORTBbits.RB4
#define LED_InkPass_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define LED_InkPass_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define LED_InkPass_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define LED_InkPass_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define LED_InkPass_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define LED_InkPass_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set LED_AntiCutFail aliases
#define LED_AntiCutFail_TRIS                 TRISBbits.TRISB5
#define LED_AntiCutFail_LAT                  LATBbits.LATB5
#define LED_AntiCutFail_PORT                 PORTBbits.RB5
#define LED_AntiCutFail_WPU                  WPUBbits.WPUB5
#define LED_AntiCutFail_ANS                  ANSELBbits.ANSB5
#define LED_AntiCutFail_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define LED_AntiCutFail_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define LED_AntiCutFail_Toggle()             do { LATBbits.LATB5 = (unsigned)~LATBbits.LATB5; } while(0)
#define LED_AntiCutFail_GetValue()           PORTBbits.RB5
#define LED_AntiCutFail_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define LED_AntiCutFail_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define LED_AntiCutFail_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define LED_AntiCutFail_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define LED_AntiCutFail_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define LED_AntiCutFail_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set LED_ReflexCon aliases
#define LED_ReflexCon_TRIS                 TRISCbits.TRISC0
#define LED_ReflexCon_LAT                  LATCbits.LATC0
#define LED_ReflexCon_PORT                 PORTCbits.RC0
#define LED_ReflexCon_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define LED_ReflexCon_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define LED_ReflexCon_Toggle()             do { LATCbits.LATC0 = (unsigned)~LATCbits.LATC0; } while(0)
#define LED_ReflexCon_GetValue()           PORTCbits.RC0
#define LED_ReflexCon_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define LED_ReflexCon_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)

// get/set LED_ReflexBlocked aliases
#define LED_ReflexBlocked_TRIS                 TRISCbits.TRISC1
#define LED_ReflexBlocked_LAT                  LATCbits.LATC1
#define LED_ReflexBlocked_PORT                 PORTCbits.RC1
#define LED_ReflexBlocked_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define LED_ReflexBlocked_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define LED_ReflexBlocked_Toggle()             do { LATCbits.LATC1 = (unsigned)~LATCbits.LATC1; } while(0)
#define LED_ReflexBlocked_GetValue()           PORTCbits.RC1
#define LED_ReflexBlocked_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define LED_ReflexBlocked_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)

// get/set LED_AntiCutDrive aliases
#define LED_AntiCutDrive_TRIS                 TRISCbits.TRISC2
#define LED_AntiCutDrive_LAT                  LATCbits.LATC2
#define LED_AntiCutDrive_PORT                 PORTCbits.RC2
#define LED_AntiCutDrive_ANS                  ANSELCbits.ANSC2
#define LED_AntiCutDrive_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define LED_AntiCutDrive_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define LED_AntiCutDrive_Toggle()             do { LATCbits.LATC2 = (unsigned)~LATCbits.LATC2; } while(0)
#define LED_AntiCutDrive_GetValue()           PORTCbits.RC2
#define LED_AntiCutDrive_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define LED_AntiCutDrive_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define LED_AntiCutDrive_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define LED_AntiCutDrive_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set LED_Detonator aliases
#define LED_Detonator_TRIS                 TRISCbits.TRISC3
#define LED_Detonator_LAT                  LATCbits.LATC3
#define LED_Detonator_PORT                 PORTCbits.RC3
#define LED_Detonator_ANS                  ANSELCbits.ANSC3
#define LED_Detonator_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define LED_Detonator_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define LED_Detonator_Toggle()             do { LATCbits.LATC3 = (unsigned)~LATCbits.LATC3; } while(0)
#define LED_Detonator_GetValue()           PORTCbits.RC3
#define LED_Detonator_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define LED_Detonator_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define LED_Detonator_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define LED_Detonator_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set LED_Bat aliases
#define LED_Bat_TRIS                 TRISCbits.TRISC4
#define LED_Bat_LAT                  LATCbits.LATC4
#define LED_Bat_PORT                 PORTCbits.RC4
#define LED_Bat_ANS                  ANSELCbits.ANSC4
#define LED_Bat_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define LED_Bat_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define LED_Bat_Toggle()             do { LATCbits.LATC4 = (unsigned)~LATCbits.LATC4; } while(0)
#define LED_Bat_GetValue()           PORTCbits.RC4
#define LED_Bat_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define LED_Bat_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define LED_Bat_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define LED_Bat_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set LED_AntiCutPass aliases
#define LED_AntiCutPass_TRIS                 TRISCbits.TRISC5
#define LED_AntiCutPass_LAT                  LATCbits.LATC5
#define LED_AntiCutPass_PORT                 PORTCbits.RC5
#define LED_AntiCutPass_ANS                  ANSELCbits.ANSC5
#define LED_AntiCutPass_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define LED_AntiCutPass_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define LED_AntiCutPass_Toggle()             do { LATCbits.LATC5 = (unsigned)~LATCbits.LATC5; } while(0)
#define LED_AntiCutPass_GetValue()           PORTCbits.RC5
#define LED_AntiCutPass_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define LED_AntiCutPass_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define LED_AntiCutPass_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define LED_AntiCutPass_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()               do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()                do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()                do { LATCbits.LATC6 = (unsigned)~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()       do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()      do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetAnalogMode()         do { ANSELCbits.ANSC6 = 1; } while(0)
#define RC6_SetDigitalMode()        do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()               do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()                do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()                do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()              PORTCbits.RC7
#define RC7_SetDigitalInput()       do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()      do { TRISCbits.TRISC7 = 0; } while(0)
#define RC7_SetAnalogMode()         do { ANSELCbits.ANSC7 = 1; } while(0)
#define RC7_SetDigitalMode()        do { ANSELCbits.ANSC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/
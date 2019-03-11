/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Fidelity Cashmaster

  @File Name
    timers.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#ifndef _TIMERS_H    /* Guard against multiple inclusion */
#define _TIMERS_H


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */
//#include "../app/wasp.h"

/* This section lists the other files that are included in this file.
 */
#include "../../mcc_generated_files/mcc.h"



/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Constants                                                         */
/* ************************************************************************** */
/* ************************************************************************** */

#define MAXTIMERS 8

#define TMR0_granularity 2

#define	 TIMERS_INTERVAL_100MS	10

#define  TIMERS_MS_100         (10)
#define  TIMERS_MS_200         (TIMERS_MS_100*2u)
#define  TIMERS_MS_300         (TIMERS_MS_100*3u)
#define  TIMERS_MS_400         (TIMERS_MS_100*4u)
#define  TIMERS_MS_500         (TIMERS_MS_100*5u)
#define  TIMERS_MS_600         (TIMERS_MS_100*6u)
#define  TIMERS_MS_700         (TIMERS_MS_100*7u)
#define  TIMERS_MS_800         (TIMERS_MS_100*8u)
#define  TIMERS_MS_900         (TIMERS_MS_100*9u)
#define  TIMERS_MS_1000        (TIMERS_MS_100*10u)							// 10
#define  TIMERS_MS_1200        (TIMERS_MS_100*12u)
#define  TIMERS_MS_1400        (TIMERS_MS_100*14u)
#define  TIMERS_MS_1500        (TIMERS_MS_100*15u)

#define  TIMERS_SEC_1          (TIMERS_MS_1000)								// 10
#define  TIMERS_SEC_1_5        (TIMERS_MS_1000 + TIMERS_MS_500)
#define  TIMERS_SEC_2          (TIMERS_MS_1000*2u)
#define  TIMERS_SEC_2_5        (TIMERS_SEC_2 + TIMERS_MS_500)
#define  TIMERS_SEC_3          (TIMERS_MS_1000*3u)
#define  TIMERS_SEC_4          (TIMERS_MS_1000*4u)
#define  TIMERS_SEC_4_5        (TIMERS_SEC_4 + TIMERS_MS_500)
#define  TIMERS_SEC_5          (TIMERS_MS_1000*5u)
#define  TIMERS_SEC_6          (TIMERS_MS_1000*6u)
#define  TIMERS_SEC_6_2        (TIMERS_SEC_6 + TIMERS_MS_200)
#define  TIMERS_SEC_8          (TIMERS_MS_1000*8u)
#define  TIMERS_SEC_10         (TIMERS_MS_1000*10u)
#define  TIMERS_SEC_15         (TIMERS_MS_1000*15u)
#define  TIMERS_SEC_20         (TIMERS_MS_1000*20u)
#define  TIMERS_SEC_25         (TIMERS_MS_1000*25u)
#define  TIMERS_SEC_30         (TIMERS_MS_1000*30u)
#define  TIMERS_SEC_40         (TIMERS_MS_1000*40u)
#define  TIMERS_SEC_50         (TIMERS_MS_1000*50u)
#define  TIMERS_SEC_60         (TIMERS_MS_1000*60u)							// 600
#define  TIMERS_SEC_70         (TIMERS_MS_1000*70u)
#define  TIMERS_SEC_90         (TIMERS_MS_1000*90u)

#define  TIMERS_MIN_1          (TIMERS_SEC_60)									// 600
#define  TIMERS_MIN_2          (TIMERS_MIN_1 * 2u)
#define  TIMERS_MIN_3          (TIMERS_MIN_1 * 3u)
#define  TIMERS_MIN_4          (TIMERS_MIN_1 * 4u)
#define  TIMERS_MIN_5          (TIMERS_MIN_1 * 5u)
#define  TIMERS_MIN_7          (TIMERS_MIN_1 * 7u)


// for 32bit timers
#define  TIMERS_MIN_10         (TIMERS_MIN_1 * 10ul)
#define  TIMERS_MIN_15         (TIMERS_MIN_1 * 15ul)
#define  TIMERS_MIN_20         (TIMERS_MIN_1 * 20ul)
#define  TIMERS_MIN_30         (TIMERS_MIN_1 * 30ul)
#define  TIMERS_MIN_40         (TIMERS_MIN_1 * 40ul)
#define  TIMERS_MIN_50         (TIMERS_MIN_1 * 50ul)
#define  TIMERS_MIN_60         (TIMERS_MIN_1 * 60ul)							// 36,000

#define  TIMERS_HOUR_2         (TIMERS_MIN_60 * 2ul)
#define  TIMERS_HOUR_3         (TIMERS_MIN_60 * 3ul)
#define  TIMERS_HOUR_4         (TIMERS_MIN_60 * 4ul)
#define  TIMERS_HOUR_5         (TIMERS_MIN_60 * 5ul)
#define  TIMERS_HOUR_10        (TIMERS_MIN_60 * 10ul)						// 360,000
#define  TIMERS_HOUR_24        (TIMERS_MIN_60 * 24ul)

#define  TIMERS_DAY_1          (TIMERS_HOUR_24)
#define  TIMERS_DAY_2          (TIMERS_HOUR_24 * 2ul)
#define  TIMERS_DAY_3          (TIMERS_HOUR_24 * 3ul)
#define  TIMERS_DAY_4          (TIMERS_HOUR_24 * 4ul)
#define  TIMERS_DAY_5          (TIMERS_HOUR_24 * 5ul)
#define  TIMERS_DAY_6          (TIMERS_HOUR_24 * 6ul)
#define  TIMERS_DAY_7          (TIMERS_HOUR_24 * 7ul)

#define TIMERS_SEC_PER_MIN		(60)
#define TIMERS_SEC_PER_HOUR		(TIMERS_SEC_PER_MIN*60)
#define TIMERS_SEC_PER_DAY		(TIMERS_SEC_PER_HOUR*24)



// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************

/*  A brief description of a section can be given directly below the section
	banner.
 */

    

// *****************************************************************************
// *****************************************************************************
// Section: Interface Functions
// *****************************************************************************
// *****************************************************************************

    void TIMERS_Initialize(); // create initial timer chain
    
	uint8_t TIMERS_u8GetTicksNow(void);
	uint8_t TIMERS_u8CalcTickDiff(uint8_t u8PreviousTick);
	uint16_t TIMERS_u16GetTicksNow(void);
	uint16_t TIMERS_u16CalcTickDiff(uint16_t u16PreviousTick);
	uint32_t TIMERS_u32GetTicksNow(void);
	uint32_t TIMERS_u32CalcTickDiff(uint32_t u32PreviousTick);
	
#endif /* _TIMERS_H */

/* *****************************************************************************
 End of File
 */

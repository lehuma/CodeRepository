/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Fidelity Cashmaster

  @File Name
    nf.c

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

//#define THIS_CLASS						DIAG_NF_CLASS

/* This section lists the other files that are included in this file.
 */

/* TODO:  Include other files here if needed. */
#include <xc.h>
#include <string.h>
#include "APP/app.h"
#include "General/general.h"
#include "../mcc_generated_files/mcc.h"

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */
#define FLASH_SUPERFAST 	15 // *10ms
#define FLASH_FAST      	25 // * 10ms
#define FLASH_FAST_OFF  	25
#define FLASH_SLOW      	150 // * 10ms
#define FLASH_SLOW_OFF  	250

#define HEARTBEAT_TIME      200 		// * 100ms

//void PollSlaveBoard(void);


schedule_t heartbeatSchedule;
char msgHeartbeat[] = "Hello world!\n\r";
char readBuffer[READBUFLEN];

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Local function prototypes                                         */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */
void SendHeartbeatMsg(void);
 
/* ************************************************************************** */
/* ************************************************************************** */
// Section: Interface Functions                                               */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

void main (void)
{
   // initialize the device
    SYSTEM_Initialize();
    
	APP_Initialize();
    SCHEDULE_Subscribe(&heartbeatSchedule,READ_VOLTAGE_TIME,SendHeartbeatMsg);

    SCHEDULE_Start();

    while (1)
    {
        // Add your application code
        SCHEDULE_Process();
		//DIO_Manager();
    }
}

 
 
 
/* ************************************************************************** */
/* ************************************************************************** */
// Section: Local Functions                                                   */
/* ************************************************************************** */
/* ************************************************************************** */


void SendHeartbeatMsg(void)
{
    SERIAL_WriteBuffer(msgHeartbeat,strlen(msgHeartbeat));
}
//*/

 
/* *****************************************************************************
 End of File
 */


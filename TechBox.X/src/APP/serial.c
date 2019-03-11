/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Fidelity Cashmaster

  @File Name
    serial.c

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
#include "../Wrapper/wrapper.h"
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

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Local function prototypes                                         */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

 
 
/* ************************************************************************** */
/* ************************************************************************** */
// Section: Interface Functions                                               */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */
extern char readBuffer[READBUFLEN];

void SERIAL_WriteBuffer(char *s, unsigned int length)
{
    unsigned int index = 0;
    
	if(UART1_isTxReady())
	{
		while (index < length)
		{
			UART1_WriteByte(s[index]);
			index++;
		}
	}
}
#if 0
unsigned int SERIAL_ReadBuffer(char *buffer)
{
//    char myBuffer[MY_BUFFER_SIZE];
    unsigned int numBytes;//, terminate = UART2_TransferStatusGet();
    //char *p = buffer;

    numBytes = 0;

    while ((numBytes < READBUFLEN)) //*&& (terminate & UART2_TRANSFER_STATUS_RX_EMPTY != UART2_TRANSFER_STATUS_RX_EMPTY)*)
    {
        /*if( UART2_TRANSFER_STATUS_RX_DATA_PRESENT & UART2_TransferStatusGet() )
        {
            *p++ = UART2_Read();
            numBytes++;
        }
        else
        {
            break;
        }
        terminate = UART2_TransferStatusGet();*/
    }
    return numBytes;
}
#endif
//*/

 
 
 
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


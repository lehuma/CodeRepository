/* ********************************************************************************* */
/* Copyright : © Netstar (Pty) Limited, 2007                                         */
/*             All rights reserved. No part of this publication may be reproduced,   */
/*             stored in a retrieval system, or transmitted in any form or by any    */
/*             means, electronic, mechanical,photocopying, recording, or otherwise,  */
/*             without the prior written permission of Netstar (Pty) Limited.        */
/*                                                                                   */
/*                                                                                   */
/* Module :  typedef.h                                                               */
/*                                                                                   */
/* Purpose : typedef definitions                                                     */
/*                                                                                   */
/* Created : D. de Gouveia                                                           */
/*                                                                                   */
/* Date Created: 2007/04/12                                                          */
/*                                                                                   */
/* Compiler: OPEN-AT Version 4.13                                                    */
/*                                                                                   */
/* Target processor:  Wavecom Q2686 Gsm Module                                       */
/*                                                                                   */
/* ***********************************************************************************/

#ifndef _TYPEDEF_H_
#define _TYPEDEF_H_

#include "../../mcc_generated_files/mcc.h"


#define VOID			void
#define GLOBAL			extern
#define LOCAL			static


//==================== GLOBAL CONSTANT DEFINITIONS ============================

#define VALID_BEGIN	0x55
#define VALID_END		0xAA

#define ENABLE			(1u)
#define DISABLE		(0u)

#define ON				(1u)
#define OFF				(0u)


#ifndef TRUE
#define TRUE			(1u)
#endif
#ifndef FALSE
#define FALSE			(0u)
#endif
//*/

//#define HIGH			(1u)
//#define LOW				(0u)

#define BIT0			(0x0001u)
#define BIT1			(0x0002u)
#define BIT2			(0x0004u)
#define BIT3			(0x0008u)
#define BIT4			(0x0010u)
#define BIT5			(0x0020u)
#define BIT6			(0x0040u)
#define BIT7			(0x0080u)
#define BIT8			(0x0100u)
#define BIT9			(0x0200u)
#define BIT10			(0x0400u)
#define BIT11			(0x0800u)
#define BIT12			(0x1000u)
#define BIT13			(0x2000u)
#define BIT14			(0x4000u)
#define BIT15			(0x8000u)

#define SETBIT_0		(0x01)
#define SETBIT_1		(0x02)
#define SETBIT_2		(0x04)
#define SETBIT_3		(0x08)
#define SETBIT_4		(0x10)
#define SETBIT_5		(0x20)
#define SETBIT_6		(0x40)
#define SETBIT_7		(0x80)

#define CLRBIT_0		(0xFE)
#define CLRBIT_1		(0xFD)
#define CLRBIT_2		(0xFB)
#define CLRBIT_3		(0xF7)
#define CLRBIT_4		(0xEF)
#define CLRBIT_5		(0xDF)
#define CLRBIT_6		(0xBF)
#define CLRBIT_7		(0x7F)

#define ClrBit(x)		(x = x & x##_CLR)
#define SetBit(x)		(x = x | x##_SET)
#define ChgBit(x)		(x = x ^ x##_CHG)


#define NO_INIT		__no_init
#define CODE			const
#define FLASH			const

#define NAK				(0x15)
#define ACK				(0x06)
#define EOT				(0x04)
#define STX				(0x02)

#ifndef NULL
#define NULL			(0)
#endif


//==================== GLOBAL TYPE DEFINITIONS ================================

/*
//WAVECOM DEFINITIONS:
typedef unsigned char   bool;
typedef unsigned char   u8;
typedef signed   char   s8;
typedef          char   ascii;
typedef unsigned short  u16;
typedef          short  s16;
typedef unsigned int    u32;
typedef          int    s32; 
*/

//DANNY DEFINITIONS:
#define BYTE   		unsigned 	char	
#define SCHAR  		signed 		char		
#define INT    		short				
#define WORD   		unsigned 	short	
#define ULONG  		unsigned 	int		
#define LONGINT		int					
#define BOOL   		bool				
#define REAL   		float				

//JOHANN DEFINITIONS:
typedef				char			CHAR;
typedef	signed		char			INT8S;
typedef	unsigned	char			INT8U;
typedef	signed		short			INT16S;
typedef	unsigned	short			INT16U;
typedef	signed		long			INT32S;
typedef	unsigned	long			INT32U;
//typedef	signed		long long		INT64S;
//typedef	unsigned	long long		INT64U;

//FUNCTION-POINTER TYPE DEFINITIONS
typedef VOID (*VOID_VOID_FP)(VOID);		//function ptr with void parameters returning void
typedef VOID (*VOID_BOOL_FP)(INT8U/*BOOL*/);		//function ptr

typedef union WB_T
{
  WORD Word;
  BYTE Byte[2];
} WB;

typedef union IB_T
{
  INT sword;
  BYTE Byte[2];
} IB;

typedef union PACKED_LONG_T
{
  ULONG  ulong;
  WB     word[2];
} PACKED_LONG;

typedef union PACKED_ILONG_T
{
  LONGINT  ilong;
  IB     sword[2];
} PACKED_ILONG;


//==================== GLOBAL MACRO DEFINITIONS ===============================
#define DIVIDE_BY_2(X)      (BYTE)((X) >> 1u)
#define DIVIDE_BY_8(X)      (BYTE)((X) >> 3u)
#define WORD_DIVIDE_BY_8(X) ((X) >> 3u)
#define DIVIDE_BY_16(X)     (BYTE)((X) >> 4u)
#define MULTIPLY_BY_16(X)   (ULONG)((X) << 4u)
#define GET_MOD_2(X)        (BYTE)((BYTE)(X) & 0x1u)
#define GET_MOD_8(X)        (BYTE)((BYTE)(X) & 0x7u)
#define GET_MOD_16(X)       (BYTE)((BYTE)(X) & 0xfu)


#define HiByte Byte[1]
#define LoByte Byte[0]

#define Swap(x) ((((x) & 0x00FFu) << 8u)) + ((((x) & 0xFF00u) >> 8u)) 

#define HiWord word[0]
#define LoWord word[1]


#define HiSword sword[0]
#define LoSword sword[1]


#define HI(x) ((BYTE)((x) >> 8))
#define LO(x) ((BYTE)((x) & 0xFFu))


#define sizeoflist(x) (sizeof((x))/sizeof(((x)[0])))


#define Filter(x,y,z) (((y)>(x))?           \
((x) = (y - HI( (z) * ((y) - (x)) ))):      \
((x) = (y + HI( (z) * ((x) - (y)) ))))


#endif
// ********************************** end/einde/fin ************************************************

/* ********************************************************************************* */
/* Copyright :	© Fidelity Security                                                  */
/*              All rights reserved. No part of this publication may be reproduced,  */
/*              stored in a retrieval system, or transmitted in any form or by any   */
/*              means, electronic, mechanical,photocopying, recording, or otherwise, */
/*              without the prior written permission of Fidelity Security.           */
/*                                                                                   */
/*                                                                                   */
/* Module :  mystring.c                                                              */
/*                                                                                   */
/* Purpose : General string routines                                                 */
/*                                                                                   */
/* Created : Peter TL Nthite                                                         */
/*                                                                                   */
/* Date Created: 2008/04/12                                                          */
/*                                                                                   */
/* ***********************************************************************************/

#ifndef _MYSTRING_C_
#define _MYSTRING_C_


// ****************************************************************************************
// ****************************************************************************************
// Include files
// ****************************************************************************************
// ****************************************************************************************

#include "typedef.h"
#include "mystring.h"

#define DONT_COMPILE	0


//#include "mymath.h"
//
//
//1. In the wmnew script addiotional options write the path to include library file as given below: 
//Example: 
//In Open AT Project Wizard in "wmnew script additional options" window write: 
//-inc "C:\OpenAT\Tools\GCC\arm-elf\lib" 
//
//Click OK 
//
//2. Go to the project directory and open the mak file <MyProject.mak> with WordPad. In the file there is a option for library list: 
//Code: 
//EXTERNAL_LIB_LIST = \ 
//
//
//After that line, add a line with library path. For me this look like this: 
//Code: 
//EXTERNAL_LIB_LIST = \ 
///cygdrive/C/OpenAT/Tools/GCC/arm-elf/lib/thumb/interwork/libm.a \ 
//
//That's it. Now for Target Mode will work all math functions.
//
//
//

#if DONT_COMPILE

#endif
//*****************************************************************
// <Function> : convert char to ascii
// <Input>  : in_char = char to convert, bDigits1 = lsd, bDigits2 = msd
// <Output> : e.g. n_char = 45 then bDigits2 = '4' and bDigits1 = '5'
// <Return> : none
//*****************************************************************
VOID MYSTRING_word_to_ascii(INT16U wInWord, INT8U *bpDig, INT8U size)
{
	INT16U remainder = 0;

	if (wInWord >= 10000)
	{
		bpDig[0] = (wInWord / 10000) + '0';

		remainder = wInWord % 10000;
		bpDig[1] = (remainder / 1000) + '0';

		remainder = wInWord % 1000;
		bpDig[2] = (remainder / 100) + '0';

		remainder = wInWord % 100;
		bpDig[3] = (remainder / 10) + '0';

		remainder = wInWord % 10;
		bpDig[4] = (remainder)+'0';
	}
	else if (wInWord >= 1000)
	{
		bpDig[0] = (wInWord / 1000) + '0';

		remainder = wInWord % 1000;
		bpDig[1] = (remainder / 100) + '0';

		remainder = wInWord % 100;
		bpDig[2] = (remainder / 10) + '0';

		remainder = wInWord % 10;
		bpDig[3] = (remainder) + '0';
	}
	else if (wInWord >= 100)
	{
		bpDig[0] = (wInWord / 100) + '0';

		remainder = wInWord % 100;
		bpDig[1] = (remainder / 10) + '0';

		remainder = wInWord % 10;
		bpDig[2] = (remainder) + '0';
	}
	else if (wInWord >= 10)
	{
		bpDig[0] = (wInWord / 10) + '0';

		remainder = wInWord % 10;
		bpDig[1] = (remainder) + '0';
	}
	else
	{
		bpDig[0] = wInWord + '0';
	}
}


//*****************************************************************
// <Function> : copy 0x00 terminated src string to dest string
// <Input>  : src pointer, dest pointer
// <Output> : None
// <Return> : None
//*****************************************************************
VOID MYSTRING_StrCopy(BYTE *bpDestString, BYTE *bpSrcString, WORD wLen)
{
	WORD wIndex;

	wIndex = 0u;

	if((bpDestString != NULL)
	&& (bpSrcString != NULL))
	{
		while((bpSrcString[wIndex] != 0x00) && (wIndex < wLen))
		{
			bpDestString[wIndex] = bpSrcString[wIndex];
			wIndex++;
		}

		bpDestString[wIndex] = 0x00;
	}
}


//*****************************************************************
// <Function> : cat 0x00 terminated src string to dest string
// <Input>  : src pointer, dest pointer
// <Output> : None
// <Return> : None
//*****************************************************************
VOID MYSTRING_StrCat(BYTE *bpDestString, BYTE *bpSrcString)
{
	WORD wIndex;
	WORD wOffset;

	wIndex = 0u;

	if((bpDestString != NULL)
	&& (bpSrcString != NULL))
	{
		while(bpDestString[wIndex] != 0x00)
		{
			wIndex++;
		}

		wOffset = wIndex;
		wIndex = 0u;

		while(bpSrcString[wIndex] != 0x00)
		{
			bpDestString[(wOffset+wIndex)] = bpSrcString[wIndex];
			wIndex++;
		}

		bpDestString[(wOffset+wIndex)] = 0x00;
	}
}

#if DONT_COMPILE
BOOL MYSTRING_IsDigits(CHAR* src_s)
{
	INT8U		i;
	
	while( (*src_s != '\0') && (*src_s >= '0') && (*src_s <= '9') )
	{
		src_s++;
	}
	if(*src_s == '\0')	return(TRUE);
	else						return(FALSE);
}


//*****************************************************************
// <Function> : Tests whether the character is a decimal digit in uppercase or lowercase, that is, one of 0–9.
// <Input>  : Character
// <Output> : None
// <Return> : True/False
//*****************************************************************
BOOL MYSTRING_fIsDigit(BYTE bByte)
{
	BOOL fReturnStatus;

	if((bByte >= '0') && (bByte <= '9'))
	{
		fReturnStatus = TRUE;
	}
	else
	{
		fReturnStatus = FALSE;
	}

	return(fReturnStatus);
}


//*****************************************************************
// <Function> : Tests whether the character is a hexadecimal digit in uppercase or lowercase, that is, one of 0–9, a–f, or A–F.
// <Input>  : Character
// <Output> : None
// <Return> : True/False
//*****************************************************************
BOOL MYSTRING_fIsXdigit(BYTE bByte)
{
	BOOL fReturnStatus;

	if((bByte >= '0') && (bByte <= '9'))
	{
		fReturnStatus = TRUE;
	}
	else if((bByte >= 'A') && (bByte <= 'F'))
	{
		fReturnStatus = TRUE;
	}
	else if((bByte >= 'a') && (bByte <= 'f'))
	{
		fReturnStatus = TRUE;
	}
	else
	{
		fReturnStatus = FALSE;
	}

	return(fReturnStatus);
}

//*****************************************************************
// <Function> : convert char to ascii
// <Input>  : in_char = char to convert, bDigits1 = lsd, bDigits2 = msd
// <Output> : e.g. n_char = 45 then bDigits2 = '4' and bDigits1 = '5'
// <Return> : none
//*****************************************************************
void MYSTRING_char_to_ascii(unsigned char bInChar, unsigned char *bpDig)
{
	if(bpDig == NULL)
		return;
		
	bpDig[0] = 0;
	bpDig[1] = 0;
	bpDig[2] = 0;

	if ((bInChar >= 100u)/* && (bInChar <= (BYTE)(255u))*/)
	{
		unsigned char remainder = (unsigned char)(bInChar % 100);
		bpDig[0] = (unsigned char)(bInChar / 100);
		bpDig[1] = (unsigned char)(remainder / 10);
		bpDig[2] = (unsigned char)(remainder - (unsigned char)(10 * (unsigned char)(bpDig[1])) + '0');
	}
	else if (bInChar > 9)
	{
		bpDig[0] = (unsigned char)(bInChar / 10);
		bpDig[1] = (unsigned char)(bInChar - (10 * (bpDig[0])));
	}
	else
	{
		bpDig[1] = bInChar;
		bpDig[0] = 0;
	}

	bpDig[0] += '0';
	bpDig[1] += '0';
}

//*****************************************************************
// <Function> : convert nibble to hex
// <Input>  : nibble to convert
// <Output> : None
// <Return> : Hex Byte e.g. n_char = 0x0A , return = 'A'
//*****************************************************************
BYTE MYSTRING_Nibble_to_ascii_hex(BYTE bInNibble)
{
	bInNibble = (unsigned char)(bInNibble & 0x0f);

	if(bInNibble > (BYTE)(9))
	{
		bInNibble += 0x37;
	}
	else
	{
		bInNibble += '0';
	}

	return(bInNibble);
}


//*****************************************************************
//	Convert the 2 nibbles of a INT8U to a two-char string with the 2nd 
// char containing the 2nd nibble.
// <Function> : convert char to hex (2*ascii bDigitsits)
// <Input>	source			: in_char = char to convert, bDigits1 = lsd, bDigits2 = msd
// <Output> dest (*bpDig)	: e.g. n_char = 0x4A then bDigits1 = '4' and bDigits2 = 'A'
// <Return> : none
//*****************************************************************
VOID MYSTRING_char_to_ascii_hex(BYTE src_char, BYTE *dest_p)
{
	dest_p[0] = (unsigned char)(src_char / 16);
	if(dest_p[0] > 9)
	{
		dest_p[0] += 0x37;	//'7'
	}
	else
	{
		dest_p[0] += '0';
	}
	
	dest_p[1] = (unsigned char)(src_char & 0x0f);
	
	if(dest_p[1] > 9)
	{
		dest_p[1] += 0x37;
	}
	else
	{
		dest_p[1] += '0';
	}
}	//end MYSTRING_char_to_ascii_hex()


//*****************************************************************
// <Function> : convert word to hex (4*ascii bDigitsits)
// <Input>  : in_char = char to convert, bDigits1 = lsd, bDigits2 = msd
// <Output> : e.g. word = 0x4A then bDigits1 = '4' and bDigits2 = 'A'
// <Return> : none
//*****************************************************************
VOID MYSTRING_word_to_ascii_hex(WORD wInWord, BYTE *bpDig, BYTE bDigits)
{
	if(bDigits >= 4)
	{
		bpDig[0] = (BYTE)((wInWord / 4096u) & 0x0f);

		if(bpDig[0] > 9)
		{
			bpDig[0] += 0x37;
		}
		else
		{
			bpDig[0] += '0';
		}

		bpDig[1] = (BYTE)((wInWord / 256u) & 0x0f);

		if(bpDig[1] > 9)
		{
			bpDig[1] += 0x37;
		}
		else
		{
			bpDig[1] += '0';
		}


		bpDig[2] = (BYTE)((wInWord / 16u) & 0x0f);

		if(bpDig[2] > 9)
		{
			bpDig[2] += 0x37;
		}
		else
		{
			bpDig[2] += '0';
		}

		bpDig[3] = (BYTE)(wInWord & 0x0f);

		if(bpDig[3] > 9)
		{
			bpDig[3] += 0x37;
		}
		else
		{
			bpDig[3] += '0';
		}
	}
	else
	{
		bpDig[0] = (BYTE)((wInWord / 256u) & 0x0f);

		if(bpDig[0] > 9)
		{
			bpDig[0] += 0x37;
		}
		else
		{
			bpDig[0] += '0';
		}


		bpDig[1] = (BYTE)((wInWord / 16u) & 0x0f);

		if(bpDig[1] > 9)
		{
			bpDig[1] += 0x37;
		}
		else
		{
			bpDig[1] += '0';
		}

		bpDig[2] = (BYTE)(wInWord & 0x0f);

		if(bpDig[2] > 9)
		{
			bpDig[2] += 0x37;
		}
		else
		{
			bpDig[2] += '0';
		}
	}
}


//*****************************************************************
// <Function> : convert long to hex (8*ascii bDigitsits)
// <Input>  : in_char = char to convert, bDigits1 = lsd, bDigits2 = msd
// <Output> : e.g. word = 0x4A then bDigits1 = '4' and bDigits2 = 'A'
// <Return> : none
//*****************************************************************
VOID MYSTRING_long_to_ascii_hex(ULONG ulInLong, BYTE *bpDig)
{
	MYSTRING_word_to_ascii_hex(((WORD)(ulInLong>>16u)), bpDig, 4);
	bpDig += 4;
	MYSTRING_word_to_ascii_hex(((WORD)ulInLong), bpDig, 4);
}


//*****************************************************************
// <Function> : convert hex ascii to char  (opposite of char_to_ascii_hex)
// <Input>  : bDigits2 = lsd, bDigits1 = msd
// <Output> : bDigits1 = '4' and bDigits2 = 'A' return = 0x4a
// <Return> : hex byte
//*****************************************************************
BYTE MYSTRING_ascii_hex_to_char(BYTE bDig1, BYTE bDig2)
{
	BYTE bOutChar;

	bDig1 -= '0';

	if(bDig1 > 9)      //ABCDEF
	{
		bDig1 -= 7;
		bDig1 &= 0x0f; 	//abcdef
	}
	
	bOutChar = (unsigned char)((bDig1) * 16);

	bDig2 -= '0';

	if(bDig2 > 9)      //ABCDEF
	{
		bDig2 -= 7;
		bDig2 &= 0x0f;  //abcdef
	}
				
	bOutChar |= bDig2;

	return(bOutChar);
}


//*****************************************************************
// <Function> : convert 2 ascii characters to char  (opposite of char_to_ascii)
// <Input>  : bDigits2 = lsd, bDigits1 = msd
// <Output> : bDigits1 = '4' and bDigits2 = '9' return = 49
// <Return> : byte
//*****************************************************************
BYTE MYSTRING_ascii_to_char(BYTE bDig1, BYTE bDig2)
{
	BYTE bOutChar;

	if(bDig1 < '0')
	{
		bDig1 = '0';
	}

	bDig1 -= '0';
	bOutChar = (unsigned char)((bDig1) * (unsigned char)10);

	if(bDig2 >= '0')
	{
		bDig2 -= '0';

		bOutChar += bDig2;
	}

	return(bOutChar);
}


//*****************************************************************
// <Function> : convert 2 ascii characters to char  (opposite of char_to_ascii)
// <Input>  : bDigits2 = lsd, bDigits1 = msd
// <Output> : bDigits1 = '4' and bDigits2 = '9' return = 0x49
// <Return> : byte
//*****************************************************************
BYTE MYSTRING_ascii_to_hex(BYTE bDig1, BYTE bDig2)
{
	BYTE bOutChar;

	if(bDig1 < '0')
	{
		bDig1 = '0';
	}

	bDig1 -= '0';
	bOutChar = (unsigned char)((bDig1) << 4);

	if(bDig2 >= '0')
	{
		bDig2 -= '0';

		bOutChar += bDig2;
	}

	return(bOutChar);
}


//*****************************************************************
// <Function> : convert BCD to char
// <Input>  : BCD char
// <Output> : None
// <Return> : byte
//*****************************************************************
BYTE MYSTRING_bcd_to_char(BYTE bBcd)
{
	BYTE bTempChar;
	
	bTempChar = (unsigned char)((bBcd & 0xf0) >> 4);
	bTempChar *= 10;
	bTempChar += (unsigned char)(bBcd & (unsigned char)0x0f);

	return(bTempChar);		
}


//*****************************************************************
// <Function> : convert char to BCD
// Convert 1 byte hex value to BCD ConvHexToBcd()
// <Input>  : Byte
// <Output> : None
// <Return> : BCD char
//*****************************************************************
BYTE MYSTRING_char_to_bcd(BYTE bChar)
{
	BYTE bTempBcd;
	
	bTempBcd = (unsigned char)(bChar / 10);
	bChar -= (unsigned char)(bTempBcd * 10);
	bTempBcd <<= 4;
	bTempBcd |= bChar;

	return(bTempBcd);		
}


//*****************************************************************
// <Function> : Count chars in string
// <Input>  : src pointer
// <Output> : None
// <Return> : Nr Chars
//*****************************************************************
WORD MYSTRING_wStrlen(BYTE *bpSrcString)
{
	WORD wIndex;

	wIndex = 0u;

	if(bpSrcString != NULL)
	{
		while((bpSrcString[wIndex] != 0x00) && (wIndex < 500u))
		{
			wIndex++;
		}
	}
	return(wIndex);
}


//*****************************************************************
// <Function> : Set dest array to data byte value
// <Input>  : dest pointer, data byte, length
// <Output> : init array to value
// <Return> : None
//*****************************************************************
VOID MYSTRING_MemSet(BYTE *bpDestString, BYTE bDataByte, WORD wLen)
{
	WORD wIndex;

	wIndex = 0u;

	if(bpDestString != NULL)
	{
		while(wIndex < wLen)
		{
			bpDestString[wIndex++] = bDataByte;
		}
	}
}


//*****************************************************************
// <Function> : src string to dest string
// <Input>  : src pointer, dest pointer
// <Output> : None
// <Return> : None
//*****************************************************************
VOID MYSTRING_MemCopy(BYTE *bpDestString, BYTE  *bpSrcString, WORD wLen)
{
	WORD wIndex;

	wIndex = 0u;

	if(	(bpDestString != NULL)
		&&	(bpSrcString != NULL)	)
	{
		while(wIndex < wLen)
		{
			bpDestString[wIndex] = bpSrcString[wIndex];
			wIndex++;
		}
	}
}


//*****************************************************************
// <Function> : compare src string to dest string
// <Input>  : src pointer, dest pointer
// <Output> : None
// <Return> : TRUE/FALSE
//*****************************************************************
BOOL MYSTRING_StrCmp(BYTE *bpDestString, BYTE *bpSrcString, WORD wLen)
{
	WORD wIndex;

	wIndex = 0u;

	if((bpDestString != NULL)
	&& (bpSrcString != NULL))
	{
		while((bpDestString[wIndex] == bpSrcString[wIndex]) && (wIndex < wLen))
		{
			wIndex++;
		}

		if(wIndex == wLen)
		{
			return(TRUE);
		}
		else
		{
			return(FALSE);
		}
	}
	return(FALSE);
}


//*****************************************************************
// <Function> : find next matching byte in src string (max 254 search bytes allowed)
// <Input>  : zero terminated src pointer, search byte
// <Output> : None
// <Return> : NULL/next match address
//*****************************************************************
BYTE * MYSTRING_bpStrChr(BYTE *bpDestString, BYTE bSrcByte)
{
	WORD wIndex;

	if(bpDestString != NULL)
	{
		wIndex = 0u;

		while((bpDestString[wIndex] != 0x00) && (bpDestString[wIndex] != bSrcByte))
		{
			wIndex++;
		}

		if(bpDestString[wIndex] != 0x00)
		{
			return(&bpDestString[wIndex]);
		}
		else
		{
			return(NULL);
		}
	}
	else
	{
		return(NULL);
	}
}

//*****************************************************************
// <Function> : find next matching str in src string (max 254 search bytes allowed)
// <Input>  : zero terminated src pointer, search byte
// <Output> : None
// <Return> : NULL/next match address
//*****************************************************************
BYTE * MYSTRING_bpStrStr(BYTE *bpDestString, BYTE *bSrcString)
{
	WORD i;
	WORD wIndex;
	BOOL fStatus;

	wIndex = 0u;
	fStatus = FALSE;

	if((bpDestString != NULL)
	&& (bSrcString != NULL))
	{

		do
		{
			while((bpDestString[wIndex] != 0x00) && (bpDestString[wIndex] != bSrcString[0]))
			{
				wIndex++;
			}

			if(bpDestString[wIndex] != 0x00)
			{
				fStatus = TRUE;

				for(i = 0; (bSrcString[i] != 0x00) && (fStatus == TRUE); i++)
				{
					if(bpDestString[wIndex+i] != bSrcString[i])
					{
						fStatus = FALSE;
						wIndex++;                                       // not this string, bump index along
					}
				}
			}
		}while((fStatus != TRUE) && (bpDestString[wIndex] != 0x00));

		if(fStatus == TRUE)
		{
			return(&bpDestString[wIndex]);
		}
		else
		{
			return(NULL);
		}
	}
	else
	{
		return(NULL);
	}
}

#if 0
//*****************************************************************
// <Function> : Convert string to real value
// <Input>    : string buffer
// <Output>   : None
// <Return>   : real value
//*****************************************************************
REAL MYSTRING_rStringToReal(BYTE *s)
{
	WORD p;
	WORD e;
	BYTE bCount;
	REAL y, g;
	BOOL neg, negE;


	p = 0;
	
	bCount = 0;
	while(((s[p] == ' ') || (s[p] == '0'))
	&& (bCount++ < 254))
	{
		p++;
	}
	
	
	if (s[p] == '-')
	{
		neg = TRUE;
		p++;
	}
	else
	{
		neg = FALSE;
	}
	
	bCount = 0;
	while(((s[p] == ' ') || (s[p] == '0'))
	&& (bCount++ < 254))
	{
		p++;
	}
	
	y = 0;
	
	bCount = 0;
	while((('0' <= s[p]) && (s[p] <= '9'))
	&&(bCount++ < 254))
	{
		y = (y * 10) + ((s[p]) - 0x30);
		p++;
	};
	
	if( s[p] == '.')
	{
		p++;
		g = 1;
		bCount = 0;
		while((('0' <= s[p]) && (s[p] <= '9'))
		&&(bCount++ < 254))
		{
			g = g / 10;
			y = y + (g * ((s[p]) - 0x30));
			p++;
		};
	}
	
	if ((s[p] == 'D') || (s[p] == 'E'))
	{
		p++;
		e = 0;
		
		if( s[p] == '-' )
		{
			negE = TRUE;
			p++;
		}
		else
		{
			negE = FALSE;
		}
		
		bCount = 0;
		while((s[p] == '0') && (bCount++ < 254))
		{
			p++;
		};
		
		bCount = 0;
		while((('0' <= s[p]) && (s[p] <= '9'))
		&&(bCount++ < 254))
		{
			e = (e * 10) + ((s[p]) - 0x30);
			p++;
		};
		
		if(negE)
		{
//		y = y / MYMATH_pow(10,e);
			y = (REAL)(y / pow(10,e));           
		}
		else
		{
//           y = y * MYMATH_pow(10,e);
			y = (REAL)(y * pow(10,e));
		}
	}
	
	if( neg)
	{
		y = -y;
	}
		
	return(y);
}
#endif
//*****************************************************************
// <Function> : Convert string to int value
// <Input>    : string buffer
// <Output>   : None
// <Return>   : int value
//*****************************************************************
INT MYSTRING_iStringToInt(BYTE *s)
{
	WORD p;
	INT y;
	BOOL neg;
	BYTE bCount;


	p = 0;
	
	bCount = 0;
	while(((s[p] == ' ') || (s[p] == '0'))
	&&(bCount++ < 254))
	{
		p++;
	}
	
	
	if (s[p] == '-')
	{
		neg = TRUE;
		p++;
	}
	else
	{
		neg = FALSE;
	}
	
	bCount = 0;
	while(((s[p] == ' ') || (s[p] == '0'))
	&&(bCount++ < 254))
	{
		p++;
	}
	
	y = 0;
	bCount = 0;
	
	while((('0' <= s[p]) && (s[p] <= '9'))
	&& (bCount++ < 254))
	{
		y = (y * 10) + ((s[p]) - 0x30);
		p++;
	};
	

	if( neg)
	{
		y = -y;
	}
		
	return(y);
}


//*****************************************************************
// <Function> : Convert string to longint value
// <Input>    : string buffer
// <Output>   : None
// <Return>   : int value
//*****************************************************************
LONGINT MYSTRING_liStringToLong(BYTE *s)
{
	WORD p;
	LONGINT y;
	BOOL neg;
	BYTE bCount;


	p = 0;
	
	bCount = 0;
	while(((s[p] == ' ') || (s[p] == '0'))
	&&(bCount++ < 254))
	{
		p++;
	}
	
	
	if (s[p] == '-')
	{
		neg = TRUE;
		p++;
	}
	else
	{
		neg = FALSE;
	}
	
	bCount = 0;
	while(((s[p] == ' ') || (s[p] == '0'))
	&&(bCount++ < 254))
	{
		p++;
	}
	
	y = 0;
	bCount = 0;
	
	while((('0' <= s[p]) && (s[p] <= '9'))
	&& (bCount++ < 254))
	{
		y = (y * 10) + ((s[p]) - 0x30);
		p++;
	};
	

	if( neg)
	{
		y = -y;
	}
		
	return(y);
}


//*****************************************************************
// <Function> : Convert hex string to int value
// <Input>    : string buffer
// <Output>   : None
// <Return>   : int value
//*****************************************************************
WORD MYSTRING_wHexStringToWord(BYTE *pInValue)
{
	WORD wTemp = 0;
	BYTE ucLoop;

	for (ucLoop = 0; (ucLoop < 4) ; ucLoop++)
	{
		wTemp <<= 4;

		if((*pInValue >= 'A') && (*pInValue <= 'F'))
		{
			wTemp |= (WORD)(*pInValue++ - 'A') + 0x0A;
		}
		else if ((*pInValue >= 'a') && (*pInValue <= 'f'))
		{
			wTemp |= (WORD)(*pInValue++ - 'a') + 0x0A;
		}
		else
		{
			wTemp |= (WORD)(*pInValue++ - '0');		
		}
	}
	return (wTemp);		
}


//*****************************************************************
// <Function> : Convert hex string to long value
// <Input>    : string buffer
// <Output>   : None
// <Return>   : long value
//*****************************************************************
ULONG MYSTRING_ulHexStringToLong(BYTE *pInValue)
{
	ULONG ulTemp;
	BYTE ucLoop;

	ulTemp = 0ul;

	for (ucLoop = 0; (ucLoop < 4) ; ucLoop++)
	{
		ulTemp <<= 4;

		if((*pInValue >= 'A') && (*pInValue <= 'F'))
		{
			ulTemp |= (WORD)(*pInValue++ - 'A') + 0x0A;
		}
		else if ((*pInValue >= 'a') && (*pInValue <= 'f'))
		{
			ulTemp |= (WORD)(*pInValue++ - 'a') + 0x0A;
		}
		else
		{
			ulTemp |= (WORD)(*pInValue++ - '0');		
		}
	}

	for (ucLoop = 0; (ucLoop < 4) ; ucLoop++)
	{
		ulTemp <<= 4;

		if((*pInValue >= 'A') && (*pInValue <= 'F'))
		{
			ulTemp |= (WORD)(*pInValue++ - 'A') + 0x0A;
		}
		else if ((*pInValue >= 'a') && (*pInValue <= 'f'))
		{
			ulTemp |= (WORD)(*pInValue++ - 'a') + 0x0A;
		}
		else
		{
			ulTemp |= (WORD)(*pInValue++ - '0');		
		}
	}

	return (ulTemp);		
}


//*****************************************************************
// <Function> : Convert ascii to byte value
// <Input>    : string buffer
// <Output>   : None
// <Return>   : int value
//*****************************************************************
BYTE MYSTRING_ToInt(BYTE InValue)
{
	BYTE bTemp = 0;

	if((InValue >= 'A') && (InValue <= 'F'))
	{
		bTemp |= (InValue - 'A') + 0x0A;
	}
	else if ((InValue >= 'a') && (InValue <= 'f'))
	{
		bTemp |= (InValue - 'a') + 0x0A;
	}
	else
	{
		bTemp |= (InValue - '0');		
	}

	return (bTemp);		
}

#if 0
/*===========================================================================*/
/**
\brief

\details

\param	p1		
\return			
\retval	x		

\author	
*/
/*===========================================================================*/
VOID MYSTRING_ToLower(CHAR* src_s)
{
	INT8U		i;
	
	for(i = 0; i < 250; i++)
	{
		src_s[i] = tolower(src_s[i]);
		if(src_s[i] == '\0')		return;
	}
}
#endif

//*****************************************************************
// <Function> : convert long to ascii
// <Input>    : bpDataBuffer = array to store array in, long to convert, bDigitsit = number of bDigitsits to store in
// <Output>   : None
// <Return>   : int value
//*****************************************************************
VOID MYSTRING_LongToAscii(BYTE *bpDataBuffer, ULONG ulValue, BYTE bDigits)
{
	BYTE bTempByte;
	BYTE bIndex;
	ULONG ulTempLong;


	bIndex = 0;


	if(ulValue > (ULONG)(999999999))
	{
		ulValue = (ULONG)(999999999);
	}

	ulTempLong = (ULONG)(ulValue / 100000000);
	bTempByte = (BYTE)ulTempLong;
	if(bTempByte > 9) bTempByte = 10;
		ulTempLong = (ULONG)(bTempByte * (ULONG)100000000);
	ulValue -= ulTempLong;
	if(bDigits >= 9)
		bpDataBuffer[bIndex++] = (BYTE)(bTempByte + 48);

	ulTempLong = (ULONG)(ulValue / 10000000);
	bTempByte = (BYTE)ulTempLong;
	ulTempLong = (ULONG)(bTempByte * 10000000);
	ulValue -= ulTempLong;
	if(bDigits >= 8)
		bpDataBuffer[bIndex++] = (BYTE)(bTempByte + 48);

	ulTempLong = (ULONG)(ulValue / 1000000);
	bTempByte = (BYTE)ulTempLong;
	ulTempLong = (ULONG)(bTempByte * 1000000);
	ulValue -= ulTempLong;
	if(bDigits >= 7)
		bpDataBuffer[bIndex++] = (BYTE)(bTempByte + 48);

	ulTempLong = (ULONG)(ulValue / 100000);
	bTempByte = (BYTE)ulTempLong;
	ulTempLong = (ULONG)(bTempByte * 100000);
	ulValue -= ulTempLong;
	if(bDigits >= 6)
		bpDataBuffer[bIndex++] = (BYTE)(bTempByte + 48);

	ulTempLong = (ULONG)(ulValue / 10000);
	bTempByte = (BYTE)ulTempLong;
	ulTempLong = (ULONG)(bTempByte * 10000);
	ulValue -= ulTempLong;
	if(bDigits >= 5)
		bpDataBuffer[bIndex++] = (BYTE)(bTempByte + 48);


	ulTempLong = (ULONG)(ulValue / 1000);
	bTempByte = (BYTE)ulTempLong;
	ulTempLong = (ULONG)(bTempByte * 1000);
	ulValue -= ulTempLong;
	if(bDigits >= 4)
		bpDataBuffer[bIndex++] = (BYTE)(bTempByte + 48);

	ulTempLong = (ULONG)(ulValue / 100);
	bTempByte = (BYTE)ulTempLong;
	ulTempLong = (ULONG)(bTempByte * 100);
	ulValue -= ulTempLong;
	if(bDigits >= 3)
		bpDataBuffer[bIndex++] = (BYTE)(bTempByte + 48);

	ulTempLong = (ULONG)(ulValue / 10);
	bTempByte = (BYTE)ulTempLong;
	ulTempLong = (ULONG)(bTempByte * 10);
	ulValue -= ulTempLong;
	if(bDigits >= 2)
		bpDataBuffer[bIndex++] = (BYTE)(bTempByte + 48);

	bTempByte = (BYTE)(ulValue);
	bpDataBuffer[bIndex++] = (BYTE)(bTempByte + 48);

	bpDataBuffer[bIndex] = 0;
}


//*****************************************************************
// <Function> : convert real to ascii
// <Input>    : bpDataBuffer = array to store array in, real to convert, bDigitsit = number of bDigitsits to store in, Precision
// <Output>   : None
// <Return>   : int value
//*****************************************************************
VOID MYSTRING_RealToAscii(BYTE *bpDataBuffer, REAL rValue, BYTE bDigits, BYTE bPrecision)
{
	BYTE bTempByte;
	BYTE bIndex;
	ULONG ulTempLong;
	ULONG ulValue;
	
	switch(bPrecision)
	{
		case 0:
			ulValue = (ULONG)rValue;
			break;
		case 1:
			ulValue = (ULONG)(rValue*10.0);
			break;
		case 2:
			ulValue = (ULONG)(rValue*100.0);
			break;
		case 3:
			ulValue = (ULONG)(rValue*1000.0);
			break;
		case 4:
		default:
			ulValue = (ULONG)(rValue*10000.0);
			bPrecision = 4;
			break;
	}


	bIndex = 0;


	if(ulValue > 999999999)
	{
		ulValue = 999999999;
	}

	ulTempLong = (ULONG)(ulValue / 100000000);
	bTempByte = (BYTE)ulTempLong;
	if(bTempByte > 9) bTempByte = 10;
		ulTempLong = (ULONG)(bTempByte * 100000000);
	ulValue -= ulTempLong;
	if(bDigits >= 9)
		bpDataBuffer[bIndex++] = (BYTE)(bTempByte + 48);

	ulTempLong = (ULONG)(ulValue / 10000000);
	bTempByte = (BYTE)ulTempLong;
	ulTempLong = (ULONG)(bTempByte * 10000000);
	ulValue -= ulTempLong;
	if(bDigits >= 8)
		bpDataBuffer[bIndex++] = (BYTE)(bTempByte + 48);

	ulTempLong = (ULONG)(ulValue / 1000000);
	bTempByte = (BYTE)ulTempLong;
	ulTempLong = (ULONG)(bTempByte * 1000000);
	ulValue -= ulTempLong;
	if(bDigits >= 7)
		bpDataBuffer[bIndex++] = (BYTE)(bTempByte + 48);

	ulTempLong = (ULONG)(ulValue / 100000);
	bTempByte = (BYTE)ulTempLong;
	ulTempLong = (ULONG)(bTempByte * 100000);
	ulValue -= ulTempLong;
	if(bDigits >= 6)
		bpDataBuffer[bIndex++] = (BYTE)(bTempByte + 48);

	ulTempLong = (ULONG)(ulValue / 10000);
	bTempByte = (BYTE)ulTempLong;
	ulTempLong = (ULONG)(bTempByte * 10000);
	ulValue -= ulTempLong;
	if(bDigits >= 5)
		bpDataBuffer[bIndex++] = (BYTE)(bTempByte + 48);

	if(bPrecision == 4)
	{
		bpDataBuffer[bIndex++] = '.';
	}
	ulTempLong = (ULONG)(ulValue / 1000);
	bTempByte = (BYTE)ulTempLong;
	ulTempLong = (ULONG)(bTempByte * 1000);
	ulValue -= ulTempLong;
	if(bDigits >= 4)
	{
		bpDataBuffer[bIndex++] = (BYTE)(bTempByte + 48);
	}

	if(bPrecision == 3)
	{
		bpDataBuffer[bIndex++] = '.';
	}
	ulTempLong = (ULONG)(ulValue / 100);
	bTempByte = (BYTE)ulTempLong;
	ulTempLong = (ULONG)(bTempByte * 100);
	ulValue -= ulTempLong;
	if(bDigits >= 3)
		bpDataBuffer[bIndex++] = (BYTE)(bTempByte + 48);

	if(bPrecision == 2)
	{
		bpDataBuffer[bIndex++] = '.';
	}
	ulTempLong = (ULONG)(ulValue / 10);
	bTempByte = (BYTE)ulTempLong;
	ulTempLong = (ULONG)(bTempByte * 10);
	ulValue -= ulTempLong;
	if(bDigits >= 2)
		bpDataBuffer[bIndex++] = (BYTE)(bTempByte + 48);

	if(bPrecision == 1)
	{
		bpDataBuffer[bIndex++] = '.';
	}
	bTempByte = (BYTE)(ulValue);
	bpDataBuffer[bIndex++] = (BYTE)(bTempByte + 48);

	bpDataBuffer[bIndex] = 0;
}


//********************************************************************************
//
// this function verifies that a phone number has the correct format
//
//********************************************************************************
BOOL MYSTRING_fValidatePhoneNumber(BYTE *src_nr, BYTE *dest_nr)
{       
	BOOL	fReturnStatus;                                              
	BYTE	i;
	BYTE	count;
	
	fReturnStatus = FALSE;
	dest_nr[0] = *src_nr++;
	if(dest_nr[0] == '+')
	{
		fReturnStatus = TRUE;
		count = 1;
		for(i = 1 ; (i < 15/*GSM_NR_MAXLEN*/) && (fReturnStatus == TRUE) && (*src_nr != 0); i++)
		{
			if(MYSTRING_fIsDigit(*src_nr) || (*src_nr == ' '))
			{
				dest_nr[i] = *src_nr++;
				count++;
			}                                     
			else
			{
				fReturnStatus = FALSE;
			}
		}
		dest_nr[count] = 0;
		if(count < 10)
		{
			fReturnStatus = FALSE;        
		}
	}
	return(fReturnStatus);
}

/*===========================================================================*/
/**
\brief

\details

\param	p1		
\return			
\retval	x		

\author	Johann Kok
*/
/*===========================================================================*/
BOOL MYSTRING_NumberValid(CHAR* check_nr)
{
	INT8U		i = 0;
	
	//ONLY 1ST CHAR MAY BE A '+'
	if(check_nr[i] == '+')
	{
		i++;
	}
	while(i < 15/*GSM_NR_MAXLEN*/)
	{
		if(	isdigit(check_nr[i]) 
			|| (check_nr[i] == ' ')
			|| (check_nr[i] == '-')	)
		{
			i++;
		}
		else
		{
			if(check_nr[i] == '\0')
			{
				if(i < 4/*GSM_NR_MINLEN*/)	return(FALSE);		//too short
				else								return(TRUE);		//valid number
			}
			else
			{
				return(FALSE);		//invalid char
			}
		}
	}
	return(FALSE);		//nr too long
}


//*****************************************************************
// Convert the 2 nibbles of a INT8U to a two-char string with the 2nd 
//char containing the 2nd nibble. 
//*****************************************************************
VOID MYSTRING_HexCharToAsciiStr(CHAR* ascii_dest_s, INT8U hex_src)
{
	INT8U		tmp_hex;
	
	//MS Nibble
	tmp_hex = (BYTE)(hex_src >> 4);
	if(tmp_hex < 0x0A)	ascii_dest_s[0] = tmp_hex			+ '0';
	else						ascii_dest_s[0] = (BYTE)(tmp_hex - (BYTE)(0x0A) + 'A');
	
	//LS Nibble
	tmp_hex = (BYTE)(hex_src & 0x0f);
	if(tmp_hex < 0x0A)	ascii_dest_s[1] = tmp_hex			+ '0';
	else						ascii_dest_s[1] = (BYTE)(tmp_hex - (BYTE)(0x0A) + 'A');
	ascii_dest_s[2] = '\0';															//terminate
}	//end MYSTRING_HexCharToAsciiStr()


/*===========================================================================*/
/**
\brief

\details

\param	p1		
\return			
\retval	x		

\author	
*/
/*===========================================================================*/
BOOL MYSTRING_HexStrToAsciiStr(
	CHAR*		ascii_s
	,INT16U	ascii_maxlen
	,INT8U*	hex_s
	,INT16U	hex_len
	,BOOL		hex_only
)
{
	BOOL		completed = TRUE;
	INT16U		i, j = 0;
	
	for(i = 0; i < hex_len; i++)
	{
//		if(hex_only == FALSE)
//		{
			//IS THERE'S SPACE FOR ANOTHER 2 ASCII CHARACTERS
			if((j + 2) <= ascii_maxlen)
			{
				//IF VALID ASCII CHARACTER - PUT IT AS IS
				if(	(hex_only == FALSE)
					&&	(isalnum(hex_s[i]) || (hex_s[i] == ' '))	)
				{
					ascii_s[j++] = '~';
					ascii_s[j++] = hex_s[i];
				}
				
				//IF HEX CHARACTER - CONVERT TO ASCII STR FIRST
				else
				{
					MYSTRING_HexCharToAsciiStr(&ascii_s[j], hex_s[i]);
					j += 2;
				}
			}
			else
			{
				completed = FALSE;					//couldn't convert everything
				break;
			}
//		}
//		else
//		{
//			if((j + 2) <= ascii_maxlen)
//			{
//				MYSTRING_HexCharToAsciiStr(&ascii_s[j], hex_s[i]);
//				j += 2;
//			}
//			else
//			{
//				completed = FALSE;					//couldn't convert everything
//				break;
//			}
//		}
	}
	ascii_s[j] = '\0';
	return(completed);
}	//end MYSTRING_HexStrToAsciiStr()
#endif

#endif
// ***************************** end/einde/fin **************************************************


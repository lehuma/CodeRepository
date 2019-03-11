/* ********************************************************************************* */
/* Copyright : © Netstar (Pty) Limited, 2007                                         */
/*             All rights reserved. No part of this publication may be reproduced,   */
/*             stored in a retrieval system, or transmitted in any form or by any    */
/*             means, electronic, mechanical,photocopying, recording, or otherwise,  */
/*             without the prior written permission of Netstar (Pty) Limited.        */
/*                                                                                   */
/*                                                                                   */
/* Module :  mystring.h                                                              */
/*                                                                                   */
/* Purpose : string routines definitions                                             */
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

#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include "typedef.h"

// ****************************************************************************************
//  Constant definitions
// ****************************************************************************************


// ****************************************************************************************
// Global Data
// ****************************************************************************************


// ****************************************************************************************
// Global functions
// ****************************************************************************************
BOOL MYSTRING_IsDigits(CHAR* src_s);
BOOL MYSTRING_fIsDigit(BYTE bByte);
BOOL MYSTRING_fIsXdigit(BYTE bByte);
BYTE MYSTRING_Nibble_to_ascii_hex(BYTE bInNibble);
VOID MYSTRING_char_to_ascii(BYTE bInChar, BYTE *bpDig);
VOID MYSTRING_char_to_ascii_hex(BYTE bInChar, BYTE *bpDig);
VOID MYSTRING_word_to_ascii_hex(WORD wInWord, BYTE *bpDig, BYTE bDigits);
VOID MYSTRING_long_to_ascii_hex(ULONG ulInLong, BYTE *bpDig);
BYTE MYSTRING_ascii_hex_to_char(BYTE bDig1, BYTE bDig2);
BYTE MYSTRING_ascii_to_char(BYTE bDig1, BYTE bDig2);
BYTE MYSTRING_ascii_to_hex(BYTE bDig1, BYTE bDig2);
BYTE MYSTRING_bcd_to_char(BYTE bBcd);
BYTE MYSTRING_char_to_bcd(BYTE bChar);
VOID MYSTRING_word_to_ascii(INT16U wInWord, INT8U *bpDig, INT8U size);

WORD MYSTRING_wStrlen(BYTE *bpSrcString);
VOID MYSTRING_MemSet(BYTE *bpDestString, BYTE bDataByte, WORD wLen);
VOID MYSTRING_StrCat(BYTE *bpDestString, BYTE *bpSrcString);
VOID MYSTRING_StrCopy(BYTE *bpDestString, BYTE *bpSrcString, WORD wLen);
VOID MYSTRING_MemCopy(BYTE *bpDestString, BYTE *bpSrcString, WORD wLen);
BOOL MYSTRING_StrCmp(BYTE *bpDestString, BYTE *bpSrcString, WORD wLen);
BYTE* MYSTRING_bpStrChr(BYTE *bpDestString, BYTE bSrcByte);
BYTE* MYSTRING_bpStrStr(BYTE *bpDestString, BYTE *bSrcString);
REAL MYSTRING_rStringToReal(BYTE *s);
INT  MYSTRING_iStringToInt(BYTE *s);
LONGINT MYSTRING_liStringToLong(BYTE *s);
WORD MYSTRING_wHexStringToWord(BYTE *pInValue);
ULONG MYSTRING_ulHexStringToLong(BYTE *pInValue);
BYTE MYSTRING_ToInt(BYTE InValue);
VOID MYSTRING_ToLower(CHAR* src_s);
VOID MYSTRING_LongToAscii(BYTE *bpDataBuffer, ULONG ulValue, BYTE bDigits);
VOID MYSTRING_RealToAscii(BYTE *bpDataBuffer, REAL rValue, BYTE bDigits, BYTE bPrecision);
BOOL MYSTRING_fValidatePhoneNumber(BYTE *bpPhone, BYTE *bpTempString);
BOOL MYSTRING_NumberValid(CHAR* check_nr);
VOID MYSTRING_HexCharToAsciiStr(CHAR* ascii_dest_s, INT8U hex_src);
BOOL MYSTRING_HexStrToAsciiStr(CHAR* ascii_s, INT16U ascii_maxlen, INT8U* hex_s, INT16U hex_len, BOOL hex_only);


#endif
// *********************************** end/einde/fin *************************************** 


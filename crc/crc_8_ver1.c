/*
    Auther       : Heinz Samuelsson
    Date         : 2020-05-26
    File         : crc_8_ver1.c
    Reference    : -
    Description  : -
                    ==========================================================================
                    CRC Generation Unit - Linear Feedback Shift Register implementation
                    (c) Kay Gorontzi, GHSi.de, distributed under the terms of LGPL
                    ==========================================================================
*/ 
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <stdbool.h>
 

char *MakeCRC(char *BitString) {

	static char res[9]; // CRC Result
	char CRC[8];
	int  i;
	char DoInvert;
   
	// Init before calculation
	for (i=0; i<8; ++i) {
		CRC[i] = 0;
	}
   
	for (i=0; i<strlen(BitString); ++i) {

		DoInvert = ('1'==BitString[i]) ^ CRC[7]; // XOR required?
		
		CRC[7] = CRC[6];
		CRC[6] = CRC[5];
		CRC[5] = CRC[4];
		CRC[4] = CRC[3];
		CRC[3] = CRC[2];
		CRC[2] = CRC[1] ^ DoInvert;
		CRC[1] = CRC[0] ^ DoInvert;
		CRC[0] = DoInvert;
	}
      
	for (i=0; i<8; ++i)  res[7-i] = CRC[i] ? '1' : '0'; // Convert binary to ASCII

	res[8] = 0; // Set string terminator

	return(res);
}

 
int main(int argc, char *argv[])
{
	char *Data;
	char *Result;
	
	// 0x65 0x43 0x21
	Data = "011001010100001100100001";
	Result = MakeCRC(Data);                                    // Calculate CRC
	
	printf("CRC of [%s] is [%s] with P=[100000111]\n", Data, Result);
	   
	return 0;
}




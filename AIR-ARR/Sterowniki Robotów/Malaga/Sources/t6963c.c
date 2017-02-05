//-------------------------------------------------------------------------------------------------
// Graphic LCD with Toshiba T6963 controller
// Copyright (c) Radoslaw Kwiecien, 2007r
// http://en.radzio.dxp.pl/t6963/
// Compiler : avr-gcc
//-------------------------------------------------------------------------------------------------
#include "T6963C.h"
#include "WR.h"
#include "BitIoLdd3.h"
#include "RD.h"
#include "BitIoLdd4.h"
#include "CE.h"
#include "BitIoLdd5.h"
#include "CD.h"
#include "BitIoLdd6.h"
#include "RST.h"
#include "BitIoLdd7.h"
#include "D0.h"
#include "BitIoLdd8.h"
#include "D1.h"
#include "BitIoLdd9.h"
#include "D2.h"
#include "BitIoLdd10.h"
#include "D3.h"
#include "BitIoLdd11.h"
#include "D4.h"
#include "BitIoLdd12.h"
#include "D5.h"
#include "BitIoLdd13.h"
#include "D6.h"
#include "BitIoLdd14.h"
#include "D7.h"
#include "BitIoLdd15.h"
#define F_CPU 100000000UL
//-------------------------------------------------------------------------------------------------
//
// Delay function
//	
//-------------------------------------------------------------------------------------------------
void delay(void)
{
	volatile unsigned char i;
	for(i = 0; i < (F_CPU/1000000); i++)
	{
		asm("nop");
	}
}

void data_port_dir(int kierunek)
{
	D0_SetDir(kierunek);
	D1_SetDir(kierunek);
	D2_SetDir(kierunek);
	D3_SetDir(kierunek);
	D4_SetDir(kierunek);
	D5_SetDir(kierunek);
	D6_SetDir(kierunek);
	D7_SetDir(kierunek);
}

uint8_t data_port_GetVal()
{
	uint8_t tmp = 0;
	if(D0_GetVal())
		tmp += 1;
	if(D1_GetVal())
		tmp += (1<<1);
	if(D2_GetVal())
		tmp += (1<<2);
	if(D3_GetVal())
		tmp += (1<<3);
	if(D4_GetVal())
		tmp += (1<<4);
	if(D5_GetVal())
		tmp += (1<<5);
	if(D6_GetVal())
		tmp += (1<<6);
	if(D7_GetVal())
		tmp += (1<<7);
	return tmp;
}

void data_port_PutVal(uint8_t val)
{
	D0_PutVal(val&0x01);
	D1_PutVal(val&0x02);
	D2_PutVal(val&0x04);
	D3_PutVal(val&0x08);
	D4_PutVal(val&0x10);
	D5_PutVal(val&0x20);
	D6_PutVal(val&0x40);
	D7_PutVal(val&0x80);
}
//-------------------------------------------------------------------------------------------------
//
// Ports intalization
//
//-------------------------------------------------------------------------------------------------
void GLCD_InitalizeInterface(void)
{
	CD_SetVal();
	WR_SetVal();
	RD_SetVal();
	CE_SetVal();
	RST_SetVal();
	//moze jeszcze FS ale on jest wybierany zwork¹
}
//-------------------------------------------------------------------------------------------------
//
// Reads dispay status
//
//-------------------------------------------------------------------------------------------------
unsigned char GLCD_ChceckStatus(void)
{
	uint8_t tmp;
	data_port_dir(0);

	RD_ClrVal();
	CE_ClrVal();
	asm("nop");
	asm("nop");
	asm("nop");
	tmp = data_port_GetVal();
	asm("nop");
	asm("nop");
	asm("nop");
	data_port_dir(1);
	RD_SetVal();
	CE_SetVal();
	return tmp;
}
//-------------------------------------------------------------------------------------------------
//
// Writes instruction 
//
//-------------------------------------------------------------------------------------------------
void GLCD_WriteCommand(unsigned char command)
{
	while(!(GLCD_ChceckStatus()&0x03));
	data_port_PutVal(command);

	WR_ClrVal();
	CE_ClrVal();
	asm("nop");
	asm("nop");
	asm("nop");
	WR_SetVal();
	CE_SetVal();
}

//-------------------------------------------------------------------------------------------------
//
// Writes data
//
//-------------------------------------------------------------------------------------------------
void GLCD_WriteData(unsigned char data)
{
	while(!(GLCD_ChceckStatus()&0x03));
	data_port_PutVal(data);

	WR_ClrVal();
	CD_ClrVal();
	CE_ClrVal();
	asm("nop");
	asm("nop");
	asm("nop");
	WR_SetVal();
	CD_SetVal();
	CE_SetVal();
}
//-------------------------------------------------------------------------------------------------
//
// Reads data
//
//-------------------------------------------------------------------------------------------------
unsigned char GLCD_ReadData(void)
{
	uint8_t tmp;
	while(!(GLCD_ChceckStatus()&0x03));
	data_port_dir(0);

	WR_ClrVal();
	CD_ClrVal();
	CE_ClrVal();
	asm("nop");
	asm("nop");
	asm("nop");
	tmp = data_port_GetVal();
	asm("nop");
	asm("nop");
	asm("nop");
	WR_SetVal();
	CD_SetVal();
	CE_SetVal();
	data_port_dir(1);
	return tmp;
}
//-------------------------------------------------------------------------------------------------
//
// Sets address pointer for display RAM memory
//
//-------------------------------------------------------------------------------------------------
void GLCD_SetAddressPointer(unsigned int address)
{
	GLCD_WriteData(address & 0xFF);
	GLCD_WriteData(address >> 8);
	GLCD_WriteCommand(T6963_SET_ADDRESS_POINTER);
}
//-------------------------------------------------------------------------------------------------
//
// Clears text area of display RAM memory
//
//-------------------------------------------------------------------------------------------------
void GLCD_ClearText(void)
{
	int i;
	GLCD_SetAddressPointer(GLCD_TEXT_HOME);

	for(i = 0; i < GLCD_TEXT_SIZE; i++)
	{
		GLCD_WriteDisplayData(0);
	}
}
//-------------------------------------------------------------------------------------------------
//
// Clears characters generator area of display RAM memory
//
//-------------------------------------------------------------------------------------------------
void GLCD_ClearCG(void)
{
	unsigned int i;
	GLCD_SetAddressPointer(GLCD_EXTERNAL_CG_HOME);

	for(i = 0; i < 256 * 8; i++)
	{
		GLCD_WriteDisplayData(0);
	}
}
//-------------------------------------------------------------------------------------------------
//
// Clears graphics area of display RAM memory
//
//-------------------------------------------------------------------------------------------------
void GLCD_ClearGraphic(void)
{
	int i;
	GLCD_SetAddressPointer(GLCD_GRAPHIC_HOME);
	for(i = 0; i < GLCD_GRAPHIC_SIZE; i++)
	{
		GLCD_WriteDisplayData(0x00);
	}
}
//-------------------------------------------------------------------------------------------------
//
// Writes a single character (ASCII code) to display RAM memory
//
//-------------------------------------------------------------------------------------------------
void GLCD_WriteChar(char charCode)
{
	GLCD_WriteDisplayData(charCode - 32);
}
//-------------------------------------------------------------------------------------------------
//
// Writes null-terminated string to display RAM memory
//
//-------------------------------------------------------------------------------------------------
void GLCD_WriteString(char * string)
{
	while(*string)
	{
		GLCD_WriteChar(*string++);
	}
}
//-------------------------------------------------------------------------------------------------
//
// Writes null-terminated string from program memory to display RAM memory
//
//-------------------------------------------------------------------------------------------------
void GLCD_WriteStringPgm(char * string)
{
	char ch;
	while((ch = pgm_read_byte(string++)))
	{
		GLCD_WriteChar(ch);
	}
}
//-------------------------------------------------------------------------------------------------
//
// Sets display coordinates
//
//-------------------------------------------------------------------------------------------------
void GLCD_TextGoTo(unsigned char x, unsigned char y)
{
	unsigned int address;

	address = GLCD_TEXT_HOME +  x + (GLCD_TEXT_AREA * y);

	GLCD_SetAddressPointer(address);
}
//-------------------------------------------------------------------------------------------------
//
// Writes single char pattern to character generator area of display RAM memory
//
//-------------------------------------------------------------------------------------------------
void GLCD_DefineCharacter(unsigned char charCode, unsigned char * defChar)
{
	unsigned int address;
	unsigned char i; 

	address = GLCD_EXTERNAL_CG_HOME + (8 * charCode);

	GLCD_SetAddressPointer(address);

	for(i = 0; i < 8 ; i++)
	{
		GLCD_WriteDisplayData(*(defChar + i));
	}
}

//-------------------------------------------------------------------------------------------------
//
// Set (if color==1) or clear (if color==0) pixel on screen
//
//-------------------------------------------------------------------------------------------------
void GLCD_SetPixel(unsigned char x, unsigned char y, unsigned char color)
{
	unsigned char tmp;
	unsigned int address;

	address = GLCD_GRAPHIC_HOME + (x / GLCD_FONT_WIDTH) + (GLCD_GRAPHIC_AREA * y);

	GLCD_SetAddressPointer(address);

	GLCD_WriteCommand(T6963_DATA_READ_AND_NONVARIABLE);
	tmp = GLCD_ReadData();

	if(color)
		tmp |= (1 <<  (GLCD_FONT_WIDTH - 1 - (x % GLCD_FONT_WIDTH)));
	else
		tmp &= ~(1 <<  (GLCD_FONT_WIDTH - 1 - (x % GLCD_FONT_WIDTH)));

	GLCD_WriteDisplayData(tmp);

}
//-------------------------------------------------------------------------------------------------
//
// Writes display data and increment address pointer
//
//-------------------------------------------------------------------------------------------------
void GLCD_WriteDisplayData(unsigned char x)
{
	GLCD_WriteData(x);
	GLCD_WriteCommand(T6963_DATA_WRITE_AND_INCREMENT);
}
//-------------------------------------------------------------------------------------------------
//
// Sets graphics coordinates
//
//-------------------------------------------------------------------------------------------------
void GLCD_GraphicGoTo(unsigned char x, unsigned char y)
{
	unsigned int address;
	address = GLCD_GRAPHIC_HOME + (x / GLCD_FONT_WIDTH) + (GLCD_GRAPHIC_AREA * y);
	GLCD_SetAddressPointer(address);
}
//-------------------------------------------------------------------------------------------------
//
// Displays bitmap from program memory
//
//-------------------------------------------------------------------------------------------------
void GLCD_Bitmap(unsigned char * bitmap, unsigned char x, unsigned char y, unsigned char width, unsigned char height)
{
	unsigned char i, j;

	for(j = 0; j < height; j++)
	{
		GLCD_GraphicGoTo(x, y + j);
		for(i = 0; i < width/GLCD_FONT_WIDTH; i++)
		{
			GLCD_WriteDisplayData(pgm_read_byte(bitmap + i + (GLCD_GRAPHIC_AREA * j))); 	
		}
	}
}
//-------------------------------------------------------------------------------------------------
//
// Display initalization
//
//-------------------------------------------------------------------------------------------------
void GLCD_Initalize(void)
{
	GLCD_InitalizeInterface();
	RST_ClrVal();
	delay();
	RST_SetVal();

	GLCD_WriteData(GLCD_GRAPHIC_HOME & 0xFF);
	GLCD_WriteData(GLCD_GRAPHIC_HOME >> 8);
	GLCD_WriteCommand(T6963_SET_GRAPHIC_HOME_ADDRESS);

	GLCD_WriteData(GLCD_GRAPHIC_AREA);
	GLCD_WriteData(0x00);
	GLCD_WriteCommand(T6963_SET_GRAPHIC_AREA);

	GLCD_WriteData(GLCD_TEXT_HOME);
	GLCD_WriteData(GLCD_TEXT_HOME >> 8);
	GLCD_WriteCommand(T6963_SET_TEXT_HOME_ADDRESS);

	GLCD_WriteData(GLCD_TEXT_AREA);
	GLCD_WriteData(0x00);
	GLCD_WriteCommand(T6963_SET_TEXT_AREA);

	GLCD_WriteData(GLCD_OFFSET_REGISTER);
	GLCD_WriteData(0x00);
	GLCD_WriteCommand(T6963_SET_OFFSET_REGISTER);

	GLCD_WriteCommand(T6963_DISPLAY_MODE  | T6963_GRAPHIC_DISPLAY_ON   | T6963_TEXT_DISPLAY_ON /*| T6963_CURSOR_DISPLAY_ON*/);

	GLCD_WriteCommand(T6963_MODE_SET | 0);

}

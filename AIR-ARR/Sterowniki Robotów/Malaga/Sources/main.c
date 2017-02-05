/* ###################################################################
 **     Filename    : main.c
 **     Project     : Malaga
 **     Processor   : MK40DN512VLQ10
 **     Version     : Driver 01.01
 **     Compiler    : CodeWarrior ARM C Compiler
 **     Date/Time   : 2015-03-29, 17:14, # CodeGen: 0
 **     Abstract    :
 **         Main module.
 **         This module contains user's application code.
 **     Settings    :
 **     Contents    :
 **         No public methods
 **
 ** ###################################################################*/
/*!
 ** @file main.c
 ** @version 01.01
 ** @brief
 **         Main module.
 **         This module contains user's application code.
 */         
/*!
 **  @addtogroup main_module main module documentation
 **  @{
 */         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "LED_Purple.h"
#include "PwmLdd1.h"
#include "TU1.h"
#include "FC1.h"
#include "FreeCntrLdd1.h"
#include "TU2.h"
#include "LED_Green.h"
#include "PwmLdd2.h"
#include "PWM_Yellow.h"
#include "PwmLdd3.h"
#include "Przycisk.h"
#include "ExtIntLdd1.h"
#include "Potencjometr.h"
#include "AdcLdd1.h"
#include "PWM_RGB_RED.h"
#include "PwmLdd4.h"
#include "PWM_RGB_GREEN.h"
#include "PwmLdd5.h"
#include "PWM_RGB_BLUE.h"
#include "PwmLdd6.h"
#include "PWM_SERVO.h"
#include "PwmLdd7.h"
#include "AS1.h"
#include "ASerialLdd1.h"
#include "Joystick.h"
#include "IntI2cLdd1.h"
#include "RESETn.h"
#include "BitIoLdd1.h"
#include "Podswietlenie.h"
#include "PwmLdd8.h"
#include "TU3.h"
#include "Kontrast.h"
#include "PwmLdd9.h"
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
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* User includes (#include below this line is not maintained by Processor Expert) */
#include "t6963c.h"
#include "graphic.h"
uint8_t tryb = 6;
bool flaga;

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
	/* Write your local variable definition here */
	bool czy_zmierzyl = TRUE;
	int i, j;
	word adc16 = 0;
	word adc16_meas = 0;
	uint8_t adc8 = 0;
	uint8_t test_rejestru = 0;
	int8_t xy[3];
	uint8_t error;
	uint8_t M_ctl_cfg[] = { 0x2B, 0 };
	uint8_t J_ctl_cfg[] = { 0x2B, 6 };
	uint8_t T_ctl_cfg[] = { 0x2D, 9 };
	uint8_t PWR_cfg[] = { 0x0F, 0x80 };
	unsigned short ile_znakow;
	unsigned short ile_danych;
	unsigned char data;
	unsigned char string[15];
	unsigned char ok[6] = "OK!\n\r";
	/*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
	PE_low_level_init();
	/*** End of Processor Expert internal initialization.                    ***/

	/* Write your code here */
	GLCD_Initalize();
	for(flaga = 0; flaga < 100;);
	RESETn_SetVal();
	GLCD_ClearCG();
	GLCD_ClearGraphic();
	GLCD_ClearText();

	while(czy_zmierzyl)
	{
		Joystick_SendChar(0x0F);
		Joystick_RecvChar(&test_rejestru);
		//Joystick_SendStop();
		if((test_rejestru == 0xF0) || (test_rejestru == 0xF1))
			czy_zmierzyl = FALSE;
	}
	Joystick_SendBlock(M_ctl_cfg,2,&ile_danych);
	//Joystick_SendStop();
	Joystick_SendBlock(J_ctl_cfg,2,&ile_danych);
	//Joystick_SendStop();
	Joystick_SendBlock(T_ctl_cfg,2,&ile_danych);
	//Joystick_SendStop();
	Joystick_SendBlock(PWR_cfg,2,&ile_danych);
	//Joystick_SendStop();

	/* For example: for(;;) { } */
	for(;;)
	{
		if(flaga == 2)
		{
			switch(tryb)
			{
			case 1:
				error = Joystick_SendChar(0x10);
				error = Joystick_RecvBlock(xy,2,&ile_danych);
				//Potencjometr_Measure(czy_zmierzyl);
				//Potencjometr_GetValue16(&adc16);
				//adc16_meas = adc16 * 0.1;
				//adc16_meas += 1966;
				adc16 = xy[0] + 51;
				adc16 *= 60;
				adc16 += 1966;
				GLCD_ClearText();
				GLCD_TextGoTo(0,0);
				ile_znakow = sprintf(string,"Serwo: %4d \n\r",adc16);
				GLCD_WriteString((char *)string);
				PWM_SERVO_SetRatio16(adc16);
				break;

			case 2:
				Potencjometr_Measure(czy_zmierzyl);
				Potencjometr_GetValue8(&adc8);
				PWM_RGB_RED_SetRatio8(adc8);
				GLCD_ClearText();
				GLCD_TextGoTo(0,0);
				ile_znakow = sprintf(string,"Red: %4d \n\r",adc8);
				GLCD_WriteString((char *)string);
				break;

			case 3:
				Potencjometr_Measure(czy_zmierzyl);
				Potencjometr_GetValue8(&adc8);
				PWM_RGB_GREEN_SetRatio8(adc8);
				++i;
				if(i>127)
				{
					i = 0;
					++j;
					if(j>63)
					{
						j = 0;
						GLCD_ClearGraphic();
					}
				}
				GLCD_SetPixel(i,j,1);
				break;

			case 4:
				Potencjometr_Measure(czy_zmierzyl);
				Potencjometr_GetValue8(&adc8);
				PWM_RGB_BLUE_SetRatio8(adc8);
				break;

			case 6:
				/*if(flaga == 10)
				{*/
				error = Joystick_SendChar(0x10);
				//while(Joystick_GetCharsInTxBuf()!=0);
				error = Joystick_RecvBlock(xy,2,&ile_danych);
				//Joystick_SendStop();
				xy[1] -= 23;
				ile_znakow = sprintf(string,"X: %4d Y: %4d\r",xy[0],xy[1]);
				GLCD_ClearText();
				GLCD_TextGoTo(0,0);
				GLCD_WriteString((char *)string);
				AS1_SendBlock((unsigned char *)"          \r",12,&ile_danych);
				AS1_SendBlock(string,ile_znakow,&ile_danych);
				flaga = 0;
				//}
				break;
			}
			flaga = 0;
		}
	}
	/*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
}

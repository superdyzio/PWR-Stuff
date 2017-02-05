/* ###################################################################
**     Filename    : Events.c
**     Project     : Malaga
**     Processor   : MK40DN512VLQ10
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : CodeWarrior ARM C Compiler
**     Date/Time   : 2015-03-29, 17:14, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         Cpu_OnNMIINT - void Cpu_OnNMIINT(void);
**
** ###################################################################*/
/*!
** @file Events.c
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         
/* MODULE Events */

#include "Cpu.h"
#include "Events.h"

#ifdef __cplusplus
extern "C" {
#endif 


/* User includes (#include below this line is not maintained by Processor Expert) */

/*
** ===================================================================
**     Event       :  Cpu_OnNMIINT (module Events)
**
**     Component   :  Cpu [MK40DN512LQ10]
*/
/*!
**     @brief
**         This event is called when the Non maskable interrupt had
**         occurred. This event is automatically enabled when the [NMI
**         interrupt] property 112123is set to 'Enabled'.
*/
/* ===================================================================*/
void Cpu_OnNMIINT(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  Przerwanie_delay (module Events)
**
**     Component   :  FC1 [FreeCntr]
*/
/*!
**     @brief
**         This event is called when a compare matches the counter
**         value (if compare or reload is selected as a interrupt
**         source) or a counter overflows (for free-running devices).
**         It is valid only when the component is enabled - <"Enable">
**         and the events are enabled - <"EnableEvent">. The event is
**         available only if <Interrupt service/event> is enabled.
*/
/* ===================================================================*/
void Przerwanie_delay(void)
{
	static int i;
	static bool w_gore;
	extern bool flaga;
	extern uint8_t tryb;
	flaga++;
	if(w_gore)
		i++;
	else
		i--;
	if(i >= 255)
		w_gore = FALSE;
	else if(i <= 0)
		w_gore = TRUE;\
	PWM_Yellow_SetRatio8(255);
	LED_Purple_SetRatio8(255);
	if(tryb != 5) LED_Green_SetRatio8(255);
	switch(tryb)
	{
	case 1:
		PWM_Yellow_SetRatio8(i);
		break;
	case 2:
		LED_Green_SetRatio8(i);
		break;
	case 3:
		LED_Green_SetRatio8(255-i);
		PWM_Yellow_SetRatio8(i);
		break;
	case 4:
		LED_Purple_SetRatio8(i);
		break;
	case 5:
		PWM_Yellow_SetRatio8(255-i);
		LED_Purple_SetRatio8(i);
		break;
	case 6:
		LED_Green_SetRatio8(255-i);
		LED_Purple_SetRatio8(i);
		break;
	case 7:
		LED_Green_SetRatio8(255-i);
		LED_Purple_SetRatio8(i);
		PWM_Yellow_SetRatio8(i);
		break;
	}
}

/*
** ===================================================================
**     Event       :  Przycisk_przerwanie (module Events)
**
**     Component   :  Przycisk [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void Przycisk_przerwanie(void)
{
  /* Write your code here ... */
	extern uint8_t tryb;
	uint8_t tmp;
	uint8_t *endl = (uint8_t *)"\n\r";
	unsigned short ile_znakow;
	tryb++;
	if (tryb > 6) tryb = 1;
	tmp = tryb+48;
	AS1_SendBlock(&tmp,1,&ile_znakow);
	AS1_SendBlock(endl,2,&ile_znakow);
}

/*
** ===================================================================
**     Event       :  RX_Przerwanie (module Events)
**
**     Component   :  AS1 [AsynchroSerial]
**     Description :
**         This event is called after a correct character is received.
**         The event is available only when the <Interrupt
**         service/event> property is enabled and either the <Receiver>
**         property is enabled or the <SCI output mode> property (if
**         supported) is set to Single-wire mode.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void RX_Przerwanie(void)
{
  /* Write your code here ... */
	extern uint8_t tryb;
	uint8_t tmp;

	unsigned short ile_znakow;
	unsigned char msg[55] = "Blad! Podany znak musi zawierac sie w przedziale 1-5\n\r";
	unsigned char msgled[55] = "Blad! Podany znak musi zawierac sie w przedziale 1-9\n\r";
	unsigned char ok[6] = "OK!\n\r";
	AS1_RecvChar(&tmp);
	if(tryb == 5)
	{
		if(tmp == 'k')
		{	
			tryb = 1;
			return;
		}
		if(tmp > 48 && tmp < 58)
		{
			LED_Green_SetRatio8((tmp-48)*27);
			AS1_SendBlock(ok,5,&ile_znakow);
		}
		else
			AS1_SendBlock(msgled,54,&ile_znakow);
	}
	else
	{
		if(tmp > 48 && tmp < 54)
		{
			tryb = tmp-48;
			AS1_SendBlock(ok,5,&ile_znakow);
		}
		else
			AS1_SendBlock(msg,54,&ile_znakow);
	}
}

/*
** ===================================================================
**     Event       :  Potencjometr_OnEnd (module Events)
**
**     Component   :  Potencjometr [ADC]
**     Description :
**         This event is called after the measurement (which consists
**         of <1 or more conversions>) is/are finished.
**         The event is available only when the <Interrupt
**         service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void Potencjometr_OnEnd(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  Potencjometr_OnCalibrationEnd (module Events)
**
**     Component   :  Potencjometr [ADC]
**     Description :
**         This event is called when the calibration has been finished.
**         User should check if the calibration pass or fail by
**         Calibration status method./nThis event is enabled only if
**         the <Interrupt service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void Potencjometr_OnCalibrationEnd(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  AS1_OnError (module Events)
**
**     Component   :  AS1 [AsynchroSerial]
**     Description :
**         This event is called when a channel error (not the error
**         returned by a given method) occurs. The errors can be read
**         using <GetError> method.
**         The event is available only when the <Interrupt
**         service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void AS1_OnError(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  TX_Przerwanie (module Events)
**
**     Component   :  AS1 [AsynchroSerial]
**     Description :
**         This event is called after a character is transmitted.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void TX_Przerwanie(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  AS1_OnFullRxBuf (module Events)
**
**     Component   :  AS1 [AsynchroSerial]
**     Description :
**         This event is called when the input buffer is full;
**         i.e. after reception of the last character 
**         that was successfully placed into input buffer.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void AS1_OnFullRxBuf(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  AS1_OnFreeTxBuf (module Events)
**
**     Component   :  AS1 [AsynchroSerial]
**     Description :
**         This event is called after the last character in output
**         buffer is transmitted.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void AS1_OnFreeTxBuf(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  Delay_timer (module Events)
**
**     Component   :  FC2 [FreeCntr]
*/
/*!
**     @brief
**         This event is called when a compare matches the counter
**         value (if compare or reload is selected as a interrupt
**         source) or a counter overflows (for free-running devices).
**         It is valid only when the component is enabled - <"Enable">
**         and the events are enabled - <"EnableEvent">. The event is
**         available only if <Interrupt service/event> is enabled.
*/
/* ===================================================================*/
void Delay_timer(void)
{
  /* Write your code here ... */
	extern uint32_t liczba_cykli;
	++liczba_cykli;
}

/* END Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.09]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/

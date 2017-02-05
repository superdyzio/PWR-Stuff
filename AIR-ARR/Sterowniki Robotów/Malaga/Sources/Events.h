/* ###################################################################
**     Filename    : Events.h
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
** @file Events.h
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         

#ifndef __Events_H
#define __Events_H
/* MODULE Events */

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
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

#ifdef __cplusplus
extern "C" {
#endif 

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
**         interrupt] property is set to 'Enabled'.
*/
/* ===================================================================*/
void Cpu_OnNMIINT(void);


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
void Przerwanie_delay(void);

void Przycisk_przerwanie(void);
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
void RX_Przerwanie(void);

void Potencjometr_OnEnd(void);
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

void Potencjometr_OnCalibrationEnd(void);
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
void AS1_OnError(void);

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
void TX_Przerwanie(void);

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
void AS1_OnFullRxBuf(void);

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
void AS1_OnFreeTxBuf(void);

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
void Delay_timer(void);

/* END Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __Events_H*/
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

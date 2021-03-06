/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : FC1.h
**     Project     : Malaga
**     Processor   : MK40DN512VLQ10
**     Component   : FreeCntr
**     Version     : Component 01.118, Driver 01.00, CPU db: 3.00.000
**     Compiler    : CodeWarrior ARM C Compiler
**     Date/Time   : 2015-06-14, 16:14, # CodeGen: 65
**     Abstract    :
**         This device "FreeCntr" implements a free running counter for
**         time measurement.
**     Settings    :
**         Timer name                  : FTM1_CNT (16-bit)
**         Compare name                : FTM1_MOD
**         Counter shared              : No
**
**         High speed mode
**             Prescaler               : divide-by-8
**             Clock                   : 0 Hz
**           Period
**             microseconds            : ---
**             milliseconds            : 20
**             seconds                 : ---
**             seconds (real)          : 0.020000076294
**             Hz                      : ---
**             kHz                     : ---
**             MHz                     : ---
**           Frequency of counting (Bus clock / prescaler)
**             Hz                      : 0
**
**         Initialization:
**              Timer                  : Enabled
**
**         Timer registers
**              Counter                : FTM1_CNT  [0x40039004]
**              Mode                   : FTM1_SC   [0x40039000]
**              Run                    : FTM1_SC   [0x40039000]
**              Prescaler              : FTM1_SC   [0x40039000]
**              Compare                : FTM1_MOD  [0x40039008]
**
**         Interrupt name              : INT_FTM1
**         Priority                    : 8
**         User handling procedure     : Przerwanie_delay
**         This event is called when the counter is reinitialized
**     Contents    :
**         Enable          - byte FC1_Enable(void);
**         Disable         - byte FC1_Disable(void);
**         Reset           - byte FC1_Reset(void);
**         GetCounterValue - byte FC1_GetCounterValue(FC1_TTimerValue *Value);
**
**     Copyright : 1997 - 2014 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file FC1.h
** @version 01.00
** @brief
**         This device "FreeCntr" implements a free running counter for
**         time measurement.
*/         
/*!
**  @addtogroup FC1_module FC1 module documentation
**  @{
*/         

#ifndef __FC1_H
#define __FC1_H

/* MODULE FC1. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "FreeCntrLdd1.h"

#include "Cpu.h"


#ifndef __BWUserType_FC1_TTimerValue
#define __BWUserType_FC1_TTimerValue
  typedef word FC1_TTimerValue ;       /* Counter or compare value, width depends on timer width, 8, 16, 32 or 64 bits. */
#endif

#ifdef FreeCntrLdd1_PERIOD_TICKS
#define FC1_PERIOD_VALUE FreeCntrLdd1_PERIOD_TICKS /* Initial period/offset value in ticks of the timer. It is available only if the component is enabled in high speed mode. */
#define FC1_PERIOD_VALUE_HIGH FC1_PERIOD_VALUE /* Period value in ticks of the timer in high speed mode. It is available only if the component is enabled in high speed mode. */
#endif
#define FC1_PRESCALER_VALUE 0x08UL     /* Initial prescaler value of the timer. It is available only if the component is enabled in high speed mode. */
#define FC1_PRESCALER_VALUE_HIGH 0x08UL /* Prescaler value of the timer in high speed mode. It is available only if the component is enabled in high speed mode. */
#define FC1_COUNTER_INPUT_CLOCK_HZ FreeCntrLdd1_CNT_INP_FREQ_U_0 /* Initial counter input clock frequency [Hz] (integer number). It is available only if the component is enabled in high speed mode. */
#define FC1_COUNTER_INPUT_CLOCK_HZ_HIGH FreeCntrLdd1_CNT_INP_FREQ_U_0_CFG_0 /* Counter input clock frequency in high speed mode [Hz] (integer number). It is available only if the component is enabled in high speed mode. */
#if FreeCntrLdd1_COUNTER_DIR == 0
#define FC1_UP_COUNTER     1           /* This constant is defined if the counter counts upwards, e.g. from 0 to maximal value. */
#endif
#if FreeCntrLdd1_COUNTER_DIR == 1
#define FC1_DOWN_COUNTER   1           /* This constant is defined if the counter counts down, e.g. from maximal value to 0. */
#endif
#define FC1_RESET_ON_COMPARE 1         /* This constant is defined if Reset counter on compare property is selected. */


/*
** ===================================================================
**     Method      :  FC1_Enable (component FreeCntr)
*/
/*!
**     @brief
**         This method enables the component, i.e. timer is enabled and
**         the internal clocks are counted. The method usually also
**         reset the counter (if it is supported by HW). 
**         The method is not available if the counter is shared.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
*/
/* ===================================================================*/
#define FC1_Enable() (FreeCntrLdd1_Enable(FreeCntrLdd1_DeviceData))

/*
** ===================================================================
**     Method      :  FC1_Disable (component FreeCntr)
*/
/*!
**     @brief
**         This method disables the component, i.e. timer is disabled
**         and the internal clocks are stopped. Last counter value is
**         usually preserved in the counter (if it is supported by HW).
**         The method is not available if the counter is shared.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
*/
/* ===================================================================*/
#define FC1_Disable() (FreeCntrLdd1_Disable(FreeCntrLdd1_DeviceData))

/*
** ===================================================================
**     Method      :  FC1_Reset (component FreeCntr)
*/
/*!
**     @brief
**         This method resets the timer-counter (sets to zero for
**         up-counting HW or to appropriate value for down-counting HW).
**         The method is available only if the counter register can be
**         set by software and the counter is not shared.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
*/
/* ===================================================================*/
#define FC1_Reset() (FreeCntrLdd1_ResetCounter(FreeCntrLdd1_DeviceData))

/*
** ===================================================================
**     Method      :  FC1_GetCounterValue (component FreeCntr)
*/
/*!
**     @brief
**         This method returns a content of the counter.
**     @param
**         Value           - Pointer to returned value.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
*/
/* ===================================================================*/
byte FC1_GetCounterValue(FC1_TTimerValue *Value);

/*
** ===================================================================
**     Method      :  FC1_OnInterrupt (component FreeCntr)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes event(s) of the component.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void FreeCntrLdd1_OnInterrupt(LDD_TUserData *UserDataPtr);

/* END FC1. */

#endif 
/* ifndef __FC1_H */
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

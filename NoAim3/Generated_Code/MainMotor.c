/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : MainMotor.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : PPG
**     Version     : Component 02.195, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-06-02, 15:27, # CodeGen: 107
**     Abstract    :
**         This component "PPG" implements a programmable
**         pulse generator that generates signal with variable
**         duty and variable cycle (period).
**     Settings    :
**         Used output pin             : 
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       43            |  ADC0_SE8/TSI0_CH0/PTB0/LLWU_P5/I2C0_SCL/TPM1_CH0
**             ----------------------------------------------------
**
**         Timer name                  : TPM1_CNT [16-bit]
**         Counter                     : TPM1_CNT  [0x40039004]
**         Mode register               : TPM1_SC   [0x40039000]
**         Run register                : TPM1_SC   [0x40039000]
**         Prescaler                   : TPM1_SC   [0x40039000]
**         Compare 1 register          : TPM1_MOD  [0x40039008]
**         Compare 2 register          : TPM1_C0V  [0x40039010]
**         Flip-flop 1 register        : TPM1_SC   [0x40039000]
**         Flip-flop 2 register        : TPM1_C0SC [0x4003900C]
**
**         User handling procedure     : not specified
**
**         Output pin
**
**         Port name                   : PTB
**         Bit number (in port)        : 0
**         Bit mask of the port        : 0x0001
**         Port data register          : GPIOB_PDOR [0x400FF040]
**         Port control register       : GPIOB_PDDR [0x400FF054]
**
**         Runtime setting period      : none
**         Runtime setting ratio       : calculated
**         Initialization:
**              Output level           : low
**              Timer                  : Enabled
**              Event                  : Enabled
**         High speed mode
**             Prescaler               : divide-by-8
**             Clock                   : 6000000 Hz
**           Initial value of            period        pulse width (ratio 10.00%)
**             microseconds            : 6803          680
**             milliseconds            : 7             1
**             seconds (real)          : 0.006802666667 0.000680333333
**
**     Contents    :
**         SetRatio16 - byte MainMotor_SetRatio16(word Ratio);
**         SetDutyUS  - byte MainMotor_SetDutyUS(word Time);
**         SetDutyMS  - byte MainMotor_SetDutyMS(word Time);
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file MainMotor.c
** @version 01.00
** @brief
**         This component "PPG" implements a programmable
**         pulse generator that generates signal with variable
**         duty and variable cycle (period).
*/         
/*!
**  @addtogroup MainMotor_module MainMotor module documentation
**  @{
*/         

/* MODULE MainMotor. */

#include "MainMotor.h"

/*
** ===================================================================
**     Method      :  MainMotor_SetRatio16 (component PPG)
**     Description :
**         This method sets a new duty-cycle ratio. Ratio is expressed
**         as a 16-bit unsigned integer number. Value 0 - 65535 value
**         is proportional to ratio 0 - 100%. 
**         Note: Calculated duty depends on the timer possibilities and
**         on the selected period.
**         The method is available only if method <SetPeriodMode> is
**         not selected.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Ratio           - Ratio to set. 0 - 65535 value is
**                           proportional to ratio 0 - 100%
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
/*
byte MainMotor_SetRatio16(word Ratio)
**  This method is implemented as a macro. See MainMotor.h file.  **
*/

/*
** ===================================================================
**     Method      :  MainMotor_SetDutyUS (component PPG)
**     Description :
**         This method sets the new duty value of the output signal. The
**         duty is expressed in microseconds as a 16-bit unsigned integer
**         number.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Time       - Duty to set [in microseconds]
**                      (0 to 6803 us in high speed mode)
**     Returns     :
**         ---        - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_MATH - Overflow during evaluation
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/
byte MainMotor_SetDutyUS(word Time)
{
  LDD_TError tmp;

  tmp = PpgLdd1_SetDutyUS(PpgLdd1_DeviceData, (uint16_t)Time);
  if (tmp == ERR_PARAM_RANGE) {
    return ERR_RANGE;
  }
  return (byte)tmp;
}

/*
** ===================================================================
**     Method      :  MainMotor_SetDutyMS (component PPG)
**     Description :
**         This method sets the new duty value of the output signal. The
**         duty is expressed in milliseconds as a 16-bit unsigned integer
**         number.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Time       - Duty to set [in milliseconds]
**                      (0 to 7 ms in high speed mode)
**     Returns     :
**         ---        - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_MATH - Overflow during evaluation
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/
byte MainMotor_SetDutyMS(word Time)
{
  LDD_TError tmp;

  tmp = PpgLdd1_SetDutyUS(PpgLdd1_DeviceData, (uint16_t)Time);
  if (tmp == ERR_PARAM_RANGE) {
    return ERR_RANGE;
  }
  return (byte)tmp;
}

/* END MainMotor. */

/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.08]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/

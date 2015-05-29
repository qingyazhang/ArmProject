/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : Encoder1.h
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : ExtInt
**     Version     : Component 02.105, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-05-26, 15:48, # CodeGen: 79
**     Abstract    :
**         This component "ExtInt" implements an external 
**         interrupt, its control methods and interrupt/event 
**         handling procedure.
**         The component uses one pin which generates interrupt on 
**         selected edge.
**     Settings    :
**         Interrupt name              : INT_PORTD
**         User handling procedure     : Encoder1_OnInterrupt
**
**         Used pin                    :
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       78            |  ADC0_SE6b/PTD5/SPI1_SCK/UART2_TX/TPM0_CH5
**             ----------------------------------------------------
**
**         Port name                   : PTD
**
**         Bit number (in port)        : 5
**         Bit mask of the port        : 0x0020
**
**         Signal edge/level           : rising
**         Priority                    : 2
**         Pull option                 : off
**         Initial state               : Enabled
**
**
**         Port data register          : GPIOD_PDOR [0x400FF0C0]
**         Port control register       : GPIOD_PDDR [0x400FF0D4]
**     Contents    :
**         GetVal - bool Encoder1_GetVal(void);
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file Encoder1.h
** @version 01.00
** @brief
**         This component "ExtInt" implements an external 
**         interrupt, its control methods and interrupt/event 
**         handling procedure.
**         The component uses one pin which generates interrupt on 
**         selected edge.
*/         
/*!
**  @addtogroup Encoder1_module Encoder1 module documentation
**  @{
*/         

#ifndef __Encoder1_H
#define __Encoder1_H

/* MODULE Encoder1. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "ExtIntLdd1.h"

#include "Cpu.h"

#ifdef __cplusplus
extern "C" {
#endif 




/*
** ===================================================================
**     Method      :  Encoder1_GetVal (component ExtInt)
**     Description :
**         Returns the actual value of the input pin of the component.
**     Parameters  : None
**     Returns     :
**         ---             - Returned input value. Possible values:
**                           <false> - logical "0" (Low level) <true> -
**                           logical "1" (High level)
** ===================================================================
*/
#define Encoder1_GetVal() (ExtIntLdd1_GetVal(ExtIntLdd1_DeviceData))

void ExtIntLdd1_OnInterrupt(LDD_TUserData *UserDataPtr);

/* END Encoder1. */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __Encoder1_H */
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
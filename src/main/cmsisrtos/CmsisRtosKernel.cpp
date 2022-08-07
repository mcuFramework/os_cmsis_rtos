/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "cmsis_os2.h"

//-----------------------------------------------------------------------------------------
#include "cmsisrtos/CmsisRtosKernel.h"

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using cmsisrtos::CmsisRtosKernel;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */
/**
 * @brief Construct a new Cmsis Rtos Kernel object
 * 
 */
CmsisRtosKernel::CmsisRtosKernel(void){
  return;
}
/**
 * @brief Destroy the Cmsis Rtos Kernel object
 * 
 */
CmsisRtosKernel::~CmsisRtosKernel(void){
  return;
}
/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

/* ****************************************************************************************
 * Public Method <Override> - mcuf::lang::rtos::InterfaceKernel
 */
/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool CmsisRtosKernel::kernelInitialize(void){
  return (osKernelInitialize() == osOK);
}

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool CmsisRtosKernel::kernelStart(void){
  return (osKernelStart() == osOK);
}

/**
 * @brief 
 * 
 * @return int 
 */
int CmsisRtosKernel::kernelLock(void){
  return osKernelLock();
}

/**
 * @brief 
 * 
 * @return int 
 */
int CmsisRtosKernel::kernelUnlock(void){
  return osKernelUnlock();
}

/**
 * @brief 
 * 
 * @return uint32_t 
 */
uint32_t CmsisRtosKernel::kernelGetTickCount(void){
  return osKernelGetTickCount();
}

/**
 * @brief 
 * 
 * @return uint32_t 
 */
uint32_t CmsisRtosKernel::kernelGetTickFreq(void){
  return osKernelGetSysTimerCount();
}

/**
 * @brief 
 *  
 */
bool CmsisRtosKernel::kernelDelay(int milliseconds) const{
  if(milliseconds <= 0)
    return false;
  
  return (osDelay(static_cast<uint32_t>(milliseconds)) == osOK);
}

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool CmsisRtosKernel::kernelWait(void) const{
  osThreadFlagsClear(0x00000001U);
  osThreadFlagsWait(0x00000001U, osFlagsWaitAny, osWaitForever);
  return true;
}

/**
 * @brief 
 * 
 * @param timeout 
 * @return true 
 * @return false 
 */
bool CmsisRtosKernel::kernelWait(int timeout) const{
  if(timeout <= 0)
    return false;
  
  osThreadFlagsClear(0x00000001U);
  if(osThreadFlagsWait(0x00000001U, osFlagsWaitAny, static_cast<uint32_t>(timeout)) == osFlagsErrorTimeout)
    return true;
  
  return false;
}

/* ****************************************************************************************
 * Public Method
 */

/* ****************************************************************************************
 * Protected Method <Static>
 */

/* ****************************************************************************************
 * Protected Method <Override>
 */

/* ****************************************************************************************
 * Protected Method
 */

/* ****************************************************************************************
 * Private Method
 */

/* ****************************************************************************************
 * End of file
 */

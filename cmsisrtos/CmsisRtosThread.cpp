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
#include "../rtx/cmsis_os2.h"
#include "../rtx/rtx_os.h"

//-----------------------------------------------------------------------------------------
#include "./CmsisRtosThread.h"

/* ****************************************************************************************
 * Tyoedef Struct
 */
namespace cmsisrtos{
  typedef struct _cmsis_rtos_thread_memory_t{
    osRtxThread_t handler;
    osThreadId_t id;
  }cmsis_rtos_thread_memory_t;
}

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using cmsisrtos::CmsisRtosThread;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */
/**
 * @brief Construct a new Cmsis Rtos Thread object
 * 
 */
CmsisRtosThread::CmsisRtosThread(void){
  return;
}
/**
 * @brief Destroy the Cmsis Rtos Thread object
 * 
 */
CmsisRtosThread::~CmsisRtosThread(void){
  return;
}
/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

/* ****************************************************************************************
 * Public Method <Override> - mcuf::rtos::InterfaceThread
 */

/**
 * @brief 取的當前線程的執行ID
 * 
 * @return uint32_t 執行序ID
 */
uint32_t CmsisRtosThread::threadGetCurrentID(void) const{
  return reinterpret_cast<uint32_t>(osThreadGetId());
}

/**
 * @brief 將控制權傳遞給具有相同優先級且處於 READY 狀態的下一個線程。 
 *        如果READY狀態下沒有其他相同優先級的線程，則當前線程繼續執行，不發生線程切換。
 * 
 * @return true 控制已成功傳遞給下一個線程。
 * @return false 發生了未指定的錯誤。或者無法從中斷服務例程調用該函數。
 */
bool CmsisRtosThread::threadYield(void) const{
  return (osThreadYield() == osOK);
}
/**
 * @brief 
 * 
 * @return uint32_t 
 */
uint32_t CmsisRtosThread::threadGetHandlerSize(void) const{
  return sizeof(cmsis_rtos_thread_memory_t);
}
/**
 * @brief 
 * 
 * @return sys::ThreadState 
 */
sys::ThreadState CmsisRtosThread::threadGetState(const mcuf::Memory& handler) const{
  cmsis_rtos_thread_memory_t* h  = static_cast<cmsis_rtos_thread_memory_t*>(handler.pointer());
  
  switch(osThreadGetState(h->id)){
    case osThreadInactive:
      return sys::ThreadState::INACTIVE;
    
    case osThreadReady:
      return sys::ThreadState::READY;
    
    case osThreadRunning:
      return sys::ThreadState::RUNNING;
    
    case osThreadBlocked:
      return sys::ThreadState::BLOCKED;
    
    case osThreadTerminated:
      return sys::ThreadState::TERMINATED;
    
    case osThreadError:
      return sys::ThreadState::ERROR;
    
    case osThreadReserved:
      return sys::ThreadState::ERROR;
  }
  
  return sys::ThreadState::ERROR;
}
/**
 * @brief 
 * 
 * @param thread 
 * @param name 
 */
void CmsisRtosThread::threadSetName(mcuf::Memory& handler, const char* name){
  cmsis_rtos_thread_memory_t* h  = static_cast<cmsis_rtos_thread_memory_t*>(handler.pointer());
  h->handler.name = name;
  return;
}

/**
 * @brief 
 * 
 * @param handler 
 * @return uint32_t 
 */
uint32_t CmsisRtosThread::threadGetID(const mcuf::Memory& handler) const{
  cmsis_rtos_thread_memory_t* h  = static_cast<cmsis_rtos_thread_memory_t*>(handler.pointer());
  return reinterpret_cast<uint32_t>(h->id);
}

/**
 * @brief 
 * 
 * @param thread 
 * @return const char* 
 */
const char* CmsisRtosThread::threadGetName(const mcuf::Memory& handler) const{
  cmsis_rtos_thread_memory_t* h  = static_cast<cmsis_rtos_thread_memory_t*>(handler.pointer());
  return h->handler.name;
}
/**
 * @brief 
 * 
 * @param thread 
 * @return sys::ThreadPriority 
 */
sys::ThreadPriority CmsisRtosThread::threadGetPriority(const mcuf::Memory& handler) const{
  cmsis_rtos_thread_memory_t* h  = static_cast<cmsis_rtos_thread_memory_t*>(handler.pointer());
  return static_cast<sys::ThreadPriority>(osThreadGetPriority(h->id));
}
/**
 * @brief 
 * 
 * @param thread 
 * @param stackSize 
 * @param priority 
 * @return true 
 * @return false 
 */
bool CmsisRtosThread::threatStart(mcuf::Memory& handler, sys::ThreadPriority priority, mcuf::Memory& stackMemory, func::Runnable& runnable){
  cmsis_rtos_thread_memory_t* h  = static_cast<cmsis_rtos_thread_memory_t*>(handler.pointer());
  if(reinterpret_cast<uint32_t>(h->id) != 0)
    return false;
  
  
  osThreadAttr_t attr;
  attr.stack_mem = stackMemory.pointer();
  attr.stack_size = static_cast<uint32_t>(stackMemory.length());
  
  if(true){
    uint32_t address = reinterpret_cast<uint32_t>(attr.stack_mem);
    
    if(address & 0x000007){
      address = (address & 0x000007) + 8;
      attr.stack_size -= (address & 0x000007);
      attr.stack_mem = reinterpret_cast<void*>(address);
    }
  }
  
  if(attr.stack_size < 128)
    return false;
  
  attr.cb_mem = &h->handler;
  attr.cb_size = sizeof(h->handler);
  
  attr.name = h->handler.name;
  attr.attr_bits = osThreadDetached;
  attr.priority = static_cast<osPriority_t>(priority);
  attr.reserved = 0;
  h->id = osThreadNew(CmsisRtosThread::entryPoint, &runnable, &attr);
  
  return h->id;
}
/**
 * @brief 
 * 
 * @param thread 
 * @return sys::ThreadPriority 
 */
bool CmsisRtosThread::threadSetPriority(mcuf::Memory& handler, sys::ThreadPriority priority) const{
  cmsis_rtos_thread_memory_t* h  = static_cast<cmsis_rtos_thread_memory_t*>(handler.pointer());
  return (osThreadSetPriority(h->id, static_cast<osPriority_t>(priority)) == osOK);
}
/**
 * @brief 
 * 
 * @param thread 
 * @return true 
 * @return false 
 */
bool CmsisRtosThread::threadExit(mcuf::Memory& handler){
  osThreadExit();
}

/**
 * @brief 
 * 
 * @param thread 
 * @return int 
 */
int CmsisRtosThread::threadGetStackSize(const mcuf::Memory& handler) const{
  cmsis_rtos_thread_memory_t* h  = static_cast<cmsis_rtos_thread_memory_t*>(handler.pointer());
  return static_cast<int>(osThreadGetStackSize(h->id));
}

/**
 * @brief 
 * 
 * @param thread 
 * @return true 
 * @return false 
 */
bool CmsisRtosThread::threadNotify(const mcuf::Memory& handler) const{
  cmsis_rtos_thread_memory_t* h  = static_cast<cmsis_rtos_thread_memory_t*>(handler.pointer());
  return (osThreadFlagsSet(h->id, 0x00000001U) == osOK);
}

/**
 * @brief 
 * 
 * @param threadID 
 * @return true 
 * @return false 
 */
bool CmsisRtosThread::threadNotify(uint32_t threadID) const{
  return (osThreadFlagsSet(reinterpret_cast<osThreadId_t>(threadID), 0x00000001U) == osOK);
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

/**
 * @brief 
 * 
 * @param attachment 
 */
void CmsisRtosThread::entryPoint(void* attachment){
  ASSERT(attachment, __CLASSPATH__, ErrorCode::NULL_POINTER);
  
  func::Runnable* runnable = static_cast<func::Runnable*>(attachment);
  runnable->run();
  osThreadExit();
}

/* ****************************************************************************************
 * End of file
 */

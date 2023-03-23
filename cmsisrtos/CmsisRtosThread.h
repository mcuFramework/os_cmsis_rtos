/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef CMSISRTOS_9D881823_0A3B_4E45_B5C7_EDF387D559D9
#define CMSISRTOS_9D881823_0A3B_4E45_B5C7_EDF387D559D9

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "mcuf/package-info.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */  
namespace cmsisrtos{
  class CmsisRtosThread;
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */  
class cmsisrtos::CmsisRtosThread extends mcuf::Object implements
        public rtos::InterfaceThread{

  /* **************************************************************************************
   * Variable <Public>
   */

  /* **************************************************************************************
   * Variable <Protected>
   */

  /* **************************************************************************************
   * Variable <Private>
   */

  /* **************************************************************************************
   * Abstract method <Public>
   */

  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
   * Construct Method
   */
  public: 
    /**
     * @brief Construct a new Cmsis Rtos Thread object
     * 
     */
    CmsisRtosThread(void);

    /**
     * @brief Destroy the Cmsis Rtos Thread object
     * 
     */
    virtual ~CmsisRtosThread(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override>
   */
  public:
    /**
     * @brief 取的當前線程的執行ID
     * 
     * @return uint32_t 執行序ID
     */
    virtual uint32_t threadGetCurrentID(void) const override;

    /**
     * @brief 將控制權傳遞給具有相同優先級且處於 READY 狀態的下一個線程。 
     *        如果READY狀態下沒有其他相同優先級的線程，則當前線程繼續執行，不發生線程切換。
     * 
     * @return true 控制已成功傳遞給下一個線程。
     * @return false 發生了未指定的錯誤。或者無法從中斷服務例程調用該函數。
     */
    virtual bool threadYield(void) const override;

    /**
     * @brief 
     * 
     * @return uint32_t 
     */
    virtual uint32_t threadGetHandlerSize(void) const override;

    /**
     * @brief 
     * 
     * @return mcuf::ThreadState 
     */
    virtual mcuf::ThreadState threadGetState(const mcuf::Memory& handler) const override;

    /**
     * @brief 
     * 
     * @param thread 
     * @param name 
     */
    virtual void threadSetName(mcuf::Memory& handler, const char* name) override;
    
    /**
     * @brief 
     * 
     * @param handler 
     * @return uint32_t 
     */
    virtual uint32_t threadGetID(const mcuf::Memory& handler) const override;
    
    /**
     * @brief 
     * 
     * @param thread 
     * @return const char* 
     */
    virtual const char* threadGetName(const mcuf::Memory& handler) const override;

    /**
     * @brief 
     * 
     * @param thread 
     * @return mcuf::ThreadPriority 
     */
    virtual mcuf::ThreadPriority threadGetPriority(const mcuf::Memory& handler) const override;
      
    /**
     * @brief 
     * 
     * @param handler 
     * @param priority 
     * @param stackMemory 
     * @param runnable 
     * @return true 
     * @return false 
     */
    virtual bool threatStart(mcuf::Memory& handler, mcuf::ThreadPriority priority, mcuf::Memory& stackMemory, func::Runnable& runnable) override;

    /**
     * @brief 
     * 
     * @param thread 
     * @return mcuf::ThreadPriority 
     */
    virtual bool threadSetPriority(mcuf::Memory& handler,  mcuf::ThreadPriority) const override;

    /**
     * @brief 
     * 
     * @param thread 
     * @return true 
     * @return false 
     */
    virtual bool threadExit(mcuf::Memory& handler) override;
    
    /**
     * @brief 
     * 
     * @param thread 
     * @return int 
     */
    virtual int threadGetStackSize(const mcuf::Memory& handler) const override;

    /**
     * @brief 
     * 
     * @param thread 
     * @return true 
     * @return false 
     */
    virtual bool threadNotify(const mcuf::Memory& handler) const override;

    /**
     * @brief 
     * 
     * @param threadID 
     * @return true 
     * @return false 
     */
    virtual bool threadNotify(uint32_t threadID) const override;

  /* **************************************************************************************
   * Public Method
   */

  /* **************************************************************************************
   * Protected Method <Static>
   */

  /* **************************************************************************************
   * Protected Method <Override>
   */

  /* **************************************************************************************
   * Protected Method
   */

  /* **************************************************************************************
   * Private Method <Static>
   */
  private:

    /**
     * @brief 
     * 
     * @param attachment 
     */
    static void entryPoint(void* attachment);

  /* **************************************************************************************
   * Private Method <Override>
   */

  /* **************************************************************************************
   * Private Method
   */

};

/* ****************************************************************************************
 * End of file
 */ 

#endif /* CMSISRTOS_9D881823_0A3B_4E45_B5C7_EDF387D559D9 */

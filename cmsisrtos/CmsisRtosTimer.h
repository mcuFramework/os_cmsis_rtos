/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef CMSISRTOS_B8299F1B_6D5F_4D4A_B524_B23A774599B7
#define CMSISRTOS_B8299F1B_6D5F_4D4A_B524_B23A774599B7

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
  class CmsisRtosTimer;
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */  
class cmsisrtos::CmsisRtosTimer extends mcuf::Object implements 
        public rtos::InterfaceTimer{

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
     * @brief Construct a new Cmsis Rtos Timer object
     * 
     */
    CmsisRtosTimer(void);
    /**
     * @brief Destroy the Cmsis Rtos Timer object
     * 
     */
    virtual ~CmsisRtosTimer(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override> - mcuf::rtos::InterfaceTimer
   */
  public:
    /**
     * @brief 
     * 
     * @return uint32_t 
     */
    virtual uint32_t timerGetHandlerSize(void) const override;

    /**
     * @brief 
     * 
     * @param timerTask 
     * @param delay 延遲時間 單位ms
     * @param mode false = 單次; true = 循環
     * @param runnable 直行進入點
     * @return true TimerID
     */
    virtual bool timerStart(mcuf::Memory& handler, uint32_t delay, bool mode, func::Runnable& runnable) override;

    /**
     * @brief 停止Timer
     * 
     * @param timerTask 
     * @return true 停止成功
     * @return false Timer尚未啟動
     */
    virtual bool timerStop(mcuf::Memory& handler) override;

    /**
     * @brief 回傳timer是否已啟動
     * 
     * @param timerTask 
     * @return true Timer狀態啟動
     * @return false Timer狀態閒置
     */
    virtual bool timerIsStart(mcuf::Memory& handler) override;
    
    /**
     * @brief 
     * 
     * @param handler 
     * @return uint32_t 
     */
    virtual uint32_t timerGetID(mcuf::Memory& handler) override;
    
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

#endif /* CMSISRTOS_B8299F1B_6D5F_4D4A_B524_B23A774599B7 */

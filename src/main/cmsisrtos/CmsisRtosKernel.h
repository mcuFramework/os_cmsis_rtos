/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef CMSISRTOS_493632CE_0816_452F_834F_04F3AA7010D4
#define CMSISRTOS_493632CE_0816_452F_834F_04F3AA7010D4

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "mcuf.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */  
namespace cmsisrtos{
  class CmsisRtosKernel;
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */  
class cmsisrtos::CmsisRtosKernel extends mcuf::lang::Object implements
public mcuf::lang::rtos::InterfaceKernel{

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
     * @brief Construct a new Cmsis Rtos Kernel object
     * 
     */
    CmsisRtosKernel(void);

    /**
     * @brief Destroy the Cmsis Rtos Kernel object
     * 
     */
    virtual ~CmsisRtosKernel(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override> - mcuf::lang::rtos::InterfaceKernel
   */
  public:
    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    virtual bool kernelInitialize(void) override;

    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    virtual bool kernelStart(void) override;

    /**
     * @brief 
     * 
     * @return int 
     */
    virtual int kernelLock(void) override;

    /**
     * @brief 
     * 
     * @return int 
     */
    virtual int kernelUnlock(void) override;

    /**
     * @brief 
     * 
     * @return uint32_t 
     */
    virtual uint32_t kernelGetTickCount(void) override;

    /**
     * @brief 
     * 
     * @return uint32_t 
     */
    virtual uint32_t kernelGetTickFreq(void) override;
    
    /**
     * @brief 
     *  
     */
    virtual bool kernelDelay(int milliseconds) const override;
    
    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    virtual bool kernelWait(void) const override;
    
    /**
     * @brief 
     * 
     * @param timeout 
     * @return true 
     * @return false 
     */
    virtual bool kernelWait(int timeout) const override;

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

#endif /* CMSISRTOS_493632CE_0816_452F_834F_04F3AA7010D4 */

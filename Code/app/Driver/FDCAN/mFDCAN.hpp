
#pragma once
#include "main.h"

#ifdef STM32H7xx_HAL_FDCAN_H
#include "stm32h7xx_hal_fdcan.h"
#elif
#include "fdcan.h
#endif

#include "mFDCAN_data_template.hpp"

class mFDCAN_Class : mFDCAN_template_Class{
    public:
        mFDCAN_template_Class::function_return_template Init();
        mFDCAN_template_Class::function_return_template Send();

        void TxCallback();
        void RxCallback();
        
        void Callback_Port1();
        void Callback_Port2();
        void Callback_Port3();

};

extern mFDCAN_Class mFDCAN;

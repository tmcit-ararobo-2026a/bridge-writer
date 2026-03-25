
#pragma once
#include "data_template.hpp"

class mFDCAN_Class : mFDCAN_template_Class{
    public:
        function_return_template Init();
        function_return_template Send();
        void Callback();
        
        void Callback_Port1();
        void Callback_Port2();
        void Callback_Port3();

        void Error(Error_Handler_type error);
};

extern mFDCAN_Class mFDCAN;

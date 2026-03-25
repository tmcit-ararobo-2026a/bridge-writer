
#pragma once
#include <cstdint>

class mFDCAN_template_Class{
    public:
        typedef bool function_return_template;
        /**
         * function_return_template
         * Variable Type boolean
         * 1 = COMPLETE
         * 0 = ERROR
         */

        typedef bool error_flag;
        /**
         * error_flag
         * Variable Type boolean
         * 1 = Error
         * 0 = No Error
         */

        typedef struct{
            struct{
                error_flag Config;
                error_flag Start;
                error_flag Active_RxCallBack;
                error_flag Active_TxCallBack;
            }Init;//In Init Function
            struct{

            }Send;//In Send Function
            struct{

            }TxCallBack;//In TxCallBack Function
            struct{

            }RxCallBack;//In RxCallBack Function
        }Error_Handler_TypeDef;
};


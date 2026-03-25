
#include "mFDCAN.hpp"
#include "mFDCAN_data_template.hpp"

bool mFDCAN_Class::Init(fdcan_setting_Handler_TypeDef *set)
{
    FDCAN_FilterTypeDef FDCAN_filter;
    
    HAL_FDCAN_Stop(set->hfdcanx);

    FDCAN_filter.IdType = FDCAN_STANDARD_ID;
    FDCAN_filter.FilterIndex = 0;
    FDCAN_filter.FilterType = FDCAN_FILTER_MASK;
    FDCAN_filter.FilterConfig = FDCAN_FILTER_TO_RXFIFO0;
    FDCAN_filter.FilterID1 = 0;
    FDCAN_filter.FilterID2 = 0;

    if(HAL_FDCAN_ConfigFilter(set->hfdcanx, &FDCAN_filter) != HAL_OK)
    {
        Error.Init.Config = 1;
    }
    if(HAL_FDCAN_Start(set->hfdcanx) != HAL_OK)
    {
        Error.Init.Start = 1;
    }


    if(set->CallBack.Fifo0)
    {
        if(HAL_FDCAN_ActivateNotification(set->hfdcanx, FDCAN_IT_RX_FIFO0_NEW_MESSAGE, 0) != HAL_OK){
            Error.Init.Active_RxCallBack_Fifo0 = 1;
            Error.Init.Deactive_RxCallBack_Fifo0 = 0;
        }
    }else
    {
        if(HAL_FDCAN_DeactivateNotification(set->hfdcanx, FDCAN_IT_RX_FIFO0_NEW_MESSAGE) != HAL_OK){
            Error.Init.Active_RxCallBack_Fifo0 = 0;
            Error.Init.Deactive_RxCallBack_Fifo0 = 1;
        }
    }

    if(set->CallBack.Fifo1)
    {
        if(HAL_FDCAN_ActivateNotification(set->hfdcanx, FDCAN_IT_RX_FIFO1_NEW_MESSAGE, 0) != HAL_OK){
            Error.Init.Active_RxCallBack_Fifo1 = 1;
            Error.Init.Deactive_RxCallBack_Fifo1 = 0;
        }
    }else
    {
        if(HAL_FDCAN_DeactivateNotification(set->hfdcanx, FDCAN_IT_RX_FIFO1_NEW_MESSAGE) != HAL_OK){
            Error.Init.Active_RxCallBack_Fifo1 = 0;
            Error.Init.Deactive_RxCallBack_Fifo1 = 1;
        }
    }

    if(set->CallBack.Tx_Event)
    {
        if(HAL_FDCAN_ActivateNotification(set->hfdcanx, FDCAN_IT_TX_COMPLETE, 0) != HAL_OK){
            Error.Init.Active_TxCallBack = 1;
            Error.Init.Deactive_TxCallBack = 0;
        }
    }else
    {
        if(HAL_FDCAN_DeactivateNotification(set->hfdcanx, FDCAN_IT_TX_COMPLETE) != HAL_OK){
            Error.Init.Active_TxCallBack = 0;
            Error.Init.Deactive_TxCallBack = 1;
        }
    }

    if(set->CallBack.Tx_Fifo_Empty){
        if(HAL_FDCAN_ActivateNotification(set->hfdcanx, FDCAN_IT_TX_ABORT_COMPLETE, 0) != HAL_OK){
            Error.Init.Active_TxFifoEmpty_CallBack = 1;
            Error.Init.Deactive_TxFifoEmpty_CallBack = 0;
        }
    }else
    {
        if(HAL_FDCAN_DeactivateNotification(set->hfdcanx, FDCAN_IT_TX_ABORT_COMPLETE) != HAL_OK){
            Error.Init.Active_TxFifoEmpty_CallBack = 0;
            Error.Init.Deactive_TxFifoEmpty_CallBack = 1;
        }
    }

    if(set->timeout_counter != 0)
    {
        uint32_t bit_count;
        uint32_t bit_rate;
        //HAL_FDCAN_EnableTimeoutCounter(set->hfdcanx);

        switch(set->bit_rate){

            case bit_rate_type::_1Mbps_:
                bit_rate = 1000000U;
            break;

            case bit_rate_type::_2Mbps_:
                bit_rate = 2000000U;
            break;

            case bit_rate_type::_3Mbps_:
                bit_rate = 3000000U;
            break;

            case bit_rate_type::_4Mbps_:
                bit_rate = 4000000U;
            break;

            case bit_rate_type::_5Mbps_:
                bit_rate = 5000000U;
            break;
        }

        bit_count = bit_rate / set->timeout_counter;

        if(set->fifo_num == Fifo_num_type::FIFO0)
        {
            HAL_FDCAN_ConfigTimeoutCounter(set->hfdcanx, FDCAN_TIMEOUT_RX_FIFO0, bit_count);
        }else if(set->fifo_num == Fifo_num_type::FIFO1)
        {
            HAL_FDCAN_ConfigTimeoutCounter(set->hfdcanx, FDCAN_TIMEOUT_RX_FIFO1, bit_count);
        }

        if(HAL_FDCAN_ActivateNotification(set->hfdcanx, FDCAN_IT_TIMEOUT_OCCURRED, 0) != HAL_OK)
        {
            Error.Init.Active_TimeOut_CallBack = 1;
            Error.Init.Deactive_TimeOut_CallBack = 0;
        }
    }else{
        HAL_FDCAN_DisableTimeoutCounter(set->hfdcanx);
        
        if(HAL_FDCAN_DeactivateNotification(set->hfdcanx, FDCAN_IT_TIMEOUT_OCCURRED) != HAL_OK)
        {
            Error.Init.Active_TimeOut_CallBack = 0;
            Error.Init.Deactive_TimeOut_CallBack = 1;
        }
    }


    return 1;
}

mFDCAN_Class mFDCAN;

extern "C"{

    /*----------------------------------------------------------------------------------------------------*/

    void HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo0ITs)
    {

    }
    //Fifo0 Callback

    /*----------------------------------------------------------------------------------------------------*/
    
    void HAL_FDCAN_RxFifo1Callback(FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo0ITs)
    {
        
    }
    //Fifo1 Callback

    /*----------------------------------------------------------------------------------------------------*/

    void HAL_FDCAN_TxEventFifoCallback(FDCAN_HandleTypeDef *hfdcan, uint32_t TxEventFifoITs)
    {

    }
    //Tx event callback

    /*----------------------------------------------------------------------------------------------------*/

    void HAL_FDCAN_TxFifoEmptyCallback(FDCAN_HandleTypeDef *hfdcan)
    {

    }
    //tx fifo empty callback

    /*----------------------------------------------------------------------------------------------------*/

    void HAL_FDCAN_TimeoutOccurredCallback(FDCAN_HandleTypeDef *hfdcan)
    {

    }
    //timeout
    
    /*----------------------------------------------------------------------------------------------------*/

}
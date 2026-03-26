
#include "mFDCAN.hpp"
#include "mFDCAN_data_template.hpp"

bool mFDCAN_Class::Init(fdcan_setting_Handle_TypeDef *set)
{
    FDCAN_FilterTypeDef FDCAN_filter;
    bool using_error;
    
    HAL_FDCAN_Stop(set->hfdcanx);/*設定中はfdcanを止める*/

    FDCAN_filter.IdType = FDCAN_STANDARD_ID;
    FDCAN_filter.FilterIndex = 0;
    FDCAN_filter.FilterType = FDCAN_FILTER_MASK;

    if(set->fifo_num == Fifo_num_type::FIFO0)FDCAN_filter.FilterConfig = FDCAN_FILTER_TO_RXFIFO0;
    else if(set->fifo_num == Fifo_num_type::FIFO1)FDCAN_filter.FilterConfig = FDCAN_FILTER_TO_RXFIFO1;
    else
    /*使用するfifoを指定する*/

    FDCAN_filter.FilterID1 = 0;
    FDCAN_filter.FilterID2 = 0;

    if(HAL_FDCAN_ConfigFilter(set->hfdcanx, &FDCAN_filter) != HAL_OK)
    {
        Error.Init.Config = 1;
        using_error = 1;
    }

    if(set->fifo_num == Fifo_num_type::FIFO0)
    {
        if(HAL_FDCAN_ActivateNotification(set->hfdcanx, FDCAN_IT_RX_FIFO0_NEW_MESSAGE, 0) != HAL_OK){
            Error.Init.Active_RxCallBack_Fifo = 1;
            Error.Init.Deactive_RxCallBack_Fifo = 0;
            using_error = 1;
        }
        
        if(HAL_FDCAN_DeactivateNotification(set->hfdcanx, FDCAN_IT_RX_FIFO1_NEW_MESSAGE) != HAL_OK){
            Error.Init.Active_RxCallBack_Fifo = 0;
            Error.Init.Deactive_RxCallBack_Fifo = 1;
            using_error = 1;
        }
    }else if(set->fifo_num == Fifo_num_type::FIFO1)
    {
        if(HAL_FDCAN_ActivateNotification(set->hfdcanx, FDCAN_IT_RX_FIFO1_NEW_MESSAGE, 0) != HAL_OK){
            Error.Init.Active_RxCallBack_Fifo = 1;
            Error.Init.Deactive_RxCallBack_Fifo = 0;
            using_error = 1;
        }

        if(HAL_FDCAN_DeactivateNotification(set->hfdcanx, FDCAN_IT_RX_FIFO0_NEW_MESSAGE) != HAL_OK){
            Error.Init.Active_RxCallBack_Fifo = 0;
            Error.Init.Deactive_RxCallBack_Fifo = 1;
            using_error = 1;
        }
    }
    else

    if(set->CallBack.Tx_Event)
    {
        if(HAL_FDCAN_ActivateNotification(set->hfdcanx, FDCAN_IT_TX_COMPLETE, 0) != HAL_OK){
            Error.Init.Active_TxCallBack = 1;
            Error.Init.Deactive_TxCallBack = 0;
            using_error = 1;
        }
    }else
    {
        if(HAL_FDCAN_DeactivateNotification(set->hfdcanx, FDCAN_IT_TX_COMPLETE) != HAL_OK){
            Error.Init.Active_TxCallBack = 0;
            Error.Init.Deactive_TxCallBack = 1;
            using_error = 1;
        }
    }

    if(set->CallBack.Tx_Fifo_Empty){
        if(HAL_FDCAN_ActivateNotification(set->hfdcanx, FDCAN_IT_TX_ABORT_COMPLETE, 0) != HAL_OK){
            Error.Init.Active_TxFifoEmpty_CallBack = 1;
            Error.Init.Deactive_TxFifoEmpty_CallBack = 0;
            using_error = 1;
        }
    }else
    {
        if(HAL_FDCAN_DeactivateNotification(set->hfdcanx, FDCAN_IT_TX_ABORT_COMPLETE) != HAL_OK){
            Error.Init.Active_TxFifoEmpty_CallBack = 0;
            Error.Init.Deactive_TxFifoEmpty_CallBack = 1;
            using_error = 1;
        }
    }

    if(set->RxTimeOutCycle != 0)
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

        bit_count = bit_rate / (set->RxTimeOutCycle * 1000);

        if(set->fifo_num == Fifo_num_type::FIFO0)
        {
            HAL_FDCAN_ConfigTimeoutCounter(set->hfdcanx, FDCAN_TIMEOUT_RX_FIFO0, bit_count);
        }else if(set->fifo_num == Fifo_num_type::FIFO1)
        {
            HAL_FDCAN_ConfigTimeoutCounter(set->hfdcanx, FDCAN_TIMEOUT_RX_FIFO1, bit_count);
        }
        else

        if(HAL_FDCAN_ActivateNotification(set->hfdcanx, FDCAN_IT_TIMEOUT_OCCURRED, 0) != HAL_OK)
        {
            Error.Init.Active_TimeOut_CallBack = 1;
            Error.Init.Deactive_TimeOut_CallBack = 0;
            using_error = 1;
        }
    }
    else
    {
        HAL_FDCAN_DisableTimeoutCounter(set->hfdcanx);
        
        if(HAL_FDCAN_DeactivateNotification(set->hfdcanx, FDCAN_IT_TIMEOUT_OCCURRED) != HAL_OK)
        {
            Error.Init.Active_TimeOut_CallBack = 0;
            Error.Init.Deactive_TimeOut_CallBack = 1;
            using_error = 1;
        }
    }

    switch(set->hfdcan_port)
    {
        case fdcan_ports::FDCAN1_Port:
            FDCAN_Port1_set.hfdcanx = set->hfdcanx;
            FDCAN_Port1_set.hfdcan_frame = set->hfdcan_frame;
        break;
        
        case fdcan_ports::FDCAN2_Port:
            FDCAN_Port2_set.hfdcanx = set->hfdcanx;
            FDCAN_Port2_set.hfdcan_frame = set->hfdcan_frame;
        break;
        
        case fdcan_ports::FDCAN3_Port:
            FDCAN_Port3_set.hfdcanx = set->hfdcanx;
            FDCAN_Port3_set.hfdcan_frame = set->hfdcan_frame;
        break;
    }

    if(HAL_FDCAN_Start(set->hfdcanx) != HAL_OK)
    {
        Error.Init.Start = 1;
        using_error = 1;
    }

    if(!using_error) return 0;

    return 1;
}

bool mFDCAN_Class::Send(fdcan_TxData_Handle_TypeDef *data)
{
    if(Tx_Fifo_prohibited) return 0;

    FDCAN_TxHeaderTypeDef FDCAN_TxHeader;
    FDCAN_HandleTypeDef *hfdcanx;
    can_frame_type hfdcan_frame;

    switch(data->FDCAN_Port)
    {
        case fdcan_ports::FDCAN1_Port:
            hfdcanx = FDCAN_Port1_set.hfdcanx;
            hfdcan_frame = FDCAN_Port1_set.hfdcan_frame;
            if(FDCAN_Port1_Stack.tx_events > 15)
            {
                Error.Send.TxFifo_full_Port = 1;
                return 0;
            }
        break;
        
        case fdcan_ports::FDCAN2_Port:
            hfdcanx = FDCAN_Port2_set.hfdcanx;
            hfdcan_frame = FDCAN_Port2_set.hfdcan_frame;
            if(FDCAN_Port2_Stack.tx_events > 15)
            {
                Error.Send.TxFifo_full_Port = 1;
                return 0;
            }
        break;
        
        case fdcan_ports::FDCAN3_Port:
            hfdcanx = FDCAN_Port3_set.hfdcanx;
            hfdcan_frame = FDCAN_Port3_set.hfdcan_frame;
            if(FDCAN_Port3_Stack.tx_events > 15)
            {
                Error.Send.User_TxFifo_full_Port = 1;
                return 0;
            }
        break;
    }

    if(HAL_FDCAN_GetTxFifoFreeLevel(hfdcanx) == 0)
    {
        Error.Send.TxFifo_full_Port = 1;
        return 0;
    }

    if(hfdcan_frame == can_frame_type::classic_can)
    {
        if(data->Len > 8) data->Len = 8;
        if(data->Id > 0x7FF)
        {
            Error.Send.over_Id_value = 1;
            return 0;
        }
    }
    else if(hfdcan_frame == can_frame_type::fdcan)
    {
        if(data->Len > 64) data->Len = 64;
        if(data->Id > 0x1FFFFFFF)
        {
            Error.Send.over_Id_value = 1;
            return 0;
        }
    }

    FDCAN_TxHeader.Identifier = data->Id;
    FDCAN_TxHeader.IdType = FDCAN_STANDARD_ID;
    FDCAN_TxHeader.TxFrameType = FDCAN_DATA_FRAME;
    FDCAN_TxHeader.DataLength = dlc_table[data->Len];
    FDCAN_TxHeader.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
    FDCAN_TxHeader.BitRateSwitch = FDCAN_BRS_OFF;
    FDCAN_TxHeader.FDFormat = FDCAN_CLASSIC_CAN;
    FDCAN_TxHeader.TxEventFifoControl = FDCAN_STORE_TX_EVENTS;
    FDCAN_TxHeader.MessageMarker = 0;

    if(HAL_FDCAN_AddMessageToTxFifoQ(hfdcanx, &FDCAN_TxHeader, data->data_p) != HAL_OK)
    {
        Error.Send.Add_New_TxMessage = 1;
        return 0;
    }

    switch(data->FDCAN_Port)
    {
        case fdcan_ports::FDCAN1_Port:
            ++FDCAN_Port1_Stack.tx_events;
        break;
        
        case fdcan_ports::FDCAN2_Port:
            ++FDCAN_Port2_Stack.tx_events;
        break;
        
        case fdcan_ports::FDCAN3_Port:
            ++FDCAN_Port3_Stack.tx_events;
        break;
    }

    return 1;
}

void mFDCAN_Class::TxCallback(fdcan_CallBack_Handle_TypeDef *data){

}

void mFDCAN_Class::RxCallback_Fifo0(fdcan_CallBack_Handle_TypeDef *data){

}

void mFDCAN_Class::RxCallback_Fifo1(fdcan_CallBack_Handle_TypeDef *data){

}

mFDCAN_Class mFDCAN;

extern "C"{

    /*----------------------------------------------------------------------------------------------------*/

    void HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo0ITs)
    {
        mFDCAN.fdcan_RxCallBack_Fifo0.hfdcanx = hfdcan;
        mFDCAN.fdcan_RxCallBack_Fifo0.State = RxFifo0ITs;
        mFDCAN.RxCallback_Fifo0(&mFDCAN.fdcan_RxCallBack_Fifo0);
    }
    //Fifo0 Callback

    /*----------------------------------------------------------------------------------------------------*/
    
    void HAL_FDCAN_RxFifo1Callback(FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo0ITs)
    {
        mFDCAN.fdcan_RxCallBack_Fifo1.hfdcanx = hfdcan;
        mFDCAN.fdcan_RxCallBack_Fifo1.State = RxFifo0ITs;
        mFDCAN.RxCallback_Fifo1(&mFDCAN.fdcan_RxCallBack_Fifo1);
    }
    //Fifo1 Callback

    /*----------------------------------------------------------------------------------------------------*/

    void HAL_FDCAN_TxEventFifoCallback(FDCAN_HandleTypeDef *hfdcan, uint32_t TxEventFifoITs)
    {
        mFDCAN.fdcan_TxCallBack.hfdcanx = hfdcan;
        mFDCAN.fdcan_TxCallBack.State = TxEventFifoITs;
        mFDCAN.TxCallback(&mFDCAN.fdcan_TxCallBack);
    }
    //Tx event callback

    /*----------------------------------------------------------------------------------------------------*/

    void HAL_FDCAN_TxFifoEmptyCallback(FDCAN_HandleTypeDef *hfdcan)
    {
        mFDCAN.Tx_Fifo_prohibited = 1;
    }
    //tx fifo empty callback

    /*----------------------------------------------------------------------------------------------------*/

    void HAL_FDCAN_TimeoutOccurredCallback(FDCAN_HandleTypeDef *hfdcan)
    {

    }
    //timeout
    
    /*----------------------------------------------------------------------------------------------------*/

}
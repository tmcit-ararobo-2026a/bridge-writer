
#include "main_FW.hpp"

void mmain_FW_Class::setup(){
    fdcan_setting.hfdcanx = &hfdcan1;
    fdcan_setting.hfdcan_port = mFDCAN_template_Class::fdcan_ports::FDCAN1_Port;
    fdcan_setting.fifo_num = mFDCAN_template_Class::Fifo_num_type::FIFO0;
    fdcan_setting.hfdcan_frame = mFDCAN_template_Class::can_frame_type::classic_can;
    fdcan_setting.TxCycle = 1;
    fdcan_setting.RxTimeOutCycle = 0;
    fdcan_setting.CallBack.Tx_Event = 1;
    fdcan_setting.CallBack.Tx_Fifo_Empty = 1;
    fdcan_setting.bit_rate = mFDCAN_template_Class::bit_rate_type::_1Mbps_;
    mFDCAN.Init(&fdcan_setting);

    fdcan_txdata.FDCAN_Port = mFDCAN_template_Class::fdcan_ports::FDCAN1_Port;
    fdcan_txdata.Id = 0x00;
    fdcan_txdata.Len = 0x01;
    fdcan_txdata.data_p = NULL;
    mFDCAN.Send(&fdcan_txdata);
}

void mmain_FW_Class::loop(){

}

mmain_FW_Class mmain_FW;


#include "mFDCAN.hpp"
#include "mFDCAN_data_template.hpp"

mFDCAN_template_Class::function_return_template mFDCAN_Class::Init(){
    FDCAN_FilterTypeDef FDCAN_filter;
    
    FDCAN_filter.IdType = FDCAN_STANDARD_ID;
    FDCAN_filter.FilterIndex = 0;
    FDCAN_filter.FilterType = FDCAN_FILTER_MASK;
    FDCAN_filter.FilterConfig = FDCAN_FILTER_TO_RXFIFO0;
    FDCAN_filter.FilterID1 = 0;
    FDCAN_filter.FilterID2 = 0;
}

mFDCAN_Class mFDCAN;

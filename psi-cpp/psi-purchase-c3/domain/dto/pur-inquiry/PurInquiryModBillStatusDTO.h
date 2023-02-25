#pragma once
#ifndef __PUR_INQUIRY_MOD_BILL_STATUS_DTO_H__
#define __PUR_INQUIRY_MOD_BILL_STATUS_DTO_H__
#include "../../GlobalInclude.h"

//单据状态DTO
class PurInquiryModBillStatusDTO
{
	//已关闭			;
	CC_SYNTHESIZE(int, is_close, Is_close);
	//是否作废			;
	CC_SYNTHESIZE(int, is_voided, Is_voided);
	//订单编号
	CC_SYNTHESIZE(string, bill_no, Bill_no);
public:
	friend void from_json(const json& j, PurInquiryModBillStatusDTO& t)
	{
		BIND_FROM_TO_I(j, t, is_close);
		BIND_FROM_TO_I(j, t, is_voided);
		BIND_FROM_TO_NORMAL(j, t, bill_no);
	}


};


#endif  //__PURINQUIRYMODBILLSTATUSDTO_H__

#pragma once

#ifndef __ADD_PUR_INQUIRY_VO_H__
#define __ADD_PUR_INQUIRY_VO_H__
#include <vector>
#include "../../GlobalInclude.h"

//付款方式
class AddPurInquiryVO
{
	CC_SYNTHESIZE(std::vector<string>, payment, Payment);

public:
	BIND_TO_JSON(AddPurInquiryVO, payment);
	AddPurInquiryVO()
	{
		payment.push_back(u8"全款到发货");
		payment.push_back(u8"货到付全款");
		payment.push_back(u8"发票到付全款");
		payment.push_back(u8"发票到付余款 ");
	}
};


#endif  //__ADDPURINQUIRYVO_H__

#pragma once
#ifndef __PUR_INQUIRY_REMOVE_DTO_H__
#define __PUR_INQUIRY_REMOVE_DTO_H__
#include "../../GlobalInclude.h"
//删除DTO
class PurInquiryRemoveDTO
{
	//单据编号
	CC_SYNTHESIZE(string, bill_no, Bill_no);

public:
	friend void from_json(const json& j, PurInquiryRemoveDTO& t)
	{
		BIND_FROM_TO_NORMAL(j, t, bill_no);
	}
};


#endif  //__PURINQUIRYREMOVEDTO_H__
#pragma once
#ifndef _ENTRYPURINQUIRY_DTO_
#define _ENTRYPURINQUIRY_DTO_

#include "../../GlobalInclude.h"

/**
 * 传输对象 —— 单据编号（根据单据编号匹配对应的明细列表）
 */

//指定询价单的明细分录 
class EntryPurInquiryDTO
{
	//单据编号
	CC_SYNTHESIZE(string, purInquiryBillNo, PurInquiryBillNo);    // 对应mysql数据库中bill_no字段

public:
	// 绑定from_json
	friend void from_json(const json& j, EntryPurInquiryDTO& t);  // NOLINT
	BIND_TO_JSON(EntryPurInquiryDTO, purInquiryBillNo);
};

#endif // !_ENTRYPURINQUIRYDTO_
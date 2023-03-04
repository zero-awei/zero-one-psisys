#pragma once
#ifndef _ADDZDRKBILL_DTO_
#define _ADDZDRKBILL_DTO_

#include "../../GlobalInclude.h"
#include "../../dto/Zdrk/ZdrkBillDetailDTO.h"
#include "../FileDTO.h"
/**
 * 添加单据传输对象
 */
class AddZdrkBillDTO : public FileDTO
{
	// 单据编号
	CC_SYNTHESIZE(string, billNo, BillNo);
	// 单据日期
	CC_SYNTHESIZE(string, billDate, BillDate);
	// 单据主题
	CC_SYNTHESIZE(string, subject, Subject);
	// 供应商
	CC_SYNTHESIZE(string, supplier, Supplier);
	// 盘点经办
	CC_SYNTHESIZE(string, handler, Handler);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
	// 保存or提交(0:保存, 1:提交)
	CC_SYNTHESIZE(int, save, Save);
	// 明细
	CC_SYNTHESIZE(list<ZdrkBillDetailDTO>, detail, Detail);

public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, AddZdrkBillDTO& t); // NOLINT
};

#endif // !_ADDZDRKBILL_DTO
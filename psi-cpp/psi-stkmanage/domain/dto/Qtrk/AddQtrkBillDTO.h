#pragma once

#ifndef _AddQtrkBill_DTO_
#define _AddQtrkBill_DTO_

#include "../../GlobalInclude.h"
#include "../FileDTO.h"
#include "QtrkBillDetailDTO.h"

/**
 * 添加其他入库单传输对象
 */
class AddQtrkBillDTO : public FileDTO
{
	// 单据编号
	CC_SYNTHESIZE(string, billNo, BillNo);
	// 单据日期
	CC_SYNTHESIZE(string, billDate, BillDate);
	// 单据主题
	CC_SYNTHESIZE(string, subject, Subject);
	// 盘点经办
	CC_SYNTHESIZE(string, handler, Handler);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
	// 保存or提交(0:保存, 1:提交)
	CC_SYNTHESIZE(int, save, Save);
	// 明细
	CC_SYNTHESIZE(list<QtrkBillDetailDTO>, detail, Detail);
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, AddQtrkBillDTO& t); // NOLINT
};

#endif // !_AddQtrkBill_DTO_
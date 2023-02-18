#pragma once

#ifndef _AddQtrkBill_DTO_
#define _AddQtrkBill_DTO_
#include "../../GlobalInclude.h"
/**
 * 添加其他入库单传输对象
 */
class AddQtrkBillDTO
{
	// 单据编号
	//CC_SYNTHESIZE(uint64_t, id, Id);
	// 单据日期
	CC_SYNTHESIZE(string, billDate, BillDate);
	// 单据主题
	CC_SYNTHESIZE(string, subject, Subject);
	// 供应商
	CC_SYNTHESIZE(string, supplierId, SupplierId);
	//入库经办
	CC_SYNTHESIZE(string, handler, Handler);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//上传附件
	CC_SYNTHESIZE(string, appFile, AppFile);


public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, AddQtrkBillDTO& t); // NOLINT
	BIND_TO_JSON(AddQtrkBillDTO, billDate, subject, supplierId, handler, remark, appFile);
};

#endif // !_AddQtrkBill_DTO_
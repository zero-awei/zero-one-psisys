#pragma once

#ifndef _QueryQtrkBillList_VO_
#define _QueryQtrkBillList_VO_

#include "../../GlobalInclude.h"

/**
 * 查询单据列表显示对象
 */
class QueryQtrkBillListVO
{
	// 单据编号
	CC_SYNTHESIZE(string, id, Id);
	// 单据日期-开始
	CC_SYNTHESIZE(string, billDateStart, BillDateStart);
	// 单据日期-结束
	CC_SYNTHESIZE(string, billDateEnd, BillDateEnd);
	// 单据主题
	CC_SYNTHESIZE(string, subject, Subject);
	// 供应商
	CC_SYNTHESIZE(string, supplierId, SupplierId);
	// 单据阶段
	CC_SYNTHESIZE(string, billStage, BillStage);
	// 是否生效
	CC_SYNTHESIZE(uint64_t, isEffective, IsEffective);
	// 是否关闭
	CC_SYNTHESIZE(uint64_t, isClosed, IsClosed);
	// 是否作废
	CC_SYNTHESIZE(uint64_t, isVoided, IsVoided);
public:
	QueryQtrkBillListVO()
	{
		id ="123";
		billDateStart = "2023 - 2 - 17";
		billDateEnd = "2023 - 2 - 18";
		subject = "sgrg";
		supplierId = "wangwu";
		billStage = "ing";
		isEffective = 0;
		isClosed = 0;
		isVoided = 0;
	}
	// 绑定JSON转换方法
	friend void from_json(const json& j, QueryQtrkBillListVO& t); // NOLINT
	BIND_TO_JSON(QueryQtrkBillListVO, id, billDateStart, billDateEnd, subject,supplierId, billStage, isEffective, isClosed, isVoided);
		
};

#endif // !_QueryQtrkBillList_VO_
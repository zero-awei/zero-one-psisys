#pragma once
#ifndef _P_B_D_DTO_
#define _P_B_D_DTO_

#include "../../GlobalInclude.h"
#include "../FileDTO.h"
#include "DetailDTO.h"

/*
* 前端传入单据详细信息
*/
class PyrkBillDetailDTO : public FileDTO {
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
	CC_SYNTHESIZE(list<DetailDTO>, detail, Detail);
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, PyrkBillDetailDTO& t); // NOLINT
};

#endif // !_P_B_D_DTO_
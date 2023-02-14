#pragma once

#ifndef _PURREQEXPORT_DTO_
#define _PURREQEXPORT_DTO_

#include "../../GlobalInclude.h"
#include "../FileDTO.h"

/**
 * 传输对象 —— 单据编号（利用单据编号查询想导出的订单）
 */

//导出
class PurReqExportDTO 
{
	//传输对象信息 —— 利用单据编号查询想导出的订单
	CC_SYNTHESIZE(string, purReqId, PurReqId);

public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, PurReqExportDTO& t);
};

#endif // !_PURREQEXPORT_DTO_
#pragma once

#ifndef _PURREQINTO_DTO_
#define _PURREQINTO_DTO_

#include "../FileDTO.h"

/**
 * 传输对象 —— 导入对象的信息（同新增申请单所需信息）
 */

//导入
class PurReqIntoDTO : public FileDTO
{
	// 单据主题
	CC_SYNTHESIZE(string, purReqSubject, PurReqSubject);

	// 采购类型	（公共接口）
	CC_SYNTHESIZE(string, purReqType, PurReqType);
	// 需求部门	（公共接口）
	CC_SYNTHESIZE(string, purReqRequestDept, PurReqRequestDept);
	// 需求人	（选择用户公共接口）
	CC_SYNTHESIZE(string, purReqRequester, PurReqRequester);
	// 需求时间 
	CC_SYNTHESIZE(string, purReqRequestTime, PurReqRequestTime);
//明细
	// 源单分录号	
	CC_SYNTHESIZE(string, purReqSrcEntryNo, PurReqSrcEntryNo);
	// 物料	
	CC_SYNTHESIZE(string, purReqMaterialId, PurReqMaterialId);

	// 规格型号（公共接口）

	// 计量单位	
	CC_SYNTHESIZE(string, purReqUnitId, PurReqUnitId);
	// 数量	
	CC_SYNTHESIZE(double, purReqQty, PurReqQty);
	// 税率% 
	CC_SYNTHESIZE(double, purReqTaxRate, PurReqTaxRate);
	//参考含税单价
	CC_SYNTHESIZE(double, purReqPrice, PurReqPrice);
	//参考含税金额
	CC_SYNTHESIZE(double, purReqAmt, PurReqAmt);

	// 建议供应商（公共接口）
	CC_SYNTHESIZE(string, purReqSuggestSupplierId, PurReqSuggestSupplierId);
	// 备注	
	CC_SYNTHESIZE(string, purReqRemark, PurReqRemark);
	// 自定义1	
	CC_SYNTHESIZE(string, purReqCustom1, PurReqCustom1);
	// 自定义2	
	CC_SYNTHESIZE(string, purReqCustom2, PurReqCustom2);


public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, PurReqIntoDTO& t); // NOLINT
	
	
};

#endif // !_PURREQINTO_DTO_
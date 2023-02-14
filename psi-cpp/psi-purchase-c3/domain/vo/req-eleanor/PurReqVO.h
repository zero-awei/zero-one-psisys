#pragma once

#ifndef _PURREQ_VO_
#define _PURREQ_VO_

#include "../../GlobalInclude.h"

//导出
class PurReqExportVO
{
//导出对象的信息
	// 采购类型	
	// 需求部门	
	// 需求人	
	// 需求时间	
	// 数量	
	// 参考金额	
	// 已订购数量	
	// 明细																	
	// 是否生效	
	// 附件	
	// 源单id	
	// 单据主题	
	// 单据阶段	
	// 源单号	
	// 是否自动生成	
	// 备注	
	// 审批实例id	
	// 已作废	
	// 单据编号	
	// 是否红字	
	// 源单类型	
	// 制单时间	
	// 生效时间	
	// 核批人	
	// 修改人	
	// 制单部门	
	// 已关闭	
	// 核批结果类型	
	// 单据日期	
	// 制单人	
	// 核批意见
//明细
	// 物料	
	CC_SYNTHESIZE(string, purReqMaterialId, PurReqMaterialId);
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
	// 建议供应商	
	// 已订购数量	
	// 自定义1	
	CC_SYNTHESIZE(string, purReqCustom1, PurReqCustom1);
	// 源单分录号	
	CC_SYNTHESIZE(string, purReqSrcEntryNo, PurReqSrcEntryNo);
	// 分录号	
	// 自定义2	
	CC_SYNTHESIZE(string, purReqCustom2, PurReqCustom2);
	// 源单分录id	
	// 源单类型	
	CC_SYNTHESIZE(string, purReqSrcBillType, PurReqSrcBillType);
	// 备注	
	CC_SYNTHESIZE(string, purReqRemark, PurReqRemark);
	// 单据编号	
	// 源单id
	

public:
	// 绑定JSON转换方法
		//BIND_TO_JSON();
};




//导入
class PurReqIntoVO
{
//导入对象的信息 - 同新增信息



public:
// 绑定JSON转换方法
	//BIND_TO_JSON();
};


#endif // !_PURREQ_VO_

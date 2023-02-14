#pragma once

#ifndef _PURREQEXPORT_VO_
#define _PURREQEXPORT_VO_

#include "../../GlobalInclude.h"

//导出
class PurReqExportVO
{
//导出对象的信息
	// 采购类型	（公共接口）
	// 需求部门	（公共接口）
	// 需求人	（公共接口）
	// 
	// 需求时间	
	CC_SYNTHESIZE(string, purReqRequestTime, PurReqRequestTime);
	// 数量	
	CC_SYNTHESIZE(double, purReqQty, PurReqQty);

	// 参考金额	
	CC_SYNTHESIZE(double, purReqAmt, PurReqAmt);
	// 已订购数量
	CC_SYNTHESIZE(double, purReqOrderQty, PurReqOrderQty);
	// 是否生效	
	CC_SYNTHESIZE(int, purReqIsEffective, PurReqIsEffective);
	// 附件	
	CC_SYNTHESIZE(string, purReqAttachment, PurReqAttachment);
	// 源单id	
	CC_SYNTHESIZE(string, purReqSrcBillId, PurReqSrcBillId);
	// 单据主题	
	CC_SYNTHESIZE(string, purReqSubject, PurReqSubject);
	
	// 单据阶段	（公共接口）

	// 源单号	
	CC_SYNTHESIZE(string, purReqSrcNo, PurReqSrcNo);
	// 是否自动生成	
	CC_SYNTHESIZE(int, purReqIsAuto, PurReqIsAuto);
	// 备注	
	CC_SYNTHESIZE(string, purReqRemark, PurReqReqRemark);
	// 审批实例id	
	CC_SYNTHESIZE(string, purReqBpmiInstenceId, PurReqBpmiInstenceId);
	// 是否作废	
	CC_SYNTHESIZE(int, purReqIsVoided, PurReqIsVoided);
	// 单据编号	
	CC_SYNTHESIZE(string, purReqBillNo, PurReqBillNo);
	// 是否红字	
	CC_SYNTHESIZE(int, purReqIsRubric, PurReqIsRubric);
	// 源单类型	
	CC_SYNTHESIZE(string, purReqSrcBillType, PurReqSrcBillType);
	// 制单时间	
	CC_SYNTHESIZE(string, purReqCreateTime, PurReqCreateTime);
	// 生效时间	
	CC_SYNTHESIZE(string, purReqEffectiveTime, PurReqEffectiveTime);
	// 核批人	
	CC_SYNTHESIZE(string, purReqApprover, PurReqApprover);
	// 修改人	
	CC_SYNTHESIZE(string, purReqUpdateBy, PurReqUpdateBy);
	// 制单部门	
	CC_SYNTHESIZE(string, purReqSysOrgCode, PurReqSysOrgCode);
	// 是否关闭	
	CC_SYNTHESIZE(int, purReqIsClosed, PurReqIsClosed);
	// 核批结果类型	
	CC_SYNTHESIZE(string, purReqApprovalResultType, PurReqApprovalResultType);
	// 单据日期	
	CC_SYNTHESIZE(string, purReqBillDate, PurReqBillDate);
	// 制单人	
	CC_SYNTHESIZE(string, purReqCreateBy, PurReqCreateBy);
	// 核批意见
	CC_SYNTHESIZE(string, purReqApprovalRemark, PurReqApprovalRemark);
	
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

	// 建议供应商（公共接口）
	
	// 已订购数量	
	CC_SYNTHESIZE(double, purReqOrderQty, PurReqOrderQty);
	// 自定义1	
	CC_SYNTHESIZE(string, purReqCustom1, PurReqCustom1);
	// 源单分录号	
	CC_SYNTHESIZE(string, purReqSrcEntryNo, PurReqSrcEntryNo);
	// 分录号	
	CC_SYNTHESIZE(string, purReqEntryNo, PurReqEntryNo);
	// 自定义2	
	CC_SYNTHESIZE(string, purReqCustom2, PurReqCustom2);
	// 源单分录id	
	CC_SYNTHESIZE(string, purReqSrcEntryId, PurReqSrcEntryId);
	// 源单类型	
	CC_SYNTHESIZE(string, purReqSrcBillType, PurReqSrcBillType);
	// 备注	
	CC_SYNTHESIZE(string, purReqRemark, PurReqRemark);
	// 单据编号	
	CC_SYNTHESIZE(string, purReqBillNo, PurReqBillNo);
	// 源单id
	CC_SYNTHESIZE(string, purReqSrcBillId, PurReqSrcBillId);

public:
// 绑定JSON转换方法
	// BIND_TO_JSON();

};


#endif // !_PURREQEXPORT_VO_

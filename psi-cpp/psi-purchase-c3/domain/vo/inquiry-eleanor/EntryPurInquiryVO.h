#pragma once

#ifndef _ENTRYPURINQUIRY_VO_
#define _ENTRYPURINQUIRY_VO_
#include "../../GlobalInclude.h"

/**
 * 显示对象 —— 采购询价单明细列表，即采购申请单信息
 */


//采购询价单明细—采购申请单
class EntryPurInquiryVO
{
	//源单类型
	CC_SYNTHESIZE(string, purReqSrcBillType, PurReqSrcBillType);
	//源单分录号
	CC_SYNTHESIZE(string, purReqSrcEntryNo, PurReqSrcEntryNo);
	//物料
	CC_SYNTHESIZE(string, purReqMaterialId, PurReqMaterialId);


	//规格型号（公共接口）


	//单位
	CC_SYNTHESIZE(string, purReqUnitId, PurReqUnitId);
	//数量
	CC_SYNTHESIZE(double, purReqQty, PurReqQty);
	//税率%
	CC_SYNTHESIZE(double, purReqTaxRate, PurReqTaxRate);
	//参考含税单价
	CC_SYNTHESIZE(double, purReqPrice, PurReqPrice);
	//参考含税金额
	CC_SYNTHESIZE(double, purReqAmt, PurReqAmt);
	//备注
	CC_SYNTHESIZE(string, purReqRemark, PurReqRemark);
	//自定义1
	CC_SYNTHESIZE(string, purReqCustom1, PurReqCustom1);
	//自定义2
	CC_SYNTHESIZE(string, purReqCustom2, PurReqCustom2);

public:
	// 绑定JSON转换方法
	BIND_TO_JSON(EntryPurInquiryVO, purReqSrcBillType, purReqSrcEntryNo, purReqMaterialId, purReqUnitId,
					purReqQty, purReqTaxRate, purReqPrice, purReqAmt, purReqRemark, purReqCustom1, purReqCustom2);
};


#endif // !_ENTRYPURINQUIRY_VO_

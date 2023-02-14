#pragma once

#ifndef _PUR_COM_DIVIDE_LIST_VO_
#define _PUR_COM_DIVIDE_LIST_VO_

#include "../../GlobalInclude.h"


/**
 * 报价单分录列表显示对象
 */
class PurComDividedListVO
{
	// 单据编号
	CC_SYNTHESIZE(string, billNo, BillNo);
	// # 分录编号
	CC_SYNTHESIZE(string, srcEntryId, SrcEntryId);
	// 物料
	CC_SYNTHESIZE(string, materialId, MaterialId);
	// 规格型号
	CC_SYNTHESIZE(string, specifications, Specifications);
	// 单位
	CC_SYNTHESIZE(string, unitId, UnitId);
	// 数量
	CC_SYNTHESIZE(double, qty, Qty);
	// 税率
	CC_SYNTHESIZE(uint64_t, taxRate, TaxRate);
	// 含税价格
	CC_SYNTHESIZE(double, price, Price);
	// 折扣率
	CC_SYNTHESIZE(uint64_t, discountRate, DiscountRate);
	// 含税金额
	CC_SYNTHESIZE(double, amt, Amt);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
	// 自定义1
	CC_SYNTHESIZE(string, custom1, Custom1);
	// 自定义2
	CC_SYNTHESIZE(string, custom2, Custom2);
public:
	// 绑定JSON转换方法
	BIND_TO_JSON(PurComDividedListVO, billNo, materialId, specifications, unitId, qty, taxRate, \
		price, discountRate, amt, remark, custom1, custom2);
	PurComDividedListVO()
	{
		this->setBillNo("CGBJ100QZP");
		this->setSrcEntryId("214");
		this->setRemark("测试");
	}
};

#endif 



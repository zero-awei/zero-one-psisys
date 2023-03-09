#pragma once
#ifndef _PUR_QUOT_DIVIDED_LIST_VO_H_
#define _PUR_QUOT_DIVIDED_LIST_VO_H_
#include "../../GlobalInclude.h"
//询价单分录列表的VO
class PurQuotDividedListVO
{
	//单据编号
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	//物料
	CC_SYNTHESIZE(string, material_id, Material_id);
	//规格型号
	//单位
	CC_SYNTHESIZE(string, unit_id, Unit_id);
	//数量
	CC_SYNTHESIZE(double, qty, Qty);
	//税率
	CC_SYNTHESIZE(double, tax_rate, Tax_rate);
	//参考含税单价
	CC_SYNTHESIZE(double, price, Price);
	//参考含税金额
	CC_SYNTHESIZE(double, amt, Amt);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//自定义1
	CC_SYNTHESIZE(string, custom1, Custom1);
	//自定义2
	CC_SYNTHESIZE(string, custom2, Custom2);
public:
	// 绑定JSON转换方法
	BIND_TO_JSON(PurQuotDividedListVO, bill_no, material_id, unit_id, qty, tax_rate, price, amt,remark, custom1, custom2);
};
#endif

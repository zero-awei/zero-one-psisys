#pragma once
#include "stdafx.h"
#ifndef __PUR_REQ_ENTRY_DO_H__
#define __PUR_REQ_ENTRY_DO_H__

#include "../DoInclude.h"


class PurReqEntryDO
{
	// ID
	CC_SYNTHESIZE(string, entry_id, Entry_id);
	// 主表
	CC_SYNTHESIZE(string, mid, Mid);
	// 单据号
	CC_SYNTHESIZE(string, entry_bill_no, Entry_bill_no);
	// 分录号
	CC_SYNTHESIZE(string, entry_no, Entry_no);
	// 源单类型
	CC_SYNTHESIZE(string, entry_src_bill_type, Entry_src_bill_type);
	// 源单id
	CC_SYNTHESIZE(string, entry_src_bill_id, Entry_src_bill_id);
	// 源单分录id
	CC_SYNTHESIZE(string, src_entry_id, src_entry_id);
	// 源单分录号
	CC_SYNTHESIZE(string, entry_src_no, Entry_src_no);
	// 物料
	CC_SYNTHESIZE(string, material_id, Material_id);
	// 计量单位
	CC_SYNTHESIZE(string, unit_id, Unit_id);
	// 数量
	CC_SYNTHESIZE(double, entry_qty, Entry_qty);
	// 税率%
	CC_SYNTHESIZE(double, tax_rate, Tax_rate);
	// 参考含税单价
	CC_SYNTHESIZE(double, price, Price);	
	// 参考含税金额
	CC_SYNTHESIZE(double, entry_amt, Entry_Amt);
	// 建议供应商
	CC_SYNTHESIZE(string, suggest_supplier_id, Suggest_supplier_id);
	// 已订购数量
	CC_SYNTHESIZE(double, ordered_qty, Ordered_qty);
	// 备注
	CC_SYNTHESIZE(string, entry_remark, Entry_remark);
	// 自定义1
	CC_SYNTHESIZE(string, custom1, Custom1);
	// 自定义2
	CC_SYNTHESIZE(string, custom2, Custom2);
	// 版本
	CC_SYNTHESIZE(string, version, Version);

public:
	PurReqEntryDO()
	{



	}




};


#endif //__PUR_REQ_ENTRY_DO_H__
#pragma once
#ifndef _PUR_QUOT_DETAIL_VO_H_
#define _PUR_QUOT_DETAIL_VO_H_
#include "../../GlobalInclude.h"

//明细的VO
class PurQuotDetailVO {
	//----明细(pur-quot-entry的字段)
		//源单分录号
	CC_SYNTHESIZE(string, entry_src_no, Entry_src_no);
	//物料
	CC_SYNTHESIZE(string, entry_material_id, Entry_material_id);
	//规格型号
	//单位
	CC_SYNTHESIZE(string, entry_unit_id, Entry_unit_id);
	//数量
	CC_SYNTHESIZE(string, entry_qty, Entry_qty);
	//税率
	CC_SYNTHESIZE(string, entry_tax_rate, Entry_tax_rate);
	//含税单价
	CC_SYNTHESIZE(string, entry_price, Entry_price);
	//折扣率
	CC_SYNTHESIZE(string, entry_discount_rate, Entry_discount_rate);
	//含税金额
	CC_SYNTHESIZE(string, entry_amt, Entry_amt);
	//备注
	CC_SYNTHESIZE(string, entry_remark, Entry_remark);
	//自定义1
	CC_SYNTHESIZE(string, entry_custom1, Entry_custom1);
	//自定义2
	CC_SYNTHESIZE(string, entry_custom2, Entry_custom2);
public:
	// 绑定JSON转换方法
	BIND_TO_JSON(PurQuotDetailVO, entry_src_no, entry_material_id, entry_unit_id, entry_qty, entry_tax_rate, entry_price, entry_discount_rate,
		entry_amt, entry_remark, entry_custom1, entry_custom2);
};
#endif // !_PUR_QUOT_FIND_DETAIL_BILL_VO_H_


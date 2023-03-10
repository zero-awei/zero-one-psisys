#pragma once

/*
 @Author: akun
 @Date: 2023/02/26 22:11
*/

#ifndef _PUR_ORDER_DIVIDED_LIST_DO_H_
#define _PUR_ORDER_DIVIDED_LIST_DO_H_
#include "../../GlobalInclude.h"

/**
 * 采购订单--采购申请单分录列表VO对象
 */
class PurOrderDividedListDO {
	//单据编号
	CC_SYNTHESIZE(string, bill_no, BillNo);
	//分录号
	CC_SYNTHESIZE(int, entry_no, EntryNo);
	//物料
	CC_SYNTHESIZE(string, material_id, MaterialId);
	//规格型号------没找到
	//单位
	CC_SYNTHESIZE(string, unit_id, UnitId);
	//数量
	CC_SYNTHESIZE(double, qty, Qty);
	//已定数量
	CC_SYNTHESIZE(double, ordered_qty, OrderedQty);
	//税率
	CC_SYNTHESIZE(double, tax_rate, TaxRate);
	//参考含税单价
	CC_SYNTHESIZE(double, price, Price);
	//参考含税金额
	CC_SYNTHESIZE(double, amt, Amt);
	//建议供应商
	CC_SYNTHESIZE(string, suggest_supplier_id, SuggestSupplierId);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//自定义1
	CC_SYNTHESIZE(string, custom1, Custom1);
	//自定义2
	CC_SYNTHESIZE(string, custom2, Custom2);
public:
	PurOrderDividedListDO() {
		bill_no = "";
		entry_no = -1;
		material_id = "";
		unit_id = "";
		qty = -1.0;
		ordered_qty = -1.0;
		tax_rate = -1.0;
		price = -1.0;
		amt = -1.0;
		suggest_supplier_id = "";
		remark = "";
		custom1 = "";
		custom2 = "";
	}
};

#endif // !_PUR_ORDER_VO_
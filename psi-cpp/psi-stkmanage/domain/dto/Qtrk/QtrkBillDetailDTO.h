#pragma once
#ifndef _QTRK_BILL_DETAIL_DTO
#define _QTRK_BILL_DETAIL_DTO

#include "../../GlobalInclude.h"

/*
* 其他入库单明细DTO
*/
class QtrkBillDetailDTO
{
	//分录号
	CC_SYNTHESIZE(int, entryNo, EntryNo);
	//物料
	CC_SYNTHESIZE(string, material, Material);
	//仓库
	CC_SYNTHESIZE(string, warehouse, Warehouse);
	//单位
	CC_SYNTHESIZE(string, unit, Unit);
	//入库数量
	CC_SYNTHESIZE(double, qty, Qty);
	// 单位金额
	CC_SYNTHESIZE(double, price, Price);
	//入库金额
	CC_SYNTHESIZE(double, cost, Cost);
	//明细：备注
	CC_SYNTHESIZE(string, remark, Remark);
	//自定义1
	CC_SYNTHESIZE(string, custom1, Custom1);
	//自定义2
	CC_SYNTHESIZE(string, custom2, Custom2);
public:
	friend void from_json(const json& j,QtrkBillDetailDTO& t) {
		BIND_FROM_TO_I(j, t, entryNo);
		BIND_FROM_TO_NORMAL(j, t, material);
		BIND_FROM_TO_NORMAL(j, t, warehouse);
		BIND_FROM_TO_NORMAL(j, t, unit);
		BIND_FROM_TO_D(j, t, qty);
		BIND_FROM_TO_D(j, t, price);
		BIND_FROM_TO_D(j, t, cost);
		BIND_FROM_TO_NORMAL(j, t, remark);
		BIND_FROM_TO_NORMAL(j, t, custom1);
		BIND_FROM_TO_NORMAL(j, t, custom2);
	}
};

#endif // !_QTRK_BILL_DETAIL_DTO
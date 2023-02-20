#pragma once
#ifndef _CGTHCK_BILL_ENTRY_DTO_
#define _CGTHCK_BILL_ENTRY_DTO_

#include "../../GlobalInclude.h"
/**
* 采购退货单单据明细
*/
class CgthckBillEntryDTO
{
	/***可填***/
	// 结算数量
	CC_SYNTHESIZE(double, settleQty, SettleQty);
	// 税额
	CC_SYNTHESIZE(double, tax, Tax);
	// 结算金额
	CC_SYNTHESIZE(double, settleAmt, SettleAmt);
	// 采购费用
	CC_SYNTHESIZE(double, cost, Cost);
	// 序号
	CC_SYNTHESIZE(uint64_t, batchNo, BatchNo);

	/***不可填***/
	// 源单分录号
	CC_SYNTHESIZE(std::string, srcNo, SrcNo);
	// 物料
	CC_SYNTHESIZE(string, materialId, MaterialId);
	// 规格型号
	CC_SYNTHESIZE(std::string, model, Model);
	// 仓库
	CC_SYNTHESIZE(std::string, warehouseId, WarehouseId);
	// 单位
	CC_SYNTHESIZE(std::string, unitId, UnitId);
	// 税率
	CC_SYNTHESIZE(double, taxRate, TaxRate);
	// 含税单价
	CC_SYNTHESIZE(double, price, Price);
	// 折扣率
	CC_SYNTHESIZE(double, discountRate, DiscountRate);
	// 入库数量
	CC_SYNTHESIZE(double, qty, Qty);
	// 入库金额
	CC_SYNTHESIZE(double, inAmt, InAmt);

	/***选填***/
	// 备注
	CC_SYNTHESIZE(std::string, remark, Remark);
	// 自定义1
	CC_SYNTHESIZE(std::string, custom1, Custom1);
	// 自定义2
	CC_SYNTHESIZE(std::string, custom2, Custom2);

public:
	// 绑定Json转换方法
	friend void from_json(const json& j, CgthckBillEntryDTO& t)
	{
		BIND_FROM_TO_D(j, t, settleQty);
		BIND_FROM_TO_D(j, t, tax);
		BIND_FROM_TO_D(j, t, settleAmt);
		BIND_FROM_TO_D(j, t, cost);
		BIND_FROM_TO_I(j, t, batchNo);
		BIND_FROM_TO_D(j, t, taxRate);
		BIND_FROM_TO_D(j, t, price);
		BIND_FROM_TO_D(j, t, discountRate);
		BIND_FROM_TO_D(j, t, qty);
		BIND_FROM_TO_D(j, t, inAmt);
		BIND_FROM_TO_NORMAL(j, t, srcNo);
		BIND_FROM_TO_NORMAL(j, t, materialId);
		BIND_FROM_TO_NORMAL(j, t, model);
		BIND_FROM_TO_NORMAL(j, t, warehouseId);
		BIND_FROM_TO_NORMAL(j, t, unitId);
		BIND_FROM_TO_NORMAL(j, t, remark);
		BIND_FROM_TO_NORMAL(j, t, custom1);
		BIND_FROM_TO_NORMAL(j, t, custom2);
	}
};

#endif // !_CGTHCK_BILL_ENTRY_DTO_

#pragma once
#ifndef _QUERY_CGRK_BILL_LISTS_VO_
#define _QUERY_CGRK_BILL_LISTS_VO_

#include "../../GlobalInclude.h"
class QueryCgrkBillListsVO
{
	//分录号
	CC_SYNTHESIZE(string, entryNo, EntryNo);
	//源单号
	CC_SYNTHESIZE(string, srcNo, SrcNo);
	//物料
	CC_SYNTHESIZE(string, materialId, MaterialId);
	//仓库
	CC_SYNTHESIZE(string, warehouseId, WarehouseId);
	//批次号
	CC_SYNTHESIZE(string, batchNo, BatchNo);
	//计量单位
	CC_SYNTHESIZE(string, unitId, UnitId);
	//结算数量
	CC_SYNTHESIZE(double, settleQty, SettleQty);
	//税率%
	CC_SYNTHESIZE(double, taxRate, TaxRate);
	//含税单价
	CC_SYNTHESIZE(double, price, Price);
	//折扣率
	CC_SYNTHESIZE(double, discountRate, DiscountRate);
	//税额
	CC_SYNTHESIZE(double, tax, Tax);
	//结算金额（价税合计）
	CC_SYNTHESIZE(double, settleAmt, SettleAmt);
	//数量
	CC_SYNTHESIZE(double, qty, Qty);
	//成本
	CC_SYNTHESIZE(double, cost, Cost);
	//已开票数量
	CC_SYNTHESIZE(double, invoicedQty, InvoicedQty);
	//已开票金额
	CC_SYNTHESIZE(double, invoicedAmt, InvoicedAmt);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//自定义1
	CC_SYNTHESIZE(string, custom1, Custom1);
	//自定义2
	CC_SYNTHESIZE(string, custom2, Custom2);

public:
	BIND_TO_JSON
	(
		QueryCgrkBillListsVO, entryNo, srcNo, materialId, warehouseId, batchNo, unitId, settleQty, 
		taxRate, price, discountRate, tax, settleAmt, qty, cost, invoicedQty, invoicedAmt, remark, 
		custom1, custom2
	);
};

#endif // !_QUERY_CGRK_BILL_LISTS_VO_

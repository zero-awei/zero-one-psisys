#pragma once

#ifndef _CGRK_BILL_Entry_DTO_
#define _CGRK_BILL_Entry_DTO_

#include "../../GlobalInclude.h"

/**
 * 单据明细
 */
class CgrkBillEntryDTO
{
	//批次号
	CC_SYNTHESIZE(string, batchNo, BatchNo);
	//单据号
	CC_SYNTHESIZE(string, billNo, BillNo);
	//成本
	CC_SYNTHESIZE(double, cost, Cost);
	//自定义1
	CC_SYNTHESIZE(string, custom1, Custom1);
	//自定义2
	CC_SYNTHESIZE(string, custom2, Custom2);
	//折扣率
	CC_SYNTHESIZE(double, discountRate, DiscountRate);
	//分录号
	CC_SYNTHESIZE(string, entryNo, EntryNo);
	//计入费用成本
	CC_SYNTHESIZE(double, expense, Expense);
	//ID
	CC_SYNTHESIZE(string, id, Id);
	//已开票金额
	CC_SYNTHESIZE(double, invoicedAmt, InvoicedAmt);
	//已开票数量
	CC_SYNTHESIZE(double, invoicedQty, InvoicedQty);
	//物料
	CC_SYNTHESIZE(string, materialId, MaterialId);
	//主表
	CC_SYNTHESIZE(string, mid, Mid);
	//含税单价
	CC_SYNTHESIZE(double, price, Price);
	//数量
	CC_SYNTHESIZE(double, qty, Qty);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//结算金额（价税合计）
	CC_SYNTHESIZE(double, settleAmt, SettleAmt);
	//结算数量
	CC_SYNTHESIZE(double, settleQty, SettleQty);
	//源单id（采购订单）
	CC_SYNTHESIZE(string, srcBillId, SrcBillId);
	//源单类型（采购订单）
	CC_SYNTHESIZE(string, srcBillType, SrcBillType);
	//源单分录id
	CC_SYNTHESIZE(string, srcEntryId, SrcEntryId);
	//源单号
	CC_SYNTHESIZE(string, srcNo, SrcNo);
	//出入方向
	CC_SYNTHESIZE(string, stockIoDirection, StockIoDirection);
	//供应商
	CC_SYNTHESIZE(string, supplierId, SupplierId);
	//涨吨数量+/-
	CC_SYNTHESIZE(double, swellQty, SwellQty);
	//税额
	CC_SYNTHESIZE(double, tax, Tax);
	//税率%
	CC_SYNTHESIZE(double, taxRate, TaxRate);
	//计量单位
	CC_SYNTHESIZE(string, unitId, UnitId);
	//版本
	CC_SYNTHESIZE(string, version, Version);
	//仓库
	CC_SYNTHESIZE(string, warehouseId, WarehouseId);
public:

		// 绑定JSON转换方法
	friend void from_json(const json& j, CgrkBillEntryDTO& t); // NOLINT

};

#endif // !_CGRK_BILL_Entry_DTO_

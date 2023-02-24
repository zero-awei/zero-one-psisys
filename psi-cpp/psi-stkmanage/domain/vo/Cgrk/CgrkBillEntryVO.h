#pragma once

#ifndef _CGRK_BILL_Entry_VO_
#define _CGRK_BILL_Entry_VO_

#include "../../GlobalInclude.h"

/**
 * 单据明细
 */
class CgrkBillEntryVO
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
	//源单分录号
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
	CgrkBillEntryVO() {
		batchNo = "CGRK-221110-001-10";
		billNo = "CGRK-221110-001";
		cost = 88000;
		custom1 = "";
		custom2 = "";
		discountRate = 100;
		entryNo = 10;
		expense = 0;
		id = "1590717667725066242";
		invoicedAmt = 0;
		invoicedQty = 0;
		materialId = "1584947805371310082";
		mid = "1590717667678928898";
		price = 8000;
		qty = 11;
		remark = "";
		settleAmt = 88000;
		settleQty = 11;
		srcBillId = "1590710155252645889";
		srcBillType: "PurOrder";
		srcEntryId = "1590710155294588930";
		srcNo = "CGDD-221110-001:10";
		stockIoDirection = "1";
		supplierId = "1584950950470164481";
		swellQty = 0;;
		tax = 10123.89;
		taxRate = 13;
		unitId = "40288101710a4c6201710a6618cc0003";
		version = "";
		warehouseId = "1584937486573969410";

	}
	// 绑定JSON转换方法
	BIND_TO_JSON(CgrkBillEntryVO, batchNo, billNo, cost, custom1, custom2, discountRate, entryNo, expense, id, invoicedAmt, invoicedQty,
		materialId, mid, price, qty, remark, settleAmt, settleQty, srcBillId, srcBillType, srcEntryId, srcNo, stockIoDirection, supplierId, swellQty, tax,
		taxRate, unitId, version, warehouseId);
};

#endif // !_CGRK_BILL_Entry_VO_

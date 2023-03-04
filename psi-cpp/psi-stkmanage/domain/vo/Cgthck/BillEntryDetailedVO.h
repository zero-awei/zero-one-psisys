#pragma once
#ifndef _BILL_DEILED_VO_
#define _BILL_DEILED_VO_

#include "../../GlobalInclude.h"


class BillEntryDetailedVO {
	//源单分录号
	CC_SYNTHESIZE(string, srcNo, SrcNo);
	//物料
	CC_SYNTHESIZE(string, materialId, MaterialId);
	//规格型号
	CC_SYNTHESIZE(string, size, Size);
	//仓库
	CC_SYNTHESIZE(string, warehouseId, WarehouseId);
	//单位
	CC_SYNTHESIZE(string, unit, Unit);
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
	//入库数量
	CC_SYNTHESIZE(int, inNum, InNum);
	//采购费用
	CC_SYNTHESIZE(double, buyCost, BuyCost);
	//入库金额
	CC_SYNTHESIZE(double, inMoney, InMoney);
	//已开票数量
	CC_SYNTHESIZE(double, invoicedQty, InvoicedQty);
	//已开票金额
	CC_SYNTHESIZE(double, invoicedAmt, InvoicedAmt);
	//备注
	CC_SYNTHESIZE(string, remarks, Remarks);
	//自定义1
	CC_SYNTHESIZE(string, custom1, Custom1);
	//自定义2
	CC_SYNTHESIZE(string, custom2, Custom2);

	BIND_TO_JSON
	(
		BillEntryDetailedVO, srcNo, size, warehouseId, unit, settleQty, taxRate, price,
		discountRate, tax, settleAmt, inNum, buyCost, inMoney, invoicedQty, invoicedAmt,
		remarks, custom1, custom2
	);
};

#endif
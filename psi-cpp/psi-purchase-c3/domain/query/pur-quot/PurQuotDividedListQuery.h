#include "stdafx.h"
#ifndef __PurQuotFindDetailBill_QUERY_H__
#define __PurQuotFindDetailBill_QUERY_H__

#include "../PageQuery.h"

class PurQuotDividedListQuery : public PageQuery
{

	// 序号
	CC_SYNTHESIZE(int, receiptNum, ReceiptNum);
	// 物料
	CC_SYNTHESIZE(string, material, Material);
	//规格型号
	CC_SYNTHESIZE(string, specificationsModels, SpecificationsModels);
	//单位
	CC_SYNTHESIZE(string, units, Units);
	//数量
	CC_SYNTHESIZE(int, quantity, Quantity);
	//税率
	CC_SYNTHESIZE(double, taxRate, TaxRate);
	//参考税单价
	CC_SYNTHESIZE(double, referenceTaxPrice, ReferenceTaxPrice);
	//参考含税单价
	CC_SYNTHESIZE(double, referenceIncludTaxPrice, ReferenceIncludTaxPrice);
	//参考含税金额
	CC_SYNTHESIZE(double, referenceIncludTaxAmount, referenceIncludTaxAmount);
	//备注
	CC_SYNTHESIZE(string, comments, Comments);
public:
	friend void from_json(const json& j, PurQuotDividedListQuery& t) {
		BIND_FROM_TO_I(j, t, pageIndex);
		BIND_FROM_TO_I(j, t, pageSize);
		BIND_FROM_TO_I(j, t, receiptNum);
		BIND_FROM_TO_NORMAL(j, t, material);
		BIND_FROM_TO_NORMAL(j, t, specificationsModels);
		BIND_FROM_TO_NORMAL(j, t, units);
		BIND_FROM_TO_I(j, t, quantity);
		BIND_FROM_TO_D(j, t, taxRate);
		BIND_FROM_TO_D(j, t, referenceTaxPrice);
		BIND_FROM_TO_D(j, t, referenceIncludTaxPrice);
		BIND_FROM_TO_D(j, t, referenceIncludTaxAmount);
		BIND_FROM_TO_NORMAL(j, t, comments);

	}
};

#endif

#ifndef __PUR_QUOT_DIVIDED_LIST_VO_
#define __PUR_QUOT_DIVIDED_LIST_VO_

#include "../../GlobalInclude.h"

/**
 * 供应报价单查询显示对象
 */
class PurQuotDividedListVO
{
	// 序号
	CC_SYNTHESIZE(string, receiptNum, ReceiptNum);
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
	// 自定义1
	CC_SYNTHESIZE(string, custom1, Custom1);
	// 自定义2
	CC_SYNTHESIZE(string, custom2, Custom2);
public:
	// 绑定JSON转换方法
	BIND_TO_JSON(PurQuotDividedListVO, receiptNum, material, specificationsModels,\
		units, quantity, taxRate, referenceTaxPrice, referenceIncludTaxPrice,\
		referenceIncludTaxAmount, comments, custom1, custom2);
	// 用于测试用
	PurQuotDividedListVO() {
		this->setReceiptNum("20");
		this->setMaterial("test Material");
	}
};
#endif 

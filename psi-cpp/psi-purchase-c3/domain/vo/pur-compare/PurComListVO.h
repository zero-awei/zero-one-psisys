#pragma once

#ifndef _PUR_COM_LIST_VO_
#define _PUR_COM_LIST_VO_

#include "../../GlobalInclude.h"

/**
 * 报价单列表显示对象
 */
class PurComListVO
{
	// 单据编号
	CC_SYNTHESIZE(string, billNo, BillNo);
	// 单据日期
	CC_SYNTHESIZE(string, billDate, BillDate);
	// 单据主题
	CC_SYNTHESIZE(string, subject, Subject);
	// 供应商
	CC_SYNTHESIZE(string, supplierId, SupplierId);
	// 付款方式
	CC_SYNTHESIZE(string, paymentMethod, PaymentMethod);
	// 交货日期
	CC_SYNTHESIZE(string, deliveryTime, DeliveryTime);
	// 交货地点
	CC_SYNTHESIZE(string, deliveryPlace, DeliveryPlace);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
public:
	// 绑定JSON转换方法
	BIND_TO_JSON(PurComListVO, billNo, billDate, subject, supplierId, \
		paymentMethod, deliveryTime, deliveryPlace, remark);
	//用于测试
	PurComListVO()
	{
		this->setBillNo("CGBJ100QZP");
		this->setSubject("测试接口");
	}
};


#endif 


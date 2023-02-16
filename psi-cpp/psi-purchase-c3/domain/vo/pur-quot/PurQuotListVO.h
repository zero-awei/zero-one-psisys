#ifndef __PUR_QUOT_LIST_VO_
#define __PUR_QUOT_LIST_VO_

#include "../../GlobalInclude.h"

/**
 * 供应报价单查询显示对象
 */
class PurQuotListVO
{
	// 单据编号
	CC_SYNTHESIZE(string, receiptId, ReceiptId);
	// 单据日期 
	CC_SYNTHESIZE(string, receiptTime, ReceiptTime);
	// 单据主题
	CC_SYNTHESIZE(string, receiptTheme, ReceiptTheme);
	// 联系人
	CC_SYNTHESIZE(string, contact, Contact);
	// 交货日期
	CC_SYNTHESIZE(string, deliveryDate, DeliveryDate);
	// 交货地点
	CC_SYNTHESIZE(string, deliveryPlace, DeliveryPlace);
	// 已关闭
	CC_SYNTHESIZE(string, isClose, IsClose);
public:
	// 绑定JSON转换方法
	BIND_TO_JSON(PurQuotListVO, receiptId, receiptTime, receiptTheme,contact, deliveryDate, deliveryPlace, isClose);
	// 用于测试用
	PurQuotListVO() {
		this->setReceiptId("CGBJ100QZP");
		this->setReceiptTheme("test func");
	}
};
#endif 
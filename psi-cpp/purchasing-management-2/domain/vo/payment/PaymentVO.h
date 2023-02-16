#pragma once


#ifndef _PAYMENTVO_H_
#define _PAYMENTVO_H_

class PaymentVO
{
	// 单据日期
	CC_SYNTHESIZE(std::string, billDate, BillDate);
	// 单据主题
	CC_SYNTHESIZE(std::string, subject, Subject);
	// 业务员
	CC_SYNTHESIZE(std::string, op, Op);
	// 业务部门
	CC_SYNTHESIZE(std::string, opDept, OpDept);
	// 供应商
	CC_SYNTHESIZE(std::string, supplierId, SupplierId);
	// 采购入库单单号
	CC_SYNTHESIZE(std::string,srcNo, SrcNo);

public:
	// 绑定JSON转换方法
	BIND_TO_JSON(PaymentVO, billDate, subject, op, opDept, supplierId, srcNo);

	PaymentVO() {
		//测试
		billDate = u8"2023-2-16";
		subject = u8"测试";
		op = u8"jeecg";
		opDept = u8"北京F公司";
		srcNo = u8"CGRK-230215-049";
	}


};




#endif // _PAYMENTVO_H_
#pragma once


#ifndef _PAYMENTVO_H_
#define _PAYMENTVO_H_

class PaymentVO
{
	// 
	CC_SYNTHESIZE(uint64_t, id, Id);
	// 年龄
	CC_SYNTHESIZE(int, age, Age);
	// 身份证号
	CC_SYNTHESIZE(std::string, idCard, IdCard);
public:
	// 绑定JSON转换方法
	BIND_TO_JSON(PaymentVO, id, age, idCard);
};




#endif // _PAYMENTVO_H_
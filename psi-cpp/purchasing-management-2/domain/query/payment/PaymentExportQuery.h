#pragma once

#ifndef _PAYMENTEXPORTQUERY_H_
#define _PAYMENTEXPORTQUERY_H_

#include "../../GlobalInclude.h"
#include <list>

/**
 * 导出
 */
	class PaymentExportQuery
{
protected:
	// 一组需要导出的ID(暂定类型uint64_t)，若没有则默认全部
	CC_SYNTHESIZE(std::list<uint64_t>, exportPayment, ExportPayment);
public:
	//绑定JSON转换方法
	friend void from_json(const json& j, PaymentExportQuery& t) {
		BIND_FROM_TO_OBJ(j, t, exportPayment, std::list<uint64_t>);
	}
};


#endif // _PAYMENTEXPORTQUERY_H_
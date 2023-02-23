#pragma once

#ifndef _PAYMENTIMPORTDTO_H_
#define _PAYMENTIMPORTDTO_H_

#include "../../GlobalInclude.h"
#include <list>
#include "../FileDTO.h"

/**
 * 导入
 */
class PaymentImportDTO : public FileDTO
{
protected:


	// 一组新增类型
	CC_SYNTHESIZE(std::list<std::string>, importPayment, ImportPayment);
public:
	//绑定JSON转换方法
	friend void from_json(const json& j, PaymentImportDTO& t) {
		BIND_FROM_TO_OBJ(j, t, importPayment, std::list<string>);
	}

};

#endif // _PAYMENTIMPORTDTO_H_

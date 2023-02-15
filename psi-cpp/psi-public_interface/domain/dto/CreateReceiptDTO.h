#pragma once


#ifndef _CREATERECEIPTDTO_H_
#define _CREATERECEIPTDTO_H_
#include"./FileDTO.h"
class CreateReceiptDTO : public FileDTO {

	CC_SYNTHESIZE(std::string, type, Type);
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, CreateReceiptDTO& t) { // NOLINT
		BIND_FROM_TO_NORMAL(j, t, type);

	}
};

#endif
#pragma once
#ifndef _BASBANKACCOUNTVO_H_
#define _BASBANKACCOUNTVO_H_
#include"../../GlobalInclude.h"

class BasBankAccountVO {
	
	CC_SYNTHESIZE(std::string, label, Label);

	CC_SYNTHESIZE(std::string, text, Text);

	CC_SYNTHESIZE(std::string, title, Title);

	CC_SYNTHESIZE(std::string, value, Value);

public:

	BIND_TO_JSON(BasBankAccountVO, label, text, title, value);

	BasBankAccountVO() {
		label = u8"12345678901234567890";
		text = u8"12345678901234567890";
		title = u8"12345678901234567890";
		value = u8"1584913699556106242";
	}

};


#endif
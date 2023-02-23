#pragma once
#ifndef _BASBANKACCOUNTVO_H_
#define _BASBANKACCOUNTVO_H_
#include"../../GlobalInclude.h"

class BasBankAccountVO {
	
	CC_SYNTHESIZE(string, id, Id);

	CC_SYNTHESIZE(std::string, value, Value);

public:

	BIND_TO_JSON(BasBankAccountVO, id,value);

	BasBankAccountVO() {
		id = "111";
		value = u8"1584913699556106242";
	}

};


#endif
#pragma once
#ifndef _SPACIFIEDBANKACCOUNTQUETY_H_
#define _SPACIFIEDBANKACCOUNTQUETY_H_

#include"../PageQuery.h"
class SpecifiedBankAccountQuery : public PageQuery {
	CC_SYNTHESIZE(std::string, accountNo, AccountNo);
	CC_SYNTHESIZE(std::string, name, Name);
public:

	friend void from_json(const json& j, SpecifiedBankAccountQuery& f) {
		BIND_FROM_TO_ULL(j, f, pageIndex);
		BIND_FROM_TO_ULL(j, f, pageSize);
		BIND_FROM_TO_NORMAL(j, f, name);
		BIND_FROM_TO_NORMAL(j, f, accountNo);
	}
};

#endif
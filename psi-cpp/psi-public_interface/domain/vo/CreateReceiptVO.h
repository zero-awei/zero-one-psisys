#pragma once
#ifndef _CREATERECEIPTVO_H_
#define _CREATERECEIPTVO_H_
#include"../GlobalInclude.h"

class CreateReceiptVO {
	CC_SYNTHESIZE(std::string, result, Result);

public:

	BIND_TO_JSON(CreateReceiptVO, result);
};

#endif
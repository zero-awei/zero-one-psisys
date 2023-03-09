#pragma once
/*
供应商信息
author: qiuqiu
date: 2023/2/14
*/


#ifndef SUPPLIERSINFOVO_H_
#define SUPPLIERSINFOVO_H_

#include "../../GlobalInclude.h"

class SuppliersInfoVO
{
	CC_SYNTHESIZE(std::string, id, ID);
	CC_SYNTHESIZE(std::string, code, Code);
	CC_SYNTHESIZE(std::string, name, Name);
	CC_SYNTHESIZE(std::string, auxname, AuxName);
	CC_SYNTHESIZE(std::string, create_time, Create_Time);
public:
	BIND_TO_JSON(SuppliersInfoVO, id, code, name, auxname, create_time);
};



#endif // !SUPPLIERSINFOVO_H_

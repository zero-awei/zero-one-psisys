#pragma once
#ifndef _SUPPLIERCATEGORYDO_H_
#define _SUPPLIERCATEGORYDO_H_

class SupplierCategoryDO
{
	//供应商名字
	CC_SYNTHESIZE(std::string, name, Name);
	//供应商id
	CC_SYNTHESIZE(uint64_t, id, Id);
public:
	SupplierCategoryDO()
	{
		name = "";
		id = 0;
	}
};

#endif // _SUPPLIERCATEGORYDO_H_
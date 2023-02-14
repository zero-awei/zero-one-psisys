#pragma once

#ifndef _DELETE_DTO_
#define _DELETE_DTO_

#include "../../GlobalInclude.h"

/**
 * 示例传输对象
 */
class DeleteSupplierDTO
{
	// 删除供应商需要的属性
	CC_SYNTHESIZE(string, code, Code);
	
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, DeleteSupplierDTO& t); // NOLINT
};

#endif // !_ADD_DTO_

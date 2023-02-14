#pragma once

#ifndef _DELETE_DTO_
#define _DELETE_DTO_

#include "../../GlobalInclude.h"

/**
 * 示例传输对象
 */
class DeleteSupplierDTO
{
	// 过滤匹配条件
	CC_SYNTHESIZE(string, rule, Rule);
	//查询字段
	CC_SYNTHESIZE(string, name, Name);
	//	字段查询条件：等于、包含、不等于、大于....
	CC_SYNTHESIZE(string, condition, Condition);
	//用户输入的需要查询的字段的值
	CC_SYNTHESIZE(string, value, Value);
	public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, DeleteSupplierDTO& t); // NOLINT
	BIND_TO_JSON(DeleteSupplierDTO, rule, name, condition, value);
};

#endif // !_ADD_DTO_

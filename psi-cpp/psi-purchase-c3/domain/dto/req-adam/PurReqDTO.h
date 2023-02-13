#pragma once
#ifndef _PUR_REQ_DTO_
#define _PUR_REQ_DTO_

#include "../../GlobalInclude.h"

/**
 * 示例传输对象
 */
class PurReqDTO
{
	// 编号
	CC_SYNTHESIZE(uint64_t, id, Id);
	// 姓名
	CC_SYNTHESIZE(string, name, Name);
	// 年龄
	CC_SYNTHESIZE(int, age, Age);
	// 性别
	CC_SYNTHESIZE(string, sex, Sex);
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, PurReqDTO& t); // NOLINT
	BIND_TO_JSON(PurReqDTO, id, name, age, sex);
};

#endif // !_PUR_REQ_DTO_
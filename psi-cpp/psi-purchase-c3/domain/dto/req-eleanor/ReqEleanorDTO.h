#pragma once

#ifndef _REQELEANOR_DTO_
#define _REQELEANOR_DTO_

#include "../../GlobalInclude.h"

/**
 * 示例传输对象
 */
class ReqEleanorDTO
{
//传输对象信息

public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, ReqEleanorDTO& t); // NOLINT
	//BIND_TO_JSON(ReqEleanorDTO, ,  ,  );
};

#endif // !_ReqELEANOR_DTO_
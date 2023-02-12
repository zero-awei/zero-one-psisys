#pragma once

#ifndef _INQUIRYELEANOR_DTO_
#define _INQUIRYELEANOR_DTO_

#include "../../GlobalInclude.h"

/**
 * 示例传输对象
 */
class InquiryEleanorDTO
{
//传输对象参数


public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, InquiryEleanorDTO& t); // NOLINT
	//BIND_TO_JSON();
};

class AssignInquiryEleanorDTO
{
//传输对象参数


public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, InquiryEleanorDTO& t); // NOLINT
	//BIND_TO_JSON();
};


#endif // !_INQUIRYELEANOR_DTO_
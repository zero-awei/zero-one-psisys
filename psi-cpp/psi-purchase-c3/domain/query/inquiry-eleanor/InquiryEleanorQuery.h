#pragma once

#ifndef _INQUIRYELEANOR_QUERY_
#define _INQUIRYELEANOR_QUERY_

#include "../PageQuery.h"

/**
 * 示例分页查询对象
 */
class InquiryEleanorQuery : public PageQuery
{
//查询的对象信息


public:
	// 绑定from_json
	friend void from_json(const json& j, InquiryEleanorQuery& t) { // NOLINT
	//BIND_FROM_TO_ULL(j, t, pageIndex);
	//BIND_FROM_TO_ULL(j, t, pageSize);
	//BIND_FROM_TO_NORMAL(j, t, name);
	//BIND_FROM_TO_NORMAL(j, t, sex);
	}
	}
};

class AssignInquiryEleanorQuery
{
//查询的指定对象信息

public:
	// 绑定from_json
	friend void from_json(const json& j, InquiryEleanorQuery& t) { // NOLINT
	//BIND_FROM_TO_ULL(j, t, pageIndex);
	//BIND_FROM_TO_ULL(j, t, pageSize);
	//BIND_FROM_TO_NORMAL(j, t, name);
	//BIND_FROM_TO_NORMAL(j, t, sex);
	}

};

#endif // !_INQUIRYELEANOR_QUERY_
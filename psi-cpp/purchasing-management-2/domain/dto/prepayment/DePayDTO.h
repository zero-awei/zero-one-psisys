#pragma once
#ifndef _DE_PAY_DTO_
#define _DE_PAY_DTO_

#include "../../GlobalInclude.h"
#include "../FileDTO.h"

//删除订单的DTO 前端只需要传递一个单据编号给我即可进行修改
class DePayDTO {
	// 编号
	CC_SYNTHESIZE(string, id, Id);
	//单据编号
	CC_SYNTHESIZE(string, bill_no, Bill_no);
public:
	//绑定JSON转换方法
	friend void from_json(const json& j, DePayDTO& t);
};

#endif // !_DELETE_PUR_REQ_DTO_
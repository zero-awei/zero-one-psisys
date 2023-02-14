#pragma once

#ifndef _PURREQ_DTO_
#define _PURREQ_DTO_

#include "../../GlobalInclude.h"
#include "../FileDTO.h"

/**
 * 示例传输对象
 */


//导出
class PurReqExportDTO 
{
	//传输对象信息 —— 利用单据编号查询想导出的订单
	CC_SYNTHESIZE(std::list<string>, purReqId, PurReqId);

public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, PurReqExportDTO& t)
	{
		BIND_FROM_TO_OBJ(j, t, purReqId, std::list<string>);
	}
};

//导入
class PurReqIntoDTO : public FileDTO
{
//传输对象信息
	//CC_SYNTHESIZE(std::list<string>, purReqId, PurReqId);

public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, PurReqIntoDTO& t)// NOLINT
	{
		//BIND_FROM_TO_ULL(PurReqInportDTO, purReqId, std::list<string>);          //  还未解决------------------
	}
};

#endif // !_PURREQ_DTO_
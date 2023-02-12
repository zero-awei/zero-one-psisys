#pragma once


#ifndef _INQUIRYELEANOR_CONTROLLER_
#define _INQUIRYELEANOR_CONTROLLER_

#include "../../domain/query/inquiry-eleanor/InquiryEleanorQuery.h"
#include "../../domain/dto/inquiry-eleanor/InquiryEleanorDTO.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/vo/inquiry-eleanor/InquiryEleanorVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/dto/user/UserDTO.h"
#include "../../domain/vo/user/UserVO.h"
using json = nlohmann::json;

/**
 * 示例控制器，演示接口的使用
 */
class InquiryEleanorController
{
public:
	//接口1 查询采购询价单分页列表
	CREATE_API_FUN_QUERY_PAYLOAD(queryInquiryEleanor, execQueryInquiryEleanor, InquiryEleanorQuery);
	//接口2 查看指定询价单详细信息
	CREATE_API_FUN_QUERY_PAYLOAD(queryAssignInquiryEleanor, execQueryAssignInquiryEleanor, InquiryEleanorQuery);

	//演示JSON提交
	CREATE_API_FUN_JSON(jsonInquiryEleanor, execJsonInquiryEleanor, InquiryEleanorDTO);

private:
	//查询采购询价单分页列表
	json execQueryInquiryEleanor(const InquiryEleanorQuery& query, const PayloadDTO& payload);
	//查看指定询价单详细信息
	json execQueryAssignInquiryEleanor(const InquiryEleanorQuery& query, const PayloadDTO& payload);

	//演示JSON提交
	json execJsonInquiryEleanor(const InquiryEleanorDTO& dto);
};

#endif // _INQUIRYELEANOR__CONTROLLER_

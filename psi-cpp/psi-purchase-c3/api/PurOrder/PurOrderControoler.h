
//公共头文件
#pragma once
#ifndef _PUR_ORDER_CONTROLLER_H_
#define _PUR_ORDER_CONTROLLER_H_
#include "domain/dto/IDDTO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/vo/PageVO.h"



#include "../../domain/query/PurOrder/PurOrderDividedListQuery.h"
#include "../../domain/vo/PurOrder/PurOrderDividedListVO.h"
#include "../../service/PurOrder/PurOrderService.h"

class PurOrderController
{
public:
	//询价单分录列表
	CREATE_API_FUN_QUERY_PAYLOAD(queryPurOrderDividedList, execQueryPurOrderDividedList, PurOrderDividedListQuery);
private:
	// 查询询价单分录列表
	JsonVO<list<PurOrderDividedListVO>> execQueryPurOrderDividedList(const PurOrderDividedListQuery& query, const PayloadDTO& payload) {
		//构建返回对象
		list<PurOrderDividedListVO> result;
		//数据校验
		if (query.getBillNo() == "") return JsonVO<list<PurOrderDividedListVO>>(result, RS_PARAMS_INVALID);
		//数据校验成功,返回对应的对象
		PurOrderService service;
		result = service.listPurOrderDividedListDO(query);
		return JsonVO<list<PurOrderDividedListVO>>(result, RS_SUCCESS);
	}
};
#endif // _PUI_QUOT_CONTROLLER_





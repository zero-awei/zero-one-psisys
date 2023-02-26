#pragma once

#ifndef _PUR_ORDER_SERVICE_H_
#define _PUR_ORDER_SERVICE_H_
#include <list>
#include "../../domain/vo/PageVO.h"
//vo
#include "../../domain/vo/PurOrder/PurOrderDividedListVO.h"
//query
#include "../../domain/query/PurOrder/PurOrderDividedListQuery.h"



/**
 * 示例服务实现，演示基础的示例服务实现
 */
class PurOrderService
{
public:

	//获取多个PurQuotDividedListVO对象
	list<PurOrderDividedListVO> listPurOrderDividedListDO(const PurOrderDividedListQuery& query);
};

#endif // !_SAMPLE_SERVICE_


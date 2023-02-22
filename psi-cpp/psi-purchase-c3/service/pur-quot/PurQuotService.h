#pragma once

#ifndef _PUR_QUOT_SERVICE_H_
#define _PUR_QUOT_SERVICE_H_
#include <list>
#include "../../domain/vo/pur-quot/PurQuotFindBillVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/query/pur-quot/PurQuotFindBillQuery.h"
/**
 * 示例服务实现，演示基础的示例服务实现
 */
class PurQuotService
{
public:
	//获取多个PurQuotFindBillVO对象
	PageVO<PurQuotFindBillVO> listPurQuotFindBillVO(const PurQuotFindBillQuery& query);

};

#endif // !_SAMPLE_SERVICE_


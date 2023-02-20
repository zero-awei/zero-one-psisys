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
	// 分页查询所有数据
	PageVO<PurQuotFindBillVO> listPurQuotFindBill(const PurQuotFindBillQuery& query);

};

#endif // !_SAMPLE_SERVICE_


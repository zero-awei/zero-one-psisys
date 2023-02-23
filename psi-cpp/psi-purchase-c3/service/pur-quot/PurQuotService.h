#pragma once

#ifndef _PUR_QUOT_SERVICE_H_
#define _PUR_QUOT_SERVICE_H_
#include <list>
#include "../../domain/vo/PageVO.h"

//vo
#include "../../domain/vo/pur-quot/PurQuotFindBillVO.h"
#include "../../domain/vo/pur-quot/PurQuotListVO.h"
#include "../../domain/vo/pur-quot/PurQuotDividedListVO.h"
#include "../../domain/vo/pur-quot/PurQuotFindDetailBillVO.h"
#include "../../domain/vo/pur-quot/PurQuotDetailVO.h"
#include "../../domain/vo/pur-quot/PurQuotBaseVO.h"

//query
#include "../../domain/query/pur-quot/PurQuotFindBillQuery.h"
#include "../../domain/query/pur-quot/PurQuotListQuery.h"
#include "../../domain/query/pur-quot/PurQuotDividedListQuery.h"
#include "../../domain/query/pur-quot/PurQuotFindDetailBillQuery.h"
/**
 * 示例服务实现，演示基础的示例服务实现
 */
class PurQuotService
{
public:
	//获取多个PurQuotFindBillVO对象
	PageVO<PurQuotFindBillVO> listPurQuotFindBillVO(const PurQuotFindBillQuery& query);

	//获取多个PurQuotList对象
	list<PurQuotListVO> listPurQuotListVO(const PurQuotListQuery& query);

	//获取多个PurQuotDividedListVO对象
	list<PurQuotDividedListVO> listPurQuotDividedListVO(const PurQuotDividedListQuery& query);

	PurQuotFindDetailBillVO getPurQuotFindDetailBillVO(const PurQuotFindDetailBillQuery& query) {

	}


};

#endif // !_SAMPLE_SERVICE_


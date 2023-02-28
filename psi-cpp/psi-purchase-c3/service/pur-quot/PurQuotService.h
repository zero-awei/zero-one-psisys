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
#include "../../domain/vo/pur-quot/PurQuotExportVO.h"


//query
#include "../../domain/query/pur-quot/PurQuotFindBillQuery.h"
#include "../../domain/query/pur-quot/PurQuotListQuery.h"
#include "../../domain/query/pur-quot/PurQuotDividedListQuery.h"
#include "../../domain/query/pur-quot/PurQuotFindDetailBillQuery.h"
#include "../../domain/query/pur-quot/PurQuotExportQuery.h"
//dto

#include "../../domain/dto/pur-quot/AddPurQuotDTO.h"
#include "../../domain/dto/pur-quot/ModPurQuotDTO.h"
#include "../../domain/dto/pur-quot/DelPurQuotDTO.h"
#include "../../domain/dto/pur-quot/PurQuotModBillStatusDTO.h"
#include "../../domain/dto/pur-quot/PurQuotDetailDTO.h"
#include "../../domain/dto/pur-quot/PurQuotIntoDTO.h"


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

	PurQuotFindDetailBillVO getPurQuotFindDetailBillVO(const PurQuotFindDetailBillQuery& query);

	//导出
	PurQuotExportVO listPurQuotExportVO(const PurQuotExportQuery& query);
	//导入
	uint64_t updatePurQuotInto(const PurQuotIntoDTO& dto);

	// 分页查询所有数据
	//PageVO<SampleVO> listAll(const SampleQuery& query);
	// 保存数据
	uint64_t saveData(const AddPurQuotDTO& dto, const PayloadDTO& payload);
	// 修改数据
	bool updateData(const ModPurQuotDTO& dto, const PayloadDTO& payload);
	// 通过bill_no删除数据
	bool removeData(const DelPurQuotDTO& dto);
	// 通过bill_no修改报价状态
	bool UpdateDataBillStatus(const PurQuotModBillStatusDTO& dto);
	// 通过ID删除数据
	//bool removeData(uint64_t id);				//sample案例

};

#endif // !_SAMPLE_SERVICE_


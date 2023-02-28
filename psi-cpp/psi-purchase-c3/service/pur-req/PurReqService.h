#pragma once

#ifndef _PUR_REQ_SERVICE_
#define _PUR_REQ_SERVICE_

#include "../../domain/vo/PageVO.h"
//dto
#include "../../domain/dto/pur-req/AddPurReqDTO.h"
#include "../../domain/dto/pur-req/ModifyPurReqDTO.h"
#include "../../domain/dto/pur-req/PurReqModBillStatusDTO.h"
//vo
#include "../../domain/vo/pur-req/PurReqFindBillVO.h"
#include "../../domain/vo/pur-req/PurReqFindDetailBillVO.h"
//query
#include "../../domain/query/pur-req/PurReqFindBillQuery.h"
#include "../../domain/query/pur-req/PurReqFindDetailBillQuery.h"

/**
 * 示例服务实现
 */
class PurReqService
{
public:
	//插入数据
	uint64_t saveData(const AddPurReqDTO& dto, const PayloadDTO& payload);

	//修改数据
	uint64_t updateData(const ModifyPurReqDTO& dto, const PayloadDTO& payload);

	//修改数据状态
	uint64_t updateBillStatus(const PurReqModBillStatusDTO& dto, const PayloadDTO& payload);

	// 通过主目录billNo删除数据
	bool removeData(string billNo);

	//进行从execl转换成数据格式
	uint64_t getFromExecl(string fieldName, const PayloadDTO& payload);

	//通过bill_no列表获得execl表格
	string getToExecl(list<string> billNoList);

	// 分页查询所有数据
	PageVO<PurReqFindBillVO> listAll(const PurReqFindBillQuery& query);
	//查询指定单据详细信息
	PurReqFindDetailBillVO detailsOne(const PurReqFindDetailBillQuery& query);

};

#endif // !_PUR_REQ_SERVICE_
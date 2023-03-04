#pragma once
#ifndef _QTRK_SERVICE_
#define _QTRK_SERVICE_

#include "../../domain/dto/Qtrk/AddQtrkBillDTO.h"
#include "../../domain/dto/Pyrk/ApprovalDTO.h"
#include <list>
#include "../../domain/query/Qtrk/QueryQtrkBillListQuery.h"
#include "../../domain/query/Qtrk/QueryQtrkBillDetailsQuery.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/vo/Qtrk/QueryQtrkBillListVO.h"
#include "../../domain/vo/Qtrk/QueryQtrkBillDetailsVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
#include"domain/dto/Qtrk/ModifyQtrkBillDTO.h"
#include"domain/do/Qtrk/ModifyQtrkBillStatusDO.h"
#include"domain/dto/Qtrk/DeleteQtrkBillDTO.h"
#include"domain/do/Qtrk/DeleteBill.h"

/*
* 其他入库服务
*/
class QtrkService {
public:
	// 新增单据数据
	int saveBillData(const AddQtrkBillDTO& dto, const PayloadDTO& payload);
	// 修改单据数据
	int updateBillDate(const AddQtrkBillDTO& dto, const PayloadDTO& payload);
	// 审核单据
	int updateApproval(const ApprovalDTO& dto, const PayloadDTO& payload);
	
	// 分页查询所有数据
	PageVO<QueryQtrkBillListVO> listQtrkBillList(const QueryQtrkBillListQuery& query);

	//查询单据详细信息
	QueryQtrkBillDetailsVO getQtrkBillDetails(const QueryQtrkBillDetailsQuery& query);

	//修改单据状态
	bool updataBillStatus(const ModifyQtrkBillDTO& dto, const PayloadDTO& payload);

	//删除单据
	bool deleteBill(const DeleteQtrkBillDTO& dto);
};

#endif // !_QTRK_SERVICE_

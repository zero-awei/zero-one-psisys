#pragma once
#ifndef _PREPAYMENT_DAO_
#define _PREPAYMENT_DAO_
#include "BaseDAO.h"
#include "../../domain/do/PurReq/PurReqDO.h"

/**
 * 采购预付表数据库操作实现
 */
class PaymentDAO : public BaseDAO
{
public:
	// 添加预付申请单数据
	uint64_t insertPrepay(const PurReqDO& iObj);
	//修改单据状态
	int ChangeStatusClose(const PurReqDO& uObj);
	int ChangeStatusCancel(const PurReqDO& uObj);
	// 通过ID删除数据
	int deleteById(const PurReqDO& uObj);

};
#endif // !_PREPAYMENT_DAO_
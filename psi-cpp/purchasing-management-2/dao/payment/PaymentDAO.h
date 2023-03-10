#pragma once
#ifndef _PAYMENT_DAO_
#define _PAYMENT_DAO_
#include "BaseDAO.h"
#include "../../domain/do/FinPayReq/FinPayReqDO.h"

/**
 * 采购预付表数据库操作实现
 */
class PaymentDAO : public BaseDAO
{
public:
	// 添加预付申请单数据
	uint64_t  insertPayment(const FinPayReqDO& Obj);
	//修改单据状态
	int ChangeStatusClose(const FinPayReqDO& uObj);
	int ChangeStatusCancel(const FinPayReqDO& uObj);
	// 通过ID删除数据
	int deleteById(const FinPayReqDO& uObj);

};
#endif // !_PREPAYMENT_DAO_
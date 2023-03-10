#pragma once

#ifndef _FIN_PAYMENT_REQ_DAO_
#define _FIN_PAYMENT_REQ_DAO_
#include "BaseDAO.h"
#include "../../domain/do/FinPaymentReq/FinPaymentReqManageDO.h"
#include "../../domain/do/FinPaymentReq/FinPaymentReqEntryManageDO.h"
#include "../../domain/do/FinPaymentReq/FinPaymentReqEntryDO.h"
#include "../../domain/do/FinPaymentReq/FinPaymentReqDO.h"


/**
 * 采购付款申请
 */
class FinPaymentReqDAO : public BaseDAO
{
public:
	// 插入
	uint64_t insert(const FinPaymentReqManageDO& obj);

	// 插入到明细表
	uint64_t insertEntry(const FinPaymentReqEntryManageDO& obj);

	// ͨ通过bill_no删除
	int deleteByBillNo(string billNo);

	// 通过bill_no查询
	list<FinPaymentReqManageDO> selectByBillNo(const string& billNo);

	// 通过bill_no查询明细表
	list<FinPaymentReqEntryManageDO> selectEntryByBillNo(const string& billNo);

	// 计数
	uint64_t count(const FinPaymentReqDO& iObj);
	// 查询指定页
	list<FinPaymentReqDO> selectWithPage(const FinPaymentReqDO& obj, uint64_t pageIndex, uint64_t pageSize);
	// ͨ通过bill_no查询
	list<FinPaymentReqDO> selectBillNo(const string& billNo);

};
#endif // _FIN_PAYMENT_REQ_DAO_
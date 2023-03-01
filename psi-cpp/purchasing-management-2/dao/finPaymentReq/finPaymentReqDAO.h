#pragma once

#ifndef _FIN_PAYMENT_REQ_DAO_
#define _FIN_PAYMENT_REQ_DAO_
#include "BaseDAO.h"
#include "../../domain/do/finPaymentReq/FinPaymentReqManageDO.h"
#include "../../domain/do/finPaymentReq/FinPaymentReqEntryManageDO.h"
#include "../../domain/do/finPaymentReq/FinPaymentReqEntryDO.h"
#include "../../domain/do/finPaymentReq/FinPaymentReqDO.h"


/**
 * 示例表数据库操作实现
 */
class FinPaymentReqDAO : public BaseDAO
{
public:
	// 添加申请(保存/提交) 插入数据
	uint64_t insert(const FinPaymentReqManageDO& obj);

	// 添加明细申请(保存/提交) 插入数据
	uint64_t insertEntry(const FinPaymentReqEntryManageDO& obj);

	// 通过billNo删除数据
	int deleteByBillNo(string billNo);

	//通过BillNo查找主表数据 由于主表只有一个所以只返回一个
	list<FinPaymentReqManageDO> selectByBillNo(const string& billNo);

	//通过BillNo查找明细表数据
	list<FinPaymentReqEntryManageDO> selectEntryByBillNo(const string& billNo);

	// 统计数据条数
	uint64_t count(const FinPaymentReqDO& iObj);
	// 分页查询数据
	list<FinPaymentReqDO> selectWithPage(const FinPaymentReqDO& obj, uint64_t pageIndex, uint64_t pageSize);
	// 通过编号查看详细信息
	list<FinPaymentReqDO> selectBillNo(const string& billNo);

};
#endif // _FIN_PAYMENT_REQ_DAO_
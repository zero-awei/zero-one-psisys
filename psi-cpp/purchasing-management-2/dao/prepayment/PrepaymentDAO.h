#pragma once
#ifndef _PREPAYMENT_DAO_
#define _PREPAYMENT_DAO_
#include "BaseDAO.h"
#include "../../domain/do/prepayment/PrepaymentDO.h"
#include "../../domain/do/prepayment/PrepaymentEntryDO.h"

/**
 * 采购预付表数据库操作实现
 */
class PrepaymentDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const PrepaymentDO& iObj);
	// 分页查询数据
	list<PrepaymentDO> selectWithPage(const PrepaymentDO& obj, uint64_t pageIndex, uint64_t pageSize);
	// 查询指定单据详细信息-通过单据编号查询数据
	list<PrepaymentDO> selectByBill_no(const string& bill_no);
	// 指定单据明细分录
	list<PrepaymentEntryDO> selectBillEntry(const PrepaymentEntryDO& obj);
	// 通过ID删除数据
	int deleteById(const PrepaymentDO& uObj);


};
#endif // !_PREPAYMENT_DAO_
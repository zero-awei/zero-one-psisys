#pragma once
#ifndef _PREPAYMENT_DAO_
#define _PREPAYMENT_DAO_
#include "BaseDAO.h"
#include "../../domain/do/PurQuot/PurQuotDO.h"

/**
 * 采购预付表数据库操作实现
 */
class PurQuotDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const PurQuotDO& iObj);
	// 分页查询数据
	list<PurQuotDO> selectWithPage(const PurQuotDO& obj, uint64_t pageIndex, uint64_t pageSize);
	// 查询指定单据详细信息-通过单据编号查询数据
	list<PurQuotDO> selectByBill_no(const string& bill_no);


	// 添加预付申请单数据
	uint64_t insertPurQuot(const PurQuotDO& iObj);
	//修改单据状态
	int updateStatus(const PurQuotDO& uObj);
	// 通过ID删除数据
	int deleteById(uint64_t id);

};
#endif // !_PREPAYMENT_DAO_
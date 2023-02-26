#pragma once
#ifndef _PREPAYMENT_DAO_
#define _PREPAYMENT_DAO_
#include "BaseDAO.h"
#include "../../domain/do/prepayment/PrepaymentDO.h"

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
	// 添加预付申请单数据
	uint64_t insertPrepay(const PrepaymentDO& iObj);
	// 修改预付申请单数据
	int updatePrepay(const PrepaymentDO& uObj);
	
	// 修改单据状态(关闭/反关闭/作废)
	// 负责人：Andrew
	int updateStatusClose(const PrepaymentDO& uObj);
	int updateStatusCancel(const PrepaymentDO& uObj);
	
	// 通过ID删除数据
	int deleteById(uint64_t id);
	// 保存导入数据
	uint64_t insertInfo(const PrepaymentDO& iObj);
	// 导出数据

};
#endif // !_PREPAYMENT_DAO_
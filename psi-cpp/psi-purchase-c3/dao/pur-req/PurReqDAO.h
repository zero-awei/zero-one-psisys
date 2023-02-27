#pragma once

#ifndef _PUR_REQ_DAO_
#define _PUR_REQ_DAO_
#include "BaseDAO.h"
#include "../../domain/do/pur-req/PurReqAdamDO.h"
#include "../../domain/do/pur-req/PurReqEntryAdamDO.h"
#include "../../domain/do/pur-req/PurReqDO.h"


/**
 * 示例表数据库操作实现
 */
class PurReqDAO : public BaseDAO
{
public:
	// 添加申请(保存/提交) 插入数据
	uint64_t insert(const PurReqAdamDO& obj);

	// 添加明细申请(保存/提交) 插入数据
	uint64_t insertEntry(const PurReqEntryAdamDO& obj);

	// 修改状态数据
	int update(const PurReqAdamDO& obj);

	// 通过billNo删除数据
	int deleteByBillNo(string billNo);

	//通过BillNo查找主表数据 由于主表只有一个所以只返回一个
	list<PurReqAdamDO> selectByBillNo(const string& billNo);

	//通过BillNo查找明细表数据
	list<PurReqEntryAdamDO> selectEntryByBillNo(const string& billNo);


	// 统计数据条数
	uint64_t count(const PurReqDO& iObj);
	// 分页查询数据
	list<PurReqDO> selectWithPage(const PurReqDO& obj, uint64_t pageIndex, uint64_t pageSize);
	// 通过编号查看详细信息
	list<PurReqDO> selectByNo(const string& no);

};
#endif // !_PUR_REQ_DAO_

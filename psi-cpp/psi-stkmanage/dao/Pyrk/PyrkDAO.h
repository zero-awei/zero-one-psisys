#pragma once
#ifndef _PYRK_DAO_
#define _PYRK_DAO_
#include "BaseDAO.h"
#include "../../domain/do/Cgrk/StkIoDO.h"
#include "../../domain/do/Cgrk/StkIoEntryDO.h"
#include "../../domain/vo/Pyrk/QueryPyrkBillDetailsVO.h"
#include "../../domain/query/Pyrk/QueryPyrkBillListQuery.h"
#include"domain/do/Pyrk/QueryPyrkBillListDo.h"

class PyrkDAO : public BaseDAO {
public:
	
	// 插入数据
	int insert(const StkIoDO& iObj);
	int insert(const StkIoEntryDO& iObj);
	// 审核单据更新数据
	int updateApproval(const StkIoDO& iObj);
	// 修改数据
	int update(const StkIoDO& iObj);
	// 修改单据状态
	int updateState(const StkIoDO& iObj);
	// 更新明细
	int update(const StkIoEntryDO& iObj);
	// 根据单据编号删除单据
	int deleteBillById(const string& billNo);
	// 根据单据编号和分录号删除明细
	int deleteDetailById(const string& billNo, const int& entryNo);
	// 根据单据编号删除所有明细
	int deleteDetailById(const string& billNo);
	
	//查询单据列表
	std::list<StkIoDO> selectBillList(const QueryPyrkBillListQuery query);

	//查询单个单据列表信息
	list<StkIoDO>selectBillListByBillNo(string BillNo);

	//查询单据详细信息
	list<StkIoEntryDO> selectBillDetails(string billNo);
	
	// 统计数据条数
	uint64_t count(const QueryPyrkBillListDo& Obj);
};
#endif

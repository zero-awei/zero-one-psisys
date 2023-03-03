#pragma once
#ifndef _ZDRK_DAO_
#define _ZDRK_DAO_
#include "BaseDAO.h"
#include "../../domain/do/SysDictDO.h"
#include "../../domain/do/Cgrk/StkIoDO.h"
#include "../../domain/do/Cgrk/StkIoEntryDO.h"
#endif //!_ZDRK_DAO_

/**
 * 涨吨入库数据库操作实现
 */
class ZdrkDAO : public BaseDAO
{
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
};

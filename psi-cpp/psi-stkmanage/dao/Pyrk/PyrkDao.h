#pragma once
#ifndef _PYRK_DAO_
#define _PYRK_DAO_
#include "BaseDAO.h"
#include"domain/do/Pyrk/QueryPyrkBillListDo.h"
#include "../../domain/do/Cgrk/StkIoDO.h"
#include "../../domain/do/Cgrk/StkIoEntryDO.h"
class PyrkDao : public BaseDAO {
public:
	// 统计数据条数
	uint64_t count(const QueryPyrkBillListDo& Obj);
	// 根据username查询其所属部门代码
	string selectOrgCodeByUsername(const string& username);
	// 根据单据编号查其id
	string selectBillIdByBillNo(const string& billNo);
	// 插入数据
	int insert(const StkIoDO& iObj);
	int insert(const StkIoEntryDO& iObj);
	// 上传文件
	string insertFile(const string& fileName);
	// 审核单据更新数据
	int updateApproval(const StkIoDO& iObj);
	// 修改数据
	int update(const StkIoDO& iObj);
	int update(const StkIoEntryDO& iObj);
};
#endif
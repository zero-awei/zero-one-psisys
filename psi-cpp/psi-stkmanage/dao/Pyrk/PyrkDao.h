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
	uint64_t insert(const StkIoDO& iObj);
	uint64_t insert(const StkIoEntryDO& iObj);
	// 上传文件
	string insertFile(const string& fileName);
	// 审核单据更新数据
	uint64_t updateApproval(const StkIoDO& iObj);
	// 修改数据
	uint64_t update(const StkIoDO& iObj);
	uint64_t update(const StkIoEntryDO& iObj);
};
#endif
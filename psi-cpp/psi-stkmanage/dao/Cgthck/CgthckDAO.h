#pragma once
#ifndef _CGTHCK_DAO_
#define _CGTHCK_DAO_

#include "BaseDAO.h"
#include "FastDfsClient.h"
#include "../../domain/do/Cgrk/StkIoDO.h"
#include "../../domain/do/Cgrk/StkIoEntryDO.h"
#include "../../service/Cgthck/CgthckMapper.h"
#include "../lib-common/include/SnowFlake.h"

constexpr auto DATABASE1 = "stk_io";
constexpr auto DATABASE2 = "stk_io_entry";
//using CgthckDO = StkIoDO;
//using CgthckEntryDO = StkIoEntryDO;

class CgthckDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const CgthckDO& iobj);
	// 分页查询数据
	list<CgthckDO> selectById(const string& id);
	// 插入单据数据
	uint64_t insertIntoBill(const CgthckDO& iobj);
	// 插入单据明细
	int insertIntoEntry(const CgthckEntryDO& iobj);
	// 插入文件
	string insertFile(const string& fileName);
	// 修改数据
	int update(const CgthckDO& iobj);
	// 删除通过单号数据
	int deleteById(const CgthckDO& iobj);
};

#endif // !_CGTHCK_DAO_
#pragma once
//
#ifndef _CGRK_DAO_
#define _CGRK_DAO_
#include "BaseDAO.h"
#include "FastDfsClient.h"
#include "../../domain/do/Cgrk/StkIoDO.h"
#include "../../domain/do/Cgrk/StkIoEntryDO.h"
#include "../../service/Cgthck/CgthckMapper.h"
#include "../lib-common/include/SnowFlake.h"
#include"domain/do/Cgthck/QueryCgthrkBillListDO.h"
#include"domain/do/Cgthck/QueryCgthrkBillListReturnDO.h"
#include"domain/vo/Cgthck/BillEntryDetailedVO.h"
#include"domain/do/Cgthck/BillDetailedDO.h"
#include"../../domain/do/Cgthck/QueryCgthrkBillListReturnDO.h"
#include"../../domain/do/Cgthck/QueryCgthrkBillDetailedReturnDO.h"

#include"list"
class CgthckDAO : public BaseDAO {
public:
	uint64_t count(const CgthckEntryDO& iobj);
	list<CgthckEntryDO> selectWithId(const CgthckEntryDO& iobj);
	// 统计数据条数
	uint64_t count(const QueryCgthrkBillListDO& Obj);
	// 查询单据列表
	list<QueryCgthrkBillListReturnDO> selectCgthckBillList(const QueryCgthrkBillListDO& Obj, uint64_t pageIndex, uint64_t pageSize);
	// 查询详细信息
	QueryCgthrkBillDetailedReturnDO selectCgthckBillListDetailed(const BillDetailedDO& Obj);
	// 插入单据数据
	uint64_t insert(const CgthckDO& iobj);
	// 插入单据明细
	int insert(const CgthckEntryDO& iobj);
	// 插入文件
	string insertFile(const string& fileName);
	// 删除文件
	bool deleteFile(const string& fileName);
	// 修改单据数据
	int update(const CgthckDO& iobj);
	// 修改单据明细
	int update(const CgthckEntryDO& iobj);
	// 审批
	int updateApproval(const CgthckDO& iobj);
	// 修改状态
	int updateStatus(const CgthckDO& iobj);
	// 删除通过单号数据
	int deleteBillById(const string& billNo);
	// 删除通过单号明细
	int deleteEntryById(const string& billNo);
	int deleteEntryById(const string& billNo, const string& entryNo);
	// 导入
	uint64_t importData(const CgthckDO& iobj);
	uint64_t importData(const CgthckEntryDO& iobj);
	// 导出
	list< CgthckDO> exportData(const CgthckDO& iobj);
	list< CgthckEntryDO> exportData(const CgthckEntryDO& iobj);
};





#endif


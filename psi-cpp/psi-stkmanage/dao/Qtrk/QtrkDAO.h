#pragma once
#ifndef _QTRK_DAO_
#define _QTRK_DAO_

#include "BaseDAO.h"
#include "../../domain/do/Cgrk/StkIoDO.h"
#include "../../domain/do/Cgrk/StkIoEntryDO.h"
#include "../../domain/vo/Qtrk/QueryQtrkBillDetailsVO.h"
#include "../../domain/query/Qtrk/QueryQtrkBillListQuery.h"
#include "../../domain/dto/Qtrk/AddQtrkBillDTO.h"
#include"domain/do/Qtrk/ModifyQtrkBillStatusDO.h"
#include"domain/do/Qtrk/DeleteBill.h"

class QtrkDAO : public BaseDAO {
public:
	// 插入数据
	int insert(const StkIoDO& iObj);
	int insert(const StkIoEntryDO& iObj);
	// 审核单据更新数据
	int updateApproval(const StkIoDO& iObj);
	// 修改数据
	int update(const StkIoDO& iObj);
	// 更新明细
	int update(const StkIoEntryDO& iObj);
	// 根据单据编号和分录号删除明细
	int deleteDetailById(const string& billNo, const int& entryNo);
	
	//查询单据列表
	std::list<StkIoDO> selectBillList(const QueryQtrkBillListQuery query);

	//查询单个单据列表信息
	list<StkIoDO>selectBillListByBillNo(string BillNo);

	//查询单据详细信息
	list<StkIoEntryDO> selectBillDetails(string billNo);

	int updataBillStatus(const ModifyQtrkBillStatusDO& doObject);


	int deleteBill(const DeleteBill& doObject);
};

#endif // !_QTRK_DAO_

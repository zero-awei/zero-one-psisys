
#ifndef _PUR_QUOT_DAO_H_
#define _PUR_QUOT_DAO_H_
#include "BaseDAO.h"
#include "../../domain/do/pur-quot/PurQuotDO.h"
#include "../../domain/do/pur-quot/PurQuotEntryDO.h"
#include "../../domain/do/pur-quot/PurQuotNaiGuanDO.h"

class PurQuotDAO : public BaseDAO {
public:
	//统计数据条数
	uint64_t count(const PurQuotDO& iObj);
	uint64_t count(const PurQuotEntryDO& iObj);

	//查询单据列表,返回多个对象
	list<PurQuotDO> selectPurQuotFindBill(const PurQuotDO& obj, uint64_t pageIndex, uint64_t pageSize);
	//报价单列表(多个对象)
	list<PurQuotEntryDO> selectPurQuotList(const PurQuotEntryDO& obj);
	//报价单分录列表(多个对象)
	list<PurQuotEntryDO> selectPurQuotDividedList(const PurQuotEntryDO& obj);

	//此DO用于填充BaseVO
	list<PurQuotDO> selectPurQuotBase(const PurQuotDO& obj);
	//此DO用于填充DetailVO
	list<PurQuotEntryDO> selectPurQuotDetail(const PurQuotEntryDO& obj);


	// 插入数据
	uint64_t insert(const PurQuotNaiGuanDO& iObj);
	// 修改数据
	int update(const PurQuotNaiGuanDO& uObj);
	// 通过bill_no删除数据
	int deleteByBillNo(const PurQuotNaiGuanDO& dObj);
	// 通过bill_no修改报价状态
	int updateBillStatus(const PurQuotNaiGuanDO& ubsObj);

	// 通过ID删除数据
	int deleteById(uint64_t id);
	
};

#endif
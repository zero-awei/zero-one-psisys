
#ifndef _PUR_QUOT_DAO_H_
#define _PUR_QUOT_DAO_H_
#include "BaseDAO.h"
#include "../../domain/do/pur-quot/PurQuotDO.h"
#include "../../domain/do/pur-quot/PurQuotEntryDO.h"


class PurQuotDAO : public BaseDAO {
public:
	//统计数据条数
	uint64_t count(const PurQuotDO& iObj);
	//查询单据列表,返回多个对象
	list<PurQuotDO> selectPurQuotFindBillDO(const PurQuotDO& obj, uint64_t pageIndex, uint64_t pageSize);

	////查询指定单据详细信息
	//list<xx> selectPurQuotFindDetailBillDO(const PurQuotFindDetailBillDO& obj);
	////报价单列表
	//list<PurQuotListDO> selectPurQuotListDO(const PurQuotListDO& obj);
	////报价单分录列表
	//list<PurQuotDividedListDO> selectPurQuotDividedListDO(const PurQuotDividedListDO& obj);
	
};

#endif
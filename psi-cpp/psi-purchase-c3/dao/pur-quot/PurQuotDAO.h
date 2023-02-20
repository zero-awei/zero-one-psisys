
#ifndef _PUR_QUOT_DAO_H_
#define _PUR_QUOT_DAO_H_
#include "BaseDAO.h"
#include "../../domain/do/pur-quot/PurQuotFindBillDO.h"


class PurQuotDAO : public BaseDAO {
public:
	// 统计数据条数
	uint64_t count(const PurQuotFindBillDO& iObj);
	//查询单据列表
	list<PurQuotFindBillDO> selectPurQuotFindBillDO(const PurQuotFindBillDO& obj, uint64_t pageIndex, uint64_t pageSize);
};

#endif
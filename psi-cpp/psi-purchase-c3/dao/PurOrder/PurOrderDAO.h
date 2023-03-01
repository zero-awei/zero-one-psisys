#pragma once

#ifndef _PUR_ORDER_DAO_H_
#define _PUR_ORDER_DAO_H_
#include "BaseDAO.h"
#include "../../domain/do/PurOrder/PurOrderDividedListDO.h"
class PurOrderDAO : public BaseDAO {
public:
	//采购申请单分录列表
	list<PurOrderDividedListDO> selectPurOrderDividedListDO(const PurOrderDividedListDO& obj);
};

#endif
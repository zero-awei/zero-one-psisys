#pragma once
#ifndef _PUR_QUOT_FIND_DETAIL_BILL_VO_H_
#define _PUR_QUOT_FIND_DETAIL_BILL_VO_H_
#include "../../GlobalInclude.h"
#include "PurQuotBaseVO.h"
#include "PurQuotDetailVO.h"

//指定单据明细列表的VO
class PurQuotFindDetailBillVO{
	CC_SYNTHESIZE(PurQuotBaseVO, base_vo, Base_vo);
	CC_SYNTHESIZE(list<PurQuotDetailVO>, detail_vo, Detail_vo);
public:
	BIND_TO_JSON(PurQuotFindDetailBillVO, base_vo, detail_vo);
	//默认构造函数
	PurQuotFindDetailBillVO() {}
	PurQuotFindDetailBillVO(PurQuotBaseVO &b_vo, list<PurQuotDetailVO> &entry_vo) :base_vo(b_vo), detail_vo(entry_vo){}
};

#endif
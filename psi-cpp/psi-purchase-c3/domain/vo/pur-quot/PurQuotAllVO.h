
#pragma once
#ifndef _PUR_QUOT_ALL_VO_H_
#define _PUR_QUOT_ALL_VO_H_
#include "../../GlobalInclude.h"
#include <list>
#include "PurQuotBaseVO.h"
#include "PurQuotListVO.h"
#include "PurQuotDividedListVO.h"
#include "PurQuotDetailVO.h"

//暂时不知道是否会有用, 先暂存在这里
class PurQuotAllVO{
	CC_SYNTHESIZE(PurQuotBaseVO, base_vo, Base_vo);
	CC_SYNTHESIZE(list<PurQuotDetailVO>, detail_vo, Detail_vo);
	CC_SYNTHESIZE(list<PurQuotListVO>, list_vo, List_vo);
	CC_SYNTHESIZE(list<PurQuotDividedListVO>, divided_list_vo, Divided_list_vo);

public:
	// 绑定JSON转换方法
	BIND_TO_JSON(PurQuotAllVO, base_vo, detail_vo, list_vo, divided_list_vo);
};
#endif


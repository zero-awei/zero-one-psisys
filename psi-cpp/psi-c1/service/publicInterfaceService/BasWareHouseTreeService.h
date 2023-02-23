#pragma once
/*
@Author: yunjj
@Date : 2023 / 2 / 13 15 : 36
*/

#ifndef _BASWAREHOUSETREESERVICE_H_
#define _BASWAREHOUSETREESERVICE_H_

#include"./domain/vo/publicInterfaceVO/BasWareHouseTreeListVO.h"
#include"./domain/query/publicInterfaceQuery/BasWareHouseItemQuery.h"
#include"./domain/vo/PageVO.h"

class BasWareHouseTreeService {
public:
	PageVO<BasWareHouseTreeListVO> listAll(const BasWareHouseItemQuery& query);
};

#endif
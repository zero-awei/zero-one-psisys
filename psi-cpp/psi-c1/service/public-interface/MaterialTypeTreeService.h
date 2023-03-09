#pragma once
/*
@Author: yunjj
@Date : 2023 / 2 / 13 15 : 36
*/

#ifndef _MATERIALTYPETREESERVICE_H_
#define _MATERIALTYPETREESERVICE_H_

#include"./domain/vo/public-interface/MaterialTypeTreeListVO.h"
#include"./domain/query/public-interface/MaterialTypeItemQuery.h"
#include"./domain/vo/PageVO.h"

class MaterialTypeTreeListService {
public:
	PageVO<MaterialTypeTreeListVO> listAll(const MaterialTypeItemQuery& query);
};

#endif
#include "stdafx.h"
#include "IsEnabledController.h"

/*
* 是否启用选项
* @Author: Oxygen
* @Date: 2023/2/13 20:53:44
*/

JsonVO<std::list<IsEnabledVO>> IsEnabledController::executeQueryIsEnabled()
{
	list<IsEnabledVO> data;
	IsEnabledVO vo;
	vo.setId(1);
	vo.setName(u8"是");
	data.push_back(vo);
	JsonVO<list<IsEnabledVO>> res;
	res.success(data);
	return res;
}

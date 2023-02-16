#include "stdafx.h"
#include "areaController.h"


//暂时的样例实习用户apipost测试

JsonVO<list<AreaVO>> AreaController::execQueryArea(const AreaQuery& query, const PayloadDTO& payload)
{
	JsonVO<list<AreaVO>>rs;
	list<AreaVO> data;
	data.push_back(AreaVO());
	data.push_back(AreaVO());
	data.push_back(AreaVO());
	rs.success(data);
	return rs;
}

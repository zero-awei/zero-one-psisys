#include "stdafx.h"
#include "areaController.h"


//暂时的样例实习用户apipost测试

JsonVO<PageVO<AreaVO>> AreaController::execQueryArea(const AreaQuery& query, const PayloadDTO& payload)
{
	JsonVO<PageVO<AreaVO>>rs;
	PageVO<AreaVO>data;
	rs.success(data);
	return rs;
}

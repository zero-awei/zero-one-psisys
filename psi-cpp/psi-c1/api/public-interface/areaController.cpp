#include "stdafx.h"
#include "areaController.h"
#include "../../service/public-interface/areaService.h"

JsonVO<list<AreaVO>> AreaController::execQueryArea(const AreaQuery& query, const PayloadDTO& payload)
{
	AreaService service;
	list<AreaVO> result= service.listAll(query);
	JsonVO<list<AreaVO>> rs(result, RS_SUCCESS);
	return rs;
}

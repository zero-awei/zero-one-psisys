#include "stdafx.h"
#include "areaController.h"
#include "../../service/publicInterfaceService/areaService.h"



JsonVO<list<AreaVO>> AreaController::execQueryArea(const AreaQuery& query, const PayloadDTO& payload)
{
	AreaService service;
	service.listAll(query);
	list<AreaVO> result;
	JsonVO<list<AreaVO>> rs(result, RS_SUCCESS);
	return rs;
}

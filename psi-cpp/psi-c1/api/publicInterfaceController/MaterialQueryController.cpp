#include"stdafx.h"
#include"MaterialQueryController.h"
#include "../../service/publicInterfaceService/MaterialService.h"

JsonVO<PageVO<MaterialVO>>MaterialQueryController::execQueryMaterial(const MaterialQuery& query, const PayloadDTO& payload)
{
	MaterialService service;
	PageVO<MaterialVO> result = service.listAll(query);
	//ÏìÓ¦½á¹û
	return JsonVO<PageVO<MaterialVO>>(result, RS_SUCCESS);
}
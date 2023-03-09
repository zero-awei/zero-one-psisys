#include"stdafx.h"
#include"DepartChoiceController.h"
#include "../../service/publicInterfaceService/DepartNameService.h"


JsonVO<list<DepartVO>> DepartChoiceController::execQueryDepart(const DepartNameQuery& query, const PayloadDTO& payload)
{
	DepartNameService service;
	list<DepartVO> result = service.listAll(query);
	JsonVO<list<DepartVO>> rs(result, RS_SUCCESS);
	return rs;
}
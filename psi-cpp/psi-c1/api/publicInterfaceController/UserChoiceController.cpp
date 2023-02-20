#include "stdafx.h"
#include "UserChoiceController.h"
#include "../../service/publicInterfaceService/UserChoiceService.h"


JsonVO<PageVO<UserVO>> UserChoiceController::execQueryUser(const UserQuery& query, const PayloadDTO& payload)
{
	JsonVO<PageVO<UserVO>>rs;
	UserChoiceService service;
	PageVO<UserVO> result = service.listAll(query);
	//ÏìÓ¦½á¹û
	return JsonVO<PageVO<UserVO>>(result, RS_SUCCESS);
}

#include "stdafx.h"
#include "UserChoiceController.h"



JsonVO<PageVO<UserVO>> UserChoiceController::execQueryUser(const UserQuery& query, const PayloadDTO& payload)
{
	JsonVO<PageVO<UserVO>>rs;
	PageVO<UserVO>data;
	rs.success(data);
	return rs;
}

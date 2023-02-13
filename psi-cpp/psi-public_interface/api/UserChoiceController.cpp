#include "stdafx.h"
#include "UserChoiceController.h"



JsonVO<PageVO<DepartVO>> UserChoiceController::execQueryDepart(const DepartNameQuery& query, const PayloadDTO& payload)
{
	JsonVO<PageVO<DepartVO>>rs;
	PageVO<DepartVO>data;
	rs.success(data);
	return rs;
}

JsonVO<PageVO<UserVO>> UserChoiceController::execQueryUser(const UserQuery& query, const PayloadDTO& payload)
{
	JsonVO<PageVO<UserVO>>rs;
	PageVO<UserVO>data;
	rs.success(data);
	return rs;
}

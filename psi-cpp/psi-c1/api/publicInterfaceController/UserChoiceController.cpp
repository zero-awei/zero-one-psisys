#include "stdafx.h"
#include "UserChoiceController.h"



JsonVO<PageVO<UserVO>> UserChoiceController::execQueryUser(const UserQuery& query, const PayloadDTO& payload)
{
	JsonVO<PageVO<UserVO>>rs;
	PageVO<UserVO>data;
	list<UserVO> rows;
	rows.push_back(UserVO());
	rows.push_back(UserVO());
	rows.push_back(UserVO());
	data.setRows(rows);
	rs.success(data);
	return rs;
}

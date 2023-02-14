#include"stdafx.h"
#include"DepartChoiceController.h"

JsonVO<list<DepartVO>> DepartChoiceController::execQueryDepart(const DepartNameQuery& query, const PayloadDTO& payload)
{
	JsonVO<list<DepartVO>>rs;
	list<DepartVO>data;
	rs.success(data);
	return rs;
}
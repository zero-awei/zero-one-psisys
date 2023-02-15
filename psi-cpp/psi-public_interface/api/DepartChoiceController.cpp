#include"stdafx.h"
#include"DepartChoiceController.h"

JsonVO<list<DepartVO>> DepartChoiceController::execQueryDepart(const DepartNameQuery& query, const PayloadDTO& payload)
{
	JsonVO<list<DepartVO>>rs;
	list<DepartVO>data;
	data.push_back(DepartVO());
	data.push_back(DepartVO());
	data.push_back(DepartVO());
	data.push_back(DepartVO());
	rs.success(data);
	return rs;
}
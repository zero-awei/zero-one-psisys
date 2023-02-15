#include"stdafx.h"
#include"MaterialQueryController.h"

JsonVO<PageVO<MaterialVO>>MaterialQueryController::execQueryMaterial(const MaterialQuery& query, const PayloadDTO& payload)
{
	JsonVO<PageVO<MaterialVO>>rs;
	PageVO<MaterialVO>data;
	list<MaterialVO> rows;
	rows.push_back(MaterialVO());
	rows.push_back(MaterialVO());
	rows.push_back(MaterialVO());
	data.setRows(rows);
	rs.success(data);
	return rs;
}
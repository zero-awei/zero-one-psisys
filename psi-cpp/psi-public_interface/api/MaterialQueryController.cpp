#include"stdafx.h"
#include"MaterialQueryController.h"

JsonVO<PageVO<MaterialVO>>MaterialQueryController::execQueryMaterial(const MaterialQuery& query, const PayloadDTO& payload)
{
	JsonVO<PageVO<MaterialVO>>rs;
	PageVO<MaterialVO>data;
	rs.success(data);
	return rs;
}
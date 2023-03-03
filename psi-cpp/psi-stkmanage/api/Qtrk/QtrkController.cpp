
#include "stdafx.h"
#include "QtrkController.h"
#include"service/Qtrk/QtrkService.h"
//#include "../../service/sample/SampleService.h"

JsonVO<PageVO<QueryQtrkBillListVO>> QtrkController::execQueryQtrk(const QueryQtrkBillListQuery& query, const PayloadDTO& payload)
{
	QtrkService service;
	PageVO<QueryQtrkBillListVO> result = service.listQtrkBillList(query);
	return JsonVO<PageVO<QueryQtrkBillListVO>>(result, RS_SUCCESS);
}

JsonVO<QueryQtrkBillDetailsVO> QtrkController::execQueryQtrkBillDetails(const QueryQtrkBillDetailsQuery& query)
{
	QtrkService service;
	QueryQtrkBillDetailsVO result = service.getQtrkBillDetails(query);
	return JsonVO<QueryQtrkBillDetailsVO>(result, RS_SUCCESS);
}




JsonVO<uint64_t> QtrkController::execModifyQtrk(const ModifyQtrkBillDTO& dto)
{
	QtrkService cs;
	JsonVO<uint64_t> result;

	if (cs.updataBillStatus(dto)) {
		result.success(1);
	}
	else
	{
		result.fail(0);
	}
	return result;
}

JsonVO<uint64_t> QtrkController::execRemoveQtrk(const DeleteQtrkBillDTO& dto)
{
	JsonVO<uint64_t> result;
	//执行数据删除
	QtrkService cs;

	if (cs.deleteBill(dto)) {
		result.success(1);
	}
	else
	{
		result.fail(0);
	}
	//响应结果
	return result;
}

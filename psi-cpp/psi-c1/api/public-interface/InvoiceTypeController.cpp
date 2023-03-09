#include "stdafx.h"
#include "InvoiceTypeController.h"
#include "../../service/public-interface/InvoiceTypeService.h"

/**
 *Author c1-ruizi
 * 2023/2/13  16:40
 * 接口：发票类型
 */

JsonVO<list<InvoiceTypeVO>> InvoiceTypeController::executequeryInvoiceType()
{
	InvoiceTypeService service;
	list<InvoiceTypeVO> data = service.listAll();
	//JsonVO<list<SettleMethodVO>> res;
	return JsonVO<list<InvoiceTypeVO>>(data, RS_SUCCESS);
}
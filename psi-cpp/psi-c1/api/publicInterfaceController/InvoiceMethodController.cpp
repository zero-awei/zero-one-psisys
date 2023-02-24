#include "stdafx.h"
#include "InvoiceMethodController.h"
#include "../../service/publicInterfaceService/InvoiceMethodService.h"

/**
 *Author c1-ruizi
 * 2023/2/12  17:46
 * 接口：开票方式
 */

JsonVO<list<InvoiceMethodVO>> InvoiceMethodController::executequeryInvoiceMethod()
{
	InvoiceMethodService service;
	list<InvoiceMethodVO> data = service.listAll();
	//JsonVO<list<SettleMethodVO>> res;
	return JsonVO<list<InvoiceMethodVO>>(data, RS_SUCCESS);
}
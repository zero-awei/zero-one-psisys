#include "stdafx.h"
#include "InvoiceMethodController.h"

/**
 *Author c1-ruizi
 * 2023/2/12  17:46
 * 接口：开票方式
 */

JsonVO<list<InvoiceMethodVO>> InvoiceMethodController::executequeryInvoiceMethod()
{
	list<InvoiceMethodVO> data;
	InvoiceMethodVO vo;
	vo.setId(1);
	vo.setName(u8"审核中");
	data.push_back(vo);
	JsonVO<list<InvoiceMethodVO>> res;
	res.success(data);
	return res;
}
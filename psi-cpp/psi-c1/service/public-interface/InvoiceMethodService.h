/**
 *Author c1-ruizi
 * 2023/2/22 17:46
 * 接口：开票方式
 */

#ifndef _INVOICEMETHOD_SERVICE_
#define _INVOICEMETHOD_SERVICE_

#include <list>
#include "../../domain/vo/public-interface/InvoiceMethodVO.h"


class InvoiceMethodService
{
public:
	//数据列表
	list<InvoiceMethodVO> listAll();
};
#endif // !_INVOICEMETHOD_SERVICE_
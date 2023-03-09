/**
 *Author c1-ruizi
 * 2023/2/22 17:46
 * 接口：发票类型
 */

#ifndef _INVOICETYPE_SERVICE_
#define _INVOICETYPE_SERVICE_

#include <list>
#include "../../domain/vo/public-interface/InvoiceTypeVO.h"


class InvoiceTypeService
{
public:
	//数据列表
	list<InvoiceTypeVO> listAll();
};
#endif // !_INVOICETYPE_SERVICE_
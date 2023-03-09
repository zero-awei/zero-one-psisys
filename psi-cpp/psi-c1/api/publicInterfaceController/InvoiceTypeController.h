#ifndef _INVOICETYPECONTROLLER_VO_
#define _INVOICETYPECONTROLLER_VO_

#include "../../domain/vo/JsonVO.h"
#include "../../domain/vo/publicInterfaceVO/InvoiceTypeVO.h"
#include "api/ApiHelper.h"
/**
 *Author c1-ruizi
 * 2023/2/13  15:57
 * 发票种类接口
 */
class InvoiceTypeController
{
public:
	CREATE_API_FUN_QUERY3(queryInvoiceType, executequeryInvoiceType);
private:
	JsonVO<list<InvoiceTypeVO>> executequeryInvoiceType();
};

#endif // !_INVOICETYPECONTROLLER_VO_
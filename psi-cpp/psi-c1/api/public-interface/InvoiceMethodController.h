#ifndef _INVOICEMETHODCONTROLLER_VO_
#define _INVOICEMETHODCONTROLLER_VO_

#include "../../domain/vo/JsonVO.h"
#include "../../domain/vo/public-interface/InvoiceMethodVO.h"

/**
 *Author c1-ruizi
 * 2023/2/12  17:46
 * 开票选项接口
 */
class InvoiceMethodController
{
public:
	CREATE_API_FUN_QUERY3(queryInvoiceMethod, executequeryInvoiceMethod);
private:
	JsonVO<list<InvoiceMethodVO>> executequeryInvoiceMethod();
};

#endif // !_INVOICEMETHODCONTROLLER_VO_
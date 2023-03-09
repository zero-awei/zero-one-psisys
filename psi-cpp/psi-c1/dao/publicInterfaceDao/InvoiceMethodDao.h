/**
 *Author c1-ruizi
 * 2023/2/22 17:46
 * 接口：开票方式
 */

#ifndef _INVOICEMETHOD_DAO_
#define _INVOICEMETHOD_DAO_
#include "BaseDAO.h"
#include "../../domain/do/publicInterfaceDO/InvoiceMethodDo.h"

class InvoiceMethodDAO : public BaseDAO
{
public:
	//查询数据
	list<InvoiceMethodDO> selectInvoiceMethod();
};
#endif // !_INVOICEMETHOD_DAO_
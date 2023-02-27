/**
 *Author c1-ruizi
 * 2023/2/22 17:46
 * 接口：发票类型
 */

#ifndef _INVOICETYPE_DAO_
#define _INVOICETYPE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/publicInterfaceDO/InvoiceTypeDo.h"

class InvoiceTypeDAO : public BaseDAO
{
public:
	//查询数据
	list<InvoiceTypeDO> selectInvoiceType();
};
#endif // !_INVOICETYPE_DAO_
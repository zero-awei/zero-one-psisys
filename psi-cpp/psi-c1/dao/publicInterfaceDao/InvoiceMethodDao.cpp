/**
 *Author c1-ruizi
 * 2023/2/22 17:46
 * 接口：开票方式
 */

#include "stdafx.h"
#include "InvoiceMethodDAO.h"
#include "InvoiceMethodMapper.h"
#include <sstream>


list<InvoiceMethodDO> InvoiceMethodDAO::selectInvoiceMethod()
{
	stringstream sql;
	sql << "SELECT id,item_text FROM sys_dict_item where id = 1534365760488562690 or id = 1534366120896716801 or id = 1534366255508709377 or id = 1534366461134462977";
	string sqlStr = sql.str();
	InvoiceMethodMapper mapper;
	return sqlSession->executeQuery<InvoiceMethodDO, InvoiceMethodMapper>(sqlStr, mapper);
}
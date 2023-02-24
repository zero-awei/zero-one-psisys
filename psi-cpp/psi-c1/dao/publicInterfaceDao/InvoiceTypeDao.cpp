/**
 *Author c1-ruizi
 * 2023/2/22 17:46
 * 接口：发票类型
 */

#include "stdafx.h"
#include "InvoiceTypeDAO.h"
#include "InvoiceTypeMapper.h"
#include <sstream>


list<InvoiceTypeDO> InvoiceTypeDAO::selectInvoiceType()
{
	stringstream sql;
	sql << "SELECT id,item_text FROM sys_dict_item where id = 1586969312687636481 or id = 1263481284356096001 or id = 1263481374277779458 or id = 1263481462391717889 or id = 1263481770165551106 or id = 1263481997916258306";
	string sqlStr = sql.str();
	InvoiceTypeMapper mapper;
	return sqlSession->executeQuery<InvoiceTypeDO, InvoiceTypeMapper>(sqlStr, mapper);
}
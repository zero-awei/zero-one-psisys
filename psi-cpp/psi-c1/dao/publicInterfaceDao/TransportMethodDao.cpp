/**
 *Author c1-ruizi
 * 2023/2/22 17:46
 * 接口：运输方式
 */

#include "stdafx.h"
#include "TransportMethodDAO.h"
#include "TransportMethodMapper.h"
#include <sstream>


list<TransportMethodDO> TransportMethodDAO::selectTransportMethod()
{
	stringstream sql;
	sql << "SELECT id,item_text FROM sys_dict_item where id = 1531512789790711809 or id = 1531512874792476674 or id = 1531513715905617921 or id = 1531513761959075841 or id = 1531513905991475201 or id = 1531514046093811713 or id = 1531514113429168130";
	string sqlStr = sql.str();
	TransportMethodMapper mapper;
	return sqlSession->executeQuery<TransportMethodDO, TransportMethodMapper>(sqlStr, mapper);
}
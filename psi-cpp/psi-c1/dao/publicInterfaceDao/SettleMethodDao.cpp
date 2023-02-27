/**
 *Author c1-ruizi
 * 2023/2/22  15:46
 * 接口：结算方式
 */

#include "stdafx.h"
#include "SettleMethodDao.h"
#include "SettleMethodMapper.h"
#include <sstream>


list<SettleMethodDO> SettleMethodDAO::selectSettleMethod()
{
	stringstream sql;
	sql << "SELECT id,item_text FROM sys_dict_item where id = 1531509526357958658 or id = 1531509576203067393 or id = 1531509669283061762 or id = 1531509895955832834 or id = 1531509976440332290 or id = 1531510095130746882 or id = 1531510185073401857";
	string sqlStr = sql.str();
	SettleMethodMapper mapper;
	return sqlSession->executeQuery<SettleMethodDO, SettleMethodMapper>(sqlStr, mapper);
}
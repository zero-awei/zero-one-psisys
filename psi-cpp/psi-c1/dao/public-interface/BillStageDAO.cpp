#include "stdafx.h"
#include "BillStageDAO.h"
#include "BillStageMapper.h"
#include <sstream>

list<BillStageDO> BillStageDAO::selectBillStage()
{
	stringstream sql;
	sql << "SELECT * FROM sys_dict_item where dict_id=1240560989760811010";
	string sqlStr = sql.str();
	BillStageMapper mapper;
	return sqlSession->executeQuery<BillStageDO, BillStageMapper>(sqlStr, mapper);
}

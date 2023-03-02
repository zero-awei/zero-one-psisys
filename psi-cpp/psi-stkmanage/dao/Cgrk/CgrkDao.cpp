#include "stdafx.h"
#include"CgrkDao.h"
#include <sstream>


int CgrkDao::updataBillStatus(const ModifyCgrkBillStatusDO& doObject) {
	string sql = "UPDATE `stk_io` SET `is_closed`=?, `is_voided`=? WHERE `bill_no`=?";
	return sqlSession->executeUpdate(sql, "%i%i%s", doObject.getIsClosed(),doObject.getIsVoided(),doObject.getBillNo());
}
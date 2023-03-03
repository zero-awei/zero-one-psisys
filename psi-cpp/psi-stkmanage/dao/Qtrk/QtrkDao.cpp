#include "stdafx.h"
#include"QtrkDAO.h"
#include <sstream>


int QtrkDAO::updataBillStatus(const ModifyQtrkBillStatusDO& doObject) {
	string sql = "UPDATE `stk_io` SET `is_closed`=?, `is_voided`=? WHERE `bill_no`=?";
	return sqlSession->executeUpdate(sql, "%i%i%s", doObject.getIsClosed(), doObject.getIsVoided(), doObject.getBillNo());
}


int QtrkDAO::deleteBill(const DeleteBill& doObject) {
	string sql = "DELETE from `stk_io` where bill_no = ?";
	return sqlSession->executeUpdate(sql, "%s", doObject.getId());
}

#include "stdafx.h"
#include"QtrkService.h"
#include"dao/Qtrk/QtrkDao.h"
bool QtrkService::updataBillStatus(const ModifyQtrkBillDTO& dto) {
	//组装传输数据
	ModifyQtrkBillStatusDO data;
	data.setBillNo(dto.getBillNo());
	data.setIsClosed(dto.getIsClosed());
	data.setIsVoided(dto.getIsVoided());

	//执行数据修改
	QtrkDao cd;
	return cd.updataBillStatus(data) == 1;
}
bool QtrkService::deleteBill(const DeleteQtrkBillDTO& dto) {
	//组装传输数据
	DeleteBill data;
	data.setId(dto.getId());

	//执行数据修改
	QtrkDao cd;
	return cd.deleteBill(data) == 1;
}
#include "stdafx.h"
#include "CgrkService.h"
#include"../../dao/Cgrk/CgrkDao.h"
#include"../../domain/do/Cgrk/ModifyCgrkBillStatusDO.h"
bool CgrkService::updataBillStatus(const ModifyCgrkBillStateDTO& dto) {
	//组装传输数据
	ModifyCgrkBillStatusDO data;
	data.setBillNo(dto.getBillNo());
	data.setIsClosed(dto.getIsClosed());
	data.setIsVoided(dto.getIsVoided());

	//执行数据修改
	CgrkDao cd;
	return cd.updataBillStatus(data) == 1;
}
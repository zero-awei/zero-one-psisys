#pragma once
#ifndef _QTRK_SERVICE_
#define _QTRK_SERVICE_

#include "../../domain/dto/Qtrk/AddQtrkBillDTO.h"

/*
* 其他入库服务
*/
class QtrkService {
public:
	// 新增单据数据
	int saveBillData(const AddQtrkBillDTO& dto, const PayloadDTO& payload);
	// 修改单据数据
	int updateBillDate(const AddQtrkBillDTO& dto, const PayloadDTO& payload);
};

#endif // !_QTRK_SERVICE_
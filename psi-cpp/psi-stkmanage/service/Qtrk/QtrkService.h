#pragma once
#ifndef _QTRK_SERVICE_
#define _QTRK_SERVICE_
#include"domain/dto/Qtrk/ModifyQtrkBillDTO.h"
#include"domain/do/Qtrk/ModifyQtrkBillStatusDO.h"
#include"domain/dto/Qtrk/DeleteQtrkBillDTO.h"
#include"domain/do/Qtrk/DeleteBill.h"
class QtrkService {
public:
	//修改单据状态
	bool updataBillStatus(const ModifyQtrkBillDTO& dto);

	//删除单据
	bool deleteBill(const DeleteQtrkBillDTO& dto);
};



#endif
#pragma once
#ifndef Q_D
#define Q_D
#include "BaseDAO.h"
#include"domain/do/Qtrk/ModifyQtrkBillStatusDO.h"
#include"domain/do/Qtrk/DeleteBill.h"
class QtrkDAO : public BaseDAO {
public:
	int updataBillStatus(const ModifyQtrkBillStatusDO& doObject);


	int deleteBill(const DeleteBill& doObject);
};
#endif // !C_D
#pragma once

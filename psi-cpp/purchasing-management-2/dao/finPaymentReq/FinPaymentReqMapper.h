#pragma once


#ifndef _FIN_PAYMENT_REQ_MAPPER_
#define _FIN_PAYMENT_REQ_MAPPER_

#include "Mapper.h"
#include "../../domain/do/FinPaymentReq/FinPaymentReqManageDO.h"

class FinPaymentReqMapper : public Mapper<FinPaymentReqManageDO>
{
public:
	FinPaymentReqManageDO mapper(ResultSet* resultSet) const override
	{
		int i = 1;
		FinPaymentReqManageDO data;
		data.setId(resultSet->getString(i++));
		data.setBillNo(resultSet->getString(i++));
		data.setBillDate(resultSet->getString(i++));
		data.setSrcBillType(resultSet->getString(i++));
		data.setSrcBillId(resultSet->getString(i++));
		data.setSrcNo(resultSet->getString(i++));
		data.setSubject(resultSet->getString(i++));
		data.setIsRubric(resultSet->getInt(i++));
		data.setPaymentType(resultSet->getString(i++));
		data.setSupplierId(resultSet->getString(i++));
		data.setOpDept(resultSet->getString(i++));
		data.setOperator(resultSet->getString(i++));
		data.setAmt(resultSet->getDouble(i++));
		data.setPaidAmt(resultSet->getDouble(i++));
		data.setAttachment(resultSet->getString(i++));
		data.setRemark(resultSet->getString(i++));
		data.setIsAuto(resultSet->getInt(i++));
		data.setBillStage(resultSet->getString(i++));
		data.setApprover(resultSet->getString(i++));
		data.setBpmiInstanceId(resultSet->getString(i++));
		data.setApprovalResultType(resultSet->getString(i++));
		data.setApprovalRemark(resultSet->getString(i++));
		data.setIsEffective(resultSet->getInt(i++));
		data.setEffectiveTime(resultSet->getString(i++));
		data.setIsClosed(resultSet->getInt(i++));
		data.setIsVoided(resultSet->getInt(i++));
		data.setSysOrgCode(resultSet->getString(i++));
		data.setCreateBy(resultSet->getString(i++));
		data.setCreateTime(resultSet->getString(i++));
		data.setUpdateBy(resultSet->getString(i++));
		data.setUpdateTime(resultSet->getString(i++));
		data.setVersion(resultSet->getInt(i++));
		return data;
	}
};

#endif // _FIN_PAYMENT_REQ_MAPPER_

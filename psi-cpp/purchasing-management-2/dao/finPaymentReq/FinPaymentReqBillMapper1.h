#pragma once


#ifndef _FIN_PAYMENT_REQ_BILL_MAPPER_
#define _FIN_PAYMENT_REQ_BILL_MAPPER_

#include "Mapper.h"
#include "../../domain/do/FinPaymentReq/FinPaymentReqDO.h"

class FinPaymentReqBillMapper : public Mapper<FinPaymentReqDO>
{
public:
	FinPaymentReqDO mapper(ResultSet* resultSet) const override
	{
		FinPaymentReqDO data;
		data.setId(resultSet->getString(1));
		data.setBill_no(resultSet->getString(2));
		data.setBill_date(resultSet->getString(3));
		data.setSrc_bill_type(resultSet->getString(4));
		data.setSrc_bill_id(resultSet->getString(5));
		data.setSrc_no(resultSet->getString(6));
		data.setSubject(resultSet->getString(7));
		data.setIs_rubric(resultSet->getInt(8));
		data.setPayment_type(resultSet->getString(9));
		data.setSupplier_id(resultSet->getString(10));
		data.setOp_dept(resultSet->getString(11));
		data.setOperator(resultSet->getString(12));;
		data.setAmt(resultSet->getDouble(14));
		data.setPaid_amt(resultSet->getDouble(15));
		data.setAttachment(resultSet->getString(16));
		data.setRemark(resultSet->getString(17));
		data.setIs_auto(resultSet->getInt(18));
		data.setBill_stage(resultSet->getString(19));
		data.setApprover(resultSet->getString(20));
		data.setBpmi_instance_id(resultSet->getString(21));
		data.setApproval_result_type(resultSet->getString(22));
		data.setApproval_remark(resultSet->getString(23));
		data.setIs_effective(resultSet->getInt(24));
		data.setEffective_time(resultSet->getString(25));
		data.setIs_closed(resultSet->getInt(26));
		data.setIs_voided(resultSet->getInt(27));
		data.setSys_org_code(resultSet->getString(28));
		data.setCreate_by(resultSet->getString(29));
		data.setCreate_time(resultSet->getString(30));
		data.setUpdate_by(resultSet->getString(31));
		data.setUpdate_time(resultSet->getString(32));
		return data;
	}
};

#endif //_FIN_PAYMENT_REQ_BILL_MAPPER_

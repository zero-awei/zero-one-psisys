#pragma once
#ifndef _SAMPLE_MAPPER_
#define _SAMPLE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/prepayment/PrepaymentDO.h"

/**
 * ²É¹ºÔ¤¸¶ÉêÇë±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */

#define MAPPER_GETINT(funName,x) data.set##funName(resultSet->getUInt64(x))
#define MAPPER_GETSTR(funName,x) data.set##funName(resultSet->getString(x))

class PrepaymentMapper : public Mapper<PrepaymentDO>
{
public:
	PrepaymentDO mapper(ResultSet* resultSet) const override
	{
		PrepaymentDO data;
		MAPPER_GETSTR(Id, 1);
		MAPPER_GETSTR(Bill_no, 2);
		MAPPER_GETSTR(Bill_begin_date, 3);
		MAPPER_GETSTR(Bill_end_date, 3);
		MAPPER_GETSTR(Src_bill_type, 4);
		MAPPER_GETSTR(Src_bill_id, 5);
		MAPPER_GETSTR(Src_no, 6);
		MAPPER_GETSTR(Subject, 7);
		MAPPER_GETINT(Is_rubric, 8);
		MAPPER_GETSTR(Payment_type, 9);
		MAPPER_GETSTR(Supplier_id, 10);
		MAPPER_GETSTR(Op_dept, 11);
		MAPPER_GETSTR(Operator, 12);
		MAPPER_GETINT(Amt, 13);
		MAPPER_GETINT(Paid_amt, 14);
		MAPPER_GETSTR(Attachment, 15);
		MAPPER_GETSTR(Remark, 16);
		MAPPER_GETINT(Is_auto, 17);
		MAPPER_GETSTR(Bill_stage, 18);
		MAPPER_GETSTR(Approver, 19);
		MAPPER_GETSTR(Bpmi_instance_id, 20);
		MAPPER_GETSTR(Approval_result_type, 21);
		MAPPER_GETSTR(Approval_remark, 22);
		MAPPER_GETINT(Is_effective, 23);
		MAPPER_GETSTR(Effective_time, 24);
		MAPPER_GETINT(Is_closed, 25);
		MAPPER_GETINT(Is_voided, 26);
		MAPPER_GETSTR(Sys_org_code, 27);
		MAPPER_GETSTR(Create_by, 28);
		MAPPER_GETSTR(Create_time, 29);
		MAPPER_GETSTR(Update_by, 30);
		MAPPER_GETSTR(Update_time, 31);
		MAPPER_GETINT(Version, 32);


		return data;
	}
};

#endif // !_SAMPLE_MAPPER_
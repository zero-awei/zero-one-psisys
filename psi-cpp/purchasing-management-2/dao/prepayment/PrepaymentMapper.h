#pragma once
#ifndef _SAMPLE_MAPPER_
#define _SAMPLE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/prepayment/PrepaymentDO.h"
#include "../../domain/do/prepayment/PrepaymentEntryDO.h"

/**
 * 普通查询列表字段匹配映射
 */
class PrepaymentMapper : public Mapper<PrepaymentDO>
{
public:
	PrepaymentDO mapper(ResultSet* resultSet) const override
	{
		PrepaymentDO data;
		data.setId(resultSet->getString("id"));
		data.setBill_no(resultSet->getString("bill_no"));
		data.setBill_date(resultSet->getString("bill_date"));
		data.setSubject(resultSet->getString("subject"));
		data.setSupplier_id(resultSet->getString("supplier_id"));
		data.setOp_dept(resultSet->getString("op_dept"));
		data.setOperator(resultSet->getString("Operator"));
		data.setAmt(resultSet->getInt("amt"));
		data.setPaid_amt(resultSet->getInt("paid_amt"));
		data.setBill_stage(resultSet->getString("bill_stage"));
		data.setIs_effective(resultSet->getInt("is_effective"));
		data.setEffective_time(resultSet->getString("effective_time"));
		data.setIs_closed(resultSet->getInt("is_closed"));
		data.setIs_voided(resultSet->getInt("is_voided"));
		data.setRemark(resultSet->getString("remark"));
		data.setApprover(resultSet->getString("approver"));
		data.setCreate_time(resultSet->getString("create_time"));
		data.setCreate_by(resultSet->getString("create_by"));
		data.setSys_org_code(resultSet->getString("sys_org_code"));

		return data;
	}
};

#endif // !_SAMPLE_MAPPER_


/**
 * 指定单据详情基础信息字段匹配映射
 */
class PrepaymentEntryMapper : public Mapper<PrepaymentEntryDO>
{
public:
	PrepaymentEntryDO mapper(ResultSet* resultSet) const override
	{
		PrepaymentEntryDO data;

		data.setAmt(resultSet->getInt("amt"));
		data.setRemark(resultSet->getString("remark"));
		data.setCustom1(resultSet->getString("custom1"));
		data.setCustom2(resultSet->getString("custom2"));
		
		return data;
	}
};

#pragma once
#ifndef Q_C_B_DO_MAPPER
#define Q_C_B_DO_MAPPER

#include "Mapper.h"
#include "../../domain/do/Cgthck/QueryCgthrkBillListReturnDO.h"

class QueryCgthrkBillListDOMapper : public Mapper<QueryCgthrkBillListReturnDO> {
public:
	QueryCgthrkBillListReturnDO mapper(ResultSet* resultSet) const override
	{
		QueryCgthrkBillListReturnDO data;
		data.setBillNo(resultSet->getString(1));
		data.setBillDate(resultSet->getString(2));
		data.setSubject(resultSet->getString(3));
		data.setSrcNo(resultSet->getString(4));
		data.setSupplierId(resultSet->getString(5));
		data.setOptDept(resultSet->getString(6));
		data.setInAmt(resultSet->getDouble(7));
		data.setSettleAmt(resultSet->getDouble(8));
		data.setSettledAmt(resultSet->getDouble(9));
		data.setInvoicedAmt(resultSet->getDouble(10));
		data.setInvoiceType(resultSet->getString(11));
		data.setHandler(resultSet->getString(12));
		data.setBillStage(resultSet->getString(13));
		data.setIsEff(resultSet->getInt(14));
		data.setIsClosed(resultSet->getInt(15));
		data.setIsVoided(resultSet->getInt(16));
		data.setIsAuto(resultSet->getInt(17));
		data.setIsRubric(resultSet->getInt(18));
		data.setRemark(resultSet->getString(19));
		data.setEffTime(resultSet->getString(20));
		data.setApprover(resultSet->getString(21));
		data.setCreateTime(resultSet->getString(22));
		data.setCreateBy(resultSet->getString(23));
		data.setSysOrgCode(resultSet->getString(24));
		data.setUpdateTime(resultSet->getString(25));
		data.setUpdateBy(resultSet->getString(26));

		//data.setName(resultSet->getString(2));
		//data.setSex(resultSet->getString(3));
		//data.setAge(resultSet->getInt(4));
		return data;
	}

};

#endif // !Q_C_B_DO_MAPPER

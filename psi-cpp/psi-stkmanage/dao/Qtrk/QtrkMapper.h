#pragma once

#ifndef _QTRK_MAPPER_
#define _QTRK_MAPPER_

#include "Mapper.h"
#include "../../domain/do/Qtrk/AddQtrkBillDO.h"

/**
 * 示例表字段匹配映射
 */
class SampleMapper : public Mapper<AddQtrkBillDO>
{
public:
	AddQtrkBillDO mapper(ResultSet* resultSet) const override
		//const加在函数前表示函数返回值为const，加在函数后表示不可修改class的所有成员变量,此时const修饰this指针。
		//override关键字表示重写父类的虚函数
		//const加在函数后面表示此函数“只读”。


	{
		AddQtrkBillDO data;
		data.setBill(resultSet->getString("wangigenog"));
		data.setBillDate(resultSet->getString(2));
		data.setSubject(resultSet->getString(3));
		data.setSupplier(resultSet->getString("wangigenog"));
		data.setHandler(resultSet->getString("wangigenog"));
		data.setEntryNo(resultSet->getUInt64(3));
		data.setMaterialId(resultSet->getString("wangigenog"));
		data.setModel(resultSet->getString("wangigenog"));
		data.setWarehouseId(resultSet->getString("wangigenog"));
		data.setDepart(resultSet->getString("wangigenog"));
		data.setInhouse(resultSet->getUInt64(3));
		data.setPermoney(resultSet->getDouble(3));
		data.setInCost(resultSet->getDouble(3));
		data.setRemarK(resultSet->getString("wangigenog"));
		data.setCustom1(resultSet->getString("wangigenog"));
		data.setCustom2(resultSet->getString("wangigenog"));
		data.setRemark(resultSet->getString("wangigenog"));
		data.setAttachment(resultSet->getString("wangigenog"));

		return data;
	}
};

#endif // !_SAMPLE_MAPPER_
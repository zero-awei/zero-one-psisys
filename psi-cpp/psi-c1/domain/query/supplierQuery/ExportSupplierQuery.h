#pragma once
#ifndef _EXPORT_SUPPLIER_QUERY_
#define _EXPORT_SUPPLIER_QUERY_
#include "../PageQuery.h"
class ExportSupplierQuery : public PageQuery
{
	//供应商编号
	CC_SYNTHESIZE(std::string, id, Id);
	//供应商编号
	CC_SYNTHESIZE(std::string, code, Code);
	//供应商名称
	CC_SYNTHESIZE(std::string, name, Name);
public:
	// 绑定from_json
	friend void from_json(const json& j, ExportSupplierQuery& t) { // NOLINT
		BIND_FROM_TO_NORMAL(j, t, id);
		BIND_FROM_TO_NORMAL(j, t, code);
		BIND_FROM_TO_NORMAL(j, t, name);
	}
};
#endif // !_EXPORT_SUPPLIER_QUERY_

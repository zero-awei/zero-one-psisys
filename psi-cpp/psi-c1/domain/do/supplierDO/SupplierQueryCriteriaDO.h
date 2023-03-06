#ifndef _SUPPLIERQUERYCRITERIA_DO_
#define _SUPPLIERQUERYCRITERIA_DO_
#include "../DoInclude.h"

/*
供应商高级查询条件下拉列表
Author C1-三木
*/

class SupplierQueryCriteriaDO
{
	// 阶段编号
	CC_SYNTHESIZE(string, id, Id);
	// 阶段名称
	CC_SYNTHESIZE(string, name, Name);
public:
	SupplierQueryCriteriaDO() {
		id = "";
		name = "";
	}
};


#endif // !_SUPPLIERQUERYCRITERIA_DO_
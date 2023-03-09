#ifndef _DELETE_CGTHCK_BILL_DTO_
#define _DELETE_CGTHCK_BILL_DTO_

#include "../../GlobalInclude.h"
/**
* 采购退货出库(红入), 删除采购退货出库单数据传输对象
*/

class DeleteCgthckBillDTO
{
	CC_SYNTHESIZE(std::string, billNo, BillNo);
	CC_SYNTHESIZE(std::list<std::string>, entries, Entries);
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, DeleteCgthckBillDTO& t)
	{
		BIND_FROM_TO_NORMAL(j, t, billNo);
		BIND_FROM_TO_OBJ(j, t, entries, std::list<std::string>);
	}
};

#endif // !_DELETE_CGTHCK_BILL_DTO_


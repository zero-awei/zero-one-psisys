#ifndef _REMOVE_DOC_LIST_DTO_
#define _REMOVE_DOC_LIST_DTO_

#include "../../GlobalInclude.h"
/**
* 采购退货出库(红入), 删除采购退货出库单数据传输对象
*/

class RemoveDocListDTO
{
	CC_SYNTHESIZE(std::list<std::string>, ids, Ids);
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, RemoveDocListDTO& t)
	{
		BIND_FROM_TO_OBJ(j, t, ids, std::list<std::string>);
	}
};

#endif // !_REMOVE_DOC_LIST_DTO_


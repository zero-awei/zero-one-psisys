#ifndef _EXPORT_DOC_LIST_DTO_
#define _EXPORT_DOC_LIST_DTO_
#include "../../GlobalInclude.h"

/**
* * 采购退货出库(红入), 导出采购退货出库单数据传输对象
*/
class ExportDocListDTO
{
	CC_SYNTHESIZE(std::list<std::string>, ids, Ids);
public:
	// 绑定Json转换方法
	friend void from_json(const json& j, ExportDocListDTO& t)
	{
		BIND_FROM_TO_OBJ(j, t, ids, std::list<std::string>);
	}
};

#endif // !_EXPORT_DOC_LIST_DTO_


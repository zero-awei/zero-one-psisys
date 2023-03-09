#ifndef _EXPORT_CGTHCK_FILE_DTO_
#define _EXPORT_CGTHCK_FILE_DTO_
#include "../../GlobalInclude.h"

/**
* * 采购退货出库(红入), 导出采购退货出库单数据传输对象
*/
class ExportCgthckFileDTO
{
	CC_SYNTHESIZE(std::string, billNo, BillNo);
public:
	// 绑定Json转换方法
	friend void from_json(const json& j, ExportCgthckFileDTO& t)
	{
		BIND_FROM_TO_NORMAL(j, t, billNo);
	}
};

#endif // !_EXPORT_CGTHCK_FILE_DTO_


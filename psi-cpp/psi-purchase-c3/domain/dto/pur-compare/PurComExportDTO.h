#ifndef _PUR_COM_EXPORT_DTO_
#define _PUR_COM_EXPORT_DTO_

#include "../../GlobalInclude.h"
#include "../FileDTO.h"

class PurComExportDTO{
	//单据编号(使用单据编号查询)
	CC_SYNTHESIZE(string, bill_no, Bill_no);

public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, PurComExportDTO& t) {
		BIND_FROM_TO_ULL(j, t, bill_no);
	}
};
#endif
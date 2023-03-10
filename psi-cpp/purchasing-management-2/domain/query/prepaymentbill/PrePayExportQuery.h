#ifndef _PUR_REQ_EXPORT_QUERY_
#define _PUR_REQ_EXPORT_QUERY_

#include "../../GlobalInclude.h"
//#include "../FileDTO.h"

/**
 * 传输对象 —— 单据编号（利用单据编号查询想导出的订单）
 */

 //导出
class PrePayExportQuery
{
	//传输对象信息 —— 利用单据编号查询想导出的订单
	CC_SYNTHESIZE(string, bill_no, Bill_no);

public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, PrePayExportQuery& t){
		BIND_FROM_TO_NORMAL(j, t, bill_no);
	}
	
};

#endif // !_PUR_REQ_EXPORT_QUERY_
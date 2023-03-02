#pragma once
#ifndef __PUR_INQUIRY_EXPORT_QUERY_H__
#define __PUR_INQUIRY_EXPORT_QUERY_H__

#include "../../GlobalInclude.h"
#include "../PageQuery.h"

/**
 * 传输对象 —— 单据编号（利用单据编号查询想导出的订单）
 */

//导出
class PurInquiryExportQuery : public PageQuery
{
	// 单据编号
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	CC_SYNTHESIZE(list<string>, bill_no_list, Bill_no_list);

public:

	friend void from_json(const json& j, PurInquiryExportQuery& t)
	{
		BIND_FROM_TO_OBJ(j, t, bill_no, string);
		BIND_FROM_TO_OBJ(j, t, bill_no_list, list<string>);
	}
};

#endif  //__PURINQUIRYEXPORTQUERY_H__


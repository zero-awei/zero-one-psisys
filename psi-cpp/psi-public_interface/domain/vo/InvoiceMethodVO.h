#ifndef _INVOICEMETHOD_VO_
#define _INVOICEMETHOD_VO_

#include "../GlobalInclude.h"

/**
 *Author c1-ruizi
 * 2023/2/12  17:46
 * 接口：开票方式
 */

class InvoiceMethodVO
{
	// 方式编号
	CC_SYNTHESIZE(int, id, Id);
	// 方式名称
	CC_SYNTHESIZE(string, name, Name);
	
public:
	// 绑定JSON转换方法
	BIND_TO_JSON(InvoiceMethodVO, id, name);
};

#endif //_INVOICEMETHOD_VO_
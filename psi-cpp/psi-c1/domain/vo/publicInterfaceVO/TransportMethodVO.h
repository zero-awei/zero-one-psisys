#ifndef _TRANSPORTMETHOD_VO_
#define _TRANSPORTMETHOD_VO_

#include "../../GlobalInclude.h"

/**
 *Author c1-ruizi
 * 2023/2/13  15:46
 * 接口：运输方式
 */

class TransportMethodVO
{
	// 方式编号
	CC_SYNTHESIZE(int, id, Id);
	// 方式名称
	CC_SYNTHESIZE(string, name, Name);

public:
	// 绑定JSON转换方法
	BIND_TO_JSON(TransportMethodVO, id, name);
};

#endif //_TRANSPORTMETHOD_VO_
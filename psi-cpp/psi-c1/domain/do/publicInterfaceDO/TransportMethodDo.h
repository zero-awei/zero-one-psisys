/**
 *Author c1-ruizi
 * 2023/2/22 17:46
 * 接口：运输方式
 */

#pragma once
#ifndef _TRANSPORTMETHOD_DO_
#define _TRANSPORTMETHOD_DO_
#include "../DoInclude.h"

 /**
  * 数据库实体类
  */
class TransportMethodDO
{
	// 编号
	CC_SYNTHESIZE(uint64_t, id, Id);
	// 货币名
	CC_SYNTHESIZE(string, name, Name);
public:
	TransportMethodDO() {
		id = 0;
		name = "";
	}
};

#endif // !_TRANSPORTMETHOD_DO_
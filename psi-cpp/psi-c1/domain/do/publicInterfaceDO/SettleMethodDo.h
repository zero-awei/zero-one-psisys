/**
 *Author c1-ruizi
 * 2023/2/22  15:46
 * 接口：结算方式
 */

#pragma once
#ifndef _SETTLEMETHOD_DO_
#define _SETTLEMETHOD_DO_
#include "../DoInclude.h"

 /**
  * 数据库实体类
  */
class SettleMethodDO
{
	// 编号
	CC_SYNTHESIZE(uint64_t, id, Id);
	// 货币名
	CC_SYNTHESIZE(string, name, Name);
public:
	SettleMethodDO() {
		id = 0;
		name = "";
	}
};

#endif // !_SETTLEMETHOD_DO_
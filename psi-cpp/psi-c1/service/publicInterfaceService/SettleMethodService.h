/**
 *Author c1-ruizi
 * 2023/2/22  15:46
 * 接口：结算方式
 */

#ifndef _SETTLEMETHOD_SERVICE_
#define _SETTLEMETHOD_SERVICE_

#include <list>
#include "../../domain/vo/publicInterfaceVO/SettleMethodVO.h"


class SettleMethodService
{
public:
	//数据列表
	list<SettleMethodVO> listAll();
};
#endif // !_SETTLEMETHOD_SERVICE_
/**
 *Author c1-ruizi
 * 2023/2/22 17:46
 * 接口：运输方式
 */

#ifndef _TRANSPORTMETHOD_SERVICE_
#define _TRANSPORTMETHOD_SERVICE_

#include <list>
#include "../../domain/vo/publicInterfaceVO/TransportMethodVO.h"


class TransportMethodService
{
public:
	//数据列表
	list<TransportMethodVO> listAll();
};
#endif // !_TRANSPORTMETHOD_SERVICE_
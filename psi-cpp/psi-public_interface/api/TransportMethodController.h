#ifndef _TRANSPORTMETHODCONTROLLER_VO_
#define _TRANSPORTMETHODCONTROLLER_VO_

#include "domain/vo/JsonVO.h"
#include "domain/vo/TransportMethodVO.h"
#include "api/ApiHelper.h"
/**
 *Author c1-ruizi
 * 2023/2/13  15:57
 * 运输方式接口
 */
class TransportMethodController
{
public:
	CREATE_API_FUN_QUERY3(queryTransportMethod, executequeryTransportMethod);
private:
	JsonVO<list<TransportMethodVO>> executequeryTransportMethod();
};

#endif // !_TRANSPORTMETHODCONTROLLER_VO_
#ifndef _SETTLEMETHODCONTROLLER_VO_
#define _SETTLEMETHODCONTROLLER_VO_

#include "domain/vo/JsonVO.h"
#include "domain/vo/SettleMethodVO.h"
#include "api/ApiHelper.h"
/**
 *Author c1-ruizi
 * 2023/2/13  15:57
 * 结算方式接口
 */
class SettleMethodController
{
public:
	CREATE_API_FUN_QUERY3(querySettleMethod, executequerySettleMethod);
private:
	JsonVO<list<SettleMethodVO>> executequerySettleMethod();
};

#endif // !_SETTLEMETHODCONTROLLER_VO_
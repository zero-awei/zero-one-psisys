/**
 *Author c1-ruizi
 * 2023/2/22 17:46
 * 接口：运输方式
 */

#ifndef _TRANSPORTMETHOD_DAO_
#define _TRANSPORTMETHOD_DAO_
#include "BaseDAO.h"
#include "../../domain/do/publicInterfaceDO/TransportMethodDo.h"

class TransportMethodDAO : public BaseDAO
{
public:
	//查询数据
	list<TransportMethodDO> selectTransportMethod();
};
#endif // !_TRANSPORTMETHOD_DAO_
/*
 *Author c1-ruizi
 * 2023/2/19  17:56
 * 接口：银行账户普通查询
 */
#ifndef _BANKACCOUNT_SERVICE_
#define _BANKACCOUNT_SERVICE_
#include <list>
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/bank-account/BankAccountListVO.h"
#include "../../domain/query/bank-account/BankAccountQuery.h"

 /**
  * 示例服务实现，演示基础的示例服务实现
  */
class BankAccountService
{
public:
	// 分页查询所有数据
	PageVO<BankAccountListVO> listAll(const BankAccountQuery& query);
};

#endif // !_BANKACCOUNT_SERVICE_
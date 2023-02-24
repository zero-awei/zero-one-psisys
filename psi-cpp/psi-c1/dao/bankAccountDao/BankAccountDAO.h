/*
 *Author c1-ruizi
 * 2023/2/19  17:56
 * 接口：银行账户普通查询
 */

#ifndef _BANKACCOUNT_DAO_
#define _BANKACCOUNT_DAO_
#include "BaseDAO.h"
#include "../../domain/do/bankAccount/BankAccountDO.h"

 /**
  * 示例表数据库操作实现
  */
class BankAccountDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count();
	// 分页查询数据
	list<BankAccountDO> selectWithPage(uint64_t pageIndex, uint64_t pageSize);
};
#endif // !_BANKACCOUNT_DAO_
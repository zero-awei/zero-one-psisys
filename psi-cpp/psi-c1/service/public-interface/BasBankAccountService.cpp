#include "stdafx.h"
#include "BasBankAccountService.h"
#include"../../dao/public-interface/BasBankAccountDAO.h"

list<BasBankAccountVO> BasBankAccountService::listAll()
{
    list<BasBankAccountVO> data;
	BasBankAccountDAO dao;
	list<BasBankAccountDO> result = dao.selectAccount();
	for (BasBankAccountDO sub : result)
	{
		BasBankAccountVO vo;
		vo.setId(sub.getId());
		vo.setValue(sub.getValue());
		data.push_back(vo);
	}
	return data;
}

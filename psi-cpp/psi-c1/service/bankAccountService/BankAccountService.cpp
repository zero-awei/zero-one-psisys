/*
 *Author c1-ruizi
 * 2023/2/19  17:56
 * 接口：银行账户普通查询
 */
#include "stdafx.h"
#include "BankAccountService.h"
#include "../../dao/bankAccountDao/BankAccountDAO.h"

PageVO<BankAccountListVO> BankAccountService::listAll(const BankAccountQuery& query)
{
	//构建返回对象
	PageVO<BankAccountListVO> pages;
	pages.setPageIndex(query.getPageIndex());
	pages.setPageSize(query.getPageSize());

	/*
	//查询数据总条数
	BankAccountDO obj;
	//普通查询这块应该咋查找
	//什么都不set咩
	obj.setName(query.getName());
	obj.setSex(query.getSex());
	*/
	BankAccountDAO dao;
	uint64_t count = dao.count();
	if (count <= 0)
	{
		return pages;
	}

	//分页查询数据
	pages.setTotal(count);
	pages.calcPages();
	list<BankAccountDO> result = dao.selectWithPage(query.getPageIndex(), query.getPageSize());
	list<BankAccountListVO> vr;
	for (BankAccountDO sub : result)
	{
		BankAccountListVO vo;		
		vo.setAccountNo(sub.getAccountNo());
		vo.setBankAddress(sub.getBankAddress());
		vo.setBankNo(sub.getBankNo());
		vo.setCreateBy_dictText(sub.getCreateBy_dictText());
		vo.setCreateTime(sub.getCreateTime());
		vo.setCurrency_dictText(sub.getCurrency_dictText());
		vo.setIsEnabled_dictText(sub.getIsEnabled_dictText());
		vo.setManager_dictText(sub.getManager_dictText());
		vo.setName(sub.getName());
		vo.setRemark(sub.getRemark());
		vo.setUpdateBy(sub.getUpdateBy());
		vo.setUpdateTime(sub.getUpdateTime());
		vr.push_back(vo);
	}
	pages.setRows(vr);
	return pages;
}




#include "stdafx.h"
#include "BankAccountController.h"
#include"CharsetConvertHepler.h"
#include "../../service/bankAccountService/BankAccountService.h"

JsonVO<PageVO<SpecifiedBankAccountListVO>> BankAccountController::execSpecifiedBankAccount(SpecifiedBankAccountQuery& query)
{
	SpecifiedBankAccountListVO vo;
	vo.setAccountNo("111");
	vo.setAttachment("");
	vo.setBankAddress("");
	vo.setBankNo("");
	vo.setCreateBy("psi");
	vo.setCreateBy_dictText(CharsetConvertHepler::ansiToUtf8("管理员"));
	vo.setCreateTime("2023-01-14 00:46:24");
	vo.setCurrency("CNY");
	vo.setCurrency_dictText(CharsetConvertHepler::ansiToUtf8("人民币"));
	vo.setId("1625174558616363009");
	vo.setInitBal(0);
	vo.setIsEnabled(1);
	vo.setIsEnabled_dictText(CharsetConvertHepler::ansiToUtf8("是"));
	vo.setManager("");
	vo.setName("123");
	vo.setRemark("");
	vo.setUpdateBy("");
	vo.setUpdateTime("");
	vo.setVersion("");
	PageVO<SpecifiedBankAccountListVO> data(query.getPageIndex(), query.getPageSize(), 100, 10, { vo });
    JsonVO<PageVO<SpecifiedBankAccountListVO>> res;
    res.success(data);
    return res;
}
/*JsonVO<PageVO<BankAccountListVO>> BankAccountController::executequeryBankAccountList(BankAccountQuery query)
{
	PageVO<BankAccountListVO> data;
	JsonVO<PageVO<BankAccountListVO>> res;
	//res.success(data);
	return res;
}
*/

JsonVO<PageVO<BankAccountListVO>> BankAccountController::executequeryBankAccountList(BankAccountQuery& query)
{
	//定义一个Service
	BankAccountService service;
	//查询数据
	PageVO<BankAccountListVO> result = service.listAll(query);
	//响应结果
	return JsonVO<PageVO<BankAccountListVO>>(result, RS_SUCCESS);
}

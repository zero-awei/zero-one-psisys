

#include "stdafx.h"
#include "PurInquiryController.h"
#include "../../service/pur-inquiry/PurInquiryService.h"


//查询采购询价单分页列表
JsonVO<PageVO<PurInquiryFindBillVO>> PurInquiryController::execQueryPurInquiryFindBill(const PurInquiryFindBillQuery& query, const PayloadDTO& payload)
{
	//测试Apipost
	PurInquiryFindBillVO test;
	list<PurInquiryFindBillVO> ls; 
	ls.push_back(test);
	PageVO<PurInquiryFindBillVO> result(1, 2, 0, 0, ls);
	//PageVO<PurInquiryFindBillVO> result;

	return JsonVO<PageVO<PurInquiryFindBillVO>>(result, RS_SUCCESS);
}

//查看指定询价单详细信息
JsonVO<PurInquiryFindDetailBillVO> PurInquiryController::execQueryPurInquiryFindDetailBill(const PurInquiryFindDetailBillQuery& query, const PayloadDTO& payload)
{
	PurInquiryFindDetailBillVO result;
	//响应结果
	return JsonVO<PurInquiryFindDetailBillVO>(result, RS_SUCCESS);
}

//添加采购询价
JsonVO<AddPurInquiryVO> PurInquiryController::execAddPurInquiry(const AddPurInquiryDTO& dto)
{
	JsonVO<AddPurInquiryVO> result;
	AddPurInquiryVO vo;


	result.success(vo);
	return result;
}

//修改采购询价
JsonVO<AddPurInquiryVO> PurInquiryController::execModifyPurInquiry(const AddPurInquiryDTO& dto)
{
	JsonVO<AddPurInquiryVO> result;
	AddPurInquiryVO vo;


	


	result.success(vo);
	return result;
}

//删除采购询价
JsonVO<uint64_t> PurInquiryController::execRemovePurInquiry(const PurInquiryRemoveDTO& dto)
{
	JsonVO<uint64_t> result;




	return result;
}

//修改单据编号
JsonVO<uint64_t> PurInquiryController::execModifyPurQuotModBillStatus(const PurInquiryModBillStatusDTO& dto)
{
	JsonVO<uint64_t> result;




	return result;
}

//文件上传
JsonVO<PurInquiryIntoVO> PurInquiryController::execPurInquiryInto(const PurInquiryIntoDTO& dto)
{
	JsonVO<PurInquiryIntoVO> result;
	PurInquiryIntoVO vo;



	result.success(vo);
	return result;
}

//文件导出
JsonVO<std::string> PurInquiryController::execPurInquiryExport(const PurInquiryExportQuery& query)
{

	JsonVO<std::string> result;
	string fileName = "d//f//a.txt";


	result.success(fileName);
	return result;
}


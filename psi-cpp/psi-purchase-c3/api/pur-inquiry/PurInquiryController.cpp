#include "stdafx.h"
#include "PurInquiryController.h"

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

//文件导入
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



#include "stdafx.h"
#include "PurInquiryController.h"
#include "../../service/pur-inquiry/PurInquiryService.h"
#include "api/pur-inquiry/ExecExport.h"


// 查询采购询价单分页列表
JsonVO<PageVO<PurInquiryFindBillVO>> PurInquiryController::execQueryPurInquiryFindBill(const PurInquiryFindBillQuery& query, const PayloadDTO& payload)
{
	// 定义一个Service
	PurInquiryService service;
	// 查询数据
	PageVO<PurInquiryFindBillVO> result = service.listAll(query);
	// 响应结果
	return JsonVO<PageVO<PurInquiryFindBillVO>>(result, RS_SUCCESS);
}

// 查看指定询价单详细信息
JsonVO<PurInquiryFindDetailBillVO> PurInquiryController::execQueryPurInquiryFindDetailBill(const PurInquiryFindDetailBillQuery& query, const PayloadDTO& payload)
{
	// 定义一个Service
	PurInquiryService service;
	//数据校验
	PurInquiryFindDetailBillVO result;
	if (query.getBill_no() == "") return JsonVO<PurInquiryFindDetailBillVO>(result, RS_PARAMS_INVALID);
	//查询数据
	result = service.listPurInquiryFindDetailBill(query);
	// 响应结果
	return JsonVO<PurInquiryFindDetailBillVO>(result, RS_SUCCESS);
}


//添加采购询价
JsonVO<uint64_t> PurInquiryController::execAddPurInquiry(const AddPurInquiryDTO& dto, const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	PurInquiryService server;
	uint64_t id = server.saveData(dto);
	if (id > 0)
	{
		result.success(id);
	}
	else
	{
		result.fail(id);
	}


	return result;
}

//修改采购询价
JsonVO<std::string> PurInquiryController::execModifyPurInquiry(const AddPurInquiryDTO& dto, const PayloadDTO& payload)
{
	PurInquiryService service;
	JsonVO<std::string> result;
	if (service.updateData(dto)) {
		result.success(dto.getBill_no());
	}
	else
	{
		result.fail(dto.getBill_no());
	}
	return result;
}

//删除采购询价
JsonVO<string> PurInquiryController::execRemovePurInquiry(const PurInquiryRemoveDTO& dto)
{
	JsonVO<string> result;
	PurInquiryService service;
	if (service.removeData(dto))
	{
		result.success(dto.getBill_no());
	}
	else
	{
		result.fail(dto.getBill_no());
	}


	return result;
}

//修改单据编号
JsonVO<string> PurInquiryController::execModifyPurQuotModBillStatus(const PurInquiryModBillStatusDTO& dto)
{
	JsonVO<string> result;
	PurInquiryService service;
	if (service.updateDataByStatus(dto))
	{
		result.success(dto.getBill_no());
	}
	else
	{
		result.fail(dto.getBill_no());
	}

	return result;
}


// 导出（按单据编号批量查询后，放入xml，再下载文件）
JsonVO<std::string> PurInquiryController::execPurInquiryExport(const PurInquiryExportQuery& query, const PayloadDTO& payload)
{
	// 定义一个Service
	PurInquiryService service;
	//查询数据
	JsonVO<std::string> result(u8"../../public/temporaryfile/testExportExcel.xlsx", RS_SUCCESS);
	// 创建excel表
	vector<std::string> head = { u8"付款方式", u8"交货地点", u8"交货时间", u8"联系人",u8"联系电话",\
		u8"fax", u8"email",u8"数量", u8"参考金额", u8"生效的报价单数", u8"物料", u8"计量单位", u8"数量",\
		u8"税率%", u8"参考含税单价", u8"参考含税金额", u8"自定义1", u8"源单分录号", u8"分录号", u8"自定义2",\
		u8"源单分录id", u8"源单类型", u8"备注", u8"单据编号", u8"源单id", u8"是否生效", u8"附件", u8"源单id",\
		u8"单据主题", u8"单据阶段", u8"源单号", u8"是否自动生成", u8"备注", u8"审批实例id", u8"已作废", \
		u8"单据编号", u8"是否红字", u8"源单类型", u8"制单时间", u8"生效时间", u8"核批人" , u8"修改人",\
		u8"制单部门", u8"已关闭", u8"核批结果类型", u8"单据日期", u8"制单人", u8"核批意见" };
	PageVO<PurInquiryExportVO> res = service.PurInquiryExport(query);
	execexport(head, u8"采购询价单", res);
	
	//响应结果
	return JsonVO<std::string>(result);
}

// 导入（上传文件后，将xml解析成json/cpp放入数据库，保存数据）
JsonVO<PurInquiryIntoVO> PurInquiryController::execPurInquiryInto(const PurInquiryIntoDTO& dto)
{
	JsonVO<PurInquiryIntoVO> result;
	PurInquiryIntoVO vo;



	result.success(vo);
	return result;
}





#include "stdafx.h"
#include "PurInquiryController.h"
#include "../../service/pur-inquiry/PurInquiryService.h"
#include "api/pur-inquiry/ExecExport.h"
#include "CharsetConvertHepler.h"


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
	uint64_t id = server.saveData(dto, payload);
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
	if (service.updateData(dto, payload)) {
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
JsonVO<std::string> PurInquiryController::execQueryPurInquiryExport(const PurInquiryExportQuery& query, const PayloadDTO& payload)
{
	// 构建返回对象数据
	JsonVO<std::string> result;
	// 设置exlce表头名称
	vector<std::string> head = {
		CharsetConvertHepler::ansiToUtf8("单据编号"),CharsetConvertHepler::ansiToUtf8("单据日期"), \
		CharsetConvertHepler::ansiToUtf8("单据阶段"), CharsetConvertHepler::ansiToUtf8("单据主题"),\
		CharsetConvertHepler::ansiToUtf8("源单号"), CharsetConvertHepler::ansiToUtf8("源单id"),\
		CharsetConvertHepler::ansiToUtf8("源单类型"),CharsetConvertHepler::ansiToUtf8("付款方式"),\
		CharsetConvertHepler::ansiToUtf8("交货地点"), CharsetConvertHepler::ansiToUtf8("交货时间"),\
		CharsetConvertHepler::ansiToUtf8("联系人"), CharsetConvertHepler::ansiToUtf8("联系电话"),\
		CharsetConvertHepler::ansiToUtf8("fax"), CharsetConvertHepler::ansiToUtf8("email"),\
		CharsetConvertHepler::ansiToUtf8("数量"), CharsetConvertHepler::ansiToUtf8("参考金额"),\
		CharsetConvertHepler::ansiToUtf8("生效的报价单数"), CharsetConvertHepler::ansiToUtf8("备注"),
		CharsetConvertHepler::ansiToUtf8("是否生效"), CharsetConvertHepler::ansiToUtf8("生效时间"),\
		CharsetConvertHepler::ansiToUtf8("已关闭"), CharsetConvertHepler::ansiToUtf8("已作废"),\
		CharsetConvertHepler::ansiToUtf8("是否自动生成"), CharsetConvertHepler::ansiToUtf8("是否红字"),\
		CharsetConvertHepler::ansiToUtf8("制单人"), CharsetConvertHepler::ansiToUtf8("制单时间"),\
		CharsetConvertHepler::ansiToUtf8("制单部门"), CharsetConvertHepler::ansiToUtf8("修改人"),\
		CharsetConvertHepler::ansiToUtf8("附件"), CharsetConvertHepler::ansiToUtf8("审批实例id"),\
		CharsetConvertHepler::ansiToUtf8("核批人"), CharsetConvertHepler::ansiToUtf8("核批结果类型"),\
		CharsetConvertHepler::ansiToUtf8("核批意见"), CharsetConvertHepler::ansiToUtf8("单据编号"),\
		CharsetConvertHepler::ansiToUtf8("分录号"), CharsetConvertHepler::ansiToUtf8("源单id"),\
		CharsetConvertHepler::ansiToUtf8("源单分录号"), CharsetConvertHepler::ansiToUtf8("源单分录id"),\
		CharsetConvertHepler::ansiToUtf8("源单类型"), CharsetConvertHepler::ansiToUtf8("物料"),\
		CharsetConvertHepler::ansiToUtf8("计量单位"), CharsetConvertHepler::ansiToUtf8("数量"),\
		CharsetConvertHepler::ansiToUtf8("税率%"), CharsetConvertHepler::ansiToUtf8("参考含税单价"),\
		CharsetConvertHepler::ansiToUtf8("参考含税金额"), CharsetConvertHepler::ansiToUtf8("自定义1"),\
		CharsetConvertHepler::ansiToUtf8("自定义2"), CharsetConvertHepler::ansiToUtf8("备注")};
	// 查询要导出的单据编号列表
	list<std::string> exres = query.getBill_no_list();
	// 读入excel表，并返回fastDfs地址
	std::string url = execexport(head, CharsetConvertHepler::ansiToUtf8("采购询价单"), exres);
	if (url == "")
		result.fail("");
	else 
		result.success(url);
	//响应结果
	return JsonVO<std::string>(result);
}

// 导入（上传文件后，将xml解析成json/cpp放入数据库，保存数据）
JsonVO<uint64_t> PurInquiryController::execaddPurInquiryInto(const PurInquiryIntoDTO& dto, const PayloadDTO& payload)
{
	JsonVO<uint64_t> result;
	//下载文件并且进行execl解析
	PurInquiryService service;
	uint64_t ret = 1;
	for (string file : dto.getFiles()) {
		ret = service.PurInquiryInto(file, payload);
		if (ret == 0)
		{
			result.fail(9995);
			break;
		}
	}
	//响应结果
	if (ret)
	{
		result.success(100);
	}
	return result;
}




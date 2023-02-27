/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:58:42

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "CgrkController.h"
#include "../../service/Cgrk/CgrkService.h"



//查询单据列表
JsonVO<PageVO<QueryCgrkBillListVO>> CgrkController::execQueryCgrkBillList(const QueryCgrkBillListQuery& query)
{

	CgrkService service;
	PageVO<QueryCgrkBillListVO> result = service.listCgrkBillList(query);
	return JsonVO<PageVO<QueryCgrkBillListVO>>(result, RS_SUCCESS);


}

//高级查询单据列表
JsonVO<PageVO<QueryCgrkBillListVO>> CgrkController::execQueryCgrkBillListAdvanced(const QueryCgrkBillListAdvancedQuery& query)
{
	PageVO<QueryCgrkBillListVO> result;
	list<QueryCgrkBillListVO> rows;
	rows.push_back(QueryCgrkBillListVO());
	rows.push_back(QueryCgrkBillListVO());
	rows.push_back(QueryCgrkBillListVO());
	result.setRows(rows);
	return JsonVO<PageVO<QueryCgrkBillListVO>>(result, RS_SUCCESS);
}


//查看指定单据详细信息
JsonVO<QueryCgrkBillDetailsVO> CgrkController::execQueryCgrkBillDetails(const QueryCgrkBillDetailsQuery& query)
{
	CgrkService service;
	QueryCgrkBillDetailsVO result = service.getCgrkBillDetails(query);
	return JsonVO<QueryCgrkBillDetailsVO>(result, RS_SUCCESS);
}




//查询采购订单列表
JsonVO<PageVO<QueryPurOrderListVO>> CgrkController::execQueryPurOrderList(const QueryPurOrderListQuery& query)
{
	CgrkService service;
	PageVO<QueryPurOrderListVO> result = service.listPurOrderList(query);
	return JsonVO<PageVO<QueryPurOrderListVO>>(result, RS_SUCCESS);
}
//查看采购订单分录列表
JsonVO<PageVO<QueryPurOrderEntryVO>> CgrkController::execQueryPurOrderEntry(const QueryPurOrderEntryQuery& query)
{
	CgrkService service;
	PageVO<QueryPurOrderEntryVO> result = service.listPurOrderEntry(query);
	return JsonVO<PageVO<QueryPurOrderEntryVO>>(result, RS_SUCCESS);
}

//添加采购入库单
JsonVO<int> CgrkController::execAddCgrkBill(const AddCgrkBillDTO& dto,const PayloadDTO& payload)
{
	JsonVO<int> result;
	CgrkService service;



	// 执行新增数据
	int row = service.saveCgrkBill(dto, payload);
	if (row > 0) {
		result.success(row);
	}
	else if (row == -1) {
		result.setData(row);
		result.setStatus(RS_PARAMS_INVALID);
	}
	else {
		result.fail(row);
	}
	return result;

}
//修改采购入库单
JsonVO<uint64_t>  CgrkController::execModifyCgrkBill(const ModifyCgrkBillDTO& dto)
{

	JsonVO<uint64_t> result;
	
	return result;
}

//删除采购入库单
JsonVO<std::string> CgrkController::execRemoveCgrkBill(const RemoveCgrkBillDTO& dto)
{

	CgrkService service;
	JsonVO<std::string> result;
	//执行数据删除
	if (service.removeCgrkBill(dto.getBillNo())) {
		result.success(dto.getBillNo());
	}
	else
	{
		result.fail(dto.getBillNo());
	}
	//响应结果
	return result;
}

//修改单据状态
JsonVO<uint64_t> CgrkController::execModifyCgrkBillState(const ModifyCgrkBillStateDTO& dto)
{

	JsonVO<uint64_t> result;
	result.success(1);

	return result;
}
// 导入
JsonVO<uint64_t> CgrkController::execImportCgrkFile(const ImportCgrkFileDTO& dto)
{
	JsonVO<uint64_t> result;
	result.success(1);
	return result;
}
// 导出
JsonVO<std::string> CgrkController::execExportCgrkFile()
{
	JsonVO<std::string> result;
	result.success(u8"下载链接");
	return result;
}



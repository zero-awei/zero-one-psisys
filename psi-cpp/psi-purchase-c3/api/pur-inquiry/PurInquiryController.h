



#pragma once
#ifndef _PUR_INQUIRY_CONTROLLER_
#define _PUR_INQUIRY_CONTROLLER_

//公共接口
#include "stdafx.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/dto/IDDTO.h"
//dto
#include "../../domain/dto/pur-inquiry/AddPurInquiryDTO.h"
#include "../../domain/dto/pur-inquiry/PurInquiryIntoDTO.h"
#include "../../domain/dto/pur-inquiry/PurInquiryModBillStatusDTO.h"


//query
#include "../../domain/query/pur-inquiry/PurInquiryFindBillQuery.h"
#include "../../domain/query/pur-inquiry/PurInquiryFindDetailBillQuery.h"
#include "../../domain/query/pur-inquiry/PurInquiryExportQuery.h"
//vo
#include "../../domain/vo/pur-inquiry/PurInquiryFindBillVO.h"
#include "../../domain/vo/pur-inquiry/PurInquiryFindDetailBillVO.h"
#include "../../domain/vo/pur-inquiry/EntryPurInquiryVO.h"


//存在问题的命名
#include "../../domain/dto/pur-inquiry/PurInquiryRemoveDTO.h"
#include "../../domain/dto/pur-inquiry/PurInquiryIntoDTO.h"


#include "../../domain/vo/pur-inquiry/PurInquiryIntoVO.h"


#include "../../domain/vo/pur-inquiry/AddPurInquiryVO.h"

/**
 * 示例控制器，演示接口的使用
 */
class PurInquiryController
{
public:
	//接口1 查询采购询价单分页列表
	CREATE_API_FUN_QUERY_PAYLOAD(queryPurInquiryFindBill, execQueryPurInquiryFindBill, PurInquiryFindBillQuery);
	//接口2 查看指定询价单详细信息
	CREATE_API_FUN_QUERY_PAYLOAD(queryPurInquiryFindDetailBill, execQueryPurInquiryFindDetailBill, PurInquiryFindDetailBillQuery);
	CREATE_API_FUN_BODY_FILE(addPurInquiry, execAddPurInquiry, AddPurInquiryDTO);
	CREATE_API_FUN_BODY_FILE(modifyPurInquiry, execModifyPurInquiry, AddPurInquiryDTO);
	CREATE_API_FUN_BODY(removePurInquiry, execRemovePurInquiry, PurInquiryRemoveDTO);
	CREATE_API_FUN_BODY(modifyPurQuotModBillStatus,execModifyPurQuotModBillStatus,PurInquiryModBillStatusDTO)
	CREATE_API_FUN_BODY_FILE(PurInquiryInto, execPurInquiryInto, PurInquiryIntoDTO);
	CREATE_API_FUN_QUERY(PurInquiryExport, execPurInquiryExport, PurInquiryExportQuery);
private:
	//查询采购询价单分页列表
	JsonVO<PageVO<PurInquiryFindBillVO>> execQueryPurInquiryFindBill(const PurInquiryFindBillQuery& query, const PayloadDTO& payload);
	//查看指定询价单详细信息
	JsonVO<PurInquiryFindDetailBillVO> execQueryPurInquiryFindDetailBill(const PurInquiryFindDetailBillQuery& query, const PayloadDTO& payload);
	//添加数据
	JsonVO<AddPurInquiryVO> execAddPurInquiry(const AddPurInquiryDTO& dto);
	//修改数据
	JsonVO<AddPurInquiryVO> execModifyPurInquiry(const AddPurInquiryDTO& dto);
	//删除数据
	JsonVO<uint64_t> execRemovePurInquiry(const PurInquiryRemoveDTO& dto);
	//修改单据状态
	JsonVO<uint64_t> execModifyPurQuotModBillStatus(const PurInquiryModBillStatusDTO& dto);
	//文件上传
	JsonVO<PurInquiryIntoVO> execPurInquiryInto(const PurInquiryIntoDTO& dto);
	//文件下载
	JsonVO<std::string> execPurInquiryExport(const PurInquiryExportQuery& qurry);


};

#endif 






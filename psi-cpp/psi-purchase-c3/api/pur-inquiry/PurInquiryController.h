



#pragma once
#ifndef _PUR_INQUIRY_CONTROLLER_H_
#define _PUR_INQUIRY_CONTROLLER_H_

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
#include "../../domain/vo/pur-inquiry/PurInquiryExportVO.h"
#include "stdafx.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/dto/IDDTO.h"
//dto
#include "../../domain/dto/pur-inquiry/AddPurInquiryDTO.h"
#include "../../domain/dto/pur-inquiry/PurInquiryIntoDTO.h"
#include "../../domain/dto/pur-inquiry/PurInquiryModBillStatusDTO.h"
#include "../../domain/dto/pur-inquiry/PurInquiryRemoveDTO.h"
#include "../../domain/dto/pur-inquiry/PurInquiryIntoDTO.h"


//query
#include "../../domain/query/pur-inquiry/PurInquiryFindBillQuery.h"
#include "../../domain/query/pur-inquiry/PurInquiryFindDetailBillQuery.h"
#include "../../domain/query/pur-inquiry/PurInquiryExportQuery.h"
//vo
#include "../../domain/vo/pur-inquiry/PurInquiryFindBillVO.h"
#include "../../domain/vo/pur-inquiry/PurInquiryFindDetailBillVO.h"
#include "../../domain/vo/pur-inquiry/EntryPurInquiryVO.h"
#include "../../domain/vo/pur-inquiry/PurInquiryExportVO.h"
#include "../../domain/vo/pur-inquiry/PurInquiryIntoVO.h"


//存在问题的命名
#include "../../domain/dto/pur-inquiry/PurInquiryRemoveDTO.h"
//#include "../../domain/dto/pur-inquiry/PurInquiryIntoDTO.h"


#include "../../domain/vo/pur-inquiry/PurInquiryIntoVO.h"




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
	//增加询价
	CREATE_API_FUN_JSON_PAYLOAD(addPurInquiry, execAddPurInquiry, AddPurInquiryDTO);
	//修改询价
	CREATE_API_FUN_JSON_PAYLOAD(modifyPurInquiry, execModifyPurInquiry, AddPurInquiryDTO);
	//删除询价
	CREATE_API_FUN_BODY(removePurInquiry, execRemovePurInquiry, PurInquiryRemoveDTO);
	//修改询价单据
	CREATE_API_FUN_BODY(modifyPurQuotModBillStatus, execModifyPurQuotModBillStatus, PurInquiryModBillStatusDTO);
	// 导出
	CREATE_API_FUN_JSON_PAYLOAD(queryPurInquiryExport, execQueryPurInquiryExport, PurInquiryExportQuery);
	// 导入
	CREATE_API_FUN_BODY_PAYLOAD_FILE(addPurInquiryInto, execaddPurInquiryInto, PurInquiryIntoDTO);
private:
	//查询采购询价单分页列表
	JsonVO<PageVO<PurInquiryFindBillVO>> execQueryPurInquiryFindBill(const PurInquiryFindBillQuery& query, const PayloadDTO& payload);
	//查看指定询价单详细信息
	JsonVO<PurInquiryFindDetailBillVO> execQueryPurInquiryFindDetailBill(const PurInquiryFindDetailBillQuery& query, const PayloadDTO& payload);
	//添加数据
	JsonVO<uint64_t> execAddPurInquiry(const AddPurInquiryDTO& dto, const PayloadDTO& payload);
	//修改数据
	JsonVO<std::string> execModifyPurInquiry(const AddPurInquiryDTO& dto, const PayloadDTO& payload);
	//删除数据
	JsonVO<string> execRemovePurInquiry(const PurInquiryRemoveDTO& dto);
	//修改单据状态
	JsonVO<string> execModifyPurQuotModBillStatus(const PurInquiryModBillStatusDTO& dto);
	//导出（按单据编号批量查询后，放入xml，再下载文件）
	JsonVO<std::string> execQueryPurInquiryExport(const PurInquiryExportQuery& query,const PayloadDTO& payload);
	//导入（上传文件后，将xml解析成json/cpp放入数据库，保存数据）
	JsonVO<uint64_t> execaddPurInquiryInto(const PurInquiryIntoDTO& dto, const PayloadDTO& payload);
};

#endif 






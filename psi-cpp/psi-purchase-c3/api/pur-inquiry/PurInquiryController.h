
#pragma once


#ifndef _PUR_INQUIRY_CONTROLLER_
#define _PUR_INQUIRY_CONTROLLER_

//公共接口
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/dto/IDDTO.h"
//dto
//#include "../../domain/dto/pur-inquiry/PurInquiryDTO.h"
#include "../../domain/dto/pur-inquiry/PurInquiryFindBillDTO.h"
#include "../../domain/dto/pur-inquiry/PurInquiryFindDetailBillDTO.h"

//query
//#include "../../domain/query/pur-inquiry/PurInquiryQuery.h"
#include "../../domain/query/pur-inquiry/PurInquiryFindBillQuery.h"
#include "../../domain/query/pur-inquiry/PurInquiryFindDetailBillQuery.h"

//vo
//#include "../../domain/vo/pur-inquiry/PurInquiryVO.h"
#include "../../domain/vo/pur-inquiry/PurInquiryFindBillVO.h"
#include "../../domain/vo/pur-inquiry/PurInquiryFindDetailBillVO.h"
#include "../../domain/vo/pur-inquiry/EntryPurInquiryVO.h"



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
	//CREATE_API_FUN_BODY(addPurInquiry, execAddPurInquiry, InquiryDTO);
	//CREATE_API_FUN_BODY(modifyPurInquiry, execModifyPurInquiry, InquiryDTO);
	//CREATE_API_FUN_BODY(removePurInquiry, execRemovePurInquiry, PurInquiryRemoveDTO);
	//CREATE_API_FUN_BODY_FILE(PurInquiryInto, execPurInquiryInto, PurInquiryDTO);
	//CREATE_API_FUN_QUERY(PurInquiryExport, execPurInquiryExport, PurInquiryQurey);
private:
	//查询采购询价单分页列表
	JsonVO<PageVO<PurInquiryFindBillVO>> execQueryPurInquiryFindBill(const PurInquiryFindBillQuery& query, const PayloadDTO& payload);
	//查看指定询价单详细信息
	JsonVO<PurInquiryFindDetailBillVO> execQueryPurInquiryFindDetailBill(const PurInquiryFindDetailBillQuery& query, const PayloadDTO& payload);
	//添加数据
	//JsonVO<uint64_t> execAddPurInquiry(const InquiryDTO& dto);
	////修改数据
	//JsonVO<uint64_t> execModifyPurInquiry(const InquiryDTO& dto);
	////删除数据
	//JsonVO<uint64_t> execRemovePurInquiry(const PurInquiryRemoveDTO& dto);
	////文件上传
	//JsonVO<PurInquiryVO> execPurInquiryInto(const PurInquiryDTO& dto);
	////文件下载
	//JsonVO<std::string> execPurInquiryExport(const PurInquiryQurey& qurry);

};

#endif 






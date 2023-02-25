#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Eleanor
 @Date: 2023/2/15 14:42

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
#ifndef _PUR_INQUIRY_SERVICE_
#define _PUR_INQUIRY_SERVICE_
#include <list>
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/vo/Message.h"

//vo
#include "../../domain/vo/pur-inquiry/PurInquiryFindBillVO.h"
#include "../../domain/vo/pur-inquiry/PurInquiryFindDetailBillVO.h"
#include "../../domain/vo/pur-inquiry/PurInquiryExportVO.h"
//query
#include "../../domain/query/pur-inquiry/PurInquiryFindBillQuery.h"
#include "../../domain/query/pur-inquiry/PurInquiryFindDetailBillQuery.h"
#include "../../domain/query/pur-inquiry/PurInquiryExportQuery.h"
//dto
#include "../../domain/dto/pur-inquiry/PurInquiryIntoDTO.h"
#include "../../domain/dto/pur-inquiry/AddPurInquiryDTO.h"
#include "../../domain/dto/pur-inquiry/PurInquiryRemoveDTO.h"
#include "../../domain/dto/pur-inquiry/PurInquiryModBillStatusDTO.h"


/**
 * 示例服务实现
 */
class PurInquiryService
{
public:
	// 分页查询所有数据
	PageVO<PurInquiryFindBillVO> listAll(const PurInquiryFindBillQuery& query);
	// 查看指定采购询价单详情
	PurInquiryFindDetailBillVO listPurInquiryFindDetailBill(const PurInquiryFindDetailBillQuery& query);

	// 导出（按id批量查询后，放入xml，再下载文件）
	PageVO<PurInquiryExportVO>  PurInquiryExport(const PurInquiryExportQuery& query);
	
	// 导入（上传文件后，将xml解析成json/cpp放入数据库，保存数据）
	bool  PurInquiryInto(const PurInquiryIntoDTO& dto);
	// 保存数据
	uint64_t saveData(const PurInquiryIntoDTO& dto);


	// 保存数据(插入询价)
	uint64_t saveData(const AddPurInquiryDTO& dto);
	// 修改询价
	bool updateData(const AddPurInquiryDTO& dto);
	//删除询价
	bool removeData(const PurInquiryRemoveDTO& dto);
	//修改单据状态
	bool updateDataByStatus(const PurInquiryModBillStatusDTO& dto);
	
};

#endif // !_PUR_INQUIRY_SERVICE_
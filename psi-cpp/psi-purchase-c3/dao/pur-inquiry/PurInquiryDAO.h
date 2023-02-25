#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Eleanor
 @Date: 2023/2/18 22:43

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
#ifndef _PUR_INQUIRY_DAO_
#define _PUR_INQUIRY_DAO_
#include "BaseDAO.h"
#include "../../domain/do/pur-inquiry/PurInquiryDO.h"
#include "../../domain/do/pur-inquiry/PurInquiryEntryDO.h"
#include "../../domain/do/pur-inquiry/PurReqDO.h"
#include "../../domain/do/pur-inquiry/PurReqEntryDO.h"

#include "../../domain/do/pur-inquiry/AddPurInquiryDO.h"
#include "../../domain/do/pur-inquiry/AddPurInquiryEntryDO.h"
#include "../../domain/dto/pur-inquiry/PurInquiryRemoveDTO.h"
#include "../../domain/do/pur-inquiry/PurInquiryModBillStatusDO.h"

/*
*  数据库操作实现
*/


class PurInquiryDAO : public BaseDAO
{
public:
	// 插入数据
	uint64_t insert(const AddPurInquiryDO& iObj);
	//插入明细
	uint64_t insertByEntry(const AddPurInquiryEntryDO& iObj);
	// 修改数据
	int update(const AddPurInquiryDO& uObj);
	//修改明细
	int updateByEntry(const AddPurInquiryEntryDO& uObj);
	// 通过单据编号删除询价
	int deleteById(string bill_no);
	//修改单据状态
	int updateByModBillStatus(const PurInquiryModBillStatusDO& uObj);

	// 统计数据条数
	uint64_t count(const PurInquiryDO& iObj);
	// 统计导出的数据条数
	uint64_t countExport(PurInquiryDO iObj);
	// 统计导入的数据条数
	uint64_t countInto(PurInquiryDO iObj);	
	// 分页查询数据
	list<PurInquiryDO> selectPurInquiryFindBillWithPage(const PurInquiryDO& obj, uint64_t pageIndex, uint64_t pageSize);
	// 查看指定单据详情（按单据编号查询）
	list<PurInquiryDO> selectPurInquiryFindDetailBill(const PurInquiryDO& obj);
	// 指定单据明细分录
	list<PurInquiryEntryDO> selectPurInquiryFindDetailBillEntry(const PurInquiryEntryDO& obj);

	//// 指定单据申请单分录
	//list<PurReqDO> selectPurReq(const PurReqDO& obj, uint64_t pageIndex, uint64_t pageSize);
	//// 指定单据申请单明细
	//list<PurReqEntryDO> selectPurReqEntry(const PurReqEntryDO& obj);

	// 导出（按单据编号批量查询后，放入xml，再下载文件）
	list<PurInquiryDO> selectPurInquiryExport(const PurInquiryDO& obj, long pageIndex, long pageSize);

	list<PurInquiryEntryDO> selectPurInquiryExportEntry(const PurInquiryEntryDO& obj);
	



	// 导入（上传文件后，将xml解析成json/cpp放入数据库，保存数据）
	 
};


#endif // !_PUR_INQUIRY_FIND_BILL_DAO_
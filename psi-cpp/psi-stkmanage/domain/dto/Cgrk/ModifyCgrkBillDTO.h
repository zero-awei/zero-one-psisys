
#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:59:38

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
#ifndef _MODIFY_CGRK_BILL_DTO_
#define _MODIFY_CGRK_BILL_DTO_

#include "../../GlobalInclude.h"
#include "CgrkBillEntryDTO.h"
#include "../FileDTO.h"

/**
 * 修改采购入库单（保存/审核/提交）
 */
class ModifyCgrkBillDTO : public FileDTO
{

	//必填
	//单据编号
	CC_SYNTHESIZE(string, billNo, BillNo);//自动生成
	//单据日期
	CC_SYNTHESIZE(string, billDate, BillDate);
	//供应商
	CC_SYNTHESIZE(string, supplierId, SupplierId);
	//发票类型
	CC_SYNTHESIZE(string, invoiceType, InvoiceType);

	//选填############
	//源单号
	CC_SYNTHESIZE(string, srcNo, SrcNo);
	//单据主题
	CC_SYNTHESIZE(string, subject, Subject);
	//业务员
	CC_SYNTHESIZE(string, operator1, Operator1);
	//业务部门
	CC_SYNTHESIZE(string, opDept, OpDept);
	//入库经办
	CC_SYNTHESIZE(string, handler, Handler);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//附件
	CC_SYNTHESIZE(string, attachment, Attachment);
	//是否涨吨
	CC_SYNTHESIZE(int, hasSwell, HasSwell);
	//自动生成
	CC_SYNTHESIZE(int, isAuto, IsAuto);
	//单据明细
	CC_SYNTHESIZE(list<CgrkBillEntryDTO>, entry, Entry);


	// 保存or提交(0:保存, 1:提交)
	CC_SYNTHESIZE(int, save, Save);

	//审核
	CC_SYNTHESIZE(int, approve, Approve);
	//核批结果类型
	CC_SYNTHESIZE(string, approvalResultType, ApprovalResultType);
	//核批意见
	CC_SYNTHESIZE(string, approvalRemark, ApprovalRemark);

public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, ModifyCgrkBillDTO& t); // NOLINT

};

#endif // !_ADD_CGRK_BILL_DTO_
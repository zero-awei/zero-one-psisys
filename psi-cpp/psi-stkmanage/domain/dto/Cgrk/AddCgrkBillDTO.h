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
#ifndef _ADD_CGRK_BILL_DTO_
#define _ADD_CGRK_BILL_DTO_

#include "../../GlobalInclude.h"
#include "CgrkBillEntryDTO.h"
#include "../FileDTO.h"

/**
 * 修改采购入库单（保存/审核/提交）
 */
class AddCgrkBillDTO : public FileDTO
{


	//必填
	//单据编号
	CC_SYNTHESIZE(string, billNo, BillNo);//自动生成
	//单据日期
	CC_SYNTHESIZE(string, billDate, BillDate);//读取系统时间

	//选填############
	//单据主题
	CC_SYNTHESIZE(string, subject, Subject);
	//业务部门
	CC_SYNTHESIZE(string, opDept, OpDept);
	//业务员
	CC_SYNTHESIZE(string, operator1, Operator1);
	//入库经办
	CC_SYNTHESIZE(string, handler, Handler);

	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//附件
	CC_SYNTHESIZE(string, attachment, Attachment);

	//不可填######################
	//单据阶段
	CC_SYNTHESIZE(string, billStage, BillStage);
	//已生效
	CC_SYNTHESIZE(int, isEffective, IsEffective);
	//已关闭
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	//已作废
	CC_SYNTHESIZE(int, isVoided, IsVoided);
	//生效时间
	CC_SYNTHESIZE(string, effectiveTime, EffectiveTime);
	//核批人 
	CC_SYNTHESIZE(string, approver, Approver);
	//审批实例
	CC_SYNTHESIZE(string, bpmiInstanceId, BpmiInstanceId);
	//制单人*******
	CC_SYNTHESIZE(string, createBy, CreateBy);
	//制单时间
	CC_SYNTHESIZE(string, createTime, CreateTime);
	//制单部门
	CC_SYNTHESIZE(string, sysOrgCode, SysOrgCode);
	//修改时间
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
	//修改人
	CC_SYNTHESIZE(string, updateBy, UpdateBy);
	//自动单据
	CC_SYNTHESIZE(int, isAuto, IsAuto);
	//红字单据
	CC_SYNTHESIZE(int, isRubric, IsRubric);
	//有应付
	CC_SYNTHESIZE(int, hasRp, HasRp);

	//单据明细
	CC_SYNTHESIZE(list<CgrkBillEntryDTO>, entry, Entry);

public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, AddCgrkBillDTO& t); // NOLINT

};

#endif // !_ADD_CGRK_BILL_DTO_
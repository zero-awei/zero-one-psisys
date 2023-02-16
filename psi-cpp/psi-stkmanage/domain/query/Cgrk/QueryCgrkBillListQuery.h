#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:36:29

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
#ifndef _QUERY_CGRK_BILL_LIST_QUERY_
#define _QUERY_CGRK_BILL_LIST_QUERY_

#include "../PageQuery.h"

class QueryCgrkBillListQuery : public PageQuery
{
	//单据编号
	CC_SYNTHESIZE(string, billNo, BillNo);
	//单据日期（开始）
	CC_SYNTHESIZE(string, billDateStart, BillDateStart);
	//单据日期（结束）
	CC_SYNTHESIZE(string, billDateEnd, BillDateEnd);
	//单据主题
	CC_SYNTHESIZE(string, sudject, Subject);
	//供应商
	CC_SYNTHESIZE(string, supplierId, SupplierId);
	//单据阶段
	CC_SYNTHESIZE(string, billStage, BillStage);
	//已生效
	CC_SYNTHESIZE(int, isEffective, IsEffective);
	//已作废
	CC_SYNTHESIZE(int, isVoided, IsVoided);
	//已关闭
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	////红字单据
	//CC_SYNTHESIZE(int, isRubric, IsRubric);
	////源单类型
	//CC_SYNTHESIZE(string, srcBillType, SrcBillType);
	////源单号
	//CC_SYNTHESIZE(string, srcNo, SrcNo);
	////备注
	//CC_SYNTHESIZE(string, remark, Remark);
	////制单时间
	//CC_SYNTHESIZE(string, createTime, CreateTime);
	////制单部门
	//CC_SYNTHESIZE(string, sysOrgCode, SysOrgCode);
	////制单人
	//CC_SYNTHESIZE(string, createBy, CreateBy);
	////修改时间
	//CC_SYNTHESIZE(string, updateTime, UpdateTime);
	////修改人
	//CC_SYNTHESIZE(string, updateBy, UpdateBy);
	////生效时间
	//CC_SYNTHESIZE(string, effectiveTime, EffectiveTime);
	////核批人
	//CC_SYNTHESIZE(string, approver, Approver);
	////核批结果类型
	//CC_SYNTHESIZE(string, approvalResultType, ApprovalResultType);
	////有来往
	//CC_SYNTHESIZE(int, hasRp, HasRp);

public:
	// 绑定from_json
	friend void from_json(const json& j, QueryCgrkBillListQuery& t) { // NOLINT
		BIND_FROM_TO_ULL(j, t, pageIndex);
		BIND_FROM_TO_ULL(j, t, pageSize);
		BIND_FROM_TO_NORMAL(j, t, billNo);
		BIND_FROM_TO_NORMAL(j, t, billDateStart);
		BIND_FROM_TO_NORMAL(j, t, billDateEnd);
		BIND_FROM_TO_NORMAL(j, t, sudject);
		BIND_FROM_TO_NORMAL(j, t, supplierId);
		BIND_FROM_TO_NORMAL(j, t, billStage);

		BIND_FROM_TO_I(j, t, isEffective);
		BIND_FROM_TO_I(j, t, isVoided);
		BIND_FROM_TO_I(j, t, isClosed);
		//BIND_FROM_TO_I(j, t, is_rubric);

		//BIND_FROM_TO_NORMAL(j, t, src_bill_type);
		//BIND_FROM_TO_NORMAL(j, t, src_no);
		//BIND_FROM_TO_NORMAL(j, t, remark);
		//BIND_FROM_TO_NORMAL(j, t, create_time);
		//BIND_FROM_TO_NORMAL(j, t, sys_org_code);
		//BIND_FROM_TO_NORMAL(j, t, create_by);
		//BIND_FROM_TO_NORMAL(j, t, update_time);
		//BIND_FROM_TO_NORMAL(j, t, update_by);
		//BIND_FROM_TO_NORMAL(j, t, effective_time);
		//BIND_FROM_TO_NORMAL(j, t, approver);
		//BIND_FROM_TO_NORMAL(j, t, approval_result_type);

		//BIND_FROM_TO_I(j, t, has_rp);
	}
};

#endif // !_CGRK_QUERY_
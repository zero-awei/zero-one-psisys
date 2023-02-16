#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Adam
 @Date: 2023年2月15日

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
#ifndef _MODIFY_PUR_REQ_DTO_
#define _MODIFY_PUR_REQ_DTO_

#include "../../GlobalInclude.h"
#include "../FileDTO.h"

//考虑到修改和添加采购订单的操作类似所以合并为一个DTO
//添加订单的DTO(不包括明细内容),同时由于有附件内容可能添加,所以继承FileDTO
class ModifyPurReqDTO :public FileDTO
{
	//单据编号
	CC_SYNTHESIZE(string, billNo, BillNo);
	//单据日期
	CC_SYNTHESIZE(string, billDate, BillDate);
	//源单类型
	CC_SYNTHESIZE(string, srcBillType, SrcBillType);
	//源单id
	CC_SYNTHESIZE(string, srcBillId, SrcBillId);
	//源单号
	CC_SYNTHESIZE(string, srcNo, SrcNo);
	//单据主题
	CC_SYNTHESIZE(string, subject, Subject);
	//采购类型
	CC_SYNTHESIZE(string, purType, PurType);
	//需求部门
	CC_SYNTHESIZE(string, requestDept, RequestDept);
	//需求人
	CC_SYNTHESIZE(string, requester, Requester);
	//需求时间
	CC_SYNTHESIZE(string, requestTime, RequestTime);
	//数量
	CC_SYNTHESIZE(double, qty, Qty);
	//参考金额
	CC_SYNTHESIZE(double, amt, Amt);
	//已订数量
	CC_SYNTHESIZE(double, orderedQty, OrderedQty);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//是否自动生成
	CC_SYNTHESIZE(int, isAuto, IsAuto);
	//单据阶段
	CC_SYNTHESIZE(string, billStage, BillStage);
	//是否生效
	CC_SYNTHESIZE(int, isEffective, IsEffective);
	//生效时间
	CC_SYNTHESIZE(string, effectiveTime, EffectiveTime);
	//是否已关闭
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	//是否作废
	CC_SYNTHESIZE(int, isVoided, IsVoided);
	//创建部门
	CC_SYNTHESIZE(string, sysOrdCode, SysOrdCode);
	//创建人
	CC_SYNTHESIZE(string, createBy, CreateBy);
	//创建时间
	CC_SYNTHESIZE(string, createTime, CreateTime);

public:
	//绑定JSON转换方法
	friend void from_json(const json& j, ModifyPurReqDTO& t);
};

#endif // !_MODIFY_PUR_REQ_DTO_
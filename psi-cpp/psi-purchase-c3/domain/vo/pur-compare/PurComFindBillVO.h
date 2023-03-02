#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: QZP
 @Date: 2023/2/15 17:55:48

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
#ifndef _PUR_COM_FIND_BILL_VO_
#define _PUR_COM_FIND_BILL_VO_

#include "../../GlobalInclude.h"

/**
 * 比价单列表显示对象
 */
class PurComFindBillVO
{
	// 编号(非数据库表中的id字段，只是前端的#)
	CC_SYNTHESIZE(string, id, Id);
	// 单据编号
	CC_SYNTHESIZE(string, billNo, BillNo);
	// 单据日期
	CC_SYNTHESIZE(string, billDate, BillDate);
	// 单据主题
	CC_SYNTHESIZE(string, subject, Subject);
	// 源单号
	CC_SYNTHESIZE(string, srcNo, SrcNo);
	// 付款方式
	CC_SYNTHESIZE(string, paymentMethod, PaymentMethod);
	// 交货日期
	CC_SYNTHESIZE(string, deliveryTime, DeliveryTime);
	// 单据阶段
	CC_SYNTHESIZE(string, billStage, BillStage);
	// 已生效
	CC_SYNTHESIZE(string, isEffective, IsEffective);
	// 已关闭
	CC_SYNTHESIZE(string, isClosed, IsClosed);
	// 已作废
	CC_SYNTHESIZE(string, isVoided, IsVoided);
	// 交货地点
	CC_SYNTHESIZE(string, deliveryPlace, DeliveryPlace);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
	// 自动单据
	CC_SYNTHESIZE(string, isAuto, IsAuto);
	// 红字单据
	CC_SYNTHESIZE(string, isRubric, IsRubric);
	// 生效时间
	CC_SYNTHESIZE(string, effectiveTime, EffectiveTime);
	// 核批人
	CC_SYNTHESIZE(string, approver, Approver);
	// 制单时间
	CC_SYNTHESIZE(string, createTime, CreateTime);
	// 制单人
	CC_SYNTHESIZE(string, createBy, CreateBy);
	// 制单部门
	CC_SYNTHESIZE(string, sysOrgCode, SysOrgCode);
	// 修改时间
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
	// 修改人
	CC_SYNTHESIZE(string, updateBy, UpdateBy);
public:
	// 绑定JSON转换方法
	BIND_TO_JSON(PurComFindBillVO, id, billNo, billDate, subject, srcNo, paymentMethod, deliveryTime, \
		billStage, isEffective, isClosed, isVoided, deliveryPlace, remark, isAuto, isRubric, \
		effectiveTime, approver, createTime, createBy, sysOrgCode, updateTime, updateBy);
	// 用于测试用
	/*PurComFindBillVO() {
		this->setId(100);
		this->setBillNo("CGBJ100QZP");
		this->setSubject("test function");
	}*/
};


#endif 


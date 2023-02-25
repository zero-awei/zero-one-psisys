/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingyu
 @Date: 2023/02/15 11:59:38

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
#include "stdafx.h"
#include "PurOrderEntryDTO.h"
void from_json(const json& j, PurOrderEntryDTO& t) { // NOLINT
	//ID
	BIND_FROM_TO_NORMAL(j, t, id);
	//主表
	BIND_FROM_TO_NORMAL(j, t, mid);
	//单据号
	BIND_FROM_TO_NORMAL(j, t, bill_no);
	//分录号
	BIND_FROM_TO_I(j, t, entry_no);
	//源单类型
	BIND_FROM_TO_NORMAL(j, t, src_bill_type);
	//srcBillId
	BIND_FROM_TO_NORMAL(j, t, src_bill_id);
	//源单分录id
	BIND_FROM_TO_NORMAL(j, t, src_entry_id);
	//源单分录号
	BIND_FROM_TO_NORMAL(j, t, src_no);
	//物料
	BIND_FROM_TO_NORMAL(j, t, material_id);
	//计量单位
	BIND_FROM_TO_NORMAL(j, t, unit_id);
	//数量
	BIND_FROM_TO_D(j, t, qty);
	//税率%
	BIND_FROM_TO_D(j, t, tax_rate);
	//含税单价
	BIND_FROM_TO_D(j, t, price);
	//折扣率%
	BIND_FROM_TO_D(j, t, discount_rate);
	//税额
	BIND_FROM_TO_D(j, t, tax);
	//含税金额
	BIND_FROM_TO_D(j, t, amt);
	//已入库数量
	BIND_FROM_TO_D(j, t, in_qty);
	//已入库成本
	BIND_FROM_TO_D(j, t, in_cost);
	//结算数量
	BIND_FROM_TO_D(j, t, settle_qty);
	//结算金额
	BIND_FROM_TO_D(j, t, settle_amt);
	//已开票数量
	BIND_FROM_TO_D(j, t, invoiced_qty);
	//已开票金额
	BIND_FROM_TO_D(j, t, invoiced_amt);
	//备注
	BIND_FROM_TO_NORMAL(j, t, remark);
	//自定义1
	BIND_FROM_TO_NORMAL(j, t, custom1);
	//自定义2
	BIND_FROM_TO_NORMAL(j, t, custom2);
	//版本
	BIND_FROM_TO_I(j, t, version);
}
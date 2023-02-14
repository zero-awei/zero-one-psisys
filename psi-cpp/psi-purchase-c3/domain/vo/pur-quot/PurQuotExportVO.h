#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: akun
 @Date: 2023/2/14 00:15:01

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
#ifndef _PUR_QUOT_EXPORT_VO_
#define _PUR_QUOT_EXPORT_VO_

#include "../../GlobalInclude.h"
	

class PurQuotExportVO {
	//是否临时供应商
	CC_SYNTHESIZE(int, is_temp_supplier, is_temp_supplier);
	//供应商名称
	CC_SYNTHESIZE(std::string, supplier_name, supplier_name);
	//供应商
	CC_SYNTHESIZE(string, supplier_id, supplier_id);
	//付款方式
	CC_SYNTHESIZE(string, payment_method, payment_method);
	//交货地点
	CC_SYNTHESIZE(string, delivery_place, delivery_place);
	//交货时间
	CC_SYNTHESIZE(string, delivery_time, delivery_time);
	//联系人
	CC_SYNTHESIZE(string, contact, contact);
	//联系电话
	CC_SYNTHESIZE(string, phone, phone);
	//传真
	CC_SYNTHESIZE(string, fax, fax);
	//电子邮件
	CC_SYNTHESIZE(string, email, email);
	//数量
	CC_SYNTHESIZE(double, qty, qty);
	//金额
	CC_SYNTHESIZE(double, amt, amt);
	//--------------------明细开始----------------------
	//物料
	CC_SYNTHESIZE(string, material_id, material_id);
	//计量单位
	CC_SYNTHESIZE(string, unit_id, unit_id);
	//数量
	CC_SYNTHESIZE(double, qty, qty);
	//税率%
	CC_SYNTHESIZE(double, tax_rate, tax_rate);
	//含税单价
	CC_SYNTHESIZE(double, price, price);
	//折扣率%
	CC_SYNTHESIZE(double, discount_rate, discount_rate);
	//含税金额
	CC_SYNTHESIZE(double, amt, amt);
	//自定义1
	CC_SYNTHESIZE(string, custom1, custom1);
	//源单分录号---src_no
	CC_SYNTHESIZE(int, src_no, src_no);
	//分录号2
	CC_SYNTHESIZE(int, entry_no, entry_no);
	//自定义2
	CC_SYNTHESIZE(string, custom2, custom2);
	//源单分录id
	CC_SYNTHESIZE(string, src_entry_id, src_entry_id);
	//源单类型
	CC_SYNTHESIZE(string, src_bill_type, src_bill_type);
	//备注
	CC_SYNTHESIZE(string, remark, remark);
	//单据编号
	CC_SYNTHESIZE(string, bill_no, bill_no);
	//源单id
	CC_SYNTHESIZE(int, src_bill_id, src_bill_id);
	//------------------明细结束-------------------------
	//是否生效
	CC_SYNTHESIZE(int, is_effective, is_effective);
	//附件
	CC_SYNTHESIZE(string, attachment, attachment);
	//源单id
	CC_SYNTHESIZE(string, src_bill_id, src_bill_id);
	//单据主题
	CC_SYNTHESIZE(string, subject, subject);
	//单据阶段
	CC_SYNTHESIZE(string, bill_stage, bill_stage);
	//源单号
	CC_SYNTHESIZE(string, src_no, src_no);
	//是否自动生成
	CC_SYNTHESIZE(int, is_auto, is_auto);
	//备注
	CC_SYNTHESIZE(string, remark, remark);
	//审批实例id
	CC_SYNTHESIZE(string, bpmi_instance_id, bpmi_instance_id);
	//已作废
	CC_SYNTHESIZE(int, is_closed, is_closed);
	//单据编号
	CC_SYNTHESIZE(string, bill_no, bill_no);
	//是否红字
	CC_SYNTHESIZE(int, is_rubric, is_rubric);
	//源单类型
	CC_SYNTHESIZE(string, src_bill_type, src_bill_type);
	//制单时间
	CC_SYNTHESIZE(string, create_time, create_time);
	//生效时间
	CC_SYNTHESIZE(string, effective_time, effective_time);
	//核批人
	CC_SYNTHESIZE(string, approver, approver);
	//修改人
	CC_SYNTHESIZE(string, update_by, update_by);
	//制单部门
	CC_SYNTHESIZE(string, sys_org_code, sys_org_code);
	//已关闭
	CC_SYNTHESIZE(int, is_closed, is_closed);
	//核批结果类型
	CC_SYNTHESIZE(string, approval_result_type, approval_result_type);
	//单据日期
	CC_SYNTHESIZE(string, bill_date, bill_date);
	//制单人
	CC_SYNTHESIZE(string, create_by, create_by);
	//核批意见
	CC_SYNTHESIZE(string, approval_remark, approval_remark);

public:
	BIND_TO_JSON(PurQuotExportVO, is_temp_supplier, supplier_name, supplier_id, payment_method, delivery_place,
		delivery_time, contact, phone, fax, email, qty, amt,
		//明细字段开始
		material_id, unit_id, qty, tax_rate, price, discount_rate, amt,
		custom1, src_no, entry_no, custom2, src_entry_id, src_bill_type, remark, bill_no, src_bill_id,
		//明细字段结束
		is_effective, attachment, src_bill_type, subject, bill_stage, src_no, is_auto, remark,
		bpmi_instance_id, is_closed, bill_no, is_rubric, src_bill_type, create_time, effective_time, approver, update_by,
		sys_org_code, is_closed, approval_result_type, bill_date, create_by, approval_remark);
};

#endif // !

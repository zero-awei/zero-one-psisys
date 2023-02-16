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
#ifndef _PUR_COM_EXPORT_VO_
#define _PUR_COM_EXPORT_VO_

#include "../../GlobalInclude.h"


class PurComExportVO {

	//付款方式
	CC_SYNTHESIZE(string, payment_method, Payment_method);
	////交货地点
	//CC_SYNTHESIZE(string, delivery_place, Delivery_place);
	////交货时间
	//CC_SYNTHESIZE(string, delivery_time, Delivery_time);
	////候选报价单ids
	//CC_SYNTHESIZE(string, candidate_quot_ids, Candidate_quot_ids);
	////-----------------明细字段开始----------------------------
	////供应商
	//CC_SYNTHESIZE(string, supplier_id, Supplier_id);
	////物料
	//CC_SYNTHESIZE(string, material_id, Material_id);
	////计量单位
	//CC_SYNTHESIZE(string, unit_id, Unit_id);
	////数量
	//CC_SYNTHESIZE(double, qty, Qty);
	////税率%
	//CC_SYNTHESIZE(double, tax_rate, Tax_rate);
	////含税单价
	//CC_SYNTHESIZE(double, price, Price);
	////折扣率%
	//CC_SYNTHESIZE(double, discount_rate, Discount_rate);
	////含税金额
	//CC_SYNTHESIZE(double, amt, Amt);
	////排名
	//CC_SYNTHESIZE(int, ranking, Ranking);
	////自定义1
	//CC_SYNTHESIZE(string, custom1, Custom1);
	////源单分录号
	//CC_SYNTHESIZE(string, src_no, Src_no);
	////分录号
	//CC_SYNTHESIZE(string, entry_no, Entry_no);
	////自定义2
	//CC_SYNTHESIZE(string, custom2, Custom2);
	////源单分录id
	//CC_SYNTHESIZE(string, src_entry_id, Src_entry_id);
	////源单类型
	//CC_SYNTHESIZE(string, src_bill_type, Src_bill_type);
	////备注
	//CC_SYNTHESIZE(string, remark, Remark);
	////单据编号
	//CC_SYNTHESIZE(string, bill_no, Bill_no);
	////源单id
	//CC_SYNTHESIZE(string, src_bill_id, Src_bill_id);
	////----------------------明细字段结束---------------------------------
	////是否生效
	//CC_SYNTHESIZE(int, is_effective, Is_effective);
	////附件
	//CC_SYNTHESIZE(string, attachment, Attachment);
	////源单id
	//CC_SYNTHESIZE(string, src_bill_id, Src_bill_id);
	////单据主题
	//CC_SYNTHESIZE(string, subject, Subject);
	////单据阶段
	//CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	////源单号
	//CC_SYNTHESIZE(string, src_no, Src_no);
	////是否自动生成
	//CC_SYNTHESIZE(int, is_auto, Is_auto);
	////备注
	//CC_SYNTHESIZE(string, remark, Remark);
	////审批实例id
	//CC_SYNTHESIZE(string, bpmi_instance_id, Bpmi_instance_id);
	////已作废
	//CC_SYNTHESIZE(int, is_voided, Ss_voided);
	////单据编号
	//CC_SYNTHESIZE(string, bill_no, Bill_no);
	////是否红字
	//CC_SYNTHESIZE(int, is_rubric, Is_rubric);
	////源单类型
	//CC_SYNTHESIZE(string, src_bill_type, Src_bill_type);
	////制单时间
	//CC_SYNTHESIZE(string, create_time, Create_time);
	////生效时间
	//CC_SYNTHESIZE(string, effective_time, Effective_time);
	////核批人
	//CC_SYNTHESIZE(string, approver, Approver);
	////修改人
	//CC_SYNTHESIZE(string, update_by, Update_by);
	////制单部门
	//CC_SYNTHESIZE(string, sys_org_code, Sys_org_code);
	////已关闭
	//CC_SYNTHESIZE(int, is_closed, Is_closed);
	////核批结果类型
	//CC_SYNTHESIZE(string, approval_result_type, Approval_result_type);
	////单据日期
	//CC_SYNTHESIZE(string, bill_date, Bill_date);
	////制单人
	//CC_SYNTHESIZE(string, create_by, Create_by);
	////核批意见
	//CC_SYNTHESIZE(string, approval_remark, Approval_remark);

public:
	BIND_TO_JSON(PurComExportVO, payment_method);
	//BIND_TO_JSON(PurComExportVO, payment_method, delivery_place, delivery_time, candidate_quot_ids, 
	//	//明细字段开始
	//	supplier_id,material_id, unit_id, qty, tax_rate, price, discount_rate, amt,
	//	ranking, custom1, src_no, entry_no, custom2, src_entry_id, src_bill_type,remark, bill_no, src_bill_id, 
	//	//明细字段结束
	//	is_effective, attachment, src_bill_id, subject, bill_stage, src_no,is_auto, remark, bpmi_instance_id, 
	//	is_voided, bill_no, is_rubric,src_bill_type, create_time, effective_time, approver, update_by, sys_org_code, 
	//	is_closed, approval_result_type, bill_date, create_by, approval_remark);
};
#endif // !


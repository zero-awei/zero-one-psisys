#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:34:14

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
#ifndef _CGRK_QUERY_VO_
#define _CGRK_QUERY_VO_

#include "../../GlobalInclude.h"

/**
 * 示例显示对象
 */
class CgrkQueryVO
{	
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//单据编号
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	//核批结果类型
	CC_SYNTHESIZE(string, approval_result_type, Approval_result_type);
	//修改人
	CC_SYNTHESIZE(string, update_by, Update_by);
	//已生效
	CC_SYNTHESIZE(int, is_effective, Is_effective); 
	//已作废
	CC_SYNTHESIZE(int, is_voided, Is_voided);
	//单据类型
	CC_SYNTHESIZE(int, bill_type, Bill_type);
	//核批人
	CC_SYNTHESIZE(string, approver, Approver);
	//单据日期
	CC_SYNTHESIZE(string, bill_date, Bill_date);
	//源单类型
	CC_SYNTHESIZE(string, src_bill_type, Src_bill_type);
	//核批意见
	CC_SYNTHESIZE(string, approval_remark, Approval_remark );
	//源单号
	CC_SYNTHESIZE(string, src_no, Src_no);
	//修改时间
	CC_SYNTHESIZE(string, update_time, Update_time);
	//是否自动生成
	CC_SYNTHESIZE(int, is_auto, Is_auto);
	//红字单据
	CC_SYNTHESIZE(int, is_rubric, Is_rubric);
	//制单部门
	CC_SYNTHESIZE(string, sys_org_code, Sys_org_code);
	//制单时间
	CC_SYNTHESIZE(string, create_time, Create_time);
	//制单人
	CC_SYNTHESIZE(string, create_by, Create_by);
	//源单id
	CC_SYNTHESIZE(string, src_bill_id, Src_bill_id);
	//生效时间
	CC_SYNTHESIZE(string, effective_time, Effective_time);
	//单据阶段
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	//版本
	CC_SYNTHESIZE(string, version, Version);
	//附件
	CC_SYNTHESIZE(string, attachment, Attachment);
	//单据主题
	CC_SYNTHESIZE(string, sudject, Subject);
	//ID
	CC_SYNTHESIZE(string, id, Id);
	//已关闭
	CC_SYNTHESIZE(int, is_closed, Is_closed);
	//审批实例id
	CC_SYNTHESIZE(string, bpmi_instance_id, Bpmi_instance_id);
	//出入库类型
	CC_SYNTHESIZE(string, stock_io_type, Stock_io_type);
	//有来往
	CC_SYNTHESIZE(int, has_rp, Has_rp);
	//是否有涨吨
	CC_SYNTHESIZE(int, has_swell, Has_swell);
	//供应商
	CC_SYNTHESIZE(string, supplier_id, Supplier_id); 
	//客户
	CC_SYNTHESIZE(string, customer_id, Customer_id);
	//发票类型
	CC_SYNTHESIZE(string,invoice_type, Invoice_type );
	//业务部门
	CC_SYNTHESIZE(string, op_dept, Op_dept);
	//业务员
	CC_SYNTHESIZE(string, operator1, Operator1);
	//出入库经办
	CC_SYNTHESIZE(string, handler, Handler);
	//成本
	CC_SYNTHESIZE(double, cost, Cost);
	//结算金额
	CC_SYNTHESIZE(double, settle_amt, Settle_amt);
	//已结算金额
	CC_SYNTHESIZE(double, settled_amt, Settled_amt);
	//已开票金额
	CC_SYNTHESIZE(double, invoiced_amt, Invoiced_amt );
	//是否退货退票
	CC_SYNTHESIZE(int, is_returned, Is_returned );

	CC_SYNTHESIZE(string, stockIoType_dictText, StockIoType_dictText);
	CC_SYNTHESIZE(string, hasRp_dictText, HasRp_dictText);
	CC_SYNTHESIZE(string, hasSwell_dictText, HasSwell_dictText);
	CC_SYNTHESIZE(string, invoiceType_dictTex, InvoiceType_dictTex);
	CC_SYNTHESIZE(string, opDept_dictText, OpDept_dictText);
	CC_SYNTHESIZE(string, operator_dictText, Operator_dictText);
	CC_SYNTHESIZE(string, handler_dictText, Handler_dictText);
	CC_SYNTHESIZE(string, updateBy_dictText, UpdateBy_dictText);
	CC_SYNTHESIZE(string, isEffective_dictText, IsEffective_dictText);
	CC_SYNTHESIZE(string, isVoided_dictText, IsVoided_dictText);
	CC_SYNTHESIZE(string, srcBillType_dictText, SrcBillType_dictText);
	CC_SYNTHESIZE(string, isAuto_dictText, IsAuto_dictText);
	CC_SYNTHESIZE(string, isRubric_dictText, IsRubric_dictText);
	CC_SYNTHESIZE(string, sysOrgCode_dictText, SysOrgCode_dictText);
	CC_SYNTHESIZE(string, createBy_dictText, CreateBy_dictText);
	CC_SYNTHESIZE(string, billStage_dictText, BillStage_dictText);
	CC_SYNTHESIZE(string, isClosed_dictText, IsClosed_dictText);

public:
	// 绑定JSON转换方法
	BIND_TO_JSON(CgrkQueryVO, remark, bill_no, approval_result_type, update_by, is_effective, is_voided, bill_type, approver, bill_date, src_bill_type, approval_remark, src_no, update_time, is_auto,
		is_rubric, sys_org_code, create_time, create_by, src_bill_id, effective_time, bill_stage, version, attachment, sudject, id, is_closed, bpmi_instance_id, stock_io_type, has_rp, has_swell, supplier_id, customer_id,
		invoice_type, op_dept, operator1, handler, cost, settle_amt, settled_amt, invoiced_amt, is_returned, stockIoType_dictText, hasRp_dictText, hasSwell_dictText, invoiceType_dictTex, opDept_dictText, operator_dictText,
		handler_dictText, updateBy_dictText, isEffective_dictText, isVoided_dictText, srcBillType_dictText, isAuto_dictText, isRubric_dictText, sysOrgCode_dictText, createBy_dictText, billStage_dictText, isClosed_dictText );
};

#endif // !_CGRK_QUERY_VO_

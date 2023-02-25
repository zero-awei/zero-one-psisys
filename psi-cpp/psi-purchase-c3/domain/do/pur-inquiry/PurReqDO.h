#pragma once
#include "stdafx.h"
#ifndef __PUR_REQ_DO_H__
#define __PUR_REQ_DO_H__

#include "../DoInclude.h"


/*
* 与数据库 pur_req 对应
*/

class PurReqDO
{
	// ID
	CC_SYNTHESIZE(string, id, Id);
	// 单据编号  
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	// 单据日期
	CC_SYNTHESIZE(string, bill_date, Bill_date);
	// 源单类型
	CC_SYNTHESIZE(string, src_bill_type, Src_bill_type);
	// 源单id
	CC_SYNTHESIZE(string, src_bill_id, Src_bill_id);
	// 源单号
	CC_SYNTHESIZE(string, src_no, Src_no);
	// 单据主题 
	CC_SYNTHESIZE(string, subject, Subject);
	// 是否红字
	CC_SYNTHESIZE(int, is_rubric, Is_rubric);
	// 采购类型
	CC_SYNTHESIZE(string, pur_type, Pur_type);
	// 需求部门
	CC_SYNTHESIZE(string, request_dept, Request_dept);
	// 需求人
	CC_SYNTHESIZE(string, requester, Requester);
	// 需求时间
	CC_SYNTHESIZE(string, request_time, Request_time);
	// 数量
	CC_SYNTHESIZE(double, qty, Qty);
	// 参考金额
	CC_SYNTHESIZE(double, amt, Amt);
	// 已订数量
	CC_SYNTHESIZE(double, ordered_qty, Ordered_qty);
	// 附件
	CC_SYNTHESIZE(string, attachment, Attachment);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
	// 是否自动生成
	CC_SYNTHESIZE(int, is_auto, Is_auto);
	// 单据阶段（公共接口）
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	// 核批人
	CC_SYNTHESIZE(string, approver, Approver);
	// 核批实例id
	CC_SYNTHESIZE(string, bpmi_instance_id, Bpmi_instance_id);
	// 核批结果类型
	CC_SYNTHESIZE(string, approval_result_type, Approval_result_type);
	// 核批意见
	CC_SYNTHESIZE(string, approval_remark, Approval_remark);
	// 是否生效
	CC_SYNTHESIZE(int, is_effective, Is_effective);
	// 生效时间
	CC_SYNTHESIZE(string, effective_time, Effective_time);
	// 是否关闭
	CC_SYNTHESIZE(int, is_closed, Is_closed);
	// 是否作废
	CC_SYNTHESIZE(int, is_voided, Is_voided);
	// 创建部门
	CC_SYNTHESIZE(string, sys_org_code, Sys_org_code);
	// 创建人
	CC_SYNTHESIZE(string, create_by, Create_by);
	// 创建时间
	CC_SYNTHESIZE(string, create_time, Create_time);
	// 修改人
	CC_SYNTHESIZE(string, update_by, Update_by);
	// 修改时间
	CC_SYNTHESIZE(string, update_time, Update_time);
	// 版本
	CC_SYNTHESIZE(int, version, Version);

public:
	PurReqDO()
	{



	}




};


#endif //__PUR_REQ_DO_H__
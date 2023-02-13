#pragma once
#ifndef _QUERYDOC_DO_
#define __QUERYDOC_DO_
#include "../DoInclude.h"

/**
 * 涨吨入库，查询单据详细数据库实体类
 */
class QueryDocDO
{
	//单据编号
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	//单据日期
	CC_SYNTHESIZE(string, bill_date, Bill_date);
	//单据阶段
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	//已生效
	CC_SYNTHESIZE(int, is_effective, Is_effective);
	//已关闭
	CC_SYNTHESIZE(int, is_closed, Is_closed);
	//已作废
	CC_SYNTHESIZE(int, is_voided, Is_voided);
	//生效时间
	CC_SYNTHESIZE(string, effective_time, Effective_time);
    //核批人 
	CC_SYNTHESIZE(string, approver, Approver);
	//审批实例***
	CC_SYNTHESIZE(string, bpmi_instance_id, Bpmi_instance_id);
	//制单人*******
	CC_SYNTHESIZE(string, create_by, Create_by);
	//制单时间
	CC_SYNTHESIZE(string, create_time, Create_time);
	//制单部门
	CC_SYNTHESIZE(string, sys_org_code, Sys_org_code);
	//修改时间
	CC_SYNTHESIZE(string, update_time, Update_time);
	//修改人
	CC_SYNTHESIZE(string, update_by, Update_by);
	//自动单据
	CC_SYNTHESIZE(int, is_auto, Is_auto);
	//红字单据
	CC_SYNTHESIZE(int, is_rubric, Is_rubric);
	//有应付
	CC_SYNTHESIZE(int,has_rp, Has_rp);
	//单据主题
	CC_SYNTHESIZE(string, subject, Subject);
	//业务部门
	CC_SYNTHESIZE(string, op_dept, op_dept);
	//业务员
	CC_SYNTHESIZE(string, operatoR, Operator);
	//入库经办
	CC_SYNTHESIZE(string, handler, Handler);
	//分录号
	CC_SYNTHESIZE(int, entry_no, Entry_no);
	//物料
	CC_SYNTHESIZE(string, material_id, Material_id);
	//规格型号
	CC_SYNTHESIZE(string, model, Model);
	//仓库
	CC_SYNTHESIZE(string,warehouse_id, Warehouse_id);
	//单位
	CC_SYNTHESIZE(string, unit_id, Unit_id);
	//涨吨数量
	CC_SYNTHESIZE(double, swell_qty, Swell_qty);
	//入库金额
	CC_SYNTHESIZE(double, in_cost, In_cost);
	//明细：备注
	CC_SYNTHESIZE(string, remarK, RemarK);
	//自定义1
	CC_SYNTHESIZE(string, custom1, Custom1);
	//自定义2
	CC_SYNTHESIZE(string, custom2, Custom2);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//核批意见
	CC_SYNTHESIZE(string, approval_remark, Approval_remark);
	//核批结果
	CC_SYNTHESIZE(string, approval_result_type, Approval_result_type);

	
	
	
public:
	QueryDocDO() {
		bill_no = "";
		bill_date = "";
		bill_stage = "";
		is_effective = -1;
		is_closed = -1;
		is_voided = -1;
		effective_time = "";
		approver = "";
		bpmi_instance_id = "";
		create_by = "";
		create_time = "";
		sys_org_code = "";
		update_time = "";
		update_by = "";
		is_auto = -1;
		is_rubric = -1;
		has_rp = -1;
		subject = "";
		op_dept = "";
		operatoR = "";
		handler = "";
		entry_no = 0;
		material_id = "";
		model = "";
		warehouse_id = "";
		unit_id = "";
		swell_qty = 0;
		in_cost = 0;
		remarK = "";
		approval_remark = "";
		custom1 = "";
		custom2 = "";
		remark = "";
		approval_remark = "";
		approval_result_type = "";
	}
};

#endif // __QUERYDOC_DO_
#pragma once
#pragma once
#ifndef _QUERYDOCLIST_DO_
#define _QUERYDOCLIST_DO_
#include "../DoInclude.h"

/**
 * 涨吨入库，查询单据详细数据库实体类
 */
class QueryDocListDO
{
	//单据编号
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	//单据日期
	CC_SYNTHESIZE(string, bill_date, Bill_date);
	//业务部门
	CC_SYNTHESIZE(string, op_dept, op_dept);
	//业务员
	CC_SYNTHESIZE(string, operatoR, Operator);
	//单据阶段
	CC_SYNTHESIZE(string, bill_stage, Bill_stage);
	//已生效
	CC_SYNTHESIZE(int, is_effective, Is_effective);
	//已关闭
	CC_SYNTHESIZE(int, is_closed, Is_closed);
	//已作废
	CC_SYNTHESIZE(int, is_voided, Is_voided);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//备注
	CC_SYNTHESIZE(int,is_auto, Is_auto);
	//生效时间
	CC_SYNTHESIZE(string, effective_time, Effective_time);
	//核批人 
	CC_SYNTHESIZE(string, approver, Approver);
	//制单人
	CC_SYNTHESIZE(string, create_by, Create_by);
	//制单时间
	CC_SYNTHESIZE(string, create_time, Create_time);
	//制单部门
	CC_SYNTHESIZE(string, sys_org_code, Sys_org_code);
	//修改时间
	CC_SYNTHESIZE(string, update_time, Update_time);
	//修改人
	CC_SYNTHESIZE(string, update_by, Update_by);

public:
	QueryDocListDO() {
		bill_no = "";
		bill_date = "";
		op_dept = "";
		operatoR = "";
		bill_stage = "";
		is_effective = -1;
		is_closed = 1;
		is_voided = -1;
		remark = "";
		is_auto = -1;
		effective_time = "";
		approver = "";
		create_by = "";
		create_time = "";
		sys_org_code = "";
		update_time = "";
		update_by = "";


	}
};

#endif // __QUERYDOC_DO_

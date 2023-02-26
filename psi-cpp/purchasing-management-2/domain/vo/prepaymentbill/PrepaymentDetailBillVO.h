#pragma once
#ifndef _PREPAYMENT_DETAIL_BILL_VO_
#define _PREPAYMENT_DETAIL_BILL_VO_

#include "../../GlobalInclude.h"
#include "PrepaymentBillVO.h"

/**
 * 示例显示对象
 * 采购预付申请-查询单据列表显示详细信息
 */

class PrepaymentDetailBillVO : public PrepaymentBillVO {
	//申请金额
	CC_SYNTHESIZE(int, amt, Amt);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//自定义1
	CC_SYNTHESIZE(string, custom1, Custom1);
	//自定义2
	CC_SYNTHESIZE(string, custom2, Custom2);

public:
	// 绑定JSON转换方法
	BIND_TO_JSON(PrepaymentDetailBillVO, bill_no, bill_date, subject, supplier_id, od_dept, op, amt, paid_amt, bill_stage, is_effective, is_closed,
		is_voided, remark, effective_time, approver, create_time, create_by, sys_org_code, update_time, update_by, custom1, custom2)

};
#endif // !_PREPAYMENT_DETAIL_BILL_VO_
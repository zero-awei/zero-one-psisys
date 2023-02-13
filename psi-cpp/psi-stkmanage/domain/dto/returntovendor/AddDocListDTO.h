#ifndef _ADD_DOC_LIST_DTO_
#define _ADD_DOC_LIST_DTO_

#include "../../GlobalInclude.h"
/**
* 采购退货出库(红入), 添加采购退货出库单数据传输对象
*/
class AddDocListDTO
{
	// 单据日期
	CC_SYNTHESIZE(std::string, bill_date, BillDate);
	// 单据主题
	CC_SYNTHESIZE(std::string, subject, Subject);
	// 源单业务人员
	CC_SYNTHESIZE(std::string, src_operator, SrcOperator);
	// 业务部门
	CC_SYNTHESIZE(std::string, op_dept, OpDept);
	// 供应商
	CC_SYNTHESIZE(std::string, supplier_id, SupplierId);
	// 采购入库单
	CC_SYNTHESIZE(std::string, src_no, SrcNo);
	// 出库经办
	CC_SYNTHESIZE(std::string, handler, Handler);
	// 结算数量
	CC_SYNTHESIZE(double, settle_qty, SettleQty);
	// 税额
	CC_SYNTHESIZE(double, tax, Tax);
	// 结算金额
	CC_SYNTHESIZE(double, settle_amt, SettleAmt);
	// 采购费用
	CC_SYNTHESIZE(double, cost, Cost);
	// 备注
	CC_SYNTHESIZE(std::string, remark, Remark);
	// 自定义1
	CC_SYNTHESIZE(std::string, custom1, Custom1);
	// 自定义2
	CC_SYNTHESIZE(std::string, custom2, Custom2);
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, AddDocListDTO& t); // NOLINT
};

#endif _ADD_DOC_LIST_DTO_ // !_ADD_DOC_LIST_DTO_

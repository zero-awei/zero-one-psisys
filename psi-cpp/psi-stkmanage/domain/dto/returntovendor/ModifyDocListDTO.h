#ifndef _MODIFY_DOC_LIST_DTO_
#define _MODIFY_DOC_LIST_DTO_

#include "../../GlobalInclude.h"
/**
* 采购退货出库(红入), 修改采购退货出库单数据传输对象
*/
class ModifyDocListDTO
{
	// 采购入库单编号
	CC_SYNTHESIZE(std::string, srcNo, SrcNo);
	// 单据日期
	CC_SYNTHESIZE(std::string, billDate, BillDate);
	// 单据主题
	CC_SYNTHESIZE(std::string, subject, Subject);
	// 出库经办
	CC_SYNTHESIZE(std::string, handler, Handler);
	// 结算数量
	CC_SYNTHESIZE(double, settleQty, SettleQty);
	// 税额
	CC_SYNTHESIZE(double, tax, Tax);
	// 结算金额
	CC_SYNTHESIZE(double, settleAmt, SettleAmt);
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
	friend void from_json(const json& j, ModifyDocListDTO& t); // NOLINT
};

#endif _MODIFY_DOC_LIST_DTO_ // !_MODIFY_DOC_LIST_DTO_

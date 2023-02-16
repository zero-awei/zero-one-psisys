#ifndef _PUR_Quot_FIND_BILL_VO_
#define _PUR_Quot_FIND_BILL_VO_

#include "../../GlobalInclude.h"

/**
 * 供应报价单查询显示对象
 */
class PurQuotFindBillVO
{
	// 序号
	CC_SYNTHESIZE(uint64_t, id, Id);
	// 单据编号
	CC_SYNTHESIZE(string, billNu, BillNu);
	// 单据日期
	CC_SYNTHESIZE(string, billDate, BillDate);
	// 单据主题
	CC_SYNTHESIZE(string, billTheme, BillTheme);
	// 源单号
	CC_SYNTHESIZE(string, srcNu, SrcNu);
	// 供应商
	CC_SYNTHESIZE(string, supplier, Supplier);
	// 临时供应商名称
	CC_SYNTHESIZE(string, tempSupplierName, TempSupplierName);
	// 交货日期
	CC_SYNTHESIZE(string, deliveryDate, DeliveryDate);
	// 数量
	CC_SYNTHESIZE(string, count, Count);
	// 金额
	CC_SYNTHESIZE(string, amount, Amount);
	// 单据阶段
	CC_SYNTHESIZE(string, billStage, BillStage);
	// 已生效
	CC_SYNTHESIZE(string, isWork, IsWork);
	// 已关闭
	CC_SYNTHESIZE(string, isClose, IsClose);
	// 已作废
	CC_SYNTHESIZE(string, isAbolish, IsAbolish);
	// 付款方式
	CC_SYNTHESIZE(string, paymentMethod, PaymentMethod);
	// 交货地点
	CC_SYNTHESIZE(string, deliveryPlace, DeliveryPlace);
	// 联系人
	CC_SYNTHESIZE(string, contact, Contact);
	// 联系电话
	CC_SYNTHESIZE(string, contactNum, ContactNum);
	// 传真
	CC_SYNTHESIZE(string, faxes, Faxes);
	// 电子邮件
	CC_SYNTHESIZE(string, email, Email);
	// 备注
	CC_SYNTHESIZE(string, comment, Comment);
	// 自动单据
	CC_SYNTHESIZE(string, autoBill, AutoBill);
	//红字单据
	CC_SYNTHESIZE(string, redBill, RedBill);
	//生效时间
	CC_SYNTHESIZE(string, tmTakingEffect, TmTakingEffect);
	//核批人
	CC_SYNTHESIZE(string, approvalOfficer, ApprovalOfficer);
	//制单时间
	CC_SYNTHESIZE(string, billingTime, BillingTime);
	//制单人
	CC_SYNTHESIZE(string, billMaker, BillMaker);
	//制单部门
	CC_SYNTHESIZE(string, billMakerDepart, BillMakerDepart);
	//修改时间
	CC_SYNTHESIZE(string, changeTime, ChangeTime);
	//修改人
	CC_SYNTHESIZE(string, changePerson, ChangePerson);
public:
	// 绑定JSON转换方法
	BIND_TO_JSON(PurQuotFindBillVO, id,billNu, billDate, billTheme, srcNu, supplier, tempSupplierName,\
		deliveryDate,count, amount, billStage, isWork, isClose, isAbolish, paymentMethod, \
		deliveryPlace, contact, contactNum, faxes, email, comment, autoBill, redBill, \
		tmTakingEffect, approvalOfficer, billingTime, billMaker, billMakerDepart, changeTime, changePerson);
	// 用于测试用
	PurQuotFindBillVO() {
		this->setId(100);
		this->setBillNu("CGBJ100QZP");
		this->setBillTheme("test func");
	}
};


#endif 

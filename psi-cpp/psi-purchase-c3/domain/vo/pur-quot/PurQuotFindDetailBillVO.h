#ifndef __PUR_QUOT_FIND_DETAIL_BILL_VO_
#define __PUR_QUOT_FIND_DETAIL_BILL_VO_

#include "../../GlobalInclude.h"

/**
 * 供应报价单查询显示对象
 */
class PurQuotFindDetailBillVO
{
	// 单据编号
	CC_SYNTHESIZE(string, billNu, BillNu);
	// 单据日期
	CC_SYNTHESIZE(string, billDate, BillDate);
	//编制完
	CC_SYNTHESIZE(string, isMakeDone, IsMakeDone);
	// 已生效
	CC_SYNTHESIZE(string, isWork, IsWork);
	// 已关闭
	CC_SYNTHESIZE(string, isClose, IsClose);
	// 已作废
	CC_SYNTHESIZE(string, isAbolish, IsAbolish);
	//生效时间
	CC_SYNTHESIZE(string, tmTakingEffect, TmTakingEffect);
	//核批人
	CC_SYNTHESIZE(string, approvalOfficer, ApprovalOfficer);
	//核批实例
	CC_SYNTHESIZE(string, approvalObject, ApprovalObject);
	//制单时间
	CC_SYNTHESIZE(string, billingTime, BillingTime);
	//制单部门
	CC_SYNTHESIZE(string, billMakerDepart, BillMakerDepart);
	//制单人
	CC_SYNTHESIZE(string, billMaker, BillMaker);
	//修改时间
	CC_SYNTHESIZE(string, changeTime, ChangeTime);
	//修改人
	CC_SYNTHESIZE(string, changePerson, ChangePerson);
	// 自动单据
	CC_SYNTHESIZE(string, autoBill, AutoBill);
	//红字单据
	CC_SYNTHESIZE(string, redBill, RedBill);
	//源单类型
	CC_SYNTHESIZE(string, srcBillType, SrcBillType);
	// 单据主题
	CC_SYNTHESIZE(string, billTheme, BillTheme);
	//采购询价单
	CC_SYNTHESIZE(string, purchaseInquirySheet, PurchaseInquirySheet);
	//临时供应商（是否）
	CC_SYNTHESIZE(string,isTemsupplier, IsTemsupplier);
	// 供应商
	CC_SYNTHESIZE(string, supplier, Supplier);
	// 临时供应商名称
	CC_SYNTHESIZE(string, tempSupplierName, TempSupplierName);
	// 付款方式
	CC_SYNTHESIZE(string, paymentMethod, PaymentMethod);
	// 交货日期
	CC_SYNTHESIZE(string, deliveryDate, DeliveryDate);
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
	//// 源单号
	//CC_SYNTHESIZE(string, srcNu, SrcNu);
	//// 数量
	//CC_SYNTHESIZE(string, count, Count);
	//// 金额
	//CC_SYNTHESIZE(string, amount, Amount);
	//// 单据阶段
	//CC_SYNTHESIZE(string, billStage, BillStage);
	//
	//// 备注
	//CC_SYNTHESIZE(string, comment, Comment);
	//
	
public:
	// 绑定JSON转换方法
	BIND_TO_JSON(PurQuotFindDetailBillVO, billNu, billDate, isMakeDone, isWork, isClose, isAbolish, tmTakingEffect, \
		approvalOfficer, approvalObject, billingTime, billMakerDepart, billMaker, changeTime, changePerson, autoBill, \
		redBill, srcBillType, billTheme, purchaseInquirySheet, isTemsupplier, supplier, tempSupplierName, paymentMethod, \
		deliveryDate, deliveryPlace, contact, contactNum, faxes, email);
	// 用于测试用
	PurQuotFindDetailBillVO() {
		this->setBillNu("CGBJ100QZP");
		this->setBillTheme("test func");
	}
};


#endif 

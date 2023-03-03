#ifndef ADD_CGTHCK_BILL_DTO_
#define ADD_CGTHCK_BILL_DTO_

#include "../FileDTO.h"
#include "../../GlobalInclude.h"
#include "./CgthckBillEntryDTO.h"
/**
* 采购退货出库(红入), 添加采购退货出库单数据传输对象
*/
class AddCgthckBillDTO : public FileDTO
{
	/***必填***/
	// 单据编号
	CC_SYNTHESIZE(std::string, billNo, BillNo);
	// 单据日期
	CC_SYNTHESIZE(std::string, billDate, BillDate);

	/***可填***/
	// 单据主题
	CC_SYNTHESIZE(std::string, subject, Subject);
	// 源单业务人员
	CC_SYNTHESIZE(std::string, srcOperator, SrcOperator);
	// 业务部门
	CC_SYNTHESIZE(std::string, opDept, OpDept);
	// 供应商
	CC_SYNTHESIZE(std::string, supplierId, SupplierId);
	// 采购入库单
	CC_SYNTHESIZE(std::string, srcNo, SrcNo);
	// 出库经办
	CC_SYNTHESIZE(std::string, handler, Handler);
	// 备注
	CC_SYNTHESIZE(std::string, remark, Remark);
	// 附件
	CC_SYNTHESIZE(std::string, attachment, Attachment);
	// 单据阶段
	CC_SYNTHESIZE(std::string, billStage, BillStage);

	/***不可填***/
	// 已生效
	CC_SYNTHESIZE(bool, isEff, IsEff);
	// 已关闭
	CC_SYNTHESIZE(bool, isClosed, IsClosed);
	// 已作废
	CC_SYNTHESIZE(bool, isVoided, IsVoided);
	// 生效时间
	CC_SYNTHESIZE(std::string, effTime, EffTime);
	// 核批人
	CC_SYNTHESIZE(std::string, approver, Approver);
	// 审批实例
	CC_SYNTHESIZE(std::string, bpmiInstanceId, BpmiInstanceId);
	// 制单时间
	CC_SYNTHESIZE(std::string, createTime, CreateTime);
	// 制单部门
	CC_SYNTHESIZE(std::string, sysOrgCode, SysOrgCode);
	// 制单人
	CC_SYNTHESIZE(std::string, createBy, CreateBy);
	// 修改时间
	CC_SYNTHESIZE(std::string, updateTime, UpdateTime);
	// 修改人
	CC_SYNTHESIZE(std::string, updateBy, UpdateBy);
	// 是否自动单据
	CC_SYNTHESIZE(bool, isAuto, IsAuto);
	// 是否红字
	CC_SYNTHESIZE(bool, isRubric, IsRubric);
	// 有应付
	CC_SYNTHESIZE(bool, hasRp, HasRp);
	// 有涨吨
	CC_SYNTHESIZE(bool, hasSwell, HasSwell);
	// 源单类型
	CC_SYNTHESIZE(std::string, srcBillType, SrcBillType);
	// 发票类型
	CC_SYNTHESIZE(std::string, invoiceType, InvoiceType);

	// 退货出库单明细列表
	CC_SYNTHESIZE(std::list<CgthckBillEntryDTO>, entry, Entry);
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, AddCgthckBillDTO& t) // NOLINT
	{
		BIND_FROM_TO_NORMAL(j, t, billNo);
		BIND_FROM_TO_NORMAL(j, t, billDate);
		BIND_FROM_TO_NORMAL(j, t, subject);
		BIND_FROM_TO_NORMAL(j, t, srcOperator);
		BIND_FROM_TO_NORMAL(j, t, opDept);
		BIND_FROM_TO_NORMAL(j, t, supplierId);
		BIND_FROM_TO_NORMAL(j, t, srcNo);
		BIND_FROM_TO_NORMAL(j, t, handler);
		BIND_FROM_TO_NORMAL(j, t, remark);
		BIND_FROM_TO_NORMAL(j, t, attachment);
		BIND_FROM_TO_NORMAL(j, t, billStage);
		BIND_FROM_TO_I(j, t, isEff);
		BIND_FROM_TO_I(j, t, isClosed);
		BIND_FROM_TO_I(j, t, isVoided);
		BIND_FROM_TO_NORMAL(j, t, effTime);
		BIND_FROM_TO_NORMAL(j, t, approver);
		BIND_FROM_TO_NORMAL(j, t, bpmiInstanceId);
		BIND_FROM_TO_NORMAL(j, t, createTime);
		BIND_FROM_TO_NORMAL(j, t, sysOrgCode);
		BIND_FROM_TO_NORMAL(j, t, createBy);
		BIND_FROM_TO_NORMAL(j, t, updateTime);
		BIND_FROM_TO_NORMAL(j, t, updateBy);
		BIND_FROM_TO_I(j, t, isAuto);
		BIND_FROM_TO_I(j, t, isRubric);
		BIND_FROM_TO_I(j, t, hasRp);
		BIND_FROM_TO_I(j, t, hasSwell);
		BIND_FROM_TO_NORMAL(j, t, srcBillType);
		BIND_FROM_TO_NORMAL(j, t, invoiceType);
		BIND_FROM_TO_OBJ(j, t, entry, std::list<CgthckBillEntryDTO>);
		BIND_FROM_TO_OBJ(j, t, files, std::list<std::string>);
	}
};

#endif // !ADD_CGTHCK_BILL_DTO_

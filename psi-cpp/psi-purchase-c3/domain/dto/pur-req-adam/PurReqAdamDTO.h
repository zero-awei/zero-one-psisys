#pragma once
#ifndef _PUR_REQ_ADAM_DTO_
#define _PUR_REQ_ADAM_DTO_

#include "../../GlobalInclude.h"
#include "../FileDTO.h"

//考虑到修改和添加采购订单的操作类似所以合并为一个DTO
//添加订单的DTO(不包括明细内容),同时由于有附件内容可能添加,所以继承FileDTO
class AddAndModifyPurReqDTO:FileDTO
{
	// 单据id
	CC_SYNTHESIZE(string, id, Id);
	//单据编号
	CC_SYNTHESIZE(string, billNo, BillNo);
	//单据日期
	CC_SYNTHESIZE(string, billDate, BillDate);
	//源单类型
	CC_SYNTHESIZE(string, srcBillType, SrcBillType);
	//源单id
	CC_SYNTHESIZE(string, srcBillId, SrcBillId);
	//源单号
	CC_SYNTHESIZE(string, srcNo, SrcNo);
	//单据主题
	CC_SYNTHESIZE(string, subject, Subject);
	//采购类型
	CC_SYNTHESIZE(string, purType, PurType);
	//需求部门
	CC_SYNTHESIZE(string, requester, Requester);
	//需求时间
	CC_SYNTHESIZE(string, requestTime, RequestTime);
	//数量
	CC_SYNTHESIZE(double, qty, Qty);
	//参考金额
	CC_SYNTHESIZE(double, amt, Amt);
	//已订数量
	CC_SYNTHESIZE(double, orderedQty, OrderedQty);
	//附件
	CC_SYNTHESIZE(string, attachment, Attachment);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//是否自动生成
	CC_SYNTHESIZE(int, isAuto, IsAuto);
	//单据阶段
	CC_SYNTHESIZE(string, billStage, BillStage);
	//审核人
	CC_SYNTHESIZE(string, approver, Approver);
	//审批实例id
	CC_SYNTHESIZE(string, bpmiInstanceId, BpmiInstanceId);
	//核批结果类型
	CC_SYNTHESIZE(int, approvalResultType, ApprovalResultType);
	//核批意见
	CC_SYNTHESIZE(string, approvalRemark, ApprovalRemark);
	//是否生效
	CC_SYNTHESIZE(int, isEffective, IsEffective);
	//生效时间
	CC_SYNTHESIZE(string, effectiveTime, EffectiveTime);
	//是否已关闭
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	//是否作废
	CC_SYNTHESIZE(int, isVoided, IsVoided);
	//创建部门
	CC_SYNTHESIZE(string, sysOrdCode, SysOrdCode);
	//创建人
	CC_SYNTHESIZE(string, createBy, CreateBy);
	//创建时间
	CC_SYNTHESIZE(string, createTime, CreateTime);
	//修改人
	CC_SYNTHESIZE(string, updateBy, UpdateBy);
	//修改时间
	CC_SYNTHESIZE(string, updateTime, updateTime);
	//版本
	CC_SYNTHESIZE(int, version, Version);
public:
	//绑定JSON转换方法
	friend void from_json(const json& j, AddAndModifyPurReqDTO& t);
};

//删除订单的DTO 前端只需要传递一个单据编号给我即可进行修改
class DeletePurDTO {
	//单据编号
	CC_SYNTHESIZE(string, billNo, BillNo);
public:
	//绑定JSON转换方法
	friend void from_json(const json& j, DeletePurDTO& t);
};
//修改订单状态的DTO 前端需要传递一个单据编号以及状态修改信息
class PurReqModBillStatusDTO {
	//单据编号
	CC_SYNTHESIZE(string, billNo, BillNo);
	//是否生效
	CC_SYNTHESIZE(int, isEffective, IsEffective);
	//生效时间
	CC_SYNTHESIZE(string, effectiveTime, EffectiveTime);
	//是否已关闭
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	//是否作废
	CC_SYNTHESIZE(int, isVoided, IsVoided);
public:
	//绑定JSON转换方法
	friend void from_json(const json& j, PurReqModBillStatusDTO& t);
};
#endif // !_PUR_REQ_ADAM_DTO_
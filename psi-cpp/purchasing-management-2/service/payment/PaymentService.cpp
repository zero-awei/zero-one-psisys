#include "stdafx.h"
#include "../../dao/payment/PaymentDAO.h"
#include "../../lib-common/include/SimpleDateTimeFormat.h"
#include "PaymentService.h"

// 删除采购订单
bool PaymentService::DePayment(const DePaymentDTO& dto)
{
	//组装数据
	PaymentDAO dao;
	FinPayReqDO data;
	data.setId(dto.getId());
	data.setBill_no(dto.getBill_no());
	// 执行操作
	if (dto.getId() != "" || dto.getBill_no() != "")
	{
		data.setId(dto.getId());
		return dao.deleteById(data) == 1;
	}
	return false;
}

// 修改采购订单状态
bool PaymentService::ChangePayStatus(const PaymentChangeDTO& dto, const PayloadDTO& payload)
{
	FinPayReqDO data;

	string time = SimpleDateTimeFormat::format();

	// 组装用户数据
	data.setUpdate_by(payload.getUsername());
	data.setCreate_by(payload.getUsername());
	data.setUpdate_time(time);
	data.setId(dto.getId());
	data.setBill_no(dto.getBill_no());

	PaymentDAO dao;
	if (dto.getOpType() == dto.CLOSE || dto.getOpType() == dto.UNCLOSE)
	{
		data.setIs_closed(dto.OPS[dto.getOpType()]);
		return dao.ChangeStatusClose(data) == 1;
	}
	else if (dto.getOpType() == dto.CANCEL)
	{
		data.setIs_voided(dto.OPS[dto.getOpType()]);
		return dao.ChangeStatusCancel(data) == 1;
	}
	return false;
}



// 定义名字
#define MODIFY(name) data.set##name(dto.get##name());
//
#define MODIFY_DEFAULT(name) if (dto.get##name() != data.get##name()) {data.set##name(dto.get##name());}
//  添加采购付款申请订单
uint64_t PaymentService::saveData(const AddPaymentDTO& dto, const PayloadDTO& payload)
{
	// 组装数据
	FinPayReqDO data;
	SnowFlake sf(1, 4);
	string id = to_string(sf.nextId());
	string Bill_no = dto.getBill_no();
	string time = SimpleDateTimeFormat::format();
	// 获取id
	data.setId(id);
	//获取用户默认值
	data.setBill_no(Bill_no);
	MODIFY(Bill_date);
	MODIFY(Operator);
	MODIFY(Op_dept);
	MODIFY(Supplier_id);
	// 获取用户信息
	data.setOp_dept(payload.getOrgCode());
	data.setOperator(payload.getUsername());
	data.setCreate_time(time);
	data.setUpdate_by(payload.getUsername());
	data.setCreate_by(payload.getUsername());
	data.setUpdate_time(time);
	// 获取默认值
	MODIFY_DEFAULT(Src_bill_type);
	MODIFY_DEFAULT(Src_bill_id);
	MODIFY_DEFAULT(Src_no);
	MODIFY_DEFAULT(Subject);
	MODIFY_DEFAULT(Payment_type);
	MODIFY_DEFAULT(Amt);
	MODIFY_DEFAULT(Remark);
	// 连接DAO层
	PaymentDAO dao;
	return dao.insertPayment(data);
}
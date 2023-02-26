#include "stdafx.h"
#include "PaymentService.h"
#include "../../dao/Payment/PaymentDAO.h"

// 通过ID删除数据
bool PaymentService::DePayment(const DePaymentDTO& dto)
{
	//组装传输数据
	PaymentDAO dao;
	FinPayReqDO data;
	data.setId(dto.getId());
	data.setBill_no(dto.getBill_no());
	//执行数据修改
	if (dto.getId() != "" || dto.getBill_no() != "")
	{
		data.setId(dto.getId());
		return dao.deleteById(data) == 1;
	}
}

// 修改单据状态
bool PaymentService::ChangePayStatus(const PaymentChangeDTO& dto)
{
	//组装传输数据
	FinPayReqDO data;
	data.setId(dto.getId());
	data.setBill_no(dto.getBill_no());
	//执行数据修改
	PaymentDAO dao;
	if (dto.getOpType() == PaymentChangeDTO::CLOSE || dto.getOpType() == PaymentChangeDTO::UNCLOSE)
	{
		data.setIs_closed(dto.getIs_closed());
		return dao.ChangeStatusClose(data) == 1;
	}
	else if (dto.getOpType() == PaymentChangeDTO::CANCEL)
	{
		data.setIs_voided(dto.getIs_voided());
		return dao.ChangeStatusCancel(data) == 1;
	}
}


string getTime()
{
	time_t now = time(0);
	struct tm t;

	localtime_s(&t, &now);

	// 将信息输出到字符串流
	stringstream ss;
	ss << t.tm_year + 1900 << "-" << t.tm_mon + 1 << "-" << t.tm_mday << " " << t.tm_hour << ":" << t.tm_min << ":" << t.tm_sec;
	return ss.str();
}

//定义一个宏用来进行值的修改
#define MODIFY(name) data.set##name(dto.get##name());
//定义一个宏用来进行默认值的修改
#define MODIFY_DEFAULT(name) if (dto.get##name() != data.get##name()) {data.set##name(dto.get##name());}
// 保存数据
uint64_t PaymentService::saveData(const AddPaymentDTO& dto, const PayloadDTO& payload)
{
	//首先将订单本体添加进数据库
	//组装传输数据
	FinPayReqDO data;
	SnowFlake sf(1, 4);
	string id = to_string(sf.nextId());
	string Bill_no = dto.getBill_no();
	string time = getTime();
	//首先是进行id设置使用雪花算法
	data.setId(id);
	//获取必填信息
	data.setBill_no(Bill_no);
	MODIFY(Bill_date);
	MODIFY(Operator);
	MODIFY(Op_dept);
	MODIFY(Supplier_id);
	//获取用户的信息，此处为添加订单人信息
	data.setOp_dept(payload.getDepartment());
	data.setOperator(payload.getUsername());
	data.setCreate_time(time);
	data.setUpdate_by(payload.getUsername());
	data.setUpdate_time(time);
	//存在默认值时的处理
	MODIFY_DEFAULT(Src_bill_type);
	MODIFY_DEFAULT(Src_bill_id);
	MODIFY_DEFAULT(Src_no);
	MODIFY_DEFAULT(Subject);
	MODIFY_DEFAULT(Payment_type);
	MODIFY_DEFAULT(Amt);
	MODIFY_DEFAULT(Remark);
	//执行数据修改
	PaymentDAO dao;
	//然后将订单明细添加进数据库
	return dao.insertPayment(data);
}
#include "stdafx.h"
#include "PrePayService.h"
#include "../../dao/prepayment/PrepaymentDAO.h"
#include "../lib-common/include/SimpleDateTimeFormat.h"

// 修改单据状态(关闭/反关闭/作废)
// 负责人：Andrew
bool PrePayService::updateStatus(const PayModBillStatusDTO& dto, const PayloadDTO& payload)
{
	//组装传输数据
	PrepaymentDO data;
	data.setId(dto.getId());
	data.setBill_no(dto.getBill_no());
	data.setUpdate_by(payload.getUsername());
	data.setUpdate_time(SimpleDateTimeFormat::format());

	//执行数据修改
	PrepaymentDAO dao;
	if (dto.getOpType() == PayModBillStatusDTO::CLOSE || dto.getOpType() == PayModBillStatusDTO::UNCLOSE)
	{
		data.setIs_closed(dto.OPS[dto.getOpType()]);
		return dao.updateStatusClose(data) == 1;
	}
	else if (dto.getOpType() == PayModBillStatusDTO::CANCEL)
	{
		data.setIs_voided(dto.OPS[dto.getOpType()]);
		return dao.updateStatusCancel(data) == 1;
	}
}
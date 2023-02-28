/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingyu
 @Date: 2023/02/17 11:13:11

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "PurOrderService.h"
#include "../../dao/PurOrder/PurOrderDAO.h"
#include "../lib-common//include/SimpleDateTimeFormat.h"
#include "../lib-common//include/CharsetConvertHepler.h"

#define ASSIGN(key) data.set##key(dto.get##key());

// 修改数据
bool PurOrderService::updateData(const PurOrderDTO& dto)
{
	return true;
}

// 修改单据状态(关闭/反关闭/作废)
// 负责人：Andrew
bool PurOrderService::updateStatus(const PurOrderDTO& dto, const PayloadDTO& payload)
{
	PurOrderDO data;

	// 设置字段值
	data.setUpdate_by(payload.getUsername());
	data.setUpdate_time(SimpleDateTimeFormat::format());
	ASSIGN(Id);
	ASSIGN(Bill_no);

	PurOrderDAO dao;
	if (dto.getOpType() == dto.CLOSE || dto.getOpType() == dto.UNCLOSE)
	{
		data.setIs_closed(dto.OPS[dto.getOpType()]);
		return dao.updateStatusClose(data) == 1;
	}
	else if (dto.getOpType() == dto.CANCEL)
	{
		data.setIs_voided(dto.OPS[dto.getOpType()]);
		return dao.updateStatusCancel(data) == 1;
	}
}

// 删除采购订单-通过ID
// 负责人：Andrew
bool PurOrderService::removeData(string id)
{
	PurOrderDAO dao;
	return dao.deleteById(id) == 1;
}

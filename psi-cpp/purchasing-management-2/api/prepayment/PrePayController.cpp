#include "stdafx.h"
#include "PrePayController.h"
#include "../../domain/query/prepaymentbill/PrepayExportQuery.h"
#include "../../service/prepayment/PrePayService.h"
#include "../lib-common/include/CharsetConvertHepler.h"

// 修改单据状态
// 负责人：Andrew
JsonVO<string> PrePayController::execModifyPayBillStatus(const PayModBillStatusDTO& dto, const PayloadDTO& payload)
{
	PrePayService service;
	JsonVO<string> result;

	// 数据校验
	if (dto.getId() == "" || dto.getBill_no() == "") // 如果ID和单据编号为空
		return JsonVO<string>({}, RS_PARAMS_INVALID);
	// 如果必填项为空或者不是枚举类中元素则参数错误
	if (dto.getOpType() != dto.CLOSE && dto.getOpType() != dto.CANCEL && dto.getOpType() != dto.UNCLOSE)
		return JsonVO<string>({}, RS_PARAMS_INVALID);

	// 执行
	if (service.updateStatus(dto, payload)) {
		result.success(dto.getId());
		switch (dto.getOpType())
		{
		case dto.CLOSE:
			result.setMessage(CharsetConvertHepler::ansiToUtf8("关闭成功"));
			break;
		case dto.UNCLOSE:
			result.setMessage(CharsetConvertHepler::ansiToUtf8("反关闭成功"));
			break;
		case dto.CANCEL:
			result.setMessage(CharsetConvertHepler::ansiToUtf8("作废成功"));
			break;
		}
	}
	else {
		result.fail(dto.getId());
		switch (dto.getOpType())
		{
		case dto.CLOSE:
			result.setMessage(CharsetConvertHepler::ansiToUtf8("关闭失败"));
			break;
		case dto.UNCLOSE:
			result.setMessage(CharsetConvertHepler::ansiToUtf8("反关闭失败"));
			break;
		case dto.CANCEL:
			result.setMessage(CharsetConvertHepler::ansiToUtf8("作废失败"));
			break;
		}
	}
	return result;
}

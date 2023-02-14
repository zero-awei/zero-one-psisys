#pragma once

#ifndef _PURREQ_CONTROLLER_
#define _PURREQ_CONTROLLER_

#include "../../domain/dto/req-eleanor/PurReqExportDTO.h"
#include "../../domain/dto/req-eleanor/PurReqIntoDTO.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/vo/req-eleanor/PurReqIntoVO.h"

/**
 * 提供接口：导出申请单、导入申请单
 */


class PurReqController
{
public:
	//接口1 导出申请单
	CREATE_API_FUN_BODY_PAYLOAD(exportPurReqInfo, execPurReqExportInfo, PurReqExportDTO);

	//接口2 导入申请单
	CREATE_API_FUN_BODY_FILE(inportPurReqInfo, execPurReqIntoInfo, PurReqIntoDTO);
	
	
private:
	//执行方法：导出
	nlohmann::json execPurReqExportInfo(const PurReqExportDTO &dto, const PayloadDTO &payload);

	//执行方法：导入
	JsonVO<PurReqIntoVO> execPurReqIntoInfo(const PurReqIntoDTO& dto);
};

#endif // _PURREQ__CONTROLLER_
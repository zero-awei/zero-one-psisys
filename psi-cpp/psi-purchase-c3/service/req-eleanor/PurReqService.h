#pragma once

#ifndef _PURREQ_SERVICE_
#define _PURREQ_SERVICE_
#include <list>
#include "../../domain/vo/PageVO.h"
#include "../../domain/dto/req-eleanor/PurReqIntoDTO.h"

/**
 * 示例服务实现
 */
class PurReqService
{
public:
	// 导出数据
	std::string purReqExportData(PurReqExportDTO dto);
	// 保存数据
	uint64_t saveData(const PurReqIntoDTO& dto);
};

#endif // !_PURREQ_SERVICE_
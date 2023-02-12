#pragma once

#ifndef _INQUIRYELEANOR_SERVICE_
#define _INQUIRYELEANOR_SERVICE_
#include <list>
#include "../../domain/vo/inquiry-eleanor/InquiryEleanorVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/query/inquiry-eleanor/InquiryEleanorQuery.h"
#include "../../domain/dto/inquiry-eleanor/InquiryEleanorDTO.h"

/**
 * 示例服务实现
 */
class InquiryEleanorService
{
public:
	// 分页查询所有数据
	PageVO<InquiryEleanorVO> listAll(const InquiryEleanorQuery& query);
	// 保存数据
	uint64_t saveData(const InquiryEleanorDTO& dto);
};

#endif // !_INQUIRYELEANOR_SERVICE_
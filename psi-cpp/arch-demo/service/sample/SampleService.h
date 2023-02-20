#pragma once

#ifndef _SAMPLE_SERVICE_
#define _SAMPLE_SERVICE_
#include <list>
#include "../../domain/vo/sample/SampleVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/query/sample/SampleQuery.h"
#include "../../domain/dto/sample/SampleDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class SampleService
{
public:
	// 分页查询所有数据
	PageVO<SampleVO> listAll(const SampleQuery& query);
	// 保存数据
	uint64_t saveData(const SampleDTO& dto);
	// 修改数据
	bool updateData(const SampleDTO& dto);
	// 通过ID删除数据
	bool removeData(uint64_t id);
};

#endif // !_SAMPLE_SERVICE_


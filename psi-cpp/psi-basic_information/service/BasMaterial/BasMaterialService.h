#ifndef _BASMATERIAL_SERVICE_
#define _BASMATERIAL_SERVICE_
#include <list>
#include "../../domain/vo/BasMaterial/BasMaterialVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/query/BasMaterial/BasMaterialQuery.h"
#include "../../domain/query/BasMaterial/BasMaterialDetailQuery.h"
#include "../../domain/dto/BasMaterial/BasMaterialDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class BasMaterialService
{
public:
	// 分页查询所有数据
	PageVO<BasMaterialVO> listAll(const BasMaterialQuery& query);
	//id查询
	BasMaterialVO getData(const BasMaterialDetailQuery& query);

	// 保存数据
	uint64_t saveData(const BasMaterialDTO& dto, const PayloadDTO& payload);
	// 修改数据
	bool updateData(const BasMaterialDTO& dto, const PayloadDTO& payload);
	// 通过code编码删除数据
	bool removeData(uint64_t id);
	//导出
	bool getExceData(const BasMaterialQuery& query, vector<vector<string>>& data);
	//导入
	uint64_t saveExceData(const FileDTO& dto, const PayloadDTO& payload);
};

#endif // !_BASMATERIAL_SERVICE_


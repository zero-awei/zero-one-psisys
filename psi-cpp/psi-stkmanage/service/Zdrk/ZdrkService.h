#pragma once

#ifndef _ZDRK_SERVICE_
#define _ZDRK_SERVICE_
#include <list>
#include "../../domain/dto/IDDTO.h"
#include "../psi-stkmanage/domain/vo/PageVO.h"
#include "../psi-stkmanage/domain/vo/Zdrk/QueryZdrkBillListVO.h"
#include "../psi-stkmanage/domain/query/Zdrk/QueryZdrkBillListQuery.h"
#include "../psi-stkmanage/domain/dto/Zdrk/AddZdrkBillDTO.h"
#include "../psi-stkmanage/domain/dto/Zdrk/ModifyZdrkBillDTO.h"
#include "../psi-stkmanage/domain/dto/Zdrk/ModifyZdrkBillStateDTO.h"
class PyrkService {
public:
	// 新增单据数据
	int saveBillData(const AddZdrkBillDTO& dto, const PayloadDTO& payload);
	// 修改单据
	int updateBillData(const ModifyZdrkBillDTO& dto, const PayloadDTO& payload);
	// 删除单据
	int removeBillById(const StringID& billNo);
	//修改单据状态
	int updateBillState(const ModifyZdrkBillStateDTO& dto, const PayloadDTO& payload);
	//导入

	//导出

};






#endif // !_ZDRK_SERVICE_
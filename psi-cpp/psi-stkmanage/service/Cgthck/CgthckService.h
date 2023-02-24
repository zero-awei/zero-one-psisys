#pragma once
#ifndef _CGTHCK_SERVICE_
#define _CGTHCK_SERVICE_

#include "../../domain/vo/PageVO.h"
#include "../../dao/Cgthck/CgthckDAO.h"
#include "../../domain/do/Cgthck/CgthckDO.h"
#include "../../domain/vo/Cgthck/QueryCgthckBillVO.h"
#include "../../domain/query/Cgthck/QueryCgthckBillQuery.h"
#include "../../domain/dto/Cgthck/AddCgthckBillDTO.h"
#include "../../domain/dto/Cgthck/DeleteCgthckBillDTO.h"
#include "../../domain/dto/Cgthck/ExportCgthckFileDTO.h"
#include "../../domain/dto/Cgthck/ImportCgthckFileDTO.h"
#include "../../domain/dto/Cgthck/ModifyCgthckBillDTO.h"

class CgthckService
{
public:
	// 分页查询数据
	PageVO<QueryCgthckBillVO> listAll(const QueryCgthckBillQuery& query);
	// 添加采购退货出库单(保存/提交)
	uint64_t saveData(const AddCgthckBillDTO& dto);
	// 修改采购退货出库单（保存/提交/审核）
	int updateData(const AddCgthckBillDTO& dto);
	// 审核单据
	bool updateApproval(const ModifyCgthckBillDTO& dto);
	// 删除采购退货出库单
	bool removeData(uint64_t id);
	// 修改单据状态（关闭/作废/反关闭）
	bool closed(const ModifyCgthckBillDTO& dto);
	bool unclosed(const ModifyCgthckBillDTO& dto);
	bool voided(const ModifyCgthckBillDTO& dto);
	// 导入
	// 导出
};


#endif // !_CGTHCK_SERVICE_



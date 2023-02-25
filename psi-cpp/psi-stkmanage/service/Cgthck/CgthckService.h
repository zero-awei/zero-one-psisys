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
	int updateApproval(const ModifyCgthckBillDTO& dto, const PayloadDTO& payload);
	// 删除采购退货出库单
	int removeData(const DeleteCgthckBillDTO& dto);
	// 删除采购退货单明细
	int removeEntry(const DeleteCgthckBillDTO& dto);
	// 修改单据状态（关闭/作废/反关闭）
	// 关闭
	int closed(const ModifyCgthckBillDTO& dto, const PayloadDTO& payload);
	// 反关闭
	int unclosed(const ModifyCgthckBillDTO& dto, const PayloadDTO& payload);
	// 作废
	int voided(const ModifyCgthckBillDTO& dto, const PayloadDTO& payload);
	// 导入
	// 导出
};


#endif // !_CGTHCK_SERVICE_



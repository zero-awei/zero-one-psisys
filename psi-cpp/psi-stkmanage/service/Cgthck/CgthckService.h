#pragma once
#ifndef _CGTHCK_SERVICE_
#define _CGTHCK_SERVICE_
////
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/Cgthck/ExportCgthckVO.h"
#include "../../domain/vo/Cgthck/QueryCgrkBillListsVO.h"
#include "../../domain/vo/Cgthck/QueryCgthckBillVO.h"
#include "../../domain/query/Cgthck/QueryCgrkBillQuery.h"
#include "../../domain/query/Cgthck/QueryCgthckBillQuery.h"
#include "../../domain/dto/Cgthck/AddCgthckBillDTO.h"
#include "../../domain/dto/Cgthck/DeleteCgthckBillDTO.h"
#include "../../domain/dto/Cgthck/ExportCgthckFileDTO.h"
#include "../../domain/dto/Cgthck/ImportCgthckFileDTO.h"
#include "../../domain/dto/Cgthck/ModifyCgthckBillDTO.h"
#include <list>
#include "../psi-stkmanage/domain/vo/PageVO.h"
#include "../psi-stkmanage/domain/vo/Cgthck/QueryCgthckBillVO.h"
#include "../psi-stkmanage/domain/query/Cgthck/QueryCgthckBillQuery.h"
#include "../psi-stkmanage/domain/vo/Cgthck/QueryCgthrkDetailedBillVO.h"
#include"../../domain/dto/Cgthck/CgthckBillDetailedDTO.h"

class CgthckService {
public:
	// 分页查询单据列表
	PageVO<QueryCgthckBillVO> queryAllFitBill(const QueryCgthckBillQuery& query);

	// 查询详细信息
	QueryCgthrkDetailedBillVO queryBillDetial(const CgthckBillDetailedDTO& query);
	// 采购入库单分录查询数据
	std::list<QueryCgrkBillListsVO> listAll(const QueryCgrkBillQuery& query);
	// 添加采购退货出库单(保存/提交)
	int saveData(const AddCgthckBillDTO& dto);
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
	int importData(const ImportCgthckFileDTO& dto);
	// 导出
	ExportCgthckVO exportData(const ExportCgthckFileDTO& dto);
};



#endif

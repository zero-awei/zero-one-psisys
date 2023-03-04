#ifndef _CGTHCK_CONTROLLER_
#define _CGTHCK_CONTROLLER_

#include "../psi-stkmanage/domain/vo/JsonVO.h"
#include "../psi-stkmanage/domain/vo/Message.h"
#include "../psi-stkmanage/domain/vo/PageVO.h"
#include "../../service/Cgthck/CgthckService.h"
#include "../psi-stkmanage/domain/query/Cgthck/QueryCgthckBillQuery.h"
#include "../psi-stkmanage/domain/query/Cgthck/QueryCgrkBillQuery.h"
#include "../psi-stkmanage/domain/dto/Cgthck//AddCgthckBillDTO.h"
#include "../psi-stkmanage/domain/dto/Cgthck/DeleteCgthckBillDTO.h"
#include "../psi-stkmanage/domain/dto/Cgthck/ExportCgthckFileDTO.h"
#include "../psi-stkmanage/domain/dto/Cgthck/ModifyCgthckBillDTO.h"
#include "../psi-stkmanage/domain/dto/Cgthck/ImportCgthckFileDTO.h"
#include "../psi-stkmanage/domain/vo/Cgthck/ExportCgthckVO.h"
#include "../psi-stkmanage/domain/vo/Cgthck/QueryCgthckBillVO.h"
#include "../psi-stkmanage/domain/vo/Cgthck/QueryCgthrkDetailedBillVO.h"
#include"../../domain/dto/Cgthck/CgthckBillDetailedDTO.h"
#include "../psi-stkmanage/domain/vo/Cgthck/QueryCgrkBillListsVO.h"
/**
* 控制器, 采购退货出库接口的使用
*/
class CgthckController
{
public:
	// 查询单据接口
	CREATE_API_FUN_QUERY(queryCgthcBillk, execQueryCgthckBill, QueryCgthckBillQuery);
	// 查询指定单据明细接口
	CREATE_API_FUN_QUERY(queryCgthckBillDetail, execQueryCgthckBillDetail, CgthckBillDetailedDTO);
	// 查询采购入库单据分录列表
	CREATE_API_FUN_QUERY_PAYLOAD(queryCgrkEntryList, execQueryCgrkEntryList, QueryCgrkBillQuery);
	// 添加采购退货出库(红入)单据接口
	CREATE_API_FUN_JSON_PAYLOAD(addCgthckBill, execAddCgthckBill, AddCgthckBillDTO);
	// 修改采购退货出库(红入)单据接口
	CREATE_API_FUN_JSON_PAYLOAD(modifyCgthckBill, execModifyCgthckBill, AddCgthckBillDTO);
	// 修改采购退货出库(红入)审批
	CREATE_API_FUN_BODY_PAYLOAD(modifyCgthckApproval, execModifyCgthckApproval, ModifyCgthckBillDTO);
	// 修改采购退货出库(红入)单据状态接口
	// 关闭
	CREATE_API_FUN_BODY_PAYLOAD(modifyCgthckBillStatusToClosed, execModifyCgthcStatusToClose, ModifyCgthckBillDTO);
	// 反关闭
	CREATE_API_FUN_BODY_PAYLOAD(modifyCgthckBillStatusToUnclosed, execModifyCgthcStatusToUnclose, ModifyCgthckBillDTO);
	// 作废
	CREATE_API_FUN_BODY_PAYLOAD(modifyCgthckBillStatusToVoided, execModifyCgthcStatusToVoided, ModifyCgthckBillDTO);
	// 删除采购退货出库(红入)单据接口
	CREATE_API_FUN_BODY_PAYLOAD(deleteCgthckBill, execDeleteCgthckBill, DeleteCgthckBillDTO);
	// 删除采购退货出库(红入)单明细接口
	CREATE_API_FUN_BODY_PAYLOAD(deleteCgthckBillDetail, execDeleteCgthckBillDetail, DeleteCgthckBillDTO);
	// 导入
	CREATE_API_FUN_BODY_FILE(importCgthckFile, execImportCgthckFile, ImportCgthckFileDTO);
	// 导出
	CREATE_API_FUN_BODY_PAYLOAD(exportCgthckFile, execExportCgthckFile, ExportCgthckFileDTO);
private:
	// 测试查询数据
	JsonVO<PageVO<QueryCgthckBillVO>> execQueryCgthckBill(const QueryCgthckBillQuery& query);
	// 测试查询详细数据
	JsonVO<QueryCgthrkDetailedBillVO> execQueryCgthckBillDetail(const CgthckBillDetailedDTO& query);
	// 测试分录查询采购入库单列表	
	JsonVO<std::list<QueryCgrkBillListsVO>> execQueryCgrkEntryList(const QueryCgrkBillQuery& query, const PayloadDTO& payload);
	// 测试添加数据
	JsonVO<uint64_t> execAddCgthckBill(const AddCgthckBillDTO& dto, const PayloadDTO& payload);
	// 测试修改数据
	JsonVO<uint64_t> execModifyCgthckBill(const AddCgthckBillDTO& dto, const PayloadDTO& payload);
	// 审批单据
	JsonVO<uint64_t> execModifyCgthckApproval(const ModifyCgthckBillDTO& dto, const PayloadDTO& payload);
	// 修改单据状态
	// 关闭
	JsonVO<uint64_t> execModifyCgthcStatusToClose (const ModifyCgthckBillDTO& dto, const PayloadDTO& payload);
	// 反关闭
	JsonVO<uint64_t> execModifyCgthcStatusToUnclose(const ModifyCgthckBillDTO& dto, const PayloadDTO& payload);
	// 作废
	JsonVO<uint64_t> execModifyCgthcStatusToVoided(const ModifyCgthckBillDTO& dto, const PayloadDTO& payload);
	// 测试删除数据
	JsonVO<uint64_t> execDeleteCgthckBill(const DeleteCgthckBillDTO& dto, const PayloadDTO& payload);
	// 测试删除明细
	JsonVO<uint64_t> execDeleteCgthckBillDetail(const DeleteCgthckBillDTO& dto, const PayloadDTO& payload);
	// 测试提交JSON
	// 测试文件导入
	JsonVO<uint64_t> execImportCgthckFile(const ImportCgthckFileDTO& dto);
	// 测试文件导出
	JsonVO<ExportCgthckVO> execExportCgthckFile(const ExportCgthckFileDTO& dto, const PayloadDTO& payload);
};


#endif // !_CGTHCK_CONTROLLER_


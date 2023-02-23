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
#include "../psi-stkmanage/domain/vo/Cgthck/QueryCgthckBillVO.h"
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
	CREATE_API_FUN_QUERY(queryCgthckBillDetail, execQueryCgthckBillDetail, QueryCgthckBillQuery);
	// 添加采购退货出库(红入)单据接口
	CREATE_API_FUN_JSON(addCgthckBill, execAddCgthckBill, AddCgthckBillDTO);
	// 修改采购退货出库(红入)单据接口
	CREATE_API_FUN_BODY(modifyCgthckBill, execModifyCgthckBill, ModifyCgthckBillDTO);
	// 删除采购退货出库(红入)单据接口
	CREATE_API_FUN_BODY(deleteCgthckBill, execDeleteCgthckBill, DeleteCgthckBillDTO);
	// 导入
	CREATE_API_FUN_BODY(importCgthckFile, execImportCgthckFile, ImportCgthckFileDTO);
	// 导出
	CREATE_API_FUN_BODY(exportCgthckFile, execExportCgthckFile, ExportCgthckFileDTO);
private:
	// 测试查询数据
	JsonVO<PageVO<QueryCgthckBillVO>> execQueryCgthckBill(const QueryCgthckBillQuery& query);
	// 测试查询详细数据
	JsonVO<PageVO<QueryCgthckBillDetailVO>> execQueryCgthckBillDetail(const QueryCgthckBillQuery& query);
	// 测试分录查询采购入库单列表	
	JsonVO<PageVO<QueryCgrkBillListsVO>> execQueryCgrkBillList(const QueryCgrkBillQuery& query);
	// 测试添加数据
	JsonVO<uint64_t> execAddCgthckBill(const AddCgthckBillDTO& dto);
	// 测试修改数据
	JsonVO<uint64_t> execModifyCgthckBill(const ModifyCgthckBillDTO& dto);
	// 测试删除数据
	JsonVO<uint64_t> execDeleteCgthckBill(const DeleteCgthckBillDTO& dto);
	// 测试提交JSON
	// 测试文件导入
	JsonVO<uint64_t> execImportCgthckFile(const ImportCgthckFileDTO& dto);
	// 测试文件导出
	JsonVO<uint64_t> execExportCgthckFile(const ExportCgthckFileDTO& dto);
};


#endif // !_CGTHCK_CONTROLLER_


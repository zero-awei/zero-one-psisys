#ifndef _RTV_CONTROLLER_
#define _RTV_CONTROLLER_

#include "../psi-stkmanage/domain/vo/JsonVO.h"
#include "../psi-stkmanage/domain/vo/Message.h"
#include "../psi-stkmanage/domain/vo/PageVO.h"
#include "../psi-stkmanage/domain/query/Cgthck/DocListQuery.h"
#include "../psi-stkmanage/domain/dto/Cgthck/AddDocListDTO.h"
#include "../psi-stkmanage/domain/dto/Cgthck/ExportDocListDTO.h"
#include "../psi-stkmanage/domain/dto/Cgthck/ModifyDocListDTO.h"
#include "../psi-stkmanage/domain/dto/Cgthck/RemoveDocListDTO.h"
#include "../psi-stkmanage/domain/vo/Cgthck/ReturnToVendorVO.h"

/**
* 控制器, 采购退货出库接口的使用
*/
class RtvController
{
public:
	CREATE_API_FUN_QUERY(rtvQuery, execRtvQuery, DocListQuery);
	CREATE_API_FUN_QUERY(rtvEntryQuery, execRtvEntryQuery, DocListQuery);
private:
	// 测试查询数据
	JsonVO<PageVO<RtvShowVO>> execRtvQuery(const DocListQuery& query);
	JsonVO<PageVO<RtvCheckVO>> execRtvEntryQuery(const DocListQuery& query);
	// 测试添加数据
	// 测试修改数据
	// 测试删除数据
	// 测试提交JSON
	// 测试文件上传
};


#endif // !_RTV_CONTROLLER_


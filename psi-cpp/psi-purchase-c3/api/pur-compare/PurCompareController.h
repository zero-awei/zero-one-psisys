#pragma once
#ifndef _PUR_COMPARE_CONTROLLER_H
#define _PUR_COMPARE_CONTROLLER_H

#include "../../domain/dto/pur-compare/PurCompareDTO.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/vo/pur-compare/PurCompareVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"


/**
 * 示例控制器，演示基础接口的使用
 */
class PurComRenqingController
{
public:
	// 新增比价
	CREATE_API_FUN_BODY(addPurCom, execAddPurCom, AddPurComDTO);
	// 修改比价
	CREATE_API_FUN_BODY(modifyPurCom, execModifyPurCom, ModPurComDTO);
	// 删除比价
	CREATE_API_FUN_BODY(removePurCom, execRemovePurCom, DelPurComDTO);
	// 修改单据状态
	CREATE_API_FUN_JSON(purComModBillStatus, execPurComModBillStatus, PurComModBillStatusDTO);
private:
	//演示新增比价
	JsonVO<uint64_t> execAddPurCom(const AddPurComDTO& dto);
	//演示修改比价
	JsonVO<uint64_t> execModifyPurCom(const ModPurComDTO& dto);
	//演示删除比价
	JsonVO<uint64_t> execRemovePurCom(const DelPurComDTO& dto);
	//演示修改单据状态
	JsonVO<uint64_t> execPurComModBillStatus(const PurComModBillStatusDTO& dto);
	
};

#endif // _PUR_COMPARE_CONTROLLER_H
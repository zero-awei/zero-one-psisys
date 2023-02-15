/*
 Copyright Zero One Star. All rights reserved.

 @Author: renqing
 @Date: 2023/2/15 16:58:10

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
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
class PurCompareController
{
public:
	// 新增比价
	CREATE_API_FUN_BODY(addPurCom, execAddPurCom, AddPurComDTO);
	// 修改比价
	CREATE_API_FUN_BODY(modifyPurCom, execModifyPurCom, ModPurComDTO);
	// 删除比价
	CREATE_API_FUN_BODY(removePurCom, execRemovePurCom, DelPurComDTO);
	// 修改单据状态
	CREATE_API_FUN_BODY(purComModBillStatus, execPurComModBillStatus, PurComModBillStatusDTO);
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
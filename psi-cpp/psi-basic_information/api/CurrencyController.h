#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 @Author: douhao
 @Date: 2023/2/14 16:07:21
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
#ifndef _CURRENCY_CONTROLLER_
#define _CURRENCY_CONTROLLER_

#include "../domain/query/CurrencyQuery.h"
#include "../domain/dto/CurrencyDTO.h"
#include "../domain/dto/IDDTO.h"
#include "../domain/vo/CurrencyVO.h"
#include "../domain/vo/PageVO.h"
#include "../domain/vo/JsonVO.h"

/**
 * 基础资料币种模块接口
 */
class CurrencyController
{
public:
	CREATE_API_FUN_QUERY_PAYLOAD(queryCurrency, execQueryCurrency, CurrencyQuery);
	CREATE_API_FUN_QUERY_PAYLOAD(queryDetailCurrency, execQueryDetail, CurrencyQuery);
	CREATE_API_FUN_QUERY_PAYLOAD(queryActionInfolCurrency, execQueryActionInfo, CurrencyQuery);
	CREATE_API_FUN_BODY(addCurrency, execAddCurrency, CurrencyDTO);
	CREATE_API_FUN_BODY(modifyCurrency, execModifyCurrency, CurrencyDTO);
	CREATE_API_FUN_BODY(removeCurrency, execRemoveCurrency, CurrencyDTO);
	CREATE_API_FUN_BODY_FILE(modifyCurrency, execModifyCurrencys, CurrencyDTO);
	CREATE_API_FUN_QUERY_PAYLOAD(exportExecl, execExportExecl, CurrencyQuery);
private:
	//默认查询数据
	JsonVO<PageVO<CurrencyVO>> execQueryCurrency(const CurrencyQuery& query, const PayloadDTO& payload);
	// 查询详情
	JsonVO<CurrencyDetailVO> execQueryDetail(const CurrencyQuery& query, const PayloadDTO& payload);
	JsonVO<CurrencyActionInfoVO> execQueryActionInfo(const CurrencyQuery& query, const PayloadDTO& payload);
	//新增仓库 
	JsonVO<PageVO<CurrencyVO>> execAddCurrency(const CurrencyDTO& dto);
	//修改仓库
	JsonVO<PageVO<CurrencyVO>> execModifyCurrency(const CurrencyDTO& dto);
	//删除仓库
	JsonVO<PageVO<CurrencyVO>> execRemoveCurrency(const CurrencyDTO& dto);
	//文件导入
	JsonVO<PageVO<CurrencyVO>> execModifyCurrency(const CurrencyDTO& dto);
	//文件导出
	JsonVO<string> execExportExecl(const CurrencyQuery& query, const PayloadDTO& payload);
};

#endif // _CURRENCY_CONTROLLER_

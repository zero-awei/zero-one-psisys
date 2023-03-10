#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 @Author: douhao
 @Date: 2023/2/13 20:31:04
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
#ifndef _Currency_CONTROLLER_
#define _Currency_CONTROLLER_

#include "../../domain/query/currency/CurrencyQuery.h"
#include "../../domain/dto/currency/CurrencyDTO.h"
#include "../../domain/dto/IDDTO.h"
#include "../../domain/vo/currency/CurrencyVO.h"
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"

/**
 * 基础资料币种模块接口
 */
class CurrencyController
{
public:
	CREATE_API_FUN_QUERY_PAYLOAD(queryCurrency, execQueryCurrency, CurrencyQuery);
	CREATE_API_FUN_QUERY_PAYLOAD(queryDetailCurrency, execQueryDetail, OnlyValueCurrencyQuery);

	CREATE_API_FUN_BODY_PAYLOAD(addCurrency, execAddCurrency, CurrencyDTO);
	CREATE_API_FUN_BODY_PAYLOAD(modifyCurrency, execModifyCurrency, CurrencyDTO);
	CREATE_API_FUN_BODY(removeCurrency, execRemoveCurrency, CurrencyDTO);
	
	CREATE_API_FUN_BODY_PAYLOAD_FILE(addCurrencys, execAddCurrencys, CurrencyDTO);
	CREATE_API_FUN_QUERY_PAYLOAD(exportExecl, execExportExecl, CurrencyQuery);
private:
	//默认查询数据
	JsonVO<PageVO<CurrencyVO>> execQueryCurrency(const CurrencyQuery& query, const PayloadDTO& payload);
	// 查询详情
	JsonVO<CurrencyVO> execQueryDetail(const OnlyValueCurrencyQuery& query, const PayloadDTO& payload);
	//新增币种
	JsonVO<uint64_t> execAddCurrency(const CurrencyDTO& dto, const PayloadDTO& payload);
	//JsonVO<PageVO<CurrencyVO>> execAddCurrency(const CurrencyDTO& dto);
	//修改币种
	JsonVO<uint64_t> execModifyCurrency(const CurrencyDTO& dto, const PayloadDTO& payload);
	//删除币种 
	JsonVO<uint64_t>  execRemoveCurrency(const CurrencyDTO& dto);
	//文件导入
	JsonVO<bool>  execAddCurrencys(const CurrencyDTO& dto, const PayloadDTO& payload);
	//文件导出
	JsonVO<string> execExportExecl(const CurrencyQuery& query, const PayloadDTO& payload);
};

#endif // _Currency_CONTROLLER_
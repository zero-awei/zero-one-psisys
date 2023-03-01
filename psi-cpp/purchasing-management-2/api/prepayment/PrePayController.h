#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:08:56

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
#ifndef _PRE_PAY_CONTROLLER_
#define _PRE_PAY_CONTROLLER_

#include"api/ApiHelper.h"

#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/dto/IDDTO.h"

//删除
#include "../../domain/dto/prepayment/DePayDTO.h"
#include "../../domain/vo/prepayment/PrepaymentVO.h"
// 采购订单列表
#include "../../domain/query/PurOrder/PurOrderQuery.h"
#include "../../domain/vo/PurOrder/PurOrderVO.h"

/**
 * 示例控制器，演示基础接口的使用
 */
class PrePayController
{
public:

	//查询
	CREATE_API_FUN_QUERY_PAYLOAD(queryPayFindBill, execQuerypayFindBill, PurOrderQuery);
	//查询指定单据详细信息
	CREATE_API_FUN_QUERY_PAYLOAD(queryPayFinDetailBill, execQueryPayDetailBill, PurOrderQuery);
	//删除订单
	CREATE_API_FUN_BODY(removeDePayId, execRemoveDePayId, DePayDTO);
	


private:
	
	//查询
	JsonVO<PageVO<PurOrderVO>> execQuerypayFindBill(const PurOrderQuery& query, const PayloadDTO& payload);
	//查询指定单据详细信息
	JsonVO<PurOrderVO> execQueryPayDetailBill(const PurOrderQuery& query, const PayloadDTO& payload);
	//删除订单
	JsonVO<string> execRemoveDePayId(const DePayDTO& dto);
	

};

#endif // _SAMPLE_CONTROLLER_
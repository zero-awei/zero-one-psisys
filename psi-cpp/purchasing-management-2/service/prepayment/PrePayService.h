#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: xubuxi
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
#ifndef _PRE_PAY_SERVICE_
#define _PRE_PAY_SERVICE_
#include <list>
#include "../../domain/vo/PageVO.h"
#include "../../domain/vo/JsonVO.h"
#include "../../domain/vo/Message.h"

//删除
#include "../../domain/dto/prepayment/DePayDTO.h"
#include "../../domain/vo/prepayment/PrepaymentVO.h"
// 采购订单列表
#include "../../domain/query/PurOrder/PurOrderQuery.h"
#include "../../domain/vo/PurOrder/PurOrderVO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 * 预付申请的服务实现
 */
class PrePayService
{
public:
	// 分页查询 预付申请单所有数据(多个对象)
	PageVO<PurOrderVO> listAll(const PurOrderQuery& query);
	// 查询预付申请单详细数据(单个对象)
	PurOrderVO getAll(const PurOrderQuery& query);
	// 通过ID删除数据
	bool DePrePayId(const DePayDTO& dto);

};

#endif // !_PRE_PAY_SERVICE_

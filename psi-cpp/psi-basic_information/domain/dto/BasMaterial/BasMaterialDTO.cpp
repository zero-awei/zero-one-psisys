/*
 Copyright Zero One Star. All rights reserved.

 @Author: 111
 @Date: 2023/2/19 20:46:24

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
#include "stdafx.h"
#include "BasMaterialDTO.h"
void from_json(const json& j, BasMaterialDTO& t) { // NOLINT
	BIND_FROM_TO_ULL(j, t, id);
	// 编码
	BIND_FROM_TO_NORMAL(j, t, code);
	// 名称
	BIND_FROM_TO_NORMAL(j, t, name);
	// 助记名
	BIND_FROM_TO_NORMAL(j, t, auxName);

	// 分类 需要查另一个表
	BIND_FROM_TO_NORMAL(j, t, categoryId);
	//规格型号
	BIND_FROM_TO_NORMAL(j, t, model);
	//主单位 需要查另一个表
	BIND_FROM_TO_NORMAL(j, t, unitId);
	//销售价格,double
	BIND_FROM_TO_D(j, t, salePrice);
	//税控编码
	BIND_FROM_TO_NORMAL(j, t, taxCode);


	// 启用,1/0
	BIND_FROM_TO_I(j, t, isEnabled);
	// 备注
	BIND_FROM_TO_NORMAL(j, t, remark);
	//// 创建时间
	//BIND_FROM_TO_NORMAL(j, t, createTime);
	//// 创建人
	//BIND_FROM_TO_NORMAL(j, t, createBy);
	//// 修改时间
	//BIND_FROM_TO_NORMAL(j, t, updateTime);
	//// 修改人
	//BIND_FROM_TO_NORMAL(j, t, updateBy);
}
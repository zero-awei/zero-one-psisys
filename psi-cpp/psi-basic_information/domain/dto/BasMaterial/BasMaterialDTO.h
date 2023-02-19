#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 111
 @Date: 2023/02/15 21:00

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
#ifndef _BASMATERIAL_DTO_
#define _BASMATERIAL_DTO_

#include "../../GlobalInclude.h"
#include "../FileDTO.h"

/**
 * 基础资料物料模块传输对象
 */
class BasMaterialDTO : public FileDTO
{
	CC_SYNTHESIZE(string, id, Id);
	// 分类 需要查另一个表
	CC_SYNTHESIZE(string, categoryId, CategoryId);
	// 编码
	CC_SYNTHESIZE(string, code, Code);
	// 名称
	CC_SYNTHESIZE(string, name, Name);
	// 助记名
	CC_SYNTHESIZE(string, auxName, AuxName);
	// 启用
	CC_SYNTHESIZE(int, isEnabled, IsEnabled);

	//规格型号
	CC_SYNTHESIZE(string, model, Model);
	//主单位 需要查另一个表
	CC_SYNTHESIZE(string, unitId, UnitId);
	//销售价格
	CC_SYNTHESIZE(int, salePrice, SalePrice);
	//税控编码
	CC_SYNTHESIZE(string, taxCode, TaxCode);

	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
	// 创建时间
	CC_SYNTHESIZE(string, createTime, CreateTime);
	// 创建人
	CC_SYNTHESIZE(string, createBy, CreateBy);
	// 修改人
	CC_SYNTHESIZE(string, updateBy, UpdateBy);
	// 修改时间
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
public:
	// 绑定JSON转换方法
	friend void from_json(const json& j, BasMaterialDTO& t) {// NOLINT
		BIND_FROM_TO_NORMAL(j, t, id);
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
		//销售价格
		BIND_FROM_TO_I(j, t, salePrice);
		//税控编码
		BIND_FROM_TO_NORMAL(j, t, taxCode);


		// 启用
		BIND_FROM_TO_I(j, t, isEnabled);
		// 备注
		BIND_FROM_TO_NORMAL(j, t, remark);
		// 创建时间
		BIND_FROM_TO_NORMAL(j, t, createTime);
		// 创建人
		BIND_FROM_TO_NORMAL(j, t, createBy);
		// 修改时间
		BIND_FROM_TO_NORMAL(j, t, updateTime);
		// 修改人
		BIND_FROM_TO_NORMAL(j, t, updateBy);
	}
	BIND_TO_JSON(BasMaterialDTO,id, code, name, auxName, categoryId, model, unitId, salePrice, taxCode, isEnabled, remark, createTime, createBy, updateTime, updateBy);
};

#endif // !_BASMATERIAL_DTO_
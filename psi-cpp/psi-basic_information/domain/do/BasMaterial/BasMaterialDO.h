#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 111
 @Date: 2023/02/19 11:52:32

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
#ifndef _BASMATERIAL_DO_
#define _BASMATERIAL_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class BasMaterialDO
{
	//id
	CC_SYNTHESIZE(uint64_t, id, Id);
	// 分类 id
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
	//主单位id
	CC_SYNTHESIZE(string, unitId, UnitId);

	//销售价格
	CC_SYNTHESIZE(double, salePrice, SalePrice);
	//税控编码
	CC_SYNTHESIZE(string, taxCode, TaxCode);

	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
	// 创建人
	CC_SYNTHESIZE(string, createBy, CreateBy);
	// 创建时间
	CC_SYNTHESIZE(string, createTime, CreateTime);
	// 修改人
	CC_SYNTHESIZE(string, updateBy, UpdateBy);
	// 修改时间
	CC_SYNTHESIZE(string, updateTime, UpdateTime);

public:
	BasMaterialDO() {
		id = 1;
		categoryId = "";
		code = "";
		name = "";
		auxName = "";
		isEnabled = 1;
		model = "";
		unitId = "";
		salePrice = 0;
		taxCode = "";
		remark = "";
		createBy = "";
		createTime = "";
		updateBy = "";
		updateTime = "";
	}
};

#endif // !_BASMATERIAL_DO_

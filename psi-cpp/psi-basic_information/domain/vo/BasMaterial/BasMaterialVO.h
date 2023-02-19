#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 111
 @Date: 2023/02/15 20:50

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
#ifndef _BASMATERIAL_VO_
#define _BASMATERIAL_VO_

#include "../../GlobalInclude.h"

/**
 * 示例显示对象
 */
class BasMaterialVO
{
	CC_SYNTHESIZE(string, id, Id);
	// 分类 需要查另一个表
	CC_SYNTHESIZE(string, categoryId, CategoryId);
	////分类name
//CC_SYNTHESIZE(string, categoryId, CategoryId);

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
	////主单位name
	//CC_SYNTHESIZE(string, unit, Unit);
	
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
	BIND_TO_JSON(BasMaterialVO, code, name, auxName, categoryId, model, unitId, salePrice, taxCode, isEnabled, remark, createTime, createBy, updateTime, updateBy);
	//BIND_TO_JSON(BasMaterialVO, code, name, auxName, categoryId,category, model, unitId, unit
	//	,salePrice, taxCode, isEnabled, remark, createTime, createBy, updateTime, updateBy)
};

#endif // !_SAMPLE_VO_
#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yunjj
 @Date: 2023/2/21 20:33

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
#ifndef _MATERIALRETURNDO_H_
#define _MATERIALRETURNDO_H_

#include "../../GlobalInclude.h"

class MaterialReturnDO
{
	//物料的id
	CC_SYNTHESIZE(std::string, id, Id);
	//物料的编码
	CC_SYNTHESIZE(std::string, code, Code);
	//物料的名称
	CC_SYNTHESIZE(std::string, name, Name);
	//物料的助记名
	CC_SYNTHESIZE(std::string, auxName, AuxName);
	//物料分类的id
	CC_SYNTHESIZE(std::string, categoryId, CategoryId);
	//物料分类的名字
	CC_SYNTHESIZE(std::string, categoryIdDictText, CategoryIdDictText);
	//规格型号
	CC_SYNTHESIZE(std::string, model, Model);
	//主单位
	CC_SYNTHESIZE(std::string, unitIdDictText, UnitIdDictText);
	//价格
	CC_SYNTHESIZE(uint64_t, price, Price);
	//税控编码
	CC_SYNTHESIZE(std::string, taxCode, TaxCode);
	//是否启用
	CC_SYNTHESIZE(std::string, isEnabledDictText, IsEnabledDictText);
	//备注
	CC_SYNTHESIZE(std::string, remark, Remark);
	//创建时间
	CC_SYNTHESIZE(std::string, createTime, CreateTime);
	//创建人
	CC_SYNTHESIZE(std::string, createBy, CreateBy);
	//修改时间
	CC_SYNTHESIZE(std::string, updateTime, UpdateTime);
	//修改人
	CC_SYNTHESIZE(std::string, updateBy, UpdateBy);
public:
	MaterialReturnDO()
	{
		id = "";
		code = "";
		name = "";
		auxName = "";
		categoryId = "";
		model = "";
		unitIdDictText = "";
		price = 0;
		taxCode = "";
		isEnabledDictText = "";
		remark = "";
		createBy = "";
	}
};

#endif // _MATERIALRETURNDO_H_
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:47:09

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
#include "DepartController.h"

JsonVO<AddDepartVO> DepartController::execAddDepart(const AddDepartDTO& dto)
{
	//转换成VO
	AddDepartVO vo;
	vo.setDepartName(dto.getDepartName());
	vo.setMail(dto.getMail());
	vo.setPhone(dto.getPhone());
	//返回结果
	return JsonVO<AddDepartVO>(vo, RS_SUCCESS);
}

JsonVO<AddDepartMoreVO> DepartController::execAddDepartMore(const AddDepartMoreDTO& dto)
{
	//转换成VO
	AddDepartMoreVO vo;
	vo.setDepartName(dto.getOther().front().getDepartName());
	vo.setMail(dto.getOther().front().getMail());
	vo.setPhone(dto.getOther().front().getPhone());
	vo.setId(dto.getId());
	//返回结果
	return JsonVO<AddDepartMoreVO>(vo, RS_SUCCESS);
}

/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:26:52

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
#include "PurOrderDAO.h"
#include "PurOrderMapper.h"
#include <sstream>

string PurOrderDAO::insert(const PurOrderDO& iObj)
{
	return "";
}

// 通过id删除采购订单
// 负责人：Andrew
int PurOrderDAO::deleteById(string id)
{
	string sql = "DELETE FROM `pur_order` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s", id);
}

// 修改订单状态
// 负责人：Andrew
int PurOrderDAO::updateStatusClose(const PurOrderDO& purdo)
{
	string sql = "UPDATE `pur_order` SET `update_by`=?, `update_time`=?, `is_closed`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%i%s", purdo.getUpdate_by(), purdo.getUpdate_time(), purdo.getIs_closed(), purdo.getId());
}

int PurOrderDAO::updateStatusCancel(const PurOrderDO& purdo)
{
	string sql = "UPDATE `pur_order` SET `update_by`=?, `update_time`=?, `is_voided`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%i%s", purdo.getUpdate_by(), purdo.getUpdate_time(), purdo.getIs_voided(), purdo.getId());
}

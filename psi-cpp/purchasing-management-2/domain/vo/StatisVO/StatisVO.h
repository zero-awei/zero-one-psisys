#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew
 @Date: 2023/02/15 22:00:00

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
#ifndef __STATIS_VO__
#define __STATIS_VO__

#include "../../GlobalInclude.h"

/**
* 采购订单汇总VO领域模型
*/
class StatisVO
{
	CC_SYNTHESIZE(uint64_t, id, Id); // ID
	CC_SYNTHESIZE(double, price, Price); // 采购金额
	CC_SYNTHESIZE(double, incost, Incost); // 入库金额
	CC_SYNTHESIZE(double, settlePrice, SettlePrice); // 结算金额
	CC_SYNTHESIZE(double, settledPrice, SettledPrice); // 已结算金额
	CC_SYNTHESIZE(double, unsettledPrice, UnsettledPrice); // 未结算金额
	CC_SYNTHESIZE(uint16_t, year, Year); // 年份
	CC_SYNTHESIZE(uint16_t, month, Month); // 月份
	CC_SYNTHESIZE(uint16_t, orders, Orders); // 订单笔数
private:
	friend void to_json(json& j, const StatisVO& sv)
	{
		j = json{
			{"id", sv.id},
			{"price", sv.price},
			{"incost", sv.incost},
			{"settlePrice", sv.settlePrice},
			{"settledPrice", sv.settledPrice},
			{"unsettledPrice", sv.unsettledPrice},
			{"year", sv.year},
			{"month", sv.month},
			{"orders", sv.orders}
		};
	}
};

/**
* 采购订单汇总-部门/业务员/供应商VO领域模型
*/
class StatisByDeptVO : public StatisVO
{
	CC_SYNTHESIZE(std::string, dept, Dept); // 业务部门ID
	CC_SYNTHESIZE(std::string, deptName, DeptName); // 业务部门名
private:
	friend void to_json(json& j, const StatisByDeptVO& sv)
	{
		to_json(j, static_cast<const StatisVO&>(sv));
		j = json{
			{"dept", sv.dept},
			{"deptName", sv.deptName},
		};
	}
};

class StatisByOperatorVO : public StatisByDeptVO
{
	CC_SYNTHESIZE(std::string, op, Op); // 业务员ID
	CC_SYNTHESIZE(std::string, opName, OpName); // 业务员名
private:
	friend void to_json(json& j, const StatisByOperatorVO& sv)
	{
		to_json(j, static_cast<const StatisByDeptVO&>(sv));
		j = json{
			{"op", sv.op},
			{"opName", sv.opName},
		};
	}
};

class StatisBySupplierVO : public StatisVO
{
	CC_SYNTHESIZE(std::string, supplier, supplier); // 供应商ID
	CC_SYNTHESIZE(std::string, supName, SupName); // 供应商名
private:
	friend void to_json(json& j, const StatisBySupplierVO& sv)
	{
		to_json(j, static_cast<const StatisVO&>(sv));
		j = json{
			{"supplier", sv.supplier},
			{"supName", sv.supName},
		};
	}
};

#endif // !__STATIS_VO__

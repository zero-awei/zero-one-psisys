#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew
 @Date: 2023/02/18 10:00:00

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
#include "../lib-common/include/CharsetConvertHepler.h"

/**
* �ɹ���������VO����ģ��
*/
class StatisVO
{
	CC_SYNTHESIZE(uint64_t, id, Id); // ID
	CC_SYNTHESIZE(double, price, Price); // �ɹ����
	CC_SYNTHESIZE(double, incost, Incost); // �����
	CC_SYNTHESIZE(double, settlePrice, SettlePrice); // ������
	CC_SYNTHESIZE(double, settledPrice, SettledPrice); // �ѽ�����
	CC_SYNTHESIZE(double, unsettledPrice, UnsettledPrice); // δ������
	CC_SYNTHESIZE(uint16_t, year, Year); // ���
	CC_SYNTHESIZE(uint16_t, month, Month); // �·�
	CC_SYNTHESIZE(uint16_t, orders, Orders); // ��������
public:
	StatisVO() : id(666), price(6.6), incost(6.6), settlePrice(6.6), settledPrice(6.6), unsettledPrice(6.6), year(2023), month(2), orders(514) {}
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
* �ɹ���������-����/ҵ��Ա/��Ӧ��VO����ģ��
*/
class StatisByDeptVO : public StatisVO
{
	CC_SYNTHESIZE(string, dept, Dept); // ҵ����ID
	CC_SYNTHESIZE(string, deptName, DeptName); // ҵ������
public:
	StatisByDeptVO() : dept("114514"), deptName(CharsetConvertHepler::ansiToUtf8("����")) {}
	friend void to_json(json& j, const StatisByDeptVO& sv)
	{
		to_json(j, static_cast<const StatisVO&>(sv));
		j.push_back({ "dept", sv.dept });
		j.push_back({ "deptName", sv.deptName });
	}
};

class StatisByOperatorVO : public StatisByDeptVO
{
	CC_SYNTHESIZE(string, op, Op); // ҵ��ԱID
	CC_SYNTHESIZE(string, opName, OpName); // ҵ��Ա��
public:
	StatisByOperatorVO() : op(CharsetConvertHepler::ansiToUtf8("op114")), opName(CharsetConvertHepler::ansiToUtf8("ҵ��Ա1")) {}
	friend void to_json(json& j, const StatisByOperatorVO& sv)
	{
		to_json(j, static_cast<const StatisByDeptVO&>(sv));
		j.push_back({ "op", sv.op });
		j.push_back({ "opName", sv.opName });
	}
};

class StatisBySupplierVO : public StatisVO
{
	CC_SYNTHESIZE(string, supplier, supplier); // ��Ӧ��ID
	CC_SYNTHESIZE(string, supName, SupName); // ��Ӧ����
public:
	StatisBySupplierVO() : supplier(CharsetConvertHepler::ansiToUtf8("Nvidia")), supName(CharsetConvertHepler::ansiToUtf8("�ϻ�")) {}
	friend void to_json(json& j, const StatisBySupplierVO& sv)
	{
		to_json(j, static_cast<const StatisVO&>(sv));
		j.push_back({ "supplier", sv.supplier });
		j.push_back({ "supName", sv.supName });
	}
};

#endif // !__STATIS_VO__

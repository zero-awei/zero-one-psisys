#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: QZP
 @Date: 2023/02/20 23:49:16

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
#ifndef _PUR_COMPARE_ENTRY_DO_
#define _PUR_COMPARE_ENTRY_DO_
#include "../DoInclude.h"


/**
 * pur_compare_entry数据库实体类
 */
class PurCompareEntryDO
{
	// id
	CC_SYNTHESIZE(string, id, Id);
	// 主表
	CC_SYNTHESIZE(string, mid, Mid);
	// 单据号
	CC_SYNTHESIZE(string, billNo, BillNo);
	// 分录号
	CC_SYNTHESIZE(int64_t, entryNo, EntryNo);
	// 源单类型
	CC_SYNTHESIZE(string, srcBillType, SrcBillType);
	// 源单id
	CC_SYNTHESIZE(string, srcBillId, SrcBillId);
	// 源单分录id
	CC_SYNTHESIZE(string, srcEntryId, SrcEntryId);
	// 源单分录号
	CC_SYNTHESIZE(string, srcNo, SrcNo);
	// 供应商id
	CC_SYNTHESIZE(string, supplierId, SupplierId);
	// 物料
	CC_SYNTHESIZE(string, materialId, MaterialId);
	// 计量单位id
	CC_SYNTHESIZE(string, unitId, UnitId);
	// 数量
	CC_SYNTHESIZE(double, qty, Qty);
	// 税率
	CC_SYNTHESIZE(double, taxRate, TaxRate);
	// 含税价格
	CC_SYNTHESIZE(double, price, Price);
	// 折扣率
	CC_SYNTHESIZE(double, discountRate, DiscountRate);
	// 含税金额
	CC_SYNTHESIZE(double, amt, Amt);
	// 排名
	CC_SYNTHESIZE(int64_t, ranking, Ranking);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
	// 自定义1
	CC_SYNTHESIZE(string, custom1, Custom1);
	// 自定义2
	CC_SYNTHESIZE(string, custom2, Custom2);
	//// 版本
	//CC_SYNTHESIZE(string, version, Version);
	// 供应商名字
	CC_SYNTHESIZE(string, supplierName, SupplierName);
	// 物料名字
	CC_SYNTHESIZE(string, materialName, MaterialName);
	// 单位名字
	CC_SYNTHESIZE(string, unitName, UnitName);
	// 规格型号
	CC_SYNTHESIZE(string, specifications, Specifications);
public:
	PurCompareEntryDO(){
		entryNo = -1;
		qty = -1;
		price = -1;
		amt = -1;
		taxRate = -1;
		discountRate = -1;
		ranking = -1;
	}
	PurCompareEntryDO(vector<string> vecStr) {
		int i = 0;
		setBillNo(vecStr[i++]);
		setEntryNo(vecStr[i++] != "" ? stoi(vecStr[i-1]) :-1);
		setSrcBillType(vecStr[i++]); 
		setSrcBillId(vecStr[i++]);
		setSrcEntryId(vecStr[i++]);
		setSrcNo(vecStr[i++]);
		setSupplierName(vecStr[i++]); 
		setMaterialName(vecStr[i++]); 
		setUnitName(vecStr[i++]); 
		setQty(vecStr[i++]!=""?stod(vecStr[i-1]):-1);
		setTaxRate(vecStr[i++] != "" ? stod(vecStr[i-1]) : -1);
		setPrice(vecStr[i++] != "" ? stod(vecStr[i-1]) : -1);
		setDiscountRate(vecStr[i++] != "" ? stod(vecStr[i-1]) : -1);
		setAmt(vecStr[i++] != "" ? stod(vecStr[i-1]) : -1);
		setRanking(vecStr[i++] != "" ? stoi(vecStr[i-1]) : -1);
		setRemark(vecStr[i++]); 
		setCustom1(vecStr[i++]); 
		setCustom2(vecStr[i++]);
	}
	vector<string> purCompareEntryDOToVecStr() {
		vector<string> vecStr{ getBillNo(),to_string(getEntryNo()),getSrcBillType(),getSrcBillId(),getSrcEntryId(),
			getSrcNo(),getSupplierName(),getMaterialName(),getUnitName(),to_string(getQty()),
			to_string(getTaxRate()),to_string(getPrice()),to_string(getDiscountRate()),to_string(getAmt()),
			to_string(getRanking()),getRemark(),getCustom1(),getCustom2() };
		return vecStr;
	}
};
#endif 


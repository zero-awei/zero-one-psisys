#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 @Author: xubuxi
 @Date: 2023/2/18 22:45
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
#pragma once
#ifndef _PREPREPAYMENT_ENTRY_DO_
#define _PREPREPAYMENT_ENTRY_DO_
#include "../DoInclude.h"


/**
 * 示例数据库实体类-采购预付实体类-fin_payment_req_entry
 */

class PrepaymentEntryDO {
	//ID
	CC_SYNTHESIZE(string, id, Id);
	//主表
	CC_SYNTHESIZE(string, mid, Mid);
	//单据编号
	CC_SYNTHESIZE(string, bill_no, Bill_no);
	//分录号
	CC_SYNTHESIZE(string, entry_no, Entry_no);
	//源单类型
	CC_SYNTHESIZE(string, src_bill_type, Src_bill_type);
	//源单类型id
	CC_SYNTHESIZE(string, src_bill_id, Src_bill_id);
	//源单分录id
	CC_SYNTHESIZE(string, src_entry_id, Src_entry_id);
	//源单分录号
	CC_SYNTHESIZE(string, src_no, Src_no);
	//结算方式
	CC_SYNTHESIZE(string, settle_method, Settle_method);
	//资金账户
	CC_SYNTHESIZE(string, bank_account_id, Bank_account_id);
	//申请金额
	CC_SYNTHESIZE(int, amt, Amt);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//自定义1
	CC_SYNTHESIZE(string, custom1, Custom1);
	//自定义2
	CC_SYNTHESIZE(string, custom2, Custom2);
	//版本
	CC_SYNTHESIZE(int, version, Version);

public:
	PrepaymentEntryDO() {
		id = "";
		mid = "";
		bill_no = "";
		entry_no = "";
		src_bill_type = "";
		src_bill_id = "";
		src_entry_id = "";
		src_no = "";
		settle_method = "";
		bank_account_id = "";
		amt = 0;
		remark = "";
		custom1 = "test";
		custom2 = "";
		version = 0;

	}
};

#endif // !_PREPAYMENT_DO_
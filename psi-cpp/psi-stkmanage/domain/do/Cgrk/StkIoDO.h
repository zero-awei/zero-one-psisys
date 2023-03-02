<<<<<<< HEAD
#pragma once
=======
ï»¿#pragma once
>>>>>>> c5-maobing
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:52:32

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
#ifndef _STKIO_DO_
#define _STKIO_DO_
#include "../DoInclude.h"

/**
<<<<<<< HEAD
 * stk_ioÊý¾Ý¿âÊµÌåÀà
=======
 * stk_ioæ•°æ®åº“å®žä½“ç±»
>>>>>>> c5-maobing
 */
class StkIoDO
{
	//id
	CC_SYNTHESIZE(string, id, Id);
<<<<<<< HEAD
	// µ¥¾Ý±àºÅ
	CC_SYNTHESIZE(string, billNo, BillNo);
	//µ¥¾ÝÈÕÆÚ
	CC_SYNTHESIZE(string, billDate, BillDate);
	//Ô´µ¥ÀàÐÍ
	CC_SYNTHESIZE(string, srcBillType, SrcBillType);
	//Ô´µ¥id
	CC_SYNTHESIZE(string, srcBillId, SrcBillId);
	//Ô´µ¥ºÅ
	CC_SYNTHESIZE(string, srcNo, SrcNo);
	//µ¥¾ÝÖ÷Ìâ
	CC_SYNTHESIZE(string, subject, Subject);
	//ºì×Öµ¥¾Ý
	CC_SYNTHESIZE(int, isRubric, IsRubric);
	//³öÈë¿âÀàÐÍ
	CC_SYNTHESIZE(string, stockIoType, StockIoType);
	//ÒµÎñ²¿ÃÅ
	CC_SYNTHESIZE(string, opDept, OpDept);
	//ÒµÎñÔ±
	CC_SYNTHESIZE(string, operator1, Operator1);
	//³öÈë¿â¾­°ì
	CC_SYNTHESIZE(string, handler, Handler);
	//ÓÐÀ´Íù
	CC_SYNTHESIZE(int, hasRp, HasRp);
	//ÊÇ·ñÓÐÕÇ¶Ö
	CC_SYNTHESIZE(int, hasSwell, HasSwell);
	//¹©Ó¦ÉÌ
	CC_SYNTHESIZE(string, supplierId, SupplierId);
	//¿Í»§
	CC_SYNTHESIZE(string, customerId, CustomerId);
	//·¢Æ±ÀàÐÍ
	CC_SYNTHESIZE(string, invoiceType, InvoiceType);
	//³É±¾
	CC_SYNTHESIZE(double, cost, Cost);
	//½áËã½ð¶î
	CC_SYNTHESIZE(double, settleAmt, SettleAmt);
	//ÒÑ½áËã½ð¶î
	CC_SYNTHESIZE(double, settledAmt, SettledAmt);
	//ÒÑ¿ªÆ±½ð¶î
	CC_SYNTHESIZE(double, invoicedAmt, InvoicedAmt);
	//¸½¼þ
	CC_SYNTHESIZE(string, attachment, Attachment);
	//±¸×¢
	CC_SYNTHESIZE(string, remark, Remark);
	//ÊÇ·ñ×Ô¶¯Éú³É
	CC_SYNTHESIZE(int, isAuto, IsAuto);
	//µ¥¾Ý½×¶Î
	CC_SYNTHESIZE(string, billStage, BillStage);
	//ºËÅúÈË
	CC_SYNTHESIZE(string, approver, Approver);
	//ÉóÅúÊµÀýid
	CC_SYNTHESIZE(string, bpmiInstanceId, BpmiInstanceId);
	//ºËÅú½á¹ûÀàÐÍ(1Í¨¹ý£¬0¾Ü¾ø)
	CC_SYNTHESIZE(string, approvalResultType, ApprovalResultType);
	//ºËÅúÒâ¼û
	CC_SYNTHESIZE(string, approvalRemark, ApprovalRemark);
	//ÒÑÉúÐ§
	CC_SYNTHESIZE(int, isEffective, IsEffective);
	//ÉúÐ§Ê±¼ä
	CC_SYNTHESIZE(string, effectiveTime, EffectiveTime);
	//ÒÑ¹Ø±Õ
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	//ÒÑ×÷·Ï
	CC_SYNTHESIZE(int, isVoided, IsVoided);
	//ÖÆµ¥²¿ÃÅ
	CC_SYNTHESIZE(string, sysOrgCode, SysOrgCode);	
	//ÖÆµ¥ÈË
	CC_SYNTHESIZE(string, createBy, CreateBy);
	//ÖÆµ¥Ê±¼ä
	CC_SYNTHESIZE(string, createTime, CreateTime);
	//ÐÞ¸ÄÈË
	CC_SYNTHESIZE(string, updateBy, UpdateBy);
	//ÐÞ¸ÄÊ±¼ä
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
	//°æ±¾
=======
	// å•æ®ç¼–å·
	CC_SYNTHESIZE(string, billNo, BillNo);
	//å•æ®æ—¥æœŸ
	CC_SYNTHESIZE(string, billDate, BillDate);
	//æºå•ç±»åž‹
	CC_SYNTHESIZE(string, srcBillType, SrcBillType);
	//æºå•id
	CC_SYNTHESIZE(string, srcBillId, SrcBillId);
	//æºå•å·
	CC_SYNTHESIZE(string, srcNo, SrcNo);
	//å•æ®ä¸»é¢˜
	CC_SYNTHESIZE(string, subject, Subject);
	//çº¢å­—å•æ®
	CC_SYNTHESIZE(int, isRubric, IsRubric);
	//å‡ºå…¥åº“ç±»åž‹
	CC_SYNTHESIZE(string, stockIoType, StockIoType);
	//ä¸šåŠ¡éƒ¨é—¨
	CC_SYNTHESIZE(string, opDept, OpDept);
	//ä¸šåŠ¡å‘˜
	CC_SYNTHESIZE(string, operator1, Operator1);
	//å‡ºå…¥åº“ç»åŠž
	CC_SYNTHESIZE(string, handler, Handler);
	//æœ‰æ¥å¾€
	CC_SYNTHESIZE(int, hasRp, HasRp);
	//æ˜¯å¦æœ‰æ¶¨å¨
	CC_SYNTHESIZE(int, hasSwell, HasSwell);
	//ä¾›åº”å•†
	CC_SYNTHESIZE(string, supplierId, SupplierId);
	//å®¢æˆ·
	CC_SYNTHESIZE(string, customerId, CustomerId);
	//å‘ç¥¨ç±»åž‹
	CC_SYNTHESIZE(string, invoiceType, InvoiceType);
	//æˆæœ¬
	CC_SYNTHESIZE(double, cost, Cost);
	//ç»“ç®—é‡‘é¢
	CC_SYNTHESIZE(double, settleAmt, SettleAmt);
	//å·²ç»“ç®—é‡‘é¢
	CC_SYNTHESIZE(double, settledAmt, SettledAmt);
	//å·²å¼€ç¥¨é‡‘é¢
	CC_SYNTHESIZE(double, invoicedAmt, InvoicedAmt);
	//é™„ä»¶
	CC_SYNTHESIZE(string, attachment, Attachment);
	//å¤‡æ³¨
	CC_SYNTHESIZE(string, remark, Remark);
	//æ˜¯å¦è‡ªåŠ¨ç”Ÿæˆ
	CC_SYNTHESIZE(int, isAuto, IsAuto);
	//å•æ®é˜¶æ®µ
	CC_SYNTHESIZE(string, billStage, BillStage);
	//æ ¸æ‰¹äºº
	CC_SYNTHESIZE(string, approver, Approver);
	//å®¡æ‰¹å®žä¾‹id
	CC_SYNTHESIZE(string, bpmiInstanceId, BpmiInstanceId);
	//æ ¸æ‰¹ç»“æžœç±»åž‹
	CC_SYNTHESIZE(string, approvalResultType, ApprovalResultType);
	//æ ¸æ‰¹æ„è§
	CC_SYNTHESIZE(string, approvalRemark, ApprovalRemark);
	//å·²ç”Ÿæ•ˆ
	CC_SYNTHESIZE(int, isEffective, IsEffective);
	//ç”Ÿæ•ˆæ—¶é—´
	CC_SYNTHESIZE(string, effectiveTime, EffectiveTime);
	//å·²å…³é—­
	CC_SYNTHESIZE(int, isClosed, IsClosed);
	//å·²ä½œåºŸ
	CC_SYNTHESIZE(int, isVoided, IsVoided);
	//åˆ¶å•éƒ¨é—¨
	CC_SYNTHESIZE(string, sysOrgCode, SysOrgCode);
	//åˆ¶å•äºº
	CC_SYNTHESIZE(string, createBy, CreateBy);
	//åˆ¶å•æ—¶é—´
	CC_SYNTHESIZE(string, createTime, CreateTime);
	// ä¿®æ”¹äºº
	CC_SYNTHESIZE(string, updateBy, UpdateBy);
	// ä¿®æ”¹æ—¶é—´
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
	//ç‰ˆæœ¬
>>>>>>> c5-maobing
	CC_SYNTHESIZE(string, version, Version);



public:
	StkIoDO() {
<<<<<<< HEAD
		id = "";
		billNo = "";
		billDate = "";
		srcBillType = "";
		srcBillId = "";
		srcNo = "";
		subject = "";
		isRubric = -1;
		stockIoType = "";
		opDept = "";
		operator1 = "";
		handler = "";
		hasRp = -1;
		hasSwell = -1;
		supplierId = "";
		customerId = "";
		invoiceType = "";
		cost = -1;
		settleAmt = -1;
		settledAmt = -1;
		invoicedAmt = -1;
		attachment = "";
		remark = "";
		isAuto = -1;
		billStage = "";
		approver = "";
		bpmiInstanceId = "";
		approvalResultType = "";
		approvalRemark = "";
		isEffective = -1;
		effectiveTime = "";
		isClosed = -1;
		isVoided = -1;
		sysOrgCode = "";
		createBy = "";
		createTime = "";
		updateBy = "";
		updateTime = "";
		version = "";


=======
>>>>>>> c5-maobing


	}
};

<<<<<<< HEAD
#endif // !_STKIO_DO_
=======
#endif // !_STKIO_DO_
>>>>>>> c5-maobing

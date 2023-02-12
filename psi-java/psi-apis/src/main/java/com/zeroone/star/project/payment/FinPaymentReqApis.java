package com.zeroone.star.project.payment;

import com.zeroone.star.project.query.payment.PurchaseListQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.payment.FinPaymentReqVO;

/**
 * @Author: Kong
 * @License: (C) Copyright 2005-2019, xxx Corporation Limited.
 * @Contact: xxx@xxx.com
 * @Date: 2023-02-12 21:57
 * @Version: 1.0
 * @Description:
 */

public interface FinPaymentReqApis {

    /**
     * 获取采购项目清单（有申请）
     * @param purchaseListQuery
     * @return 采购项目清单
     */
    public JsonVO<PageVO<FinPaymentReqVO>> queryForAppliedPurchaseRequisitions(PurchaseListQuery purchaseListQuery);

}
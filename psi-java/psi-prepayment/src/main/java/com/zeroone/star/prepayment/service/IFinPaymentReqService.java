package com.zeroone.star.prepayment.service;

import com.zeroone.star.prepayment.entity.FinPaymentReq;
import com.zeroone.star.project.query.prepayment.PurchaseListQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.prepayment.FinPaymentReqVO;

/**
 * @Author: xxx
 * @License: (C) Copyright 2005-2019, xxx Corporation Limited.
 * @Contact: xxx@xxx.com
 * @Date: 2023-02-18 15:14
 * @Version: 1.0
 * @Description:
 */

public interface IFinPaymentReqService {

    /**
     * 获取有申请采购单（分页）
     * @param purchaseListQuery
     * @return
     */
    public PageVO<FinPaymentReqVO> getFinPaymentReq(PurchaseListQuery purchaseListQuery);


}
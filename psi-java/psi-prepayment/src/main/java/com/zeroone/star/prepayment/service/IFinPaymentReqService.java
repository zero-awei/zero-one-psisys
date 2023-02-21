package com.zeroone.star.prepayment.service;

import com.zeroone.star.prepayment.entity.FinPaymentReq;


/**
 * FinPaymentReq 服务类
 * author 狂踹瘸子那条好腿
 * since 2023-02-18
 */
public interface IFinPaymentReqService {

    /**
     * 根据明细的源单id查询对应申请单
     * @param srcBillId 源单id
     * @return 查询结果
     */
    FinPaymentReq getBySrcBillId(String srcBillId);
}

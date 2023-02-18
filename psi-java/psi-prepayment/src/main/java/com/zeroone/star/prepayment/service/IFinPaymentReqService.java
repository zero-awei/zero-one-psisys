package com.zeroone.star.prepayment.service;

import com.zeroone.star.prepayment.entity.FinPaymentReq;

import java.util.List;

/**
 * FinPaymentReq 服务类
 * author 狂踹瘸子那条好腿
 * since 2023-02-18
 */
public interface IFinPaymentReqService {
    /**
     * 根据源单ID查询对应单据列表
     * @param srcBillID 源单ID
     * @return 查询结果
     */
    List<FinPaymentReq> listBySrcBillId(String srcBillID);
}

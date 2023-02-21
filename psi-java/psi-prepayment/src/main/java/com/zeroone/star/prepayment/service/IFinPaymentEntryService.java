package com.zeroone.star.prepayment.service;

import com.zeroone.star.prepayment.entity.FinPaymentEntry;

/**
 * FinPaymentEntry 服务类
 * author 狂踹瘸子那条好腿
 * since 2023-02-18
 */
public interface IFinPaymentEntryService {
    /**
     * 根据mid查询对应明细
     * @param mid 主表ID
     * @param srcBillType 源单类型（ FinPaymentEntry  /  PurOrder ）
     * @return 查询结果
     */
    FinPaymentEntry getByMid(String mid,String srcBillType);
}

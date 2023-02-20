package com.zeroone.star.prepayment.service;

import com.zeroone.star.prepayment.entity.FinPaymentEntry;

import java.util.List;

/**
 * FinPaymentEntry 服务类
 * author 狂踹瘸子那条好腿
 * since 2023-02-18
 */
public interface IFinPaymentEntryService {
    /**
     * 根据单据编号查询对应付款单明细
     * @param srcBillId 源单id
     * @return 查询结果
     */
    List<FinPaymentEntry> listBySrcBillId(String srcBillId);
}

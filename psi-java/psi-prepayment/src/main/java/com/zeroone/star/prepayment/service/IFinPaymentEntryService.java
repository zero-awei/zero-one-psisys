package com.zeroone.star.prepayment.service;

import com.zeroone.star.prepayment.entity.FinPaymentEntry;

/**
 * @Author: xxx
 * @License: (C) Copyright 2005-2019, xxx Corporation Limited.
 * @Contact: xxx@xxx.com
 * @Date: 2023-02-18 22:03
 * @Version: 1.0
 * @Description:
 */

public interface IFinPaymentEntryService {
    /**
     * 插入
     * @param finPaymentEntry
     * @return
     */
    public int insert(FinPaymentEntry finPaymentEntry);
}
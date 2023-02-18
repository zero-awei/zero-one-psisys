package com.zeroone.star.prepayment.service.impl;

import com.zeroone.star.prepayment.entity.FinPaymentEntry;
import com.zeroone.star.prepayment.mapper.FinPaymentEntryMapper;
import com.zeroone.star.prepayment.service.IFinPaymentEntryService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

/**
 * @Author: Kong
 * @License: (C) Copyright 2005-2019, xxx Corporation Limited.
 * @Contact: xxx@xxx.com
 * @Date: 2023-02-18 22:03
 * @Version: 1.0
 * @Description:
 */
@Service
public class FinPaymentEntryServiceImpl implements IFinPaymentEntryService {
    @Autowired
    FinPaymentEntryMapper finPaymentEntryMapper;

    @Override
    public int insert(FinPaymentEntry finPaymentEntry) {
        int insert = finPaymentEntryMapper.insert(finPaymentEntry);
        return insert==1?1:0;
    }
}
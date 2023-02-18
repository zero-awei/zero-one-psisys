package com.zeroone.star.prepayment.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.prepayment.entity.FinPayment;
import com.zeroone.star.prepayment.mapper.FinPaymentMapper;
import com.zeroone.star.prepayment.service.IFinPaymentService;
import com.zeroone.star.project.dto.prepayment.PrepaymentDTO;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

/**
 * @Author: Kong
 * @License: (C) Copyright 2005-2019, xxx Corporation Limited.
 * @Contact: xxx@xxx.com
 * @Date: 2023-02-18 20:52
 * @Version: 1.0
 * @Description:
 */
@Service
public class FinPaymentServiceImpl extends ServiceImpl<FinPaymentMapper, FinPayment> implements IFinPaymentService {

    @Autowired
    FinPaymentMapper finPaymentMapper;

    @Override
    public int insert(PrepaymentDTO prepaymentDTO) {
        FinPayment finPayment = new FinPayment();
        BeanUtils.copyProperties(prepaymentDTO,finPayment);
        System.out.println(finPayment.getAmt());
        System.out.println(finPayment.getBillDate());
        int res = finPaymentMapper.insert(finPayment);
        return res;
    }
}
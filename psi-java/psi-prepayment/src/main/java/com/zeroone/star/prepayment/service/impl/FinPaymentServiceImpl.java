package com.zeroone.star.prepayment.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.prepayment.entity.FinPayment;
import com.zeroone.star.prepayment.entity.FinPaymentEntry;
import com.zeroone.star.prepayment.mapper.FinPaymentMapper;
import com.zeroone.star.prepayment.service.IFinPaymentEntryService;
import com.zeroone.star.prepayment.service.IFinPaymentService;
import com.zeroone.star.project.dto.prepayment.FinPaymentEntryDTO;
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
    @Autowired
    IFinPaymentEntryService finPaymentEntryService;

    public int insert(PrepaymentDTO prepaymentDTO) {
        FinPayment finPayment = new FinPayment();
        BeanUtils.copyProperties(prepaymentDTO,finPayment);
        System.out.println(finPayment.getAmt());
        System.out.println(finPayment.getBillDate());
        int res = finPaymentMapper.insert(finPayment);
        return res;
    }
    @Override
    public int prepay(PrepaymentDTO prepaymentDTO){
        int res = insert(prepaymentDTO);
        int count=0;
        for (FinPaymentEntryDTO finPaymentEntryDTO:prepaymentDTO.getFinPaymentEntryList()){
            FinPaymentEntry finPaymentEntry = new FinPaymentEntry();
            BeanUtils.copyProperties(finPaymentEntryDTO,finPaymentEntry);
            finPaymentEntry.setBillNo(prepaymentDTO.getBillNo());//获取单号
            int i = finPaymentEntryService.insert(finPaymentEntry);
            if(i==1) count++;
        }

        if (res!=1 || count!=prepaymentDTO.getFinPaymentEntryList().size()) return 0;
        return 1;
    }


}
package com.zeroone.star.prepayment.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.prepayment.entity.FinPayment;
import com.zeroone.star.prepayment.mapper.FinPaymentMapper;
import com.zeroone.star.prepayment.service.IFinPaymentService;
import org.springframework.stereotype.Service;

/**
 * @ClassName FinPaymentServiceImpl
 * @Description IFinPaymentService服务类的实现
 * @Author HZP
 * @Date 2023/2/18 21:48
 * @Version 1.0
 **/
@Service
public class FinPaymentServiceImpl extends ServiceImpl<FinPaymentMapper, FinPayment> implements IFinPaymentService {
    @Override
    public FinPayment selectByBillNo(String billNo) {
        QueryWrapper<FinPayment> FinQueryWrapper = new QueryWrapper<>();
        FinQueryWrapper.eq("bill_no", billNo);
        FinPayment finPayment = baseMapper.selectOne(FinQueryWrapper);
        return finPayment;
    }
}
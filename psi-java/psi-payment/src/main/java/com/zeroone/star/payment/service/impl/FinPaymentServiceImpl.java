package com.zeroone.star.payment.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.star.payment.entity.FinPayment;
import com.zeroone.star.payment.entity.FinPaymentEntry;
import com.zeroone.star.payment.mapper.FinPaymentEntryMapper;
import com.zeroone.star.payment.mapper.FinPaymentMapper;
import com.zeroone.star.payment.service.IFinPaymentService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

/**
 * <p>
 * 付款单 服务实现类
 * </p>
 *
 * @author zhd
 * @since 2023-02-11
 */
@Service
public class FinPaymentServiceImpl extends ServiceImpl<FinPaymentMapper, FinPayment> implements IFinPaymentService {

    @Resource
    FinPaymentEntryMapper finPaymentEntryMapper;

    @Override
    public void delete(String id) {

        finPaymentEntryMapper.delete(new QueryWrapper<FinPaymentEntry>().eq(
                "mid",id
        ));
        baseMapper.deleteById(id);

    }
}

package com.zeroone.star.payment.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.star.payment.entity.FinPaymentEntry;
import com.zeroone.star.payment.entity.FinPaymentReq;
import com.zeroone.star.payment.entity.FinPaymentReqEntry;
import com.zeroone.star.payment.mapper.FinPaymentEntryMapper;
import com.zeroone.star.payment.mapper.FinPaymentReqEntryMapper;
import com.zeroone.star.payment.mapper.FinPaymentReqMapper;
import com.zeroone.star.payment.service.IFinPaymentReqService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

/**
 * <p>
 * 付款申请单 服务实现类
 * </p>
 *
 * @author zhd
 * @since 2023-02-11
 */
@Service
public class FinPaymentReqServiceImpl extends ServiceImpl<FinPaymentReqMapper, FinPaymentReq> implements IFinPaymentReqService {

    @Resource
    FinPaymentReqEntryMapper finPaymentReqEntryMapper;

    @Override
    public void delete(String id) {

        finPaymentReqEntryMapper.delete(new QueryWrapper<FinPaymentReqEntry>().eq(
                "mid",id
        ));
        baseMapper.deleteById(id);

    }
}

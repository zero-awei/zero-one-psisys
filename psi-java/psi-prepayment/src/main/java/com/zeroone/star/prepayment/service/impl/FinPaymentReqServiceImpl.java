package com.zeroone.star.prepayment.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.prepayment.entity.FinPaymentReq;
import com.zeroone.star.prepayment.mapper.FinPaymentReqMapper;
import com.zeroone.star.prepayment.service.IFinPaymentReqService;
import org.springframework.stereotype.Service;

/**
 * @ClassName FinPaymentReqServiceImpl
 * @Description IFinPaymentReqService服务类的实现
 * @Author HZP
 * @Date 2023/2/18 22:00
 * @Version 1.0
 **/
@Service
public class FinPaymentReqServiceImpl extends ServiceImpl<FinPaymentReqMapper, FinPaymentReq> implements IFinPaymentReqService {
    @Override
    public FinPaymentReq getBySrcBillId(String srcBillId) {
        QueryWrapper<FinPaymentReq> FinReqQueryWrapper = new QueryWrapper<>();
        FinReqQueryWrapper.eq("id",srcBillId);
        FinPaymentReq finPaymentReq = baseMapper.selectOne(FinReqQueryWrapper);
        if(finPaymentReq!=null)
            return finPaymentReq;
        return null;
    }
}
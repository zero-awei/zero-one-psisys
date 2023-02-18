package com.zeroone.star.prepayment.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.prepayment.entity.FinPaymentReq;
import com.zeroone.star.prepayment.mapper.FinPaymentReqMapper;
import com.zeroone.star.prepayment.service.IFinPaymentReqService;
import org.springframework.stereotype.Service;

import java.util.List;

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
    public List<FinPaymentReq> listBySrcBillId(String srcBillID) {
        QueryWrapper<FinPaymentReq> FinReqQueryWrapper = new QueryWrapper<>();
        FinReqQueryWrapper.eq("src_bill_id",srcBillID);
        List<FinPaymentReq> finPaymentReqList = baseMapper.selectList(FinReqQueryWrapper);
        return finPaymentReqList;
    }
}
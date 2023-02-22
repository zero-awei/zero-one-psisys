package com.zeroone.star.prepayment.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.prepayment.entity.FinPaymentEntry;
import com.zeroone.star.prepayment.mapper.FinPaymentEntryMapper;
import com.zeroone.star.prepayment.service.IFinPaymentEntryService;
import org.springframework.stereotype.Service;

import java.util.List;

/**
 * @ClassName FinPaymentEntryServiceImpl
 * @Description IFinPaymentEntryService服务类的实现
 * @Author HZP
 * @Date 2023/2/18 22:14
 * @Version 1.0
 **/
@Service
public class FinPaymentEntryServiceImpl extends ServiceImpl<FinPaymentEntryMapper, FinPaymentEntry> implements IFinPaymentEntryService {
    @Override
    public List<FinPaymentEntry> listByMid(String mid, String srcBillType) {
        QueryWrapper<FinPaymentEntry> FinEntryQueryWrapper = new QueryWrapper<>();
        FinEntryQueryWrapper.eq("mid",mid);
        FinEntryQueryWrapper.like("src_bill_type",srcBillType);
        List<FinPaymentEntry> finPaymentEntries = baseMapper.selectList(FinEntryQueryWrapper);
        if(finPaymentEntries!=null)
            return finPaymentEntries;
        return null;
    }
}
package com.zeroone.star.payment.service.impl;

import com.zeroone.star.payment.entity.FinPaymentEntry;
import com.zeroone.star.payment.mapper.FinPaymentEntryMapper;
import com.zeroone.star.payment.service.IFinPaymentEntryService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.stereotype.Service;

/**
 * <p>
 * 付款单明细 服务实现类
 * </p>
 *
 * @author zhd
 * @since 2023-02-11
 */
@Service
public class FinPaymentEntryServiceImpl extends ServiceImpl<FinPaymentEntryMapper, FinPaymentEntry> implements IFinPaymentEntryService {

}

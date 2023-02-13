package com.zeroone.star.payment.service.impl;

import com.zeroone.star.payment.entity.FinPayment;
import com.zeroone.star.payment.mapper.FinPaymentMapper;
import com.zeroone.star.payment.service.IFinPaymentService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.stereotype.Service;

/**
 * <p>
 * 付款单 服务实现类
 * </p>
 *
 * @author zhe
 * @since 2023-02-13
 */
@Service
public class FinPaymentServiceImpl extends ServiceImpl<FinPaymentMapper, FinPayment> implements IFinPaymentService {

}

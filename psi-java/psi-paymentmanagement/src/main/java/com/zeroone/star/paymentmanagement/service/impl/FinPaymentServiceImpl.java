package com.zeroone.star.paymentmanagement.service.impl;

import com.zeroone.star.paymentmanagement.entity.FinPayment;
import com.zeroone.star.paymentmanagement.mapper.FinPaymentMapper;
import com.zeroone.star.paymentmanagement.service.IFinPaymentService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.stereotype.Service;

/**
 * <p>
 * 付款单 服务实现类
 * </p>
 *
 * @author pyramid
 * @since 2023-02-15
 */
@Service
public class FinPaymentServiceImpl extends ServiceImpl<FinPaymentMapper, FinPayment> implements IFinPaymentService {

}

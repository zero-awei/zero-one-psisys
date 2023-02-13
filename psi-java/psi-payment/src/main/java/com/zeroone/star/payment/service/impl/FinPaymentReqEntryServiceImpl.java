package com.zeroone.star.payment.service.impl;

import com.zeroone.star.payment.entity.FinPaymentReqEntry;
import com.zeroone.star.payment.mapper.FinPaymentReqEntryMapper;
import com.zeroone.star.payment.service.IFinPaymentReqEntryService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.payment.PaymentReqEntryVO;
import org.springframework.stereotype.Service;

/**
 * <p>
 * 付款申请单明细 服务实现类
 * </p>
 *
 * @author zhd
 * @since 2023-02-11
 */
@Service
public class FinPaymentReqEntryServiceImpl extends ServiceImpl<FinPaymentReqEntryMapper, FinPaymentReqEntry> implements IFinPaymentReqEntryService {

    @Override
    public PageVO<PaymentReqEntryVO> getByBillNo(String billNo) {
        return null;
    }
}

package com.zeroone.star.prepayment.service.impl;

import com.zeroone.star.prepayment.entity.FinPaymentReqEntry;
import com.zeroone.star.prepayment.mapper.FinPaymentReqEntryMapper;
import com.zeroone.star.prepayment.service.IFinPaymentReqEntryService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.prepayment.PaymentReqEntryVO;
import org.springframework.stereotype.Service;

/**
 * <p>
 * 付款申请单明细 服务实现类
 * </p>
 *
 * @author zhe
 * @since 2023-02-13
 */
@Service
public class FinPaymentReqEntryServiceImpl extends ServiceImpl<FinPaymentReqEntryMapper, FinPaymentReqEntry> implements IFinPaymentReqEntryService {

    @Override
    public PageVO<PaymentReqEntryVO> getByBillNo(String billNo) {
        return null;
    }
}

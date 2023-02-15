package com.zeroone.star.payment.service;

import com.zeroone.star.payment.entity.FinPaymentReqEntry;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.payment.PaymentReqEntryVO;

/**
 * <p>
 * 付款申请单明细 服务类
 * </p>
 *
 * @author zhe
 * @since 2023-02-13
 */
public interface IFinPaymentReqEntryService extends IService<FinPaymentReqEntry> {

    /**
     * 根据源单号获取明细信息
     * @param billNo 源单号
     * @return 返回明细结果
     */
    PageVO<PaymentReqEntryVO> getByBillNo(String billNo);
}

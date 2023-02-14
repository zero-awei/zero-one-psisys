package com.zeroone.star.payment.service;

import com.zeroone.star.payment.entity.FinPaymentReq;
import com.baomidou.mybatisplus.extension.service.IService;

/**
 * <p>
 * 付款申请单 服务类
 * </p>
 *
 * @author zhd
 * @since 2023-02-11
 */
public interface IFinPaymentReqService extends IService<FinPaymentReq> {

    /**
     * 删除付款申请单和付款申请单明细
     * @param id
     */
    void delete(String id);
}

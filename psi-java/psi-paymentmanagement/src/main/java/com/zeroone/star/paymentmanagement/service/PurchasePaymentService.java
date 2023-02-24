package com.zeroone.star.paymentmanagement.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.paymentmanagement.entity.FinPayment;
import com.zeroone.star.project.dto.paymentmanagement.purchasepayment.PaymentCreateDTO;
import com.zeroone.star.project.dto.paymentmanagement.purchasepayment.PaymentDeleteDTO;
import com.zeroone.star.project.dto.paymentmanagement.purchasepayment.PaymentUpdateDTO;

/**
 * @author Tomcat -业峰实现
 * @ 采购付款增删改表现层
 * @Date 2023/2/23 22:36
 */
public interface PurchasePaymentService extends IService<FinPayment> {
    /**
     * 新增
     * @param paymentCreateDTO
     * @return
     */
    int insert(PaymentCreateDTO paymentCreateDTO);

    /**
     * 根据单据编号删除单据
     * @param paymentDeleteDTO
     * @return
     */
    int delete(PaymentDeleteDTO paymentDeleteDTO);

    /**
     * 根据单据编号修改
     * @param paymentUpdateDTO
     * @return
     */
    int update(PaymentUpdateDTO paymentUpdateDTO);

}

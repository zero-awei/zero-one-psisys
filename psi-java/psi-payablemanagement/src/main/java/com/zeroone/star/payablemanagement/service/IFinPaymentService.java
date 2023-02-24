package com.zeroone.star.payablemanagement.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.payablemanagement.entity.FinPayment;
import com.zeroone.star.project.query.payablemanagement.PaymentBySupplierQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.paymentmanagement.PaymentVO;
import org.springframework.stereotype.Service;


public interface IFinPaymentService extends IService<FinPayment> {
    PageVO<PaymentVO> queryBySupplierId(PaymentBySupplierQuery query);
}

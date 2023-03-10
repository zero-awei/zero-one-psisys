package com.zeroone.star.payablemanagement.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.payablemanagement.entity.FinPayment;
import com.zeroone.star.project.query.payablemanagement.PaymentBySupplierQuery;
import com.zeroone.star.project.vo.paymentmanagement.PaymentVO;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

@Mapper
public interface FinPaymentMapper extends BaseMapper<FinPayment> {

    List<PaymentVO> getBySupplierId(PaymentBySupplierQuery condition);
}

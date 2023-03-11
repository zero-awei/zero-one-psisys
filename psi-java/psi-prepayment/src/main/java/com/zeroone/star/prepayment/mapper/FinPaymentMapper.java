package com.zeroone.star.prepayment.mapper;

import com.zeroone.star.prepayment.entity.FinPayment;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

/**
 * <p>
 * 付款单 Mapper 接口
 * </p>
 *
 * @author zhd
 * @since 2023-02-18
 */
@Mapper
public interface FinPaymentMapper extends BaseMapper<FinPayment> {

    void addBatch(List<FinPayment> paymentReq);
}

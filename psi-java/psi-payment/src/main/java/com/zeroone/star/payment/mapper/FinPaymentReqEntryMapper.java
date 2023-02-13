package com.zeroone.star.payment.mapper;

import com.zeroone.star.payment.entity.FinPaymentReqEntry;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;

/**
 * <p>
 * 付款申请单明细 Mapper 接口
 * </p>
 *
 * @author zhe
 * @since 2023-02-13
 */
@Mapper
public interface FinPaymentReqEntryMapper extends BaseMapper<FinPaymentReqEntry> {

}

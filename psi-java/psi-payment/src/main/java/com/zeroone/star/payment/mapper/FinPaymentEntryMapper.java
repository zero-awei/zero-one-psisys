package com.zeroone.star.payment.mapper;

import com.zeroone.star.payment.entity.FinPaymentEntry;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;

/**
 * <p>
 * 付款单明细 Mapper 接口
 * </p>
 *
 * @author zhd
 * @since 2023-02-11
 */
@Mapper
public interface FinPaymentEntryMapper extends BaseMapper<FinPaymentEntry> {

}

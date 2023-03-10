package com.zeroone.star.paymentmanagement.mapper;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.paymentmanagement.entity.FinPaymentReqEntry;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.paymentmanagement.entity.QueryDocumentList;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

/**
 * <p>
 * 付款申请单明细 Mapper 接口
 * </p>
 *
 * @author achuan
 * @since 2023-02-15
 */
@Mapper
public interface FinPaymentReqEntryMapper extends BaseMapper<FinPaymentReqEntry> {
    public Page<FinPaymentReqEntry> viewSpecifiedDocInf(Page page, @Param("billNo") String billNo);

}

package com.zeroone.star.paymentmanagement.mapper;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.paymentmanagement.entity.FinPaymentReq;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.vo.paymentmanagement.FinPaymentReqVO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

import java.time.LocalDate;

/**
 * <p>
 * 付款申请单 Mapper 接口
 * </p>
 *
 * @author pyramid
 * @since 2023-02-15
 */
@Mapper
public interface FinPaymentReqMapper extends BaseMapper<FinPaymentReq> {
    Page<FinPaymentReqVO> queryAll(@Param("page")Page<FinPaymentReq> page, @Param("billNo") String billNo, @Param("billDate") LocalDate billDate, @Param("supplierId") String supplierId);

}

package com.zeroone.star.paymentmanagement.service;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.paymentmanagement.entity.FinPaymentReq;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.query.paymentmanagement.FinPaymentReqQuery;
import com.zeroone.star.project.vo.paymentmanagement.FinPaymentReqVO;

import java.util.List;

/**
 * <p>
 * 付款申请单 服务类
 * </p>
 *
 * @author pyramid
 * @since 2023-02-15
 */
public interface IFinPaymentReqService extends IService<FinPaymentReq> {
    /**
     * 付款申请列表查询
     * @param condition  单据列表查询对象
     * @return 付款申请列表
     */
    Page<FinPaymentReqVO> queryAll(FinPaymentReqQuery condition);

    List<FinPaymentReq> test();
}

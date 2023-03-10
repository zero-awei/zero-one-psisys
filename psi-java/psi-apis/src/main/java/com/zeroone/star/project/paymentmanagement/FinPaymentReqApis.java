package com.zeroone.star.project.paymentmanagement;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.query.paymentmanagement.FinPaymentReqQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.paymentmanagement.FinPaymentReqVO;

/**
 * @author 白也
 * @title
 * @date 2023/2/15 8:12 下午
 */
public interface FinPaymentReqApis {
    /**
     * 付款申请查询
     * @param finPayment 查询条件
     * @return 查询结果
     * @author 白也
     */
    JsonVO<Page<FinPaymentReqVO>> queryAll(FinPaymentReqQuery finPayment);
}

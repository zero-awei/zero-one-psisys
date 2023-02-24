package com.zeroone.star.project.paymentmanagement;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.query.paymentmanagement.FinPaymentReqQuery;
import com.zeroone.star.project.query.paymentmanagement.StkIoQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.paymentmanagement.FinPaymentReqVO;
import com.zeroone.star.project.vo.paymentmanagement.StkIoVO;

/**
 * @author 白也
 * @title 入库单查询
 * @date 2023/2/24 6:10 下午
 */
public interface StkIoApis {
    /**
     * 入库单查询
     * @param stkIoQuery 入库单条件
     * @return
     */
    JsonVO<Page<StkIoVO>> queryAll(StkIoQuery stkIoQuery);
}

package com.zeroone.star.project.payablemanagement;

import com.zeroone.star.project.query.payablemanagement.CheckPayableEntryQuery;
import com.zeroone.star.project.query.payablemanagement.CheckPayableQuery;
import com.zeroone.star.project.query.payablemanagement.PayableBySupplierQuery;
import com.zeroone.star.project.query.payablemanagement.PaymentBySupplierQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.payablemanagement.CheckPayableEntryVO;
import com.zeroone.star.project.vo.payablemanagement.CheckPayableVO;
import com.zeroone.star.project.vo.payablemanagement.PayableVO;
import com.zeroone.star.project.vo.paymentmanagement.PaymentVO;

/**
 * @author spk
 * @since 2023-02-13 21:34
 * @description 应付核销接口
 */
public interface CheckPayableApis {

    /**
     * 在应付核销首页上查询
     * @return null
     * @param condition 查询条件
     */
    JsonVO<PageVO<CheckPayableVO>> listFinPayableCheck(CheckPayableQuery condition);

    /**
     * 根据ID查询单据详情
     * @param condition 单据id
     * @return null
     */
    JsonVO<PageVO<CheckPayableEntryVO>> getById(CheckPayableEntryQuery condition);

    /**
     * 在新增界面上根据供应商ID查询应付单
     * @return null
     * @param condition 查询条件
     */
    JsonVO<PageVO<PayableVO>> listFinPayableBySupplier(PayableBySupplierQuery condition);

    /**
     * 在新增页面上根据供应商ID查询付款单
     * @return null
     * @param condition 查询条件
     */
    JsonVO<PageVO<PaymentVO>> listFinPaymentBySupplier(PaymentBySupplierQuery condition);

}

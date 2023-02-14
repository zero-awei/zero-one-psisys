package com.zeroone.star.project.payablemanagement;

import com.zeroone.star.project.query.payablemanagement.FinPayableCheckListQuery;
import com.zeroone.star.project.query.payablemanagement.FinPayableListBySupplierQuery;
import com.zeroone.star.project.query.payablemanagement.FinPaymentListBySupplierQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.payablemanagement.FinPayableCheckVO;

/**
 * @author spk
 * @since 2023-02-13 21:34
 * @description 应付核销接口
 */
public interface FinPayableCheckApis {
    /**
     * 在应付核销首页上查询
     * @return null
     * @param condition 查询条件
     */
    JsonVO<PageVO<FinPayableCheckVO>> listFinPayableCheck(FinPayableCheckListQuery condition);

    /**
     * 在新增界面上根据供应商ID查询应付单
     * TODO PageVO<这里应该是 FinPayableVO 应付单>
     * @return null
     * @param condition 查询条件
     */
    JsonVO<PageVO<FinPayableCheckVO>> listFinPayableBySupplier(FinPayableListBySupplierQuery condition);

    /**
     * 在新增页面上根据供应商ID查询付款单
     * TODO PageVO<这里应该是 FinPaymentVO 付款单>
     * @return null
     * @param condition 查询条件
     */
    JsonVO<PageVO<FinPayableCheckVO>> listFinPaymentBySupplier(FinPaymentListBySupplierQuery condition);

}

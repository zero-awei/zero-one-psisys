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
 * @description
 */
public interface FinPayableCheckApis {

    JsonVO<PageVO<FinPayableCheckVO>> listFinPayableCheck(FinPayableCheckListQuery condition);

    JsonVO<PageVO<FinPayableCheckVO>> listFinPayableBySupplier(FinPayableListBySupplierQuery condition);

    JsonVO<PageVO<FinPayableCheckVO>> listFinPaymentBySupplier(FinPaymentListBySupplierQuery condition);

}

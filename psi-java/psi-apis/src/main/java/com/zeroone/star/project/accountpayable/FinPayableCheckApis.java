package com.zeroone.star.project.accountpayable;

import com.zeroone.star.project.dto.accountpayable.FinPayableCheckDTO;
import com.zeroone.star.project.query.accountpayable.FInPayableCheckEntryQuery;
import com.zeroone.star.project.query.accountpayable.FinPayableCheckListAdvancedQuery;
import com.zeroone.star.project.query.accountpayable.FinPayableListBySupplierQuery;
import com.zeroone.star.project.query.accountpayable.FinPaymentListBySupplierQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.accountpayable.FinPayableCheckEntryVO;
import com.zeroone.star.project.vo.accountpayable.FinPayableCheckVO;
import com.zeroone.star.project.vo.accountpayable.FinPayableVO;
import com.zeroone.star.project.vo.accountpayable.FinPaymentVO;

import java.util.List;

/**
 * @author spk
 * @since 2023-02-13 21:34
 * @description 应付核销接口
 */
public interface FinPayableCheckApis {

    /**
     * 分页列出所有应付核销单据
     * @return null
     * @param finPayableCheckDTOS 应付核销DTO列表
     */
    JsonVO<PageVO<FinPayableCheckVO>> listAll(List<FinPayableCheckDTO> finPayableCheckDTOS);

    /**
     * 根据ID查询单据详情
     * @param condition 单据id
     * @return null
     */
    JsonVO<PageVO<FinPayableCheckEntryVO>> getById(FInPayableCheckEntryQuery condition);


    /**
     * 在应付核销首页上查询
     * @return null
     * @param condition 查询条件
     */
    JsonVO<PageVO<FinPayableCheckVO>> listFinPayableCheck(FinPayableCheckListAdvancedQuery condition);

    /**
     * 在新增界面上根据供应商ID查询应付单
     * @return null
     * @param condition 查询条件
     */
    JsonVO<PageVO<FinPayableVO>> listFinPayableBySupplier(FinPayableListBySupplierQuery condition);

    /**
     * 在新增页面上根据供应商ID查询付款单
     * @return null
     * @param condition 查询条件
     */
    JsonVO<PageVO<FinPaymentVO>> listFinPaymentBySupplier(FinPaymentListBySupplierQuery condition);

}

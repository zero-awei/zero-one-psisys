package com.zeroone.star.payablemanagement.controller;

import com.zeroone.star.payablemanagement.service.FinPayableCheckService;
import com.zeroone.star.project.query.payablemanagement.FinPayableCheckListBySupplierQuery;
import com.zeroone.star.project.query.payablemanagement.FinPayableCheckListQuery;
import com.zeroone.star.project.query.payablemanagement.FinPaymentListBySupplierQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.payablemanagement.FinPayableCheckVO;
import entity.FinPayableCheck;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;


/**
 * @author spk
 * @since 2023-02-13 19:48
 * @description 缺一些东西，需要其他模块配合。暂时先写上。
 */
@RestController
@RequestMapping("fin-payable-check")
@Api(tags = "应付核销接口")
@Validated
public class FinPayableCheckController {
    @Autowired
    FinPayableCheckService finPayableCheck;

    /**
     * 在应付核销首页上查询
     */
    @GetMapping("list")
    @ApiOperation("普通查询")
    JsonVO<PageVO<FinPayableCheckVO>> listFinPayableCheck(FinPayableCheckListQuery finPayableCheckListQuery) {
        return null;
    }

    /**
     * 在新增界面上根据供应商ID查询应付单
     * TODO 这里应该用 FinPayableVO 等待合并
     */
    @GetMapping("payable-new-by-supplier")
    @ApiOperation("根据供应商ID查询应付单")
    JsonVO<PageVO<FinPayableCheckVO>> listFinPayableBySupplier(FinPayableCheckListBySupplierQuery finPayableCheckListBySupplierQuery) {
        return null;
    }

    /**
     * 在新增页面上根据供应商ID查询付款单
     * TODO 这里应该用 FinPaymentVO 等待合并
     */
    @GetMapping("payment-new-by-supplier")
    @ApiOperation("根据供应商ID查询付款单")
    JsonVO<PageVO<FinPayableCheckVO>> listFinPaymentBySupplier(FinPaymentListBySupplierQuery finPaymentListBySupplierQuery) {
        return null;
    }

}

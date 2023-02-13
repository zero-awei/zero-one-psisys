package com.zeroone.star.payablemanagement.controller;

import com.zeroone.star.payablemanagement.service.FinPayableCheckService;
import com.zeroone.star.project.payablemanagement.FinPayableCheckApis;
import com.zeroone.star.project.query.payablemanagement.FinPayableListBySupplierQuery;
import com.zeroone.star.project.query.payablemanagement.FinPayableCheckListQuery;
import com.zeroone.star.project.query.payablemanagement.FinPaymentListBySupplierQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.payablemanagement.FinPayableCheckVO;
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
 * @description
 * 当前存在的问题：
 * 1. 没有继承Api
 * 2. 一些命名存在不规范的问题，可以看着改改
 * 3. 用了不是该查询所使用的VO，因为那些VO其他组员写了，合并改一下应该就可以？
 */
@RestController
@RequestMapping("fin-payable-check")
@Api(tags = "应付核销接口")
@Validated
public class FinPayableCheckController implements FinPayableCheckApis {
    @Autowired
    FinPayableCheckService finPayableCheck;

    /**
     * 在应付核销首页上查询
     */
    @GetMapping("list")
    @ApiOperation("普通查询")
    public JsonVO<PageVO<FinPayableCheckVO>> listFinPayableCheck(FinPayableCheckListQuery condition) {
        return null;
    }

    /**
     * 在新增界面上根据供应商ID查询应付单
     * TODO PageVO<这里应该是 FinPayableVO 应付单>
     */
    @GetMapping("payable-new-by-supplier")
    @ApiOperation("根据供应商ID查询应付单")
    public JsonVO<PageVO<FinPayableCheckVO>> listFinPayableBySupplier(FinPayableListBySupplierQuery condition) {
        return null;
    }

    /**
     * 在新增页面上根据供应商ID查询付款单
     * TODO PageVO<这里应该是 FinPaymentVO 付款单>
     */
    @GetMapping("payment-new-by-supplier")
    @ApiOperation("根据供应商ID查询付款单")
    public JsonVO<PageVO<FinPayableCheckVO>> listFinPaymentBySupplier(FinPaymentListBySupplierQuery condition) {
        return null;
    }

}

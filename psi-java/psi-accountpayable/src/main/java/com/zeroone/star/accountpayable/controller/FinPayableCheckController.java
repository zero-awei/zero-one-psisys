package com.zeroone.star.accountpayable.controller;

import com.zeroone.star.accountpayable.service.FinPayableCheckService;
import com.zeroone.star.project.accountpayable.FinPayableCheckApis;
import com.zeroone.star.project.dto.accountpayable.FinPayableCheckDTO;
import com.zeroone.star.project.query.accountpayable.FInPayableCheckEntryQuery;
import com.zeroone.star.project.query.accountpayable.FinPayableListBySupplierQuery;
import com.zeroone.star.project.query.accountpayable.FinPayableCheckListAdvancedQuery;
import com.zeroone.star.project.query.accountpayable.FinPaymentListBySupplierQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.accountpayable.FinPayableCheckEntryVO;
import com.zeroone.star.project.vo.accountpayable.FinPayableCheckVO;
import com.zeroone.star.project.vo.accountpayable.FinPayableVO;
import com.zeroone.star.project.vo.accountpayable.FinPaymentVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;


/**
 * @author spk
 * @since 2023-02-13 19:48
 * @description
 */
@RestController
@RequestMapping("fin-payable-check")
@Api(tags = "应付核销接口")
@Validated
public class FinPayableCheckController implements FinPayableCheckApis {
    @Autowired
    FinPayableCheckService finPayableCheck;

    @Override
    @GetMapping("list-all")
    @ApiOperation("列出所有单据")
    public JsonVO<PageVO<FinPayableCheckVO>> listAll(List<FinPayableCheckDTO> finPayableCheckDTOS) {
        return null;
    }

    @Override
    @GetMapping("detail")
    @ApiOperation("单据详情")
    public JsonVO<PageVO<FinPayableCheckEntryVO>> getById(FInPayableCheckEntryQuery condition) {
        return null;
    }

    @GetMapping("query")
    @ApiOperation("普通查询")
    public JsonVO<PageVO<FinPayableCheckVO>> listFinPayableCheck(FinPayableCheckListAdvancedQuery condition) {
        return null;
    }

    @Override
    @GetMapping("payable-new-by-supplier-query")
    @ApiOperation("根据供应商ID查询应付单")
    public JsonVO<PageVO<FinPayableVO>> listFinPayableBySupplier(FinPayableListBySupplierQuery condition) {
        return null;
    }

    @Override
    @GetMapping("payment-new-by-supplier-query")
    @ApiOperation("根据供应商ID查询付款单")
    public JsonVO<PageVO<FinPaymentVO>> listFinPaymentBySupplier(FinPaymentListBySupplierQuery condition) {
        return null;
    }

}

package com.zeroone.star.payable.controller.check;

import com.zeroone.star.payable.service.FinPayableCheckService;
import com.zeroone.star.project.payable.checkPayableAPI.FinPayableCheckApis;
import com.zeroone.star.project.dto.payable.FinPayableCheckDTO;
import com.zeroone.star.project.query.payable.FInPayableCheckEntryQuery;
import com.zeroone.star.project.query.payable.FinPayableListBySupplierQuery;
import com.zeroone.star.project.query.payable.FinPayableCheckListAdvancedQuery;
import com.zeroone.star.project.query.payable.FinPaymentListBySupplierQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.payable.FinPayableCheckEntryVO;
import com.zeroone.star.project.vo.payable.FinPayableCheckVO;
import com.zeroone.star.project.vo.payable.FinPayableVO;
import com.zeroone.star.project.vo.payable.FinPaymentVO;
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

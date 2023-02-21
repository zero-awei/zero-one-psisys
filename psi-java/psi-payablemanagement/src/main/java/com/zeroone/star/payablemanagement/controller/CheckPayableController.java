package com.zeroone.star.payablemanagement.controller;


import com.zeroone.star.payablemanagement.service.IFinPayableCheckService;
import com.zeroone.star.project.payablemanagement.CheckPayableApis;
import com.zeroone.star.project.query.payablemanagement.CheckPayableEntryQuery;
import com.zeroone.star.project.query.payablemanagement.PayableBySupplierQuery;
import com.zeroone.star.project.query.payablemanagement.CheckPayableQuery;
import com.zeroone.star.project.query.payablemanagement.PaymentBySupplierQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.payablemanagement.CheckPayableEntryVO;
import com.zeroone.star.project.vo.payablemanagement.CheckPayableVO;
import com.zeroone.star.project.vo.payablemanagement.PayableVO;
import com.zeroone.star.project.vo.paymentmanagement.PaymentVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.multipart.MultipartFile;
import org.springframework.web.bind.annotation.PostMapping;

/**
 * @author spk, naturezh
 * @since 2023-02-13 19:48
 * @description 应付核销模块
 */
@RestController
@RequestMapping("payablemanagement/checkmanagement")
@Api(tags = "应付管理-应付核销")
@Validated
public class CheckPayableController implements CheckPayableApis {
    @Autowired
    IFinPayableCheckService finPayableCheck;

    @Override
    @GetMapping("entry")
    @ApiOperation("查询单据详情")
    public JsonVO<PageVO<CheckPayableEntryVO>> getById(CheckPayableEntryQuery condition) {
        return null;
    }

    @GetMapping("list")
    @ApiOperation("查询单据列表")
    public JsonVO<PageVO<CheckPayableVO>> listFinPayableCheck(CheckPayableQuery condition) {
        return null;
    }

    @Override
    @GetMapping("queryPayableBySupplier")
    @ApiOperation("根据供应商ID查询应付单")
    public JsonVO<PageVO<PayableVO>> listFinPayableBySupplier(PayableBySupplierQuery condition) {
        return null;
    }

    @Override
    @GetMapping("queryPaymentBySupplier")
    @ApiOperation("根据供应商ID查询付款单")
    public JsonVO<PageVO<PaymentVO>> listFinPaymentBySupplier(PaymentBySupplierQuery condition) {
        return null;
    }

    @PostMapping("/export")
    @ApiOperation(value = "应付核销导出功能")
    public JsonVO<String> fileExport() {
        return null;
    }

    @PostMapping("/import")
    @ApiOperation(value = "应付核销导入功能")
    public JsonVO<String> fileImport(MultipartFile file) {
        return null;
    }

}

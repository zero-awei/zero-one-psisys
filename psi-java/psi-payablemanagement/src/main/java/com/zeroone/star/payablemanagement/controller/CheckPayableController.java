package com.zeroone.star.payablemanagement.controller;


import com.zeroone.star.payablemanagement.service.IFinPayableCheckEntryService;
import com.zeroone.star.payablemanagement.service.IFinPayableCheckService;
import com.zeroone.star.payablemanagement.service.IFinPayableService;
import com.zeroone.star.project.dto.payablemanagement.CheckPayableDTO;
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
import io.swagger.annotations.ApiParam;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import java.util.List;

/**
 * @author spk, naturezh, the end
 * @description 应付核销模块
 */
@RestController
@RequestMapping("payablemanagement/checkmanagement")
@Api(tags = "应付管理-应付核销")
@Validated
public class CheckPayableController implements CheckPayableApis {
    @Autowired
    IFinPayableCheckService finPayableCheck;
    @Autowired
    IFinPayableService finPayable;
    @Autowired
    IFinPayableCheckEntryService finPayableCheckEntry;

    @Override
    @GetMapping("entry")
    @ApiOperation("查询单据详情")
    public JsonVO<List<CheckPayableEntryVO>> getByMainId(CheckPayableEntryQuery condition) {
        return JsonVO.success(finPayableCheckEntry.getByMainId(condition));
    }

    @GetMapping("list")
    @ApiOperation("查询单据列表")
    public JsonVO<PageVO<CheckPayableVO>> queryAll(CheckPayableQuery condition) {
        return  JsonVO.success(finPayableCheck.queryAll(condition));
    }

    @Override
    @GetMapping("queryPayableBySupplier")
    @ApiOperation("根据供应商ID查询应付单")
    public JsonVO<PageVO<PayableVO>> listPayableBySupplier(PayableBySupplierQuery condition) {
        return null;
    }

    @Override
    @GetMapping("queryPaymentBySupplier")
    @ApiOperation("根据供应商ID查询付款单")
    public JsonVO<PageVO<PaymentVO>> listPaymentBySupplier(PaymentBySupplierQuery condition) {
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

    @ApiOperation("新增应付核销单")
    @PostMapping("/save")
    @Override
    public JsonVO<Void> addPayableCheck(@RequestBody CheckPayableDTO dto) {
        return null;
    }

    @ApiOperation("修改应付核销单")
    @PutMapping("/modify")
    @Override
    public JsonVO<Void> modifyPayableCheck(@RequestBody CheckPayableDTO dto) {
        return null;
    }

    @ApiOperation("关闭应付核销单（批量）")
    @PutMapping("/close")
    @Override
    public JsonVO<Void> closePayableCheck(@ApiParam("单据id集合") @RequestParam List<String> ids) {
        return null;
    }

    @ApiOperation("反关闭应付核销单（批量）")
    @PutMapping("/unclose")
    @Override
    public JsonVO<Void> unclosePayableCheck(@ApiParam("单据id集合") @RequestParam List<String> ids) {
        return null;
    }

    @ApiOperation("删除应付核销单（批量）")
    @DeleteMapping("/delete")
    @Override
    public JsonVO<Void> deletePayableCheck(@ApiParam("单据id集合") @RequestParam List<String> ids) {
        return null;
    }

    @ApiOperation("审核应付核销单")
    @PutMapping("/check")
    @Override
    public JsonVO<Void> checkPayableCheck(@ApiParam("单据id") @RequestParam String id,
                                          @ApiParam("核批结果") String approvalResultType,
                                          @ApiParam(value = "核批意见", allowEmptyValue = true) @RequestParam(required = false) String approvalRemark) {
        return null;
    }

    @ApiOperation("作废应付核销单")
    @PutMapping("/void")
    @Override
    public JsonVO<Void> voidPayableCheck(@ApiParam("单据id") @RequestParam String id) {
        return null;
    }
}

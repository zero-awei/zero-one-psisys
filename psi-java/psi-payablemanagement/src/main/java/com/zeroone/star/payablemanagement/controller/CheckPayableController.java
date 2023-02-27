package com.zeroone.star.payablemanagement.controller;


import cn.hutool.core.util.BooleanUtil;
import com.zeroone.star.payablemanagement.entity.FinPayableCheck;
import com.zeroone.star.payablemanagement.service.IFinPayableCheckService;
import com.zeroone.star.project.dto.payablemanagement.CheckPayableDTO;
import com.zeroone.star.project.payablemanagement.CheckPayableApis;
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
    IFinPayableCheckService finPayableCheckService;

    @Override
    @GetMapping("entry")
    @ApiOperation("查询单据详情")
    public JsonVO<PageVO<CheckPayableEntryVO>> getById(CheckPayableEntryQuery condition) {
        return null;
    }

    @Override
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
    @Override
    public JsonVO<String> fileExport() {
        return null;
    }

    @PostMapping("/import")
    @ApiOperation(value = "应付核销导入功能")
    @Override
    public JsonVO<String> fileImport(MultipartFile file) {
        return null;
    }

    @ApiOperation("新增应付核销单")
    @PostMapping("/add/{action}")
    @Override
    public JsonVO<String> addPayableCheck(@RequestBody CheckPayableDTO dto, @PathVariable String action) {
        try {
            if ("submit".equals(action)) {
                finPayableCheckService.submitAdd(dto);
                return JsonVO.success("新增提交成功！");
            } else {
                finPayableCheckService.saveAdd(dto);
                return JsonVO.success("新增保存成功！");
            }
        } catch (Exception e) {
            return JsonVO.fail(e.getMessage());
        }
    }

    @ApiOperation("修改应付核销单")
    @PutMapping("/modify/{action}")
    @Override
    public JsonVO<String> modifyPayableCheck(@RequestBody CheckPayableDTO dto, @PathVariable String action) {
        try {
            if ("submit".equals(action)) {
                finPayableCheckService.submitModify(dto);
                return JsonVO.success("修改提交成功！");
            } else {
                finPayableCheckService.saveModify(dto);
                return JsonVO.success("修改保存成功！");
            }
        } catch (Exception e) {
            return JsonVO.fail(e.getMessage());
        }
    }

    @ApiOperation("关闭应付核销单（批量）")
    @PutMapping("/close")
    @Override
    public JsonVO<String> closePayableCheck(@ApiParam("单据id集合") @RequestParam List<String> ids) {
        try {
            finPayableCheckService.lambdaUpdate()
                .set(FinPayableCheck::getIsClosed, 1)
                .in(FinPayableCheck::getId, ids)
                .update();
            return JsonVO.success("关闭应付核销单成功！");
        } catch (Exception e) {
            return JsonVO.fail(e.getMessage());
        }
    }

    @ApiOperation("反关闭应付核销单（批量）")
    @PutMapping("/unclose")
    @Override
    public JsonVO<String> unclosePayableCheck(@ApiParam("单据id集合") @RequestParam List<String> ids) {
        try {
            finPayableCheckService.lambdaUpdate()
                .set(FinPayableCheck::getIsClosed, 0)
                .in(FinPayableCheck::getId, ids)
                .update();
            return JsonVO.success("反关闭应付核销单成功！");
        } catch (Exception e) {
            return JsonVO.fail(e.getMessage());
        }
    }

    @ApiOperation("删除应付核销单（批量）")
    @DeleteMapping("/delete")
    @Override
    public JsonVO<String> deletePayableCheck(@ApiParam("单据id集合") @RequestParam List<String> ids) {
        try {
            finPayableCheckService.removeWithEntry(ids);
            return JsonVO.success("删除应付核销单成功！");
        } catch (Exception e) {
            return JsonVO.fail(e.getMessage());
        }
    }

    @ApiOperation("审核应付核销单")
    @PutMapping("/check")
    @Override
    public JsonVO<String> checkPayableCheck(@ApiParam("单据id") @RequestParam String id,
        @ApiParam("核批结果") String approvalResultType,
        @ApiParam(value = "核批意见", allowEmptyValue = true) @RequestParam(required = false) String approvalRemark) {
        try {
            boolean flag = finPayableCheckService.isCheckPass(id, approvalResultType, approvalRemark);
            return JsonVO.success(BooleanUtil.isTrue(flag) ? "审核通过！" : "审核不通过！");
        } catch (Exception e) {
            return JsonVO.fail(e.getMessage());
        }
    }

    @ApiOperation("作废应付核销单")
    @PutMapping("/void")
    @Override
    public JsonVO<String> voidPayableCheck(@ApiParam("单据id") @RequestParam String id) {
        try {
            finPayableCheckService.lambdaUpdate()
                .setSql("is_voided = 1")
                .eq(FinPayableCheck::getId, id)
                .update();
            return JsonVO.success("作废应付核销单成功！");
        } catch (Exception e) {
            return JsonVO.fail(e.getMessage());
        }
    }
}

package com.zeroone.star.payablemanagement.controller;

import com.zeroone.star.payablemanagement.service.IFinPayableService;
import com.zeroone.star.project.payablemanagement.PurchasePayableApis;
import com.zeroone.star.project.query.payablemanagement.PayableQuery;
import com.zeroone.star.project.query.payablemanagement.PayableBillNoQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.payablemanagement.PayableVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;

import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.bind.annotation.PostMapping;

import java.util.List;

/**
 * <p>
 * 应付单 前端控制器 采购应付模块
 * </p>
 *
 * @author chosen1, naturezh
 * @since 2023-02-14
 */
@RestController
@RequestMapping("payablemanagement/purchasemanagement")
@Api(tags = "应付管理-采购预付")
@Validated
public class PurchasePayableController implements PurchasePayableApis {

    @Autowired
    private IFinPayableService service;

    @ApiOperation("分页查询所有单据")
    @GetMapping("query/list/select/purchase/all")
    @Override
    public JsonVO<PageVO<PayableVO>> getAll(PayableQuery query) {
        return JsonVO.success(service.getAll(query));
    }

    @ApiOperation("查询单据详情")
    @GetMapping("query/get/select/purchase/detail")
    @Override
    public JsonVO<PayableVO> getById(@Validated PayableBillNoQuery query) {
        return JsonVO.success(service.getByBillNO(query));
    }

    @PostMapping("/export")
    @ApiOperation(value = "采购应付导出功能")
    public JsonVO<String> fileExport() {
        return null;
    }

}

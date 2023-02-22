package com.zeroone.star.paymentmanagement.controller;


import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.paymentmanagement.entity.FinPaymentReq;
import com.zeroone.star.paymentmanagement.service.IFinPaymentReqService;
import com.zeroone.star.project.paymentmanagement.FinPaymentReqApis;
import com.zeroone.star.project.query.paymentmanagement.FinPaymentReqQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.paymentmanagement.FinPaymentReqVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;

import org.springframework.web.bind.annotation.RestController;

import java.util.List;

/**
 * <p>
 * 付款申请单 前端控制器
 * </p>
 *
 * @author pyramid
 * @since 2023-02-15
 */
@Api(value = "/onlytype/fin-payment-req", tags = {"付款申请单 前端控制器"})
@RestController
@RequestMapping("/onlytype/fin-payment-req")
public class FinPaymentReqController implements FinPaymentReqApis {
    @Autowired
    private IFinPaymentReqService iFinPaymentReqService;
    /**
     * 付款申请查询
     *
     * @param finPayment 查询条件
     * @return 查询结果
     * @author 白也
     */

    @ApiOperation(value = "付款申请查询", notes = "付款申请查询")
    @Override
    @GetMapping
    public JsonVO<Page<FinPaymentReqVO>> queryAll(FinPaymentReqQuery finPayment) {
        return JsonVO.success(iFinPaymentReqService.queryAll(finPayment));
    }

    @ApiOperation(value = "测试查询所有", notes = "test")
    @PostMapping
    public JsonVO<List<FinPaymentReq>> test() {
        return JsonVO.success(iFinPaymentReqService.test());
    }

}


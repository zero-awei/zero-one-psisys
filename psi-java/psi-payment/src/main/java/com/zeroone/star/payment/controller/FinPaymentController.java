package com.zeroone.star.payment.controller;


import com.zeroone.star.project.dto.payment.PrepaymentDTO;
import com.zeroone.star.project.payment.PaymentApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.payment.SupplierVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestMapping;

import org.springframework.web.bind.annotation.RestController;

import java.util.List;

/**
 * <p>
 * 付款单 前端控制器
 * </p>
 *
 * @author zhd
 * @since 2023-02-11
 */
@RestController
@RequestMapping("/payment/fin-payment")
@Api(tags = "预付款")
public class FinPaymentController implements PaymentApis {

    @PutMapping("insert-prepayment")
    @ApiOperation(value = "预付款操作")
    @Override
    public JsonVO<String> prepaymentForPurchaseRequisitions(PrepaymentDTO prepaymentDTO) {
        return null;
    }

    @Override
    public JsonVO<List<SupplierVO>> querySupplierList() {
        return null;
    }


}


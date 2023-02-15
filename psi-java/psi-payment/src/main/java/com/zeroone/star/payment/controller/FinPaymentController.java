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
 * @author zhe
 * @since 2023-02-13
 */
@RestController
@RequestMapping("/payment/fin-payment")
@Api(tags = "预付款")
public class FinPaymentController {


}


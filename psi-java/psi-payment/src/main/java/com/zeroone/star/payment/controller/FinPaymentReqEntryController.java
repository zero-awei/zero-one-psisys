package com.zeroone.star.payment.controller;


import com.zeroone.star.payment.service.IFinPaymentReqEntryService;
import com.zeroone.star.project.payment.PaymentApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.payment.PaymentReqEntryVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;

/**
 * <p>
 * 付款申请单明细 前端控制器
 * </p>
 *
 * @author zhd
 * @since 2023-02-11
 */
@RestController
@RequestMapping("/payment/fin-payment-req-entry")
@Api(tags = "付款申请单明细接口")
public class FinPaymentReqEntryController implements PaymentApis {

    @Resource
    IFinPaymentReqEntryService iFinPaymentReqEntryService;

    @GetMapping("/{billNo}")
    @Override
    @ApiOperation("付款申请单分录列表查询")
    public JsonVO<PageVO<PaymentReqEntryVO>> queryAllByBillNo(@PathVariable("billNo") String billNo) {
        return JsonVO.success(iFinPaymentReqEntryService.getByBillNo(billNo));
    }
}


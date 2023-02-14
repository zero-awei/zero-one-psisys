package com.zeroone.star.payment.controller;


import com.zeroone.star.payment.service.IFinPaymentReqService;
import com.zeroone.star.payment.service.IFinPaymentService;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.RequestMapping;

import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;

/**
 * <p>
 * 付款申请单 前端控制器
 * </p>
 *
 * @author zhd
 * @since 2023-02-11
 */
@RestController
@RequestMapping("/payment/fin-payment-req")
public class FinPaymentReqController {

    @Resource
    IFinPaymentReqService finPaymentReqService;

    /**
     * 删除付款申请单和付款申请单明细
     * @param id
     * @return
     */
    @DeleteMapping("/delete")
    @ApiOperation("删除付款申请单和付款申请单明细")
    public JsonVO<String> deletePayment(String id) {


        finPaymentReqService.delete(id);

        return  JsonVO.create("删除成功"
                ,200,"删除成功");
    }

}


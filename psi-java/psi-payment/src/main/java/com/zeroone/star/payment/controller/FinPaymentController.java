package com.zeroone.star.payment.controller;


import com.zeroone.star.payment.service.IFinPaymentService;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.RequestMapping;

import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;
import java.util.HashMap;

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
public class FinPaymentController {

    @Resource
    IFinPaymentService  finPaymentService;

    /**
     * 删除付款单和付款单明细
     * @param id
     * @return
     */
    @ApiOperation("删除付款单和付款单明细")
    @DeleteMapping("/delete")
    public JsonVO<String> deletePayment(String id) {


        finPaymentService.delete(id);

        return  JsonVO.create("删除成功"
        ,200,"删除成功");
    }
}


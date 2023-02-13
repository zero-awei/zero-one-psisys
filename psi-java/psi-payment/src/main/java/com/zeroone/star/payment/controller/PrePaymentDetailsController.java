package com.zeroone.star.payment.controller;

import com.zeroone.star.project.payment.PrePaymentDetApis;
import com.zeroone.star.project.query.payment.PreDetQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.payment.DetHavVO;
import com.zeroone.star.project.vo.payment.DetNoVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

/**
 * @ClassName PaymentDetailsController
 * @Description 根据订单编号查询详细信息
 * @Author HZP
 * @Date 2023/2/12 16:33
 * @Version 1.0
 **/
@RestController
@RequestMapping("/payment/detail")
@Api(tags = "查询详细信息")
@Validated
public class PrePaymentDetailsController implements PrePaymentDetApis {

    @GetMapping("/hav")
    @ApiOperation(value = "有申请")
    @Override
    public JsonVO<DetHavVO> queryByBillHav(PreDetQuery condition) {
        return JsonVO.success(new DetHavVO());
    }

    @GetMapping("/no")
    @ApiOperation(value = "无申请")
    @Override
    public JsonVO<DetNoVO> queryByBillNo(PreDetQuery condition) {
        return JsonVO.success(new DetNoVO());
    }
}
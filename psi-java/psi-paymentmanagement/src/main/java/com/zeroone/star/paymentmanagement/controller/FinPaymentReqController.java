package com.zeroone.star.paymentmanagement.controller;


import com.zeroone.star.project.paymentmanagement.FinPaymentReqApis;
import com.zeroone.star.project.query.paymentmanagement.FinPaymentReqQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.paymentmanagement.FinPaymentReqVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiImplicitParam;
import io.swagger.annotations.ApiImplicitParams;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;

import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.multipart.MultipartFile;

/**
 * <p>
 * 付款申请单 前端控制器
 * </p>
 *
 * @author pyramid
 * @since 2023-02-15
 */
@Api(tags = "付款管理-采购付款")
@RestController
@RequestMapping("/onlytype/fin-payment-req")
public class FinPaymentReqController implements FinPaymentReqApis {

    /**
     * 付款申请查询
     *
     * @param finPayment 查询条件
     * @return 查询结果
     * @author 白也
     */
    @ApiImplicitParams({
            @ApiImplicitParam(paramType = "query", dataType = "FinPaymentReqQuery", name = "finPayment", value = "查询条件", required = true)
    })
    @ApiOperation(value = "付款申请查询", notes = "付款申请查询")
    @Override
    @GetMapping
    public JsonVO<PageVO<FinPaymentReqVO>> queryAll(FinPaymentReqQuery finPayment) {
        return null;
    }


}


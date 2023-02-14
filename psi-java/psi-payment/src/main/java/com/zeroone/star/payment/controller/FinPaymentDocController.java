package com.zeroone.star.payment.controller;

import com.zeroone.star.project.payment.PaymentApis;
import com.zeroone.star.project.query.payment.DocListQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.payment.DocListVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

/**
 * <p>
 * 单据查询 前端控制器
 * </p>
 *
 * @author husj
 * @since 2023-02-13
 */
@RestController
@RequestMapping("/payment")
@Api(tags = "单据查询")
@Validated
public class FinPaymentDocController implements PaymentApis {
    @Override
    @GetMapping("/condition")
    @ApiOperation(value = "按照条件实现单据查询")
    public JsonVO<PageVO<DocListVO>> queryAll(DocListQuery condition) {
        return null;
    }
}

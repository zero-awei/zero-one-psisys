package com.zeroone.star.payment.controller;

import com.zeroone.star.project.dto.payment.ModifyDTO;
import com.zeroone.star.project.payment.PaymentApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
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
@RestController
@RequestMapping("edit")
@Api(tags = "测试")
public class PaymentController implements PaymentApis {

    @PutMapping("submit")
    @ApiOperation(value = "修改采购预付单功能")
    @Override
    public JsonVO<String> modifyById(ModifyDTO modifyDTO) {
        return JsonVO.success("1111");
    }

    /**
     * <p>
     * 单据查询 前端控制器
     * </p>
     *
     * @author husj
     * @since 2023-02-13
     */
    @Override
    @GetMapping("/condition")
    @ApiOperation(value = "按照条件实现单据查询")
    public JsonVO<PageVO<DocListVO>> queryAll(DocListQuery condition) {
        return null;
    }
}

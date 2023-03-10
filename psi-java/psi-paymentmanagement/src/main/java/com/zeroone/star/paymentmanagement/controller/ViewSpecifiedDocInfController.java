package com.zeroone.star.paymentmanagement.controller;

import com.zeroone.star.paymentmanagement.service.IViewSpecifiedDocInfService;
import com.zeroone.star.project.paymentmanagement.ViewSpecifiedDocInfApis;
import com.zeroone.star.project.query.paymentmanagement.ViewSpecifiedDocInfQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.paymentmanagement.ViewSpecifiedDocInfVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;

/**
 * @author achuan
 * @Date 2023/2/18 22:22
 */
@Api(tags = "应付与付款-付款管理")
@RestController
@RequestMapping("/paymentmanagement")
@ApiModel("查看指定单据信息")
public class ViewSpecifiedDocInfController implements ViewSpecifiedDocInfApis {
    @Resource
    private IViewSpecifiedDocInfService service;

    @GetMapping("/viewSpecifiedDocInfTrue")
    @ApiOperation(value="查看指定单据信息（有申请）")
    @Override
    public JsonVO<PageVO<ViewSpecifiedDocInfVO>> viewspecifieddocinf_true(ViewSpecifiedDocInfQuery condition) {
        return JsonVO.success(service.viewSpecifiedDocInf(condition));
    }
    @GetMapping("/viewSpecifiedDocInfFalse")
    @ApiOperation(value="查看指定单据信息（无申请）")
    @Override
    public JsonVO<PageVO<ViewSpecifiedDocInfVO>> viewspecifieddocinf_false(ViewSpecifiedDocInfQuery condition) {
        return JsonVO.success(service.viewSpecifiedDocInf(condition));
    }
    @GetMapping("/viewSpecifiedDocInfRed")
    @ApiOperation(value="查看指定单据信息（红付）")
    @Override
    public JsonVO<PageVO<ViewSpecifiedDocInfVO>> viewspecifieddocinf_red(ViewSpecifiedDocInfQuery condition) {
        return JsonVO.success(service.viewSpecifiedDocInf(condition));
    }

}

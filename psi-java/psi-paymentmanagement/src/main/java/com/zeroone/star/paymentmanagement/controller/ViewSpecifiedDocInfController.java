package com.zeroone.star.paymentmanagement.controller;

import com.zeroone.star.project.paymentmanagement.ViewSpecifiedDocInfApis;
import com.zeroone.star.project.query.paymentmanagement.ViewSpecifiedDocInfQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.paymentmanagement.ViewSpecifiedDocInfVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiModel;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
/**
 * @author achuan
 * @Date 2023/2/18 22:22
 */
@Api(tags = "应付与付款-付款管理")
@RestController
@RequestMapping("/paymentmanagement/viewspecifieddocinf")
@ApiModel("查看指定单据信息")
public class ViewSpecifiedDocInfController implements ViewSpecifiedDocInfApis {
    @GetMapping("/listall")
    @Override
    public JsonVO<PageVO<ViewSpecifiedDocInfVO>> queryAll(ViewSpecifiedDocInfQuery condition) {
        return null;
    }
    @GetMapping("/listone")
    @Override
    public JsonVO<ViewSpecifiedDocInfVO> queryOne(ViewSpecifiedDocInfQuery condition) {
        return null;
    }
}

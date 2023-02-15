package com.zeroone.star.payable.controller;

import com.zeroone.star.project.payable.purchaseApis;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

/**
 * 采购应付模块
 * @author naturezh
 * @since 2023-02-14
 */
@RestController
@RequestMapping("/payable/purchase")
@Api(tags = "purchase")
public class purchaseController implements purchaseApis {

    @PostMapping("/export")
    @ApiOperation(value = "采购应付导出功能")
    public JsonVO<String> fileExport() {
        return null;
    }

}

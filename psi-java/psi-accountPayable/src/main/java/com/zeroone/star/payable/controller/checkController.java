package com.zeroone.star.payable.controller;

import com.zeroone.star.project.payable.checkApis;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.multipart.MultipartFile;

/**
 * 应付核销模块
 * @author naturezh
 * @since 2023-02-14
 */
@RestController
@RequestMapping("/payable/check")
@Api(tags = "check")
public class checkController implements checkApis {

    @PostMapping("/export")
    @ApiOperation(value = "应付核销导出功能")
    public JsonVO<String> fileExport() {
        return null;
    }

    @PostMapping("/import")
    @ApiOperation(value = "应付核销导入功能")
    public JsonVO<String> fileImport(MultipartFile file) {
        return null;
    }

}

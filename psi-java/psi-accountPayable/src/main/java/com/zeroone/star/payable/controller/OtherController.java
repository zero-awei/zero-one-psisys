package com.zeroone.star.payable.controller;

import com.zeroone.star.project.payable.OtherApis;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.multipart.MultipartFile;

/**
 * 其他应付模块
 * @author naturezh
 * @since 2023-02-14
 */
@RestController
@RequestMapping("/payable/other")
@Api(tags = "other")
public class OtherController implements OtherApis {

    @PostMapping("/export")
    @ApiOperation(value = "其他应付导出功能")
    public JsonVO<String> fileExport() {
        return null;
    }

    @PostMapping("/import")
    @ApiOperation(value = "其他应付导入功能")
    public JsonVO<String> fileImport(MultipartFile file) {
        return null;
    }

}

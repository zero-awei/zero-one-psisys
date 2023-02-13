package com.zeroone.star.payablemanagement.controller;

import com.zeroone.star.payablemanagement.service.ExcelService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;

/**
 * Excel导出、导入
 *
 * @author iceberg-work
 */
@Controller
@RequestMapping("excel")
@Api(tags = "Excel")
@RestController
public class ExcelController {

    @Resource
    ExcelService excelService;

    @ApiOperation("模板导出其他应付Excel")
    @PostMapping(value = "importExcelAsTemplate", produces = "application/octet-stream")
    public ResponseEntity<byte[]> importExcelAsTemplate() {
        return excelService.downloadOthersPayable();
    }
}
